//arduino mega
#define ENCA 18/* INTERRUPTS */ 
#define ENCB 19
#define ENCC 20
#define ENCD 21
#define IN1 4/*MOTOR DRIVERS*/
#define IN2 5
#define IN3 6
#define IN4 7
#define SPST 8 /*SWITCH*/

int count1 = 0;/*counts of the encoder is global variable */
int count2 = 0;

void setup() 
{ 
  pinMode(ENCA,INPUT);
  pinMode(ENCB,INPUT);
  pinMode(ENCC,INPUT);
  pinMode(ENCD,INPUT);
  
  pinMode(SPST,INPUT);
  
  attachInterrupt(ENCA, ISR_encoderpinA, CHANGE);
  attachInterrupt(ENCB, ISR_encoderpinB, CHANGE);
  attachInterrupt(ENCC, ISR_encoderpinC, CHANGE);
  attachInterrupt(ENCD, ISR_encoderpinD, CHANGE);
  
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void loop() 
{
  // signal the motor
  setARM1();
  setARM2();
}

void ISR_encoderpinA()
{
  if((digitalRead(ENCA)) != (digitalRead(ENCB)))
  {
    count1++;
  }
  else
  {
    count1--;
  }
}

void ISR_encoderpinB()
{
  if((digitalRead(ENCA)) == (digitalRead(ENCB)))
  {
    count1++;
  }
  else
  {
    count1--;
  }
}

void ISR_encoderpinC()
{
  if((digitalRead(ENCA)) == (digitalRead(ENCB)))
  {
    count2++;
  }
  else
  {
    count2--;
  }
}

void ISR_encoderpinD()
{
  if((digitalRead(ENCA)) == (digitalRead(ENCB)))
  {
    count2++;
  }
  else
  {
    count2--;
  }
}

void setARM1()
{
  // set target position
  int target = 400;
  
  if(count1 < target)
  {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
  }
  else
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }
}

void setARM2()
{
  // set target position
  int target;
  
  if(digitalRead(SPST) == LOW)
  {
    if(count2 > target)
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
    }
    else
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
    }
  }
  else
  {
    target = 600;
    if(count2 < target)
    {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
    }
    else
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
    }
  }
}
