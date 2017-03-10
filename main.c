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

  int i = 0;
  for (i = 0; i < strlen(argv[1]); i++)
  {
    writeLetter(argv[1][i]);
  }

  styloDetach();

  return 0;
}
