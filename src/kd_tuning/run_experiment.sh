#!/usr/bin/env bash
# kd_vel 整定实验: 只修改 kd_vel 默认值 -> 重建 -> 跑仿真 -> 收集CSV
# 用法: bash run_experiment.sh <kd值> <标签> [采集时长s=65]
set -eo pipefail
KD="$1"; TAG="$2"; DUR="${3:-65}"
CTRL="/mnt/dev/tita_ws/src/TITA_GAZEBO_DRL/src/TITA_ROS2_Control_Sim/custom_joint_position_controller/src/joint_position_controller.cpp"
DIR="/mnt/dev/tita_ws/src/kd_tuning"
[ -f "$DIR/baseline_ctrl.cpp" ] || cp -a "$CTRL" "$DIR/baseline_ctrl.cpp"

cleanup_sim() {
  pkill -f "gzserve[r]" 2>/dev/null || true
  pkill -f "tita_drl_obs17[0]" 2>/dev/null || true
  pkill -f "ros2 launc[h]" 2>/dev/null || true
  pkill -f "controller_manage[r]" 2>/dev/null || true
  pkill -f "spawn_entit[y]" 2>/dev/null || true
  pkill -f "robot_reset_time[r]" 2>/dev/null || true
  pkill -f "joint_position_controlle[r]" 2>/dev/null || true
  pkill -f "robot_state_publishe[r]" 2>/dev/null || true
  sleep 3
  pkill -9 -f "gzserve[r]" 2>/dev/null || true
  sleep 1
}

echo "[实验] kd_vel=$KD tag=$TAG 时长=${DUR}s"
cleanup_sim    # 清掉上一轮残留

# 1. 只改 kd_vel 一行
sed -i "s/declare_parameter(\"kd_vel\", [0-9.eE+-]*)/declare_parameter(\"kd_vel\", $KD)/" "$CTRL"
grep -n "declare_parameter(\"kd_vel\"" "$CTRL" | head -1

# 2. 重建控制器
source /opt/ros/humble/setup.bash
cd /mnt/dev/tita_ws && colcon build --packages-select custom_joint_position_controller 2>&1 | tail -1

# 3. 启动仿真
source /mnt/dev/tita_ws/install/setup.bash
cd /mnt/dev/tita_ws
MARK=/tmp/kd_exp_start.$$
touch "$MARK"
rm -f /tmp/drl_run.log /tmp/sim_run.log
ros2 launch TITA_DRL tita_drl.launch.py > /tmp/drl_run.log 2>&1 &
sleep 2
ros2 launch sim_bringup sim_bringup.launch.py > /tmp/sim_run.log 2>&1 &
sleep 8

# 4. 就绪检查: controller_manager 服务必须在 30s 内出现 (最多重试3次)
READY=0
for attempt in 1 2; do
  for i in $(seq 1 30); do
    if grep -q "Successful initialization of hardware" /tmp/sim_run.log 2>/dev/null && pgrep -f "gzserve[r]" >/dev/null; then
      READY=1; break
    fi
    sleep 2
  done
  [ "$READY" = "1" ] && break
  echo "[重试] 第${attempt}次启动未就绪, 清理后重试..."
  cleanup_sim
  sleep 2
  ros2 launch TITA_DRL tita_drl.launch.py > /tmp/drl_run.log 2>&1 &
  sleep 2
  ros2 launch sim_bringup sim_bringup.launch.py > /tmp/sim_run.log 2>&1 &
  sleep 6
done
if [ "$READY" != "1" ]; then
  echo "[失败] 仿真2次(各60s)均未就绪, 终止本组实验"
  cleanup_sim
  exit 1
fi

# 5. 采集
echo "[采集] ${DUR}s ..."
sleep "$DUR"

# 6. 停止并收集 CSV (只收本次新生成的文件)
cleanup_sim
CSV=$(find /mnt/dev/tita_ws -maxdepth 1 -name "drl_actions_*.csv" -newer "$MARK" | sort | tail -1)
rm -f "$MARK"
if [ -z "$CSV" ] || [ "$(wc -l < "$CSV")" -lt 100 ]; then
  echo "[失败] 未收集到有效 CSV: ${CSV:-无}"
  exit 1
fi
cp -a "$CSV" "$DIR/data/${TAG}_kd${KD}.csv"
echo "[完成] CSV -> $DIR/data/${TAG}_kd${KD}.csv  ($(wc -l < "$CSV") 行)"
