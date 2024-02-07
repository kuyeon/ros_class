#!/usr/bin/env python
import rospy
from my_first_package.msg import MemberInfo

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + 'I heard %s', data)

def member_information_subscriber():
    rospy.init_node('member_information_subscriber', anonymous=False)

    rospy.Subscriber('member_info', MemberInfo, callback)
    rospy.spin()

if __name__ == '__main__':
    member_information_subscriber()
