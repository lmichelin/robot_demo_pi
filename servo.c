#include "servo.h"

// Pin number declarations. We're using the Broadcom chip pin numbers.
const int pwmPin = 18; // PWM servo - Broadcom pin 18, P1 pin 12

int initServo(){
  if (wiringPiSetupGpio() == -1) // Initialize wiringPi -- using Broadcom pin numbers
      return -1 ;
  return 0;
}

void styloUp()
{
  pinMode(pwmPin, PWM_OUTPUT);
  pwmSetMode(PWM_MODE_MS);
  pwmSetClock(1920); //clock at 50kHz (20us tick)
  pwmSetRange(200); //range at 1000 ticks (20ms)
  pwmWrite(pwmPin, 10);
}

void styloDown()
{
  pinMode(pwmPin, PWM_OUTPUT);
  pwmSetMode(PWM_MODE_MS);
  pwmSetClock(1920); //clock at 50kHz (20us tick)
  pwmSetRange(200); //range at 1000 ticks (20ms)
  pwmWrite(pwmPin, 20);
}

void styloDetach()
{
  pinMode(pwmPin, INPUT);
}
