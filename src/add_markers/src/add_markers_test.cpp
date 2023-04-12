#include <ros/ros.h>
#include <move_base_msgs/MoveBaseGoal.h>
#include "std_msgs/Bool.h"
 

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "send_navigation_goals");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<std_msgs::Bool>("/simple_navigation_goals/show", 1);
  ros::Publisher pose_pub = n.advertise<move_base_msgs::MoveBaseGoal>("/simple_navigation_goals/goal", 1);


  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  
  // Define a position and orientation for the robot to reach
  double number_to_get;
  n.getParam("/pickup_x", number_to_get);
  goal.target_pose.pose.position.x = number_to_get;
  n.getParam("/pickup_y", number_to_get);
  goal.target_pose.pose.position.y = number_to_get;
  n.getParam("/pickup_w", number_to_get);
  goal.target_pose.pose.orientation.w = number_to_get;
  
  ros::Duration(1.0).sleep();
  std_msgs::Bool show;
  show.data = true;
   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending pickup location [%f. %f]", goal.target_pose.pose.position.x, goal.target_pose.pose.position.y);
  pose_pub.publish(goal);
  pub.publish(show);
  ros::Duration(5.0).sleep();
  
  show.data = false;
  pub.publish(show);
  ros::Duration(5.0).sleep();
  
  goal.target_pose.header.stamp = ros::Time::now();
   // Define a position and orientation for the robot to reach
  n.getParam("/dropoff_x", number_to_get);
  goal.target_pose.pose.position.x = number_to_get;
  n.getParam("/dropoff_y", number_to_get);
  goal.target_pose.pose.position.y = number_to_get;
  n.getParam("/dropoff_w", number_to_get);
  goal.target_pose.pose.orientation.w = number_to_get;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending dropoff location [%f. %f]", goal.target_pose.pose.position.x, goal.target_pose.pose.position.y);
  pose_pub.publish(goal);
  show.data = true;
  pub.publish(show);
  ros::Duration(5.0).sleep();

  ros::spin();
  return 0;
}
