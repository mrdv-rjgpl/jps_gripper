// For some parts of this code I used http://wiki.ros.org/joy/Tutorials/WritingTeleopNode

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/UInt16.h>
#include <iostream>


std_msgs::UInt16 servo_angle;
ros::Publisher Servo_pub;

void Sub_Callback(const sensor_msgs::Joy::ConstPtr &msg)
{


  // ROS_INFO("Callback 1000222222 triggered");

  int servo_status[2];
  servo_status[0] = msg->buttons[0];
  servo_status[1] = msg->buttons[1];
  //std::cout<<"JOY IS"<<kk<<std::endl;

   
      if(servo_status[0]==1){
      servo_angle.data = 150; 
      Servo_pub.publish(servo_angle);
      }

      if(servo_status[1]==1){
      servo_angle.data = 0; 
      Servo_pub.publish(servo_angle);
      }

}


int main(int argc, char **argv)
{

  ros::init(argc, argv, "joy_servo");
  ros::NodeHandle node;

// defining the subscriber, publisher and the timer objects
  Servo_pub = node.advertise<std_msgs::UInt16>("/servo", 1);
  ros::Subscriber Sub_joy = node.subscribe("/joy", 100, Sub_Callback);
  ros::spin();

  return 0;
}


