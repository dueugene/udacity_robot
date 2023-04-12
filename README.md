## Assignment 5
### to run
in a terminal, build project:
```bash
catkin_make
source devel/setup.sh
```
then run any of the following shell scripts
test slam:
```bash
./test_slam.sh
```
test navigation:
```bash
./test_navigation.sh
```
pick objects:
```bash
./pick_objects.sh
```
add markers:
```bash
./add_markers.sh
```
home service robot:
```bash
./home_service.sh
```
### package description
| package name | description |
|---|---|
| amcl | implements the Adaptive Monte-Carlo localization algorithm, it takes a pre-generated map  of the environment and uses a particle filter method to estimate the robot's pose within  the environment  |
| rtabmap | stands for Real-Time Appearance-Based Mapping, and is used in the test_slam.sh script to  demonstrate SLAM. It takes in odometry, laser scan, and camera information and uses the  Graph-SLAM algorithm to provide a map of the environment. The saved map is in a .db format  but it not used for localization. |
| navigation | is used to provide path planning for the robot to reach a navigation goal from its current pose. It achieves this by creating a costmap of the environment, using a global planner to  plan a path from start to goal, and a local planner to generate paths for the robot's current pose to the global path.  |
### to run

## Assignment 4
### to run
in a terminal:
```bash
catkin_make
source devel/setup.sh
roslaunch my_robot world2.launch
```

in a new terminal:
```bash
source devel/setup.sh
roslaunch my_robot localization.launch
```

in rviz, move nav_goal around and watch robot localize
optional: run teleop

in a new terminal:
```bash
source devel/setup.sh
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```

optional: can also run in mapping mode:
```bash
source devel/setup.sh
roslaunch my_robot mapping.launch
```

## Assignment 3
### to run
in a terminal:
```bash
catkin_make
source devel/setup.sh
roslaunch my_robot world.launch
```

in a new terminal:
```bash
source devel/setup.sh
roslaunch my_robot amcl.launch
```

in rviz, move nav_goal around and watch robot localize
optional: run teleop

in a new terminal:
```bash
source devel/setup.sh
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```

### screenshots
found in screenshots/

## Assignment 2
### to run
in a terminal:
```bash
catkin_make
source devel/setup.sh
roslaunch my_robot ball_world.launch
```

in a new terminal:
```bash
catkin_make
source devel/setup.sh
roslaunch ball_chaser ball_chaser.launch
```

in gazebo, move around the white ball and watch the robot chase it
optional: in rviz, subscribe to the camera topic to see what the robot camera sees



