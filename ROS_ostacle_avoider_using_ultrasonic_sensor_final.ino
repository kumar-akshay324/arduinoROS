#include <Servo.h>                  // Library to control servos
#include <Ultrasonic.h>             // Ultrasonic sensor HC-SR04 by Eric Simoes

#include <ros.h>                    // Importing ROS support for Arduino
#include <std_msgs/Int8.h>          // Defining the standard message type

ros::NodeHandle  nh;                // Instantiate the node handle to create publisher and subscriber -  It handles the Serial communication. 

std_msgs::Int8 str_msg;          
ros::Publisher chatter("chatter", &str_msg);        // Instantiate the publisher with the name chatter

Servo myservoa;                    // create servo object to control a servo
Servo myservob;

int trigPin = 10;                  // Attaching the Ultrasonic sensor pins to Arduino Pins    
int echoPin = 11;

int ma = 4;                        // Attaching arduino pins to motor outputs 
int mb = 5;
int mc = 6;
int md = 7;
int flag =0;


int dd = 10;

Ultrasonic ultra(trigPin, echoPin);

void servo_map()
{ int pos;
  int distance;
 
  for (pos = 180; pos >= 0; pos -= 10)            // goes from 0 degrees to 180 degrees
  {          
     distance = ultra.distanceRead();
     if (distance >10){
     Serial.println(distance);}
     myservoa.write(pos);                          // tell servo to go to position in variable 'pos'
     delay(500);
  }
  for (pos = 0; pos <= 180; pos += 10)            // goes from 180 degrees to 0 degrees
 {  
     distance = ultra.distanceRead();
     if (distance >10){
     Serial.println(distance);}
     myservob.write(pos);                          // tell servo to go to position in variable 'pos'
     delay(500);
 }
 
    for (pos = 180; pos >= 0; pos -= 10)            // goes from 0 degrees to 180 degrees
  {          
     distance = ultra.distanceRead();
     if (distance >10){
     Serial.println(distance);}
     myservob.write(pos);                          // tell servo to go to position in variable 'pos'
     delay(500);     
  }
  for (pos = 0; pos <= 180; pos += 10)            // goes from 180 degrees to 0 degrees
 {  
     distance = ultra.distanceRead();
     if (distance >10){
     Serial.println(distance);}
     myservoa.write(pos);                          // tell servo to go to position in variable 'pos'
     delay(500);     
 }
}


void setup ()
{
 Serial.begin(9600);                  // Initialize the Serial communication
 
 pinMode(trigPin,OUTPUT);             // Declare the digital pins 10 and 11 as ouputs and inputs respectively
 pinMode(echoPin,INPUT);

 pinMode(ma , OUTPUT);                // Declare the motor pins as output pins
 pinMode(mb , OUTPUT);
 pinMode(mc , OUTPUT);
 pinMode(md , OUTPUT);
  
 myservoa.attach(3);                  // attaches the servo on pin 3 to the servo object
 myservob.attach(9);                  // attaches the servo on pin 9 to the servo object

 myservoa.write(180);                 // Initially position the servos to a position facing the front 
 myservob.write(0);

 nh.initNode();                       // Initialize the ROS node handle 
 nh.advertise(chatter);               // Declare the topic "chatter" a

}


void loop()
{  int distance=0;
    
  distance = ultra.distanceRead();
  str_msg.data = distance;
  chatter.publish( &str_msg );
  nh.spinOnce();
  
 if (distance>=dd) 
   {   
    digitalWrite(ma , HIGH);
    digitalWrite(mb , LOW);
    digitalWrite(mc ,HIGH); 
    digitalWrite(md , LOW);
    Serial.println("Moving Ahead");
    delay (200);
   }
  else if (distance<=dd)
   {
    digitalWrite(ma , LOW);
    digitalWrite(mb , HIGH);
    digitalWrite(mc , HIGH); 
    digitalWrite(md , LOW);
    Serial.println("Zero Turn");
    delay (200);
   }

//   Serial.println("Let's go");
}
