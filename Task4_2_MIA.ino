#include <Wire.h>
const int MPU = 0x68; // MPU6050 I2C address;
float GyroX, GyroY, GyroZ;
float gyroAngleX, gyroAngleY, gyroAngleZ;
float roll, pitch, yaw;
float GyroErrorX, GyroErrorY, GyroErrorZ;
float elapsedTime, currentTime, previousTime;
int c = 0;


void setup() 
{
  Serial.begin(9600);
  Wire.begin();                      // Initialize comunication
  Wire.beginTransmission(MPU);       // Start communication with MPU6050 // MPU=0x68
  Wire.write(0x6B);                  // Talk to the register 6B
  Wire.write(0x00);                  // Make reset - place a 0 into the 6B register
  Wire.endTransmission(true);        //end the transmission

}

void loop() 
{
  previousTime = currentTime;        // Previous time is stored before the actual time read
  currentTime = millis();            // Current time actual time read
  elapsedTime = (currentTime - previousTime) / 1000; // Divide by 1000 to get seconds
  
  Wire.beginTransmission(MPU);
  Wire.write(0x47); // Gyro data first register address 0x47
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 2, true); // Read 4 registers total, each axis value is stored in 2 registers
  
  // For a 250deg/s range we have to divide first the raw value by 131.0 LSB_senstivity
  GyroZ = (Wire.read() << 8 | Wire.read()) / 131.0;
  
  // Currently the raw values are in degrees per seconds, deg/s, so we need to multiply by seconds (s) to get the angle in degrees
  yaw =  yaw + GyroZ * elapsedTime;
  
  // Print the value on the serial monitor
  Serial.println(yaw);

}
