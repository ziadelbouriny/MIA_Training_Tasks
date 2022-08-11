int moist = A0;//moist_sensor connected to A0
int force = A1;//force_sensor connected to A1
int plant_motor = 6;//plant_motor connected to 6 
int led = 5;//led connected to 5
int fill_motor = 7;//fill_motor connected to 7
int val_plant_motor = 0;//variable to get value of plant motor
int fill_button = 4;;//fill_button connected to 4
int count_button = 3;;//count button connected to 3
int count = 0;//variable to count
unsigned int time = 0;//variable to get time

void setup()
{
  Serial.begin(9600);
  pinMode(moist, INPUT);
  pinMode(force, INPUT);
  pinMode(fill_button, INPUT);
  pinMode(plant_motor, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(fill_motor, OUTPUT); 
  attachInterrupt(digitalPinToInterrupt(count_button), counter, RISING);
  //fuction from arduino reference to interrupt for counting
}

void loop()
{
  int val_moist = analogRead(moist);//reading moist sensor
  int val_force = analogRead(force);//reading force sensor
  int val_led = map(val_force,0,1023,255,0);//mapping force for led display
  int val_plant_motor = map(val_moist,0,876,255,0);//mapping moist for motor
  
  Serial.println(count);//displaying on serial monitor the count
  
  digitalWrite(fill_motor, LOW);//OFF the filling motor deafult
  if(digitalRead(fill_button) == HIGH)//check if the button of filling is ON or OFF
  {
    time = millis();
    while(millis() < (time+10000))//filling for 10 sec
      digitalWrite(fill_motor, HIGH);
  }
  
  analogWrite(plant_motor, val_plant_motor);
  analogWrite(led, val_led);
}

void counter()//increasing the count function
{
  count++;
}
