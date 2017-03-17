#include "servo.h"
#include "motor.h"
#include "pid.h"
#include "letters.h"

//syntaxe pour l'éxécution : sudo ./main.x 20 ma phrase

int main(int argc, char const *argv[])
{

  if (argc < 3) return 1;

  initMotors();

  resetEncoders();

  if (initServo() == -1)
      return -1;

  styloUp();
  usleep(400000);

  int letter_size = atoi(argv[1]);

  int i = 0;
  int j = 0;
  for (i = 2; i < argc; i++)
  {
    for (j = 0; j < strlen(argv[i]); j++)
    {
      writeLetter(argv[i][j], letter_size);
    }
    writeLetter(' ', letter_size);
  }

  return 0;
}
