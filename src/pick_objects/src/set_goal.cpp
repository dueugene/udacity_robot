#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <move_base_msgs/MoveBaseGoal.h>
#include "std_msgs/Bool.h"
#include <actionlib/client/simple_action_client.h>
 
// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "simple_navigation_goals");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<std_msgs::Bool>("/simple_navigation_goals/show", 1);
  ros::Publisher pose_pub = n.advertise<move_base_msgs::MoveBaseGoal>("/simple_navigation_goals/goal", 1);
  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

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
  
  std_msgs::Bool show;
  show.data = true;
   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending pickup location [%f. %f]", goal.target_pose.pose.position.x, goal.target_pose.pose.position.y);
  pub.publish(show);
  pose_pub.publish(goal);
  ac.sendGoal(goal);
  
  // Wait an infinite time for the results
  ac.waitForResult();
  
  // Check if the robot reached its goal{
  if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
    ROS_INFO("Hooray, the base moved to pickup location");
    show.data = false;
    pub.publish(show);
	} else {
    ROS_INFO("The base failed to move forward 1 meter for some reason");
  }
  
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
  ac.sendGoal(goal);
  
  ac.waitForResult();
  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
    ROS_INFO("Hooray, the base moved to dropoff location");
    show.data = true;
    pub.publish(show);
  } else {
    ROS_INFO("The base failed to move forward 1 meter for some reason");
  }
  ros::Duration(15.0).sleep();
  ros::spin();
  return 0;
}
