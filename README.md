
# Assignment 3
## to run
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

## screenshots
found in screenshots/


# Assignment 4
## to run
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

