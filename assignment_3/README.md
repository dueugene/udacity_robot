## to run
in a terminal:
```bash
catkin_make
source devel/setup.sh
roslaunch my_robot world.launch
```

in a new terminal:
```bash
catkin_make
source devel/setup.sh
roslaunch ball_chaser ball_chaser.launch
```

in gazebo, move around the white ball and watch the robot chase it
optional: in rviz, subscribe to the camera topic to see what the robot camera sees
