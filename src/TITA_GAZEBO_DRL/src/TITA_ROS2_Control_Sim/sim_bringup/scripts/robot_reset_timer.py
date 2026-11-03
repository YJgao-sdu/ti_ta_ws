#!/usr/bin/env python3
# 定时重置节点: 每 reset_period 秒将机器人重置回初始位置, 姿态(四元数)随机生成
# 通过 /set_entity_state 服务实现 (由 world 文件中的 gazebo_ros_state 插件提供),
# 不删除/重建模型, 控制器与传感器保持运行
import math
import random

import rclpy
from rclpy.node import Node
from gazebo_msgs.msg import EntityState
from gazebo_msgs.srv import SetEntityState
from geometry_msgs.msg import Point, Pose, Quaternion, Twist


class RobotResetTimer(Node):
    def __init__(self):
        super().__init__("robot_reset_timer")

        # 参数: 模型名 / 重置周期 / 初始位置 / 姿态随机模式
        self.declare_parameter("model_name", "tita")
        self.declare_parameter("reset_period", 10.0)
        self.declare_parameter("init_x", 0.0)
        self.declare_parameter("init_y", 0.0)
        self.declare_parameter("init_z", 0.15)
        # full: 任意三维姿态; yaw: 仅偏航角随机(保持直立)
        self.declare_parameter("random_mode", "full")

        self.model_name_ = self.get_parameter("model_name").value
        self.reset_period_ = self.get_parameter("reset_period").value
        self.init_x_ = self.get_parameter("init_x").value
        self.init_y_ = self.get_parameter("init_y").value
        self.init_z_ = self.get_parameter("init_z").value
        self.random_mode_ = self.get_parameter("random_mode").value

        # 连接 Gazebo 的 set_entity_state 服务 (根命名空间, 由 world 中 gazebo_ros_state 插件提供)
        self.client_ = self.create_client(SetEntityState, "/set_entity_state")
        while not self.client_.wait_for_service(timeout_sec=1.0):
            self.get_logger().warn("等待 /set_entity_state 服务 ... "
                                   "(请确认 world 文件已加载 gazebo_ros_state 插件)")

        # 定时器: 每 reset_period 秒重置一次
        self.timer_ = self.create_timer(self.reset_period_, self.reset_callback)
        self.get_logger().info(
            "机器人定时重置已启动: 模型 '%s', 每 %.1f 秒重置到 (%.2f, %.2f, %.2f), 姿态随机模式 '%s'"
            % (self.model_name_, self.reset_period_,
               self.init_x_, self.init_y_, self.init_z_, self.random_mode_))

    def random_quaternion_full(self):
        """均匀随机三维姿态 (单位四元数, Shoemake 方法)"""
        u1, u2, u3 = random.random(), random.random(), random.random()
        q = Quaternion()
        q.x = math.sqrt(1.0 - u1) * math.sin(2.0 * math.pi * u2)
        q.y = math.sqrt(1.0 - u1) * math.cos(2.0 * math.pi * u2)
        q.z = math.sqrt(u1) * math.sin(2.0 * math.pi * u3)
        q.w = math.sqrt(u1) * math.cos(2.0 * math.pi * u3)
        return q

    def random_quaternion_yaw(self):
        """仅随机偏航角 (绕Z轴), 保持直立"""
        yaw = random.uniform(-math.pi, math.pi)
        q = Quaternion()
        q.x = 0.0
        q.y = 0.0
        q.z = math.sin(yaw / 2.0)
        q.w = math.cos(yaw / 2.0)
        return q

    def reset_callback(self):
        state = EntityState()
        state.name = self.model_name_
        state.reference_frame = "world"
        state.pose = Pose()
        state.pose.position = Point(x=self.init_x_, y=self.init_y_, z=self.init_z_)
        if self.random_mode_ == "yaw":
            state.pose.orientation = self.random_quaternion_yaw()
        else:
            state.pose.orientation = self.random_quaternion_full()
        state.twist = Twist()  # 线速度/角速度清零

        req = SetEntityState.Request()
        req.state = state
        future = self.client_.call_async(req)
        future.add_done_callback(self.reset_done_cb)

    def reset_done_cb(self, future):
        try:
            resp = future.result()
            if resp.success:
                self.get_logger().info("重置成功 (随机四元数已生效)")
            else:
                self.get_logger().warn("重置失败: 模型 '%s' 可能不存在" % self.model_name_)
        except Exception as e:  # noqa
            self.get_logger().error("重置服务调用异常: %s" % str(e))


def main(args=None):
    rclpy.init(args=args)
    node = RobotResetTimer()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
