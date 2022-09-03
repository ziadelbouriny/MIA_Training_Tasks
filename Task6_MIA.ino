
#define encoder_1_A 2
#define encoder_1_B 3
#define PWM 5
#define IN1 6
#define IN2 7

long long previous_time = 0;
float error_prev = 0;
float error_integral = 0;
int count = 0;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(encoder_1_A,INPUT);
  pinMode(encoder_1_B,INPUT);
  
  attachInterrupt(digitalPinToInterrupt(encoder_1_A),ISR_encoderpinA,CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoder_1_B),ISR_encoderpinB,CHANGE);
  
  pinMode(PWM,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  
}

void loop() {

  // set target position
  float angle = Serial.parseInt();
  float target = (angle * 2400) / 360; 
 
  // PID constants
  float kp = 1;
  float kd = 0.025;
  float ki = 0.0;

  // time difference
  long long current_time = millis();
  float delta_time = ((float) (current_time - previous_time))/( 1.0e3 );
  previous_time = current_time;

  // Read the position
  int pos = 0; 
  noInterrupts(); // disable interrupts temporarily while reading
  pos = count;
  interrupts(); // turn interrupts back on
  
  // error
  float error = pos - target;

  // derivative
  float derivative_error = (error-error_prev)/(delta_time);

  // integral
  error_integral = error_integral + error * delta_time;

  // control signal
  float u = kp * error + kd * derivative_error + ki * error_integral;

  // motor direction
  int direc = 1;
  if(u < 0)
  {
    direc = -1;
  }

  // motor power limiting to 255
  float power = fabs(u);
  if( power > 255 )
  {
    power = 255;
  }

  // camera set
  camera(direc,power,PWM);


  // store previous error
  error_prev = error;
}

void camera(int direc, int pwm_value, int pwm)
{
  analogWrite(pwm,pwm_value);
  
  if(direc == 1)
  {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
  }
  else if(direc == -1)
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
  }
  else
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
  }  
}

void ISR_encoderpinA()
{
  if((digitalRead(encoder_1_A)) != (digitalRead(encoder_1_B)))
  {
    count++;
  }
  else
  {
    count--;
  }
}

void ISR_encoderpinB()
{
  if((digitalRead(encoder_1_A)) == (digitalRead(encoder_1_B)))
  {
    count++;
  }
  else
  {
    count--;
  }
}
