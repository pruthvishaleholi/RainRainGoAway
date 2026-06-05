#include <Servo.h>
#define input A0

double arr[100];
int front = 0;
int sum = 0;
int currentSpeed = 0;
int change = 0;

Servo myservo;
#define servoPin 7

void setup()
{
  Serial.begin(9600);
  pinMode(input, INPUT);
  myservo.attach(servoPin);
  myservo.write(180);
}

void loop()
{
  sum=0;
  for(int i = 0; i < 100; i++)
  {
    arr[i] = analogRead(input);
    delay(10);
  }
  for(int i = 0; i < 99; i++)
  {
    sum+=(abs(arr[i+1] - arr[i]));
  }
  double currentDiff = sum / 98.0;
  
  if(currentDiff < 1.5){
    if(change == 1){
      currentSpeed = 0;
      change = 0;
      myservo.write(180);
    }
    if(currentSpeed != 0){
      change = 1;
    }
  }
  else if(currentDiff < 4.5){
    if(change == 1){
      currentSpeed = 1;
      change = 0;
      myservo.write(140);
    }
    if(currentSpeed != 1){
      change = 1;
    }
  }
  else if(currentDiff < 6.0){
    if(change == 1){
      currentSpeed = 2;
      change = 0;
      myservo.write(100);
    }
    if(currentSpeed != 2){
      change = 1;
    }
  }
  else if(currentDiff < 8.2){
    if(change == 1){
      currentSpeed = 3;
      change = 0;
      myservo.write(60);
    }
    if(currentSpeed != 3){
      change = 1;
    }
  }
  else{
    if(change == 1){
      currentSpeed = 4;
      change = 0;
      myservo.write(20);
    }
    if(currentSpeed != 4){
      change = 1;
    }
  }
  Serial.println(currentSpeed);
}
