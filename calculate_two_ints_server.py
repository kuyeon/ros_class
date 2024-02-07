#!/usr/bin/env python

from __future__ import print_function
import rospy
from my_first_package.srv import *


ADD = "add"
SUB = "sub"
MUL = "mul"
DIV = "div"

operator = ADD


def handle_calculation(req):
    if rospy.get_param('calculation_method') == ADD:
        print("Returning [%s + %s = %s]"%(req.a, req.b, (req.a + req.b)))
        return AddTwoIntsResponse(req.a + req.b)
    elif rospy.get_param('calculation_method') == SUB:
        print("Returning [%s - %s = %s]"%(req.a, req.b, (req.a - req.b)))
        return AddTwoIntsResponse(req.a - req.b)
    elif rospy.get_param('calculation_method') == MUL:
        print("Returning [%s x %s = %s]"%(req.a, req.b, (req.a * req.b)))
        return AddTwoIntsResponse(req.a * req.b)
    elif rospy.get_param('calculation_method') == DIV:
        print("Returning [%s ÷ %s = %s]"%(req.a, req.b, (int(req.a / req.b))))
        return AddTwoIntsResponse(int(req.a / req.b))

def int_calculator_server():
    rospy.init_node('int_calculator_server')
    rospy.set_param('calculation_method', operator)
    s = rospy.Service('add_two_ints', AddTwoInts, handle_calculation)
    print("Ready to calculate ints.")
    rospy.spin()

if __name__ == "__main__":
    int_calculator_server()
