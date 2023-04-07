#!/bin/sh
xterm  -e  " source devel/setup.bash; roslaunch my_robot home_service_world.launch" &
sleep 5
xterm  -e  " source devel/setup.bash; roslaunch my_robot amcl_demo.launch" &
sleep 5
xterm  -e  " source devel/setup.bash; roslaunch my_robot home_service_view.launch"