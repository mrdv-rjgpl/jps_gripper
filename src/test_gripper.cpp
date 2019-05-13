// For some parts of this code I used http://wiki.ros.org/joy/Tutorials/WritingTeleopNode

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/UInt16.h>
#include <iostream>

std_msgs::UInt16 servo_angle;
ros::Publisher Servo_pub;

int main(int argc, char** argv)
{
  ros::init(argc, argv, "joy_servo");
  ros::NodeHandle node;

  // defining the subscriber, publisher and the timer objects
  Servo_pub = node.advertise<std_msgs::UInt16>("/servo", 1);
  servo_angle.data = 0;

  for(int i = 0; i < 10; ++i)
  {
    servo_angle.data = 150 - servo_angle.data;
    ROS_INFO_STREAM("Publishing servo command with angle " << servo_angle.data << "...");
    Servo_pub.publish(servo_angle);
    ros::Duration(5.0).sleep();
  }

  ros::spin();

  return 0;
}
