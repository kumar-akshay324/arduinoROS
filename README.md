# arduinoROS
Arduino and Ultrasonic sensor based Obstacle Avoidance robot that transfers distance data as a ROS message using rosserial_python, while dodging obstacles online

Prerequisites:

1. ROS
2. Ultrasonic Sensor HC-SR04 Arduino library by Erick Simoes
3. Arduino IDE
4. rosserial library

Setup and Execution:

1. Feed the attached Arduino Code to the board
2. Ensure that the sensors have been hooked up to the correct pins and there is ample current and voltage supply
3. To read data - Run $ roscore
4. Run Python rosserial support - $ rosrun rosserial_python serial_node.py /dev/ttyUSB0 (Change USB port accordinly)
5. Create a package inside your ROS Workspace and paste the "subscriber.py" file inside.
6. Run - $ catkin_make

  ALTERNATIVELY

5. Run - $ rostopic echo chatter to directly listen to the messages being broadcasted to the topic chatter

Reference Links:

1. http://wiki.ros.org/rosserial_arduino/Tutorials
2. https://github.com/ErickSimoes/Ultrasonic
3. http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup
