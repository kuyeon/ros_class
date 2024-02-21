/* 
 * rosserial Ultrasound Example
 * 
 * This example is for the Maxbotix Ultrasound rangers.
 */

#include <ros.h>
#include <ros/time.h>
#include <sensor_msgs/Range.h>

ros::NodeHandle  nh;

sensor_msgs::Range range_msg;
ros::Publisher pub_range( "/ultrasound", &range_msg);

// defines pins numbers
const int trigPin = 9;
const int echoPin = 8;

char frameid[] = "/ultrasound";

float getRange_Ultrasound(){
  // defines variables
  long duration;
  float range;
  
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  range= duration*0.00034/2;
  
  return range;
}

void setup()
{
  nh.initNode();
  nh.advertise(pub_range);
  
  range_msg.radiation_type = sensor_msgs::Range::ULTRASOUND;
  range_msg.header.frame_id =  frameid;
  range_msg.field_of_view = 0.26;  // 
  range_msg.min_range = 0.02;
  range_msg.max_range = 5.0;
  
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
}


long range_time;

void loop()
{
  
  //publish the adc value every 50 milliseconds
  //since it takes that long for the sensor to stablize
  if ( millis() >= range_time ){

    range_msg.range = getRange_Ultrasound();
    range_msg.header.stamp = nh.now();
    pub_range.publish(&range_msg);
    range_time =  millis() + 1000;
  }
  
  nh.spinOnce();
}
