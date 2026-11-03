#include "keyboard_controller/keyboard_controller.hpp"

KeyboardControllerNode::KeyboardControllerNode(const rclcpp::NodeOptions & options) : Node("keyboard_controller", options)
{
  this->cmd_vel_publisher_ =
    this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
  this->posestamped_publisher_ =
    this->create_publisher<geometry_msgs::msg::PoseStamped>(tita_topic::manager_pose_command, 10);
  this->fsm_goal_publisher_ =
    this->create_publisher<std_msgs::msg::String>(tita_topic::manager_key_command, 10);
  realtime_cmd_vel_publisher_ =
    std::make_shared<realtime_tools::RealtimePublisher<geometry_msgs::msg::Twist>>(
      cmd_vel_publisher_);
  realtime_posestamped_publisher_ =
    std::make_shared<realtime_tools::RealtimePublisher<geometry_msgs::msg::PoseStamped>>(
      posestamped_publisher_);
  realtime_fsm_goal_publisher_ =
    std::make_shared<realtime_tools::RealtimePublisher<std_msgs::msg::String>>(fsm_goal_publisher_);

  // DRL mode status subscription
  mode_status_sub_ = this->create_subscription<std_msgs::msg::String>(
      "/tita/drl/mode_status", 10,
      std::bind(&KeyboardControllerNode::modeStatusCallback, this, std::placeholders::_1));

  // DRL mode override publisher
  mode_override_pub_ = this->create_publisher<std_msgs::msg::Int8>(
      "/tita/drl/mode_override", 10);

  this->timer_ =
    this->create_wall_timer(10ms, std::bind(&KeyboardControllerNode::PubCmdVelCallBack, this));
  std::shared_ptr<std::thread> read_key_thread =
    std::make_shared<std::thread>(&KeyboardControllerNode::ReadKeyThread, this);
  (*read_key_thread).detach();
  pose_.pose.position.z = MIN_HEIGHT;
  for (size_t i = 0; i < 3; i++) {
    rpy_[i] = 0.0;
  }
  fsm_goal_.data = "idle";
  print_interface();
}

void KeyboardControllerNode::print_interface()
{
  system("clear");
  std::cout << R"(
  -------------------------------------------------------
                    State Machines
  0: passive 1: transform up 2 balance 3: transform down 4: rl
  -------------------------------------------------------
  Moving Around    Postion Control    Orientation Control
        w                 u                 u i o
      a s d             j   l              j k l
        x                 ,                  ,
  -------------------------------------------------------
             Speed Scale        Pose Scale
            + : increase       * : increase
            - : decrease       / : decrease
  -------------------------------------------------------
  m: toggle DRL mode (auto/loco/recovery)   r: RESET at origin
  -------------------------------------------------------
  )";

  std::cout << std::fixed << std::setprecision(2);
  std::cout << std::setw(32) << "state machine now: " << std::setw(6) << GREEN << fsm_goal_.data
            << RESET << std::endl;

  // DRL mode display
  const char* mc = (drl_mode_ == "recovery") ? RED : CYAN;
  const char* ov = mode_override_val_ < 0 ? "auto" : (mode_override_val_ == 0 ? "loco" : "recov");
  std::cout << std::setw(32) << "DRL mode: " << std::setw(12) << mc << drl_mode_ << RESET
            << "  override: " << ov << std::endl;

  std::cout << std::setw(20) << "  speed scale:" << std::setw(6) << RED << speed_scale_ << RESET
            << "  pose scale:" << std::setw(6) << RED << pose_scale_ << RESET << std::endl
            << std::endl;
  std::cout << "  x vel:" << std::setw(6) << MAGENTA << twist_.linear.x << RESET
            << "  y vel:" << std::setw(6) << MAGENTA << twist_.linear.y << RESET
            << "  z vel:" << std::setw(6) << MAGENTA << twist_.angular.z << RESET
            << "  z height:" << std::setw(6) << MAGENTA << twist_.linear.z << RESET << std::endl;

  std::cout << "  pitch:" << std::setw(6) << CYAN << rpy_[0] << RESET << "   roll:" << std::setw(6)
            << CYAN << rpy_[1] << RESET << "   yaw: " << std::setw(6) << CYAN << rpy_[2] << RESET
            << std::endl;

  std::cout << "  y:    " << std::setw(6) << YELLOW << pose_.pose.position.y << RESET
            << "   z:   " << std::setw(6) << YELLOW << pose_.pose.position.z << RESET << std::endl;
}

int KeyboardControllerNode::get_key()
{
  int ch;
  struct termios oldt, newt;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  newt.c_iflag |= IGNBRK;
  newt.c_iflag &= ~(INLCR | ICRNL | IXON | IXOFF);
  newt.c_lflag &= ~(ICANON | ECHO | ECHOK | ECHOE | ECHONL | ISIG | IEXTEN);
  newt.c_cc[VMIN] = 1;
  newt.c_cc[VTIME] = 0;
  tcsetattr(fileno(stdin), TCSANOW, &newt);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return ch;
}

void KeyboardControllerNode::ReadKeyThread()
{
  while (rclcpp::ok()) {
    switch (get_key()) {
      case '0': fsm_goal_.data = "idle"; break;
      case '1': fsm_goal_.data = "transform_up"; break;
      case '2': fsm_goal_.data = "rl"; break;
      case '3': fsm_goal_.data = "transform_down"; break;
      case 'w': twist_.linear.x += STEP_ACCL_X * speed_scale_; break;
      case 'x': twist_.linear.x -= STEP_ACCL_X * speed_scale_; break;
      case 'a': twist_.angular.z += STEP_ACCL_W * speed_scale_; break;
      case 'd': twist_.angular.z -= STEP_ACCL_W * speed_scale_; break;
      case 'c': twist_.linear.z += STEP_ACCL_H * speed_scale_; break;
      case 'v': twist_.linear.z -= STEP_ACCL_H * speed_scale_; break;
      case 's':
        twist_.linear.x = 0.0; twist_.linear.y = 0.0;
        twist_.angular.z = 0.0; twist_.linear.z = 0.1;
        break;
      case 'm':
        mode_override_val_ = (mode_override_val_ + 2) % 4 - 1;
        {
          auto msg = std_msgs::msg::Int8();
          msg.data = mode_override_val_;
          mode_override_pub_->publish(msg);
        }
        break;
      case 'r':
        resetRobot();
        break;
      case '+': speed_scale_ += 0.1; break;
      case '-': speed_scale_ -= 0.1; break;
      case '*': pose_scale_ += 0.1; break;
      case '/': pose_scale_ -= 0.1; break;
      case '\033':
        if (get_key() == '[') {
          switch (get_key()) {
            case 'A': pose_.pose.position.z += STEP_HEIGHT * pose_scale_; break;
            case 'B': pose_.pose.position.z -= STEP_HEIGHT * pose_scale_; break;
            case 'C': twist_.linear.y -= STEP_ACCL_Y * speed_scale_; break;
            case 'D': twist_.linear.y += STEP_ACCL_Y * speed_scale_; break;
            default: break;
          }
        }
        break;
      case 'i': rpy_[1] += STEP_ORIENTATION * pose_scale_; break;
      case ',': rpy_[1] -= STEP_ORIENTATION * pose_scale_; break;
      case 'j': rpy_[0] -= STEP_ORIENTATION * pose_scale_; break;
      case 'l': rpy_[0] += STEP_ORIENTATION * pose_scale_; break;
      case 'u': rpy_[2] -= STEP_ORIENTATION * pose_scale_; break;
      case 'o': rpy_[2] += STEP_ORIENTATION * pose_scale_; break;
      case 'k':
        pose_.pose.position.y = 0;
        rpy_[0] = rpy_[1] = rpy_[2] = 0;
        pose_.pose.position.z = MIN_HEIGHT;
        twist_.linear.x = 0.0; twist_.linear.y = 0.0;
        twist_.linear.z = 0.1; twist_.angular.z = 0.0;
        break;
      case '\x03':
        std::cout << "KEYBOARD WILL BE BACK..." << std::endl;
        rclcpp::shutdown();
        break;
      default: break;
    }
    speed_scale_ = clamp(speed_scale_, 0.1, 4.0);
    pose_scale_ = clamp(pose_scale_, 0.1, 4.0);
    twist_.linear.x = clamp(twist_.linear.x, -MAX_VEL_X, MAX_VEL_X);
    twist_.linear.y = clamp(twist_.linear.y, -MAX_VEL_Y, MAX_VEL_Y);
    twist_.angular.z = clamp(twist_.angular.z, -MAX_VEL_W, MAX_VEL_W);
    twist_.linear.z = clamp(twist_.linear.z, MIN_HEIGHT, MAX_HEIGHT);
    for (size_t i = 0; i < 3; i++) rpy_[i] = clamp(rpy_[i], -MAX_ORIENTATION, MAX_ORIENTATION);
    tf2::Quaternion q;
    q.setRPY(rpy_[0], rpy_[1], rpy_[2]);
    pose_.pose.orientation.x = q.x(); pose_.pose.orientation.y = q.y();
    pose_.pose.orientation.z = q.z(); pose_.pose.orientation.w = q.w();
    pose_.pose.position.y = clamp(pose_.pose.position.y, -MAX_POSITION, MAX_POSITION);
    pose_.pose.position.z = clamp(pose_.pose.position.z, MIN_HEIGHT, MAX_HEIGHT);
    print_interface();
  }
}

void KeyboardControllerNode::modeStatusCallback(const std_msgs::msg::String::SharedPtr msg)
{
  drl_mode_ = msg->data;
}

void KeyboardControllerNode::resetRobot()
{
  bool is_recovery = false;
  if (mode_override_val_ >= 0)
    is_recovery = (mode_override_val_ == 1);
  else
    is_recovery = (drl_mode_ == "recovery");

  std::cout << "\n========================================" << std::endl;
  std::cout << "  RESET: " << (is_recovery ? "RECOVERY (base DOWN)" : "LOCOMOTION (base UP)") << std::endl;
  std::cout << "========================================" << std::endl;

  // Run delete+spawn in a separate thread to avoid blocking keyboard input
  std::thread([is_recovery]() {
    // Step 1: Delete existing robot
    std::cout << "  [1/2] Deleting robot..." << std::endl;
    int ret = system(
        "ros2 service call /gazebo/delete_entity gazebo_msgs/srv/DeleteEntity "
        "'{name: tita}' 2>&1");
    std::cout << "  Delete returned: " << ret << std::endl;

    // Wait for Gazebo to process deletion
    sleep(1);

    // Step 2: Respawn with correct orientation
    std::cout << "  [2/2] Respawning robot at origin..." << std::endl;
    std::string cmd;
    if (is_recovery) {
      // Base facing DOWN: roll = 180 degrees (PI radians)
      cmd = "ros2 run gazebo_ros spawn_entity.py "
            "-topic /tita/robot_description "
            "-entity tita "
            "-x 0.0 -y 0.0 -z 0.15 "
            "-R 3.14159 -P 0.0 -Y 0.0 "
            "> /tmp/spawn_result.log 2>&1";
    } else {
      // Base facing UP: normal orientation
      cmd = "ros2 run gazebo_ros spawn_entity.py "
            "-topic /tita/robot_description "
            "-entity tita "
            "-x 0.0 -y 0.0 -z 0.15 "
            "-R 0.0 -P 0.0 -Y 0.0 "
            "> /tmp/spawn_result.log 2>&1";
    }
    int ret2 = system(cmd.c_str());
    std::cout << "  Spawn returned: " << ret2 << std::endl;
    std::cout << "  [DONE] Robot reset complete." << std::endl;
    std::cout << "========================================" << std::endl;
  }).detach();
}

void KeyboardControllerNode::PubCmdVelCallBack()
{
  if (realtime_cmd_vel_publisher_ && realtime_cmd_vel_publisher_->trylock()) {
    realtime_cmd_vel_publisher_->msg_ = twist_;
    realtime_cmd_vel_publisher_->unlockAndPublish();
  }
  if (realtime_posestamped_publisher_ && realtime_posestamped_publisher_->trylock()) {
    realtime_posestamped_publisher_->msg_ = pose_;
    realtime_posestamped_publisher_->unlockAndPublish();
  }
  if (realtime_fsm_goal_publisher_ && realtime_fsm_goal_publisher_->trylock()) {
    realtime_fsm_goal_publisher_->msg_ = fsm_goal_;
    realtime_fsm_goal_publisher_->unlockAndPublish();
  }
}
