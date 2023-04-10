#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "std_msgs/Bool.h"
#include "move_base_msgs/MoveBaseActionGoal.h"

class MarkerVisualizer 
{
public:
  MarkerVisualizer() {
    //Topic you want to publish
    pub_ = n_.advertise<visualization_msgs::Marker>("visualization_marker", 1);

    //Topic you want to subscribe
    sub_ = n_.subscribe("/move_base/goal", 5, &MarkerVisualizer::goal_callback, this);
    sub2_ = n_.subscribe("/simple_navigation_goals/show", 5, &MarkerVisualizer::arrived_callback, this);
    show_ = false;
  }

  void arrived_callback(const std_msgs::Bool msg) {
    show_ = msg.data;
    ROS_INFO("I heard: [%d]", show_);
    add_marker(x_, y_, show_);
  }
  void goal_callback(const move_base_msgs::MoveBaseActionGoal& msg) {
    x_ = msg.goal.target_pose.pose.position.x;
    y_ = msg.goal.target_pose.pose.position.y;
    ROS_INFO("I heard: [%f, %f]", x_, y_);
    add_marker(x_, y_, show_);
  }

  void add_marker(float x, float y, int shape) {
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "basic_shapes";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = x;
    marker.pose.position.y = y;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.25;
    marker.scale.y = 0.25;
    marker.scale.z = 0.25;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 0.0;
    if (show_) {
      marker.color.a = 1.0;
    }

    marker.lifetime = ros::Duration();
    pub_.publish(marker);
  }
private:
  ros::NodeHandle n_;
  ros::Publisher pub_;
  ros::Subscriber sub_;
  ros::Subscriber sub2_;
  float x_;
  float y_;
  bool show_;
};

int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "basic_shapes");
  //Create an object of class SubscribeAndPublish that will take care of everything
  MarkerVisualizer my_object;

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;
  ros::spin();

  return 0;
}