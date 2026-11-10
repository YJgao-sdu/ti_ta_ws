#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""kd_vel 整定分析: 按重置周期分段, 识别恢复完成/稳定站立阶段, 计算零速收敛指标。
用法: python3 analyze_csv.py <csv> [--eps 0.1] [--th 0.5] [--stand 0.15]
只读 CSV, 不修改任何文件。"""
import argparse
import json
import sys

import numpy as np


def load(path):
    with open(path, encoding="utf-8") as f:
        header = f.readline().strip().split(",")
    names = header[1:]
    t = np.loadtxt(path, delimiter=",", skiprows=1, usecols=0)
    y = np.loadtxt(path, delimiter=",", skiprows=1,
                   usecols=range(1, len(header)))
    return t, y, names


def detect_resets(t, gx, gy, dt):
    """检测重置时刻: 相邻采样重力投影突跳 (重新放置+随机四元数)。
    返回 (重置时间列表, 检测方法说明)。"""
    d = np.abs(np.diff(gx)) + np.abs(np.diff(gy))
    idx = np.where(d > 0.5)[0]
    times = [t[i + 1] for i in idx if i + 1 < len(t)]
    # 合并同一重置附近的多次触发 (2s 窗口)
    merged = []
    for tt in times:
        if not merged or tt - merged[-1] > 2.0:
            merged.append(tt)
        else:
            merged[-1] = tt
    method = "重力投影突跳检测 (|dgx|+|dgy|>0.5/采样)" if merged else "未检出突跳, 回退固定10s网格"
    if not merged:
        merged = list(np.arange(10.0, t[-1] - 5.0, 10.0))
    return merged, method


def standing_mask(gx, gy, thresh):
    return np.hypot(gx, gy) < thresh


def analyze(path, eps, th, stand):
    t, y, names = load(path)
    assert names[4] == "left_wheel_vel" and names[5] == "right_wheel_vel", \
        "CSV 缺少轮速列: " + ",".join(names)
    lwv, rwv = y[:, 4], y[:, 5]
    gx, gy = y[:, 8], y[:, 9]
    angx, angy = y[:, 6], y[:, 7]
    fs = 1.0 / float(np.median(np.diff(t)))
    dt = float(np.median(np.diff(t)))

    resets, method = detect_resets(t, gx, gy, dt)
    resets = [r for r in resets if r > t[0] + 2.0]
    bounds = [t[0]] + resets + [t[-1]]
    cycles = []
    for c in range(len(bounds) - 1):
        m = (t >= bounds[c]) & (t < bounds[c + 1])
        if m.sum() < fs * 3:      # 不足3秒的残段跳过
            continue
        sm = standing_mask(gx[m], gy[m], stand)
        # 恢复完成: 站立条件连续保持 >= th 秒的起点 (其后的持续段为稳定站立)
        n_th = int(th * fs)
        first_stable = None
        run = 0
        for i in range(m.sum()):
            if sm[i]:
                run += 1
            else:
                run = 0
            if run >= n_th:
                first_stable = np.where(m)[0][i - n_th + 1]
                break
        if first_stable is None:
            cycles.append({"cycle": c, "recovered": False})
            continue
        st = m & (t >= t[first_stable])
        # 零速收敛: 双轮 |v|<eps 连续保持 th 秒
        zero = (np.abs(lwv) < eps) & (np.abs(rwv) < eps)
        n_th2 = int(th * fs)
        settle_t = None
        run = 0
        for i in range(m.sum()):
            ti = np.where(m)[0][i]
            if ti < first_stable:
                continue
            if zero[ti]:
                run += 1
            else:
                run = 0
            if run >= n_th2:
                settle_t = t[ti - n_th2 + 1]
                break
        sign_sw = 0
        prev_s = 0
        for i in np.where(st)[0]:
            for v in (lwv[i], rwv[i]):
                s = 1 if v > eps else (-1 if v < -eps else 0)
                if prev_s != 0 and s != 0 and s != prev_s:
                    sign_sw += 1
                if s != 0:
                    prev_s = s
        lws, rws = lwv[st], rwv[st]
        cycles.append({
            "cycle": c, "recovered": True,
            "t_reset": round(float(bounds[c]), 2),
            "t_recovery": round(float(t[first_stable]), 2),
            "t_settle": round(float(settle_t), 2) if settle_t is not None else None,
            "T_settle": round(float(settle_t - t[first_stable]), 3) if settle_t is not None else None,
            "hold_time": round(float(t[-1] - t[first_stable]), 2),
            "lw_rms": float(np.sqrt(np.mean(lws ** 2))), "rw_rms": float(np.sqrt(np.mean(rws ** 2))),
            "lw_pp": float(np.max(lws) - np.min(lws)), "rw_pp": float(np.max(rws) - np.min(rws)),
            "sign_switches": sign_sw,
            "angx_rms": float(np.sqrt(np.mean(angx[st] ** 2))),
            "angy_rms": float(np.sqrt(np.mean(angy[st] ** 2))),
            "gx_std": float(np.std(gx[st])), "gy_std": float(np.std(gy[st])),
        })

    rec = [c for c in cycles if c["recovered"] and c.get("t_reset", 0) >= 2.0]
    settled = [c for c in rec if c["T_settle"] is not None]
    summary = {
        "file": path, "fs": round(fs, 1), "n_cycles": len(cycles),
        "recovery_rate": round(len(rec) / max(len(cycles), 1), 3),
        "settle_rate": round(len(settled) / max(len(rec), 1), 3),
        "reset_method": method,
        "T_settle_mean": round(float(np.mean([c["T_settle"] for c in settled])), 3) if settled else None,
        "lw_rms_mean": round(float(np.mean([c["lw_rms"] for c in rec])), 4),
        "rw_rms_mean": round(float(np.mean([c["rw_rms"] for c in rec])), 4),
        "sign_switches_mean": round(float(np.mean([c["sign_switches"] for c in rec])), 1),
        "angx_rms_mean": round(float(np.mean([c["angx_rms"] for c in rec])), 4),
        "angy_rms_mean": round(float(np.mean([c["angy_rms"] for c in rec])), 4),
        "gx_std_mean": round(float(np.mean([c["gx_std"] for c in rec])), 4),
        "gy_std_mean": round(float(np.mean([c["gy_std"] for c in rec])), 4),
    }
    return cycles, summary


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("csv")
    ap.add_argument("--eps", type=float, default=0.1, help="零速容差 rad/s")
    ap.add_argument("--th", type=float, default=0.5, help="连续保持窗口 s")
    ap.add_argument("--stand", type=float, default=0.15, help="站立判据 hypot(gx,gy) 阈值")
    ap.add_argument("--json", action="store_true")
    a = ap.parse_args()
    cycles, s = analyze(a.csv, a.eps, a.th, a.stand)
    if a.json:
        print(json.dumps({"summary": s, "cycles": cycles}, ensure_ascii=False, indent=1))
        return
    print(f"文件: {s['file']}  采样: {s['fs']:.1f}Hz  周期数: {s['n_cycles']}  "
          f"恢复成功率: {s['recovery_rate']:.0%}  零速收敛率: {s['settle_rate']:.0%}")
    print(f"重置检测: {s['reset_method']}")
    print(f"{'周期':>4} {'t_reset':>8} {'t_recover':>9} {'T_settle':>8} {'hold':>6} "
          f"{'左RMS':>8} {'右RMS':>8} {'左pp':>7} {'右pp':>7} {'切号':>4} "
          f"{'angxRMS':>8} {'angyRMS':>8} {'gx_std':>7} {'gy_std':>7}")
    for c in cycles:
        if not c["recovered"]:
            print(f"{c['cycle']:>4}  未恢复")
            continue
        print(f"{c['cycle']:>4} {c['t_reset']:>8.2f} {c['t_recovery']:>9.2f} "
              f"{c['T_settle'] if c['T_settle'] is not None else '无':>8} {c['hold_time']:>6.2f} "
              f"{c['lw_rms']:>8.4f} {c['rw_rms']:>8.4f} {c['lw_pp']:>7.3f} {c['rw_pp']:>7.3f} "
              f"{c['sign_switches']:>4} {c['angx_rms']:>8.4f} {c['angy_rms']:>8.4f} "
              f"{c['gx_std']:>7.4f} {c['gy_std']:>7.4f}")
    print(f"\n汇总: 平均收敛时间 {s['T_settle_mean']}s | 左轮RMS {s['lw_rms_mean']} 右轮RMS {s['rw_rms_mean']} "
          f"| 平均正负切换 {s['sign_switches_mean']} | 机身角速度RMS x={s['angx_rms_mean']} y={s['angy_rms_mean']} "
          f"| 重力投影std x={s['gx_std_mean']} y={s['gy_std_mean']}")


if __name__ == "__main__":
    sys.exit(main())
