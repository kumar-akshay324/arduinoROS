#!/usr/bin/env python

import numpy as np 
import rospy 
from std_msgs.msg import Int8 

def callback(data):
	print (abs(data.data))
	file = open("data.txt", 'a')
	file.write(str(abs(data.data)) + "\n")
	file.close()



	# rospy.loginfo(rospy.get_caller_id(), data.data)
     
def subscriber():

 
   # In ROS, nodes are uniquely named. If two nodes with the same
   # node are launched, the previous one is kicked off. The
   # anonymous=True flag means that rospy will choose a unique
   # name for our 'listener' node so that multiple listeners can
   # run simultaneously.

   rospy.init_node('subscriber', anonymous=True)
   rospy.Subscriber("chatter", Int8, callback)
   # spin() simply keeps python from exiting until this node is stopped
   rospy.spin()


if __name__ == '__main__':
	subscriber()
