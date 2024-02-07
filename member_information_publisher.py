#!/usr/bin/env python
import rospy
from my_first_package.msg import MemberInfo

def member_information_publisher():
    info = MemberInfo()
    pub = rospy.Publisher('member_info', MemberInfo, queue_size=10)
    rospy.init_node('member_information_publisher', anonymous=False)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        info.name = "park"
        info.email = "example@email.com"
        info.join_date = 1707332400
        rospy.loginfo(info)
        pub.publish(info)
        rate.sleep()

if __name__ == '__main__':
    try:
        member_information_publisher()
    except rospy.ROSInterruptException:
        pass

