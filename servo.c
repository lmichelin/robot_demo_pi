#include "servo.h"

// Pin number declarations. We're using the Broadcom chip pin numbers.
#define ServoPin 4

int initServo(){
  if (wiringPiSetupGpio() == -1) // Initialize wiringPi -- using Broadcom pin numbers
      return -1 ;
  return 0;
}

void styloUp()
{
  pinMode(ServoPin, OUTPUT);
  int i;
  for (i = 0; i < 10; i++) {
    digitalWrite(ServoPin,HIGH);
    usleep(1100);
    digitalWrite(ServoPin,LOW);
    usleep(18900);
  }
  pinMode(ServoPin, INPUT);
}

void styloDown()
{
  pinMode(ServoPin, OUTPUT);
  int i;
  for (i = 0; i < 20; i++) {
    digitalWrite(ServoPin,HIGH);
    usleep(1600);
    digitalWrite(ServoPin,LOW);
    usleep(18400);
  }
  pinMode(ServoPin, INPUT);
}
