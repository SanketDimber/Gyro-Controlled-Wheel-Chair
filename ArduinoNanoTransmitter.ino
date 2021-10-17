// Code for transmitter part containing Arduino nano

#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <MPU6050.h>
MPU6050 mpu;

float timeStep = 0.01;
float pitch = 0;
float yaw =0;

RF24 radio(7, 8);
const byte address[6] = "00001";

void setup() {

   Serial.begin(9600);
   // Initialize MPU6050
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G)){
    
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
    
  }

  // Calibrate gyroscope. The calibration must be at rest.
  // If you don't want calibrate, comment this line.
 // mpu.calibrateGyro();

  // Set threshold sensivty. Default 3.
  // If you don't want use threshold, comment this line or set 0.
  mpu.setThreshold(3);

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  
}

void loop() {


   Vector norm = mpu.readNormalizeGyro();

    // Calculate Pitch and Yaw
    pitch = pitch + norm.YAxis * timeStep;
    yaw = yaw + norm.ZAxis * timeStep;
    
    float arr[2] ={pitch,yaw};
    radio.write(&arr, sizeof(arr));
    Serial.println("Pitch:");
    Serial.print(pitch);
    Serial.print("\t");
    Serial.print("Yaw:");
    Serial.print(yaw);
  
}
