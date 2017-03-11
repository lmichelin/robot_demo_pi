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
  int j = 0;
  for (i = 1; i < argc; i++) {
    for (j = 0; j < strlen(argv[i]); j++)
    {
      writeLetter(argv[i][j]);
    }
    writeLetter(' ');
  }


  styloDetach();

  return 0;
}
