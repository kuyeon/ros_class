/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

#include <ros.h>
#include <my_msgs/MyInfo.h>

ros::NodeHandle  nh;

my_msgs::MyInfo my_msg;
ros::Publisher my_info("my_info", &my_msg);

char name[8] = "geekble";
char nick_name[9] = "geekbley";
char mbti[5] = "geek";

void setup()
{
  nh.initNode();
  nh.advertise(my_info);
}

void loop()
{
  my_msg.name = name;
  my_msg.nick_name = nick_name;
  my_msg.mbti = mbti;
  my_info.publish( &my_msg );
  nh.spinOnce();
  delay(1000);
}
