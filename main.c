#include "servo.h"
#include "motor.h"
#include "pid.h"
#include "letters.h"

int main(int argc, char const *argv[])
{

  initMotors();

  resetEncoders();

  if (initServo() == -1)
      return -1 ;

  writeLetter('A');
  styloDetach();

  return 0;
}
