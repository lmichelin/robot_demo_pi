#include "servo.h"
#include "motor.h"
#include "pid.h"
#include "letters.h"

int main(int argc, char const *argv[])
{

  initMotors();

  resetEncoders();

  if (initServo() == -1)
      return -1;

  styloUp();
  usleep(500000);

  writeLetter('E');
  writeLetter('N');
  writeLetter('S');
  writeLetter('T');
  writeLetter('A');
  
  styloDetach();

  return 0;
}
