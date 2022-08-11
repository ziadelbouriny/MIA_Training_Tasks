#include<Wire.h>

int moist = A0;//moist_sensor connected to A0 pin

void setup() 
{
  Serial.begin(9600);
  pinMode(moist, INPUT);
}

void loop() 
{
  int val_moist = analogRead(moist);//reading the value from the sensor analog
  Serial.write(val_moist);//sending the data to master ard
}
