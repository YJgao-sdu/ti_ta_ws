#!/usr/bin/env python3
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import pandas as pd
import numpy as np
import os
import time
from datetime import datetime

class JointDataPlotter:
    def __init__(self):
        self.csv_path = "/mnt/dev/tita_ws/src/力矩_位置_速度实时数据.csv" # /mnt/dev/tita_ws/src
        self.output_image_path = "/mnt/dev/tita_ws/src/力矩、位置与速度记录表.png"# /mnt/dev/tita_ws/src
        
        # 创建图形和子图
        self.fig = plt.figure(figsize=(14, 10))
        self.fig.suptitle('Joint Control Data - Real Time Monitor', fontsize=16)
        
        # 创建3个子图
        self.ax1 = plt.subplot(3, 1, 1)
        self.ax2 = plt.subplot(3, 1, 2)
        self.ax3 = plt.subplot(3, 1, 3)
        
        # 初始化线条
        self.lines1 = []
        self.lines2 = []
        self.lines3 = []
        
        # 关节名称
        self.joint_names = [f'Joint {i+1}' for i in range(8)]
        
        # 颜色映射
        self.colors = plt.cm.tab10(np.linspace(0, 1, 8))
        
        # 初始化图表
        self.init_plots()
        
    def init_plots(self):
        # 力矩子图
        self.ax1.set_title('Joint Effort Commands', fontsize=14)
        self.ax1.set_ylabel('Effort (Nm)', fontsize=12)
        self.ax1.grid(True, alpha=0.3)
        self.ax1.legend(loc='upper right')
        
        # 位置子图
        self.ax2.set_title('Joint Positions', fontsize=14)
        self.ax2.set_ylabel('Position (rad)', fontsize=12)
        self.ax2.grid(True, alpha=0.3)
        
        # 速度子图
        self.ax3.set_title('Joint Velocities', fontsize=14)
        self.ax3.set_xlabel('Time (s)', fontsize=12)
        self.ax3.set_ylabel('Velocity (rad/s)', fontsize=12)
        self.ax3.grid(True, alpha=0.3)
        
        plt.tight_layout()
        
    def update_plot(self, frame):
        """更新图表"""
        if not os.path.exists(self.csv_path):
            return self.lines1 + self.lines2 + self.lines3
        
        try:
            # 读取CSV数据
            df = pd.read_csv(self.csv_path)
            
            if len(df) == 0:
                return self.lines1 + self.lines2 + self.lines3
            
            time_data = df['Time(s)']
            
            # 清除旧线条
            self.ax1.clear()
            self.ax2.clear()
            self.ax3.clear()
            
            # 重新设置标题和标签
            self.ax1.set_title('Joint Effort Commands', fontsize=14)
            self.ax1.set_ylabel('Effort (Nm)', fontsize=12)
            self.ax1.grid(True, alpha=0.3)
            
            self.ax2.set_title('Joint Positions', fontsize=14)
            self.ax2.set_ylabel('Position (rad)', fontsize=12)
            self.ax2.grid(True, alpha=0.3)
            
            self.ax3.set_title('Joint Velocities', fontsize=14)
            self.ax3.set_xlabel('Time (s)', fontsize=12)
            self.ax3.set_ylabel('Velocity (rad/s)', fontsize=12)
            self.ax3.grid(True, alpha=0.3)
            
            # 绘制力矩数据
            for i in range(8):
                effort_col = f'Joint{i+1}_Effort(Nm)'
                if effort_col in df.columns:
                    self.ax1.plot(time_data, df[effort_col], 
                                 label=self.joint_names[i], 
                                 color=self.colors[i], 
                                 linewidth=1.5)
            
            # 绘制位置数据
            for i in range(8):
                pos_col = f'Joint{i+1}_Position(rad)'
                if pos_col in df.columns:
                    self.ax2.plot(time_data, df[pos_col], 
                                 label=self.joint_names[i], 
                                 color=self.colors[i], 
                                 linewidth=1.5)
            
            # 绘制速度数据
            for i in range(8):
                vel_col = f'Joint{i+1}_Velocity(rad/s)'
                if vel_col in df.columns:
                    self.ax3.plot(time_data, df[vel_col], 
                                 label=self.joint_names[i], 
                                 color=self.colors[i], 
                                 linewidth=1.5)
            
            # 添加图例（只添加到第一个子图避免重复）
            self.ax1.legend(loc='upper right', fontsize=8, ncol=2)
            
            # 自动调整坐标轴范围
            self.ax1.relim()
            self.ax1.autoscale_view()
            self.ax2.relim()
            self.ax2.autoscale_view()
            self.ax3.relim()
            self.ax3.autoscale_view()
            
        except Exception as e:
            print(f"Error updating plot: {e}")
        
        return self.lines1 + self.lines2 + self.lines3
    
    def save_final_plot(self):
        """保存最终图表"""
        if os.path.exists(self.csv_path):
            # 读取所有数据
            df = pd.read_csv(self.csv_path)
            
            if len(df) > 0:
                # 创建最终图表
                fig_final, (ax1_f, ax2_f, ax3_f) = plt.subplots(3, 1, figsize=(14, 10))
                fig_final.suptitle('Joint Control Data - Final Record', fontsize=16)
                
                time_data = df['Time(s)']
                
                # 绘制力矩
                ax1_f.set_title('Joint Effort Commands', fontsize=14)
                ax1_f.set_ylabel('Effort (Nm)', fontsize=12)
                ax1_f.grid(True, alpha=0.3)
                for i in range(8):
                    effort_col = f'Joint{i+1}_Effort(Nm)'
                    if effort_col in df.columns:
                        ax1_f.plot(time_data, df[effort_col], 
                                  label=f'Joint {i+1}', 
                                  linewidth=1.5)
                ax1_f.legend(loc='upper right', fontsize=8, ncol=2)
                
                # 绘制位置
                ax2_f.set_title('Joint Positions', fontsize=14)
                ax2_f.set_ylabel('Position (rad)', fontsize=12)
                ax2_f.grid(True, alpha=0.3)
                for i in range(8):
                    pos_col = f'Joint{i+1}_Position(rad)'
                    if pos_col in df.columns:
                        ax2_f.plot(time_data, df[pos_col], 
                                  label=f'Joint {i+1}', 
                                  linewidth=1.5)
                ax2_f.legend(loc='upper right', fontsize=8, ncol=2)
                
                # 绘制速度
                ax3_f.set_title('Joint Velocities', fontsize=14)
                ax3_f.set_xlabel('Time (s)', fontsize=12)
                ax3_f.set_ylabel('Velocity (rad/s)', fontsize=12)
                ax3_f.grid(True, alpha=0.3)
                for i in range(8):
                    vel_col = f'Joint{i+1}_Velocity(rad/s)'
                    if vel_col in df.columns:
                        ax3_f.plot(time_data, df[vel_col], 
                                  label=f'Joint {i+1}', 
                                  linewidth=1.5)
                ax3_f.legend(loc='upper right', fontsize=8, ncol=2)
                
                plt.tight_layout()
                plt.savefig(self.output_image_path, dpi=150, bbox_inches='tight')
                print(f"Final plot saved to: {self.output_image_path}")
                plt.close(fig_final)
                
                # 同时保存统计信息
                self.save_statistics(df)
    
    def save_statistics(self, df):
        """保存统计信息"""
        stats_path = "/mnt/dev/tita_ws/src/力矩_位置_速度统计信息.txt" # /mnt/dev/tita_ws/src
        with open(stats_path, 'w') as f:
            f.write("Joint Control Data Statistics\n")
            f.write("=" * 50 + "\n\n")
            f.write(f"Total time duration: {df['Time(s)'].iloc[-1] - df['Time(s)'].iloc[0]:.2f} seconds\n")
            f.write(f"Number of data points: {len(df)}\n\n")
            
            for i in range(8):
                f.write(f"\nJoint {i+1}:\n")
                f.write(f"  Effort - Mean: {df[f'Joint{i+1}_Effort(Nm)'].mean():.3f} Nm, "
                       f"Std: {df[f'Joint{i+1}_Effort(Nm)'].std():.3f} Nm\n")
                f.write(f"  Position - Mean: {df[f'Joint{i+1}_Position(rad)'].mean():.3f} rad, "
                       f"Std: {df[f'Joint{i+1}_Position(rad)'].std():.3f} rad\n")
                f.write(f"  Velocity - Mean: {df[f'Joint{i+1}_Velocity(rad/s)'].mean():.3f} rad/s, "
                       f"Std: {df[f'Joint{i+1}_Velocity(rad/s)'].std():.3f} rad/s\n")
        
        print(f"Statistics saved to: {stats_path}")
    
    def run(self):
        """运行动画"""
        # 创建动画
        ani = animation.FuncAnimation(
            self.fig, self.update_plot, interval=500, blit=False, cache_frame_data=False
        )
        
        # 显示图表
        plt.show(block=False)
        
        # 等待用户输入来保存最终图表
        input("Press Enter to save final plot and exit...")
        
        # 保存最终图表
        self.save_final_plot()
        
        plt.close(self.fig)

if __name__ == '__main__':
    plotter = JointDataPlotter()
    plotter.run()