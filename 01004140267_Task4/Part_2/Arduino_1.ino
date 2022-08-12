#include<Wire.h>

int temp = A0;//temp_sensor connected to A0
int val_temp = 0;//var. holds the value received from the sensor

void setup()
{
  pinMode(temp, INPUT);
  Wire.begin(9);//giving to the slave and address after 0-7
  Wire.onRequest(request_event);//request from the master to send data
  Serial.begin(9600);
}

void loop()
{
  int y = analogRead(temp);//reading from the temp_sensor
  val_temp = map(y,20,358,0,100);//mapping it to be in range(0 - 100)
}

void request_event()//function to send the value of the temp_sensor to the master
{
  Wire.write(val_temp);
}
