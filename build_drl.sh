#!/usr/bin/env bash
# 自愈式编译 TITA_DRL: 编译前校验源码是否为新版 (10路分析记录),
# 被回退则自动从 pristine 副本恢复, 编译后校验二进制标记。
# 用法 (容器内):  bash /mnt/dev/tita_ws/build_drl.sh
#              或  bash build_drl.sh [工作区根] [pristine 目录]
set -euo pipefail

WS="${1:-/mnt/dev/tita_ws}"
PRISTINE="${2:-/mnt/dev/drl_action_recording/files}"
SRC="$WS/src/TITA_GAZEBO_DRL/src/TITA_DRL/src/tita_drl_obs170.cpp"
PRIS="$PRISTINE/TITA_DRL/src/tita_drl_obs170.cpp"

src_ver() { grep -c "recordWheelAnalysis" "$1" 2>/dev/null || true; }

if [ "$(src_ver "$SRC")" -lt 1 ]; then
  echo "!! 检测到源码被回退为旧版 (8关节记录)"
  if [ -f "$PRIS" ] && [ "$(src_ver "$PRIS")" -ge 1 ]; then
    cp -a "$PRIS" "$SRC"
    echo ">> 已自动恢复新版源码 (来自 $PRIS)"
  else
    echo "ERROR: 未找到新版源码副本, 终止编译。"
    echo "       请先在宿主机执行: cd /home/robot/drl_action_recording && sudo bash apply.sh"
    exit 1
  fi
fi

echo "源码版本 OK (10路分析记录), 开始编译..."
# 刷新源码时间戳: 防止 colcon 因 mtime 过旧而跳过编译 (增量编译依赖 mtime 判断)
touch "$SRC"
cd "$WS"
colcon build --packages-select TITA_DRL

# 等待二进制稳定: 可能有其他终端并发编译, 等到连续两次检查
# (间隔1s) 都含标记且 mtime 不再变化为止 (最多 20 次)
BIN="$WS/build/TITA_DRL/tita_drl_obs170"
ok=0
prev_mtime=""
stable=0
for i in $(seq 1 20); do
  cnt=$(strings "$BIN" 2>/dev/null | grep -c "left_wheel_action" || true)
  if [ "$cnt" -ge 1 ]; then
    cur=$(stat -c %Y "$BIN" 2>/dev/null || echo 0)
    if [ "$cur" = "$prev_mtime" ]; then
      stable=$((stable + 1))
      if [ "$stable" -ge 2 ]; then ok=1; break; fi
    else
      stable=0
      prev_mtime="$cur"
    fi
  else
    stable=0
  fi
  sleep 1
done
if [ "$ok" = "1" ]; then
  echo ">> 编译完成且二进制为新版 (含 left_wheel_action)"
else
  echo "ERROR: 二进制仍为旧版或被持续重写!"
  echo "  二进制时间: $(ls -la "$BIN" 2>/dev/null | awk '{print $6,$7,$8}')"
  echo "  标记计数: $(strings "$BIN" 2>/dev/null | grep -c left_wheel_action)"
  echo "  请确认没有其他终端同时在编译, 然后重跑本脚本"
  exit 1
fi
