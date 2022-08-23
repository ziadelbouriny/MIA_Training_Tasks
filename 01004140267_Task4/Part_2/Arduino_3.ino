#include<Wire.h>

int motor = 13;//motor connected to pin 13
int y = 0;//variable to get the reading from moist_sensor

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
  pinMode(12,OUTPUT);//another pin to control the direction of the motor
}

void loop()
{
  Wire.requestFrom(9,64);//getting data from ard_temp_sensor which adress 9
  int x = Wire.read();//reading the value of temp
  Serial.println(x);//displaying it on the serial monitor
  //checking if the temp conditions as required
  if(x > 40)
  {
    digitalWrite(motor, HIGH);//makes the motor moves in clockwise
    digitalWrite(12, LOW);
  }
  else if(x < 20)
  {
    digitalWrite(motor, LOW);//makes the motor moves in anticlockwise
    digitalWrite(12, HIGH);
  }
  else
    digitalWrite(motor, LOW);//makes motor OFF
  
  if(Serial.available())//checking if there's data from ard_moist_sensor
  {
    y = Serial.read();//reading the value of moist
    Serial.println(y);//displaying it on the serial monitor
  }
  
}
