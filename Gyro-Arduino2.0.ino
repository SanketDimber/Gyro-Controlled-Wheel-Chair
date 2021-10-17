/*

L298 with Arduino:

L298    Arduino
1    =    6
2    =    7
3    =    8
4    =    9

Power:

1   =   VCC
2   =   Common Ground of power supply and arduino
3   =   Not Used

*/
#include <nRF24L01.h>

#include <RF24.h>
#include <RF24_config.h>
#include <Wire.h>
#include <MPU6050.h>
#include <SPI.h>


// connect motor controller pins to Arduino digital pins
// motor one

float timeStep = 0.01;
float pitch = 0;
float yaw =0;
int in1 = 9;
int in2 = 8;

// motor two
int in3 = 7;
int in4 = 6;

int LED = 13; // Use the onboard Uno LED
int isObstaclePin = 4; // This is our input pin
int isObstacle = HIGH; // HIGH MEANS NO OBSTACLE
float arr[2]={0};
RF24 radio(2, 3); // CE, CSN
const byte address[6] = "00001";

void setup(){
  
  Serial.begin(9600);

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  // set all the motor control pins to outputs

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(LED, OUTPUT);
  pinMode(isObstaclePin, INPUT);
  
}


void motorStop(){
    
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW); 
  
}

void moveReverse(){

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
 
}

void moveForward(){

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW); 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 
}


void moveRight(){

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 
}



void moveLeft(){

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
 
}

void loop(){
  
  if (radio.available()) {

    radio.read(&arr, sizeof(arr));
    Serial.println("Pitch:");
    Serial.print(arr[0]);
    pitch = arr[0];
    Serial.print("\t");
    Serial.print("Yaw:");
    Serial.print(arr[1]);
    yaw= arr[1]; 
    Serial.println("\n"); 
    
  }
  // Checking if obstacle present and accordingly glowing LED  
  isObstacle = digitalRead(isObstaclePin);
  digitalWrite(LED, LOW);
  // Checking range of pitch for reference position
  if(pitch >-2 && pitch < 2) {   
  // Checking range of yaw for reference position
    if(yaw >-2 && yaw < 2) {  
      
        motorStop();
 
     }
      else if(yaw<0) {
     
          moveLeft(); 

      }
      else if(yaw>0) {
      
            moveRight();
      
      }
    }
    
    else if(pitch < 0) {
    
        moveReverse();
    
    }
    else if(pitch > 0) {  

      if (isObstacle == LOW){   /*while going forward if obstacle is detected out vehicle must stop */
      
        Serial.println("OBSTACLE!!");
        digitalWrite(LED, HIGH);
        motorStop();
        
      }
      else {
        
            moveForward();
 
      }  
  }
}
