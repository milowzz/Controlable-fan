int myvolt=A0;
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int speed1;
int pwmPin = 9; // assigns pin 9 to variable pwm
int pot = A0; // assigns analog input A0 to variable pot
int c1 = 0;   // declares variable c1
int c2 = 0;   // declares variable c2
int fan;

#include <Servo.h>
int servoPin=8;
int servoPos=0;

Servo servo1;

int x_axis;

void setup() 
{
 
  Serial.begin(9600);
  pinMode(myvolt, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(fan, OUTPUT);
 
  pinMode(pwmPin, OUTPUT); 
  pinMode(pot, INPUT);  
  
servo1.attach(8);
 servo1.write(0);
  

 pinMode(A1,INPUT);

  }

void loop() 
{
   int potmeasure = analogRead(myvolt);
  Serial.println(potmeasure);
  speed1 = analogRead(myvolt);
speed1 = speed1*2;
analogWrite(fan,speed1);

 c2= analogRead(pot); 
 c1= 1024-c2;         // subtracts c2 from 1000 ans saves the result in c1
 digitalWrite(pwmPin, HIGH); 
 delayMicroseconds(c1);   
 digitalWrite(pwmPin, LOW);  
 delayMicroseconds(c2);  

x_axis = analogRead(A1);

int  servo_valx = map(x_axis,0,1023,0,180);
  Serial.print(servo_valx);
  servo1.write(servo_valx);
 
  
  if (potmeasure < 40)
  {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
 
  }
  else if (potmeasure < 256)
  {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
   
  
  
  }
  else if (potmeasure < 512)
  {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);

  }
  else if (potmeasure < 768)
  {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);

  }
  else if (potmeasure == 1023)
  {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
 
  }

}
