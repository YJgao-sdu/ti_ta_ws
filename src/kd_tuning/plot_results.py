#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""kd 整定对比图: 不同 kd 的轮速/机身信号统一时间尺度, 标注重置时刻。
用法: python3 plot_results.py <csv1> <csv2> ... -o out.png"""
import argparse
import sys

import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

SURFACE, INK, MUTED, GRID = "#fcfcfb", "#0b0b0b", "#898781", "#e1e0d9"
SERIES = ["#2a78d6", "#1baf7a", "#eda100", "#008300", "#4a3aa7", "#e34948"]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("csvs", nargs="+")
    ap.add_argument("-o", "--out", default="comparison.png")
    a = ap.parse_args()
    fig, axes = plt.subplots(2, 1, figsize=(14, 7), sharex=True)
    fig.patch.set_facecolor(SURFACE)
    for ax in axes:
        ax.set_facecolor(SURFACE)
        ax.grid(True, color=GRID, linewidth=0.8)
        ax.tick_params(colors=MUTED, labelsize=8)
        for sp in ("top", "right"):
            ax.spines[sp].set_visible(False)
    for i, path in enumerate(a.csvs):
        with open(path, encoding="utf-8") as f:
            hdr = f.readline().strip().split(",")
        t = np.loadtxt(path, delimiter=",", skiprows=1, usecols=0)
        y = np.loadtxt(path, delimiter=",", skiprows=1,
                       usecols=range(1, len(hdr)))
        tag = path.split("/")[-1].replace(".csv", "")
        c = SERIES[i % len(SERIES)]
        axes[0].plot(t, y[:, 4], color=c, linewidth=1.2, label=tag + " left")
        axes[1].plot(t, np.hypot(y[:, 8], y[:, 9]), color=c, linewidth=1.2, label=tag)
    axes[0].set_ylabel("left wheel vel (rad/s)", color=MUTED, fontsize=10)
    axes[0].legend(fontsize=7, frameon=False, loc="upper right")
    axes[1].set_ylabel("|gravity_proj_xy|", color=MUTED, fontsize=10)
    axes[1].legend(fontsize=7, frameon=False, loc="upper right")
    axes[1].set_xlabel("time (s)", color=MUTED, fontsize=10)
    fig.suptitle("kd tuning comparison", color=INK, fontsize=13, fontweight="bold")
    fig.tight_layout(rect=(0, 0, 1, 0.95))
    fig.savefig(a.out, dpi=150, facecolor=SURFACE)
    print("saved", a.out)


if __name__ == "__main__":
    sys.exit(main())
