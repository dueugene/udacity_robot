#!/bin/sh
xterm  -e  " source devel/setup.bash; roslaunch my_robot home_service_world.launch" &
sleep 5
xterm  -e  " source devel/setup.bash; roslaunch my_robot gmapping_demo.launch" &
sleep 5
xterm  -e  " source devel/setup.bash; roslaunch my_robot home_service_view.launch" &
sleep 5
xterm  -e  " source devel/setup.bash; rosrun teleop_twist_keyboard teleop_twist_keyboard.py"
