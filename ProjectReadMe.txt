********************************************************************************
Project Name : GYRO CONTROLLED WHEEL CHAIR 

Project opening date : 11 / 06 / 2019

Project closing date : 11 / 07 / 2019

Presented by : NXP Semiconductors 

********************************************************************************

Protocol used : 
I2C communication , refer <Wire.h>  and <MPU6050.h> library.

Hardware requirements : 
MPU6050 Sensor, Arduino Uno, IR obstacle sensor, LED, Breadboard, Jumper cables (male to female, male to male), DC motor(9V), 100? Resistor, power source.

Connections:

(L298N) Motor Driver Module to Arduino Uno and motor connections :
GND (Common)
Battery 
IN1 - digital pin 6 
IN2 - digital pin 7
IN3 – digital pin 8
IN4 – digital pin 9
OUT1 and OUT2 – MOTOR A
OUT3 and OUT4 – MOTOR B

IR obstacle sensor to Arduino Uno connections :
GND (Common)
VCC (3.3 V)
Output – digital pin 12
Output LED – digital pin 13

Gyroscope to Arduino Uno connections :
GND (Common)
VCC (5 V)
SCL – A5
SDA – A4


Precautions : 
1) It is recommended to operate the circuit at 9-12 Volts.
2) Please confirm the board selected and protocol to be followed in ‘Tools’ section before compiling the program.

Objective: 
For the ease of movement of differently abled  and aged  people.

Program modified so as to control the movement of the chair on encountering an obstacle.

Applications : 
1) The main application of it is for paralytic people so that they can control the movement by their head or hand gestures .
2) Its extended application is of interfacing it with an android device and controlling it with gyroscope of the device or through an app .

********************************************************************************

Links for connection + code :

Link 1 : 
https://www.circuitmagic.com/arduino/how-to-control-dc-motor-with-l298n-driver-and-arduino/

Link 2 : 
http://qqtrading.com.my/ir-infrared-obstacle-detaction-sensor-module-fc-5

Link 3 :
https://www.electronicwings.com/arduino/mpu6050-interfacing-with-arduino-uno

Link 4 :
https://github.com/jarzebski/Arduino-MPU6050
(For including library of “MPU6050.h” and its cpp file “MPU6050.cpp” . They are needed to be copied in the library folder of Arduino .) 


 
