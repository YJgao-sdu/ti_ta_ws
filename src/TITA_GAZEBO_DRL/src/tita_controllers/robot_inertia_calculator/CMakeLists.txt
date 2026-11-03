cmake_minimum_required(VERSION 3.8)
project(robot_inertia_calculator)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -O3")

list(APPEND CMAKE_PREFIX_PATH "/opt/openrobots")#

# find dependencies
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

find_package(pinocchio REQUIRED) #

include_directories(include)

ament_auto_add_library(${PROJECT_NAME}_lib SHARED
    src/robot_inertia_calculator.cpp
)

target_link_libraries(${PROJECT_NAME}_lib
    pinocchio::pinocchio
) #

ament_auto_add_executable(${PROJECT_NAME}_node
    src/main.cpp
)

set_target_properties(${PROJECT_NAME}_node PROPERTIES
    INSTALL_RPATH "/opt/openrobots/lib"
    BUILD_WITH_INSTALL_RPATH TRUE
) #

install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})
install(DIRECTORY config DESTINATION share/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_auto_package()

