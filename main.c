#include "servo.h"
#include "motor.h"
#include "pid.h"

int main(int argc, char const *argv[]) {

  initMotors();

  resetEncoders();

  if (initServo() == -1)
      return -1 ;

  styloUp();
  usleep(1000000);

  translate(500);

  styloUp();
  usleep(1000000);
  styloDetach();

  return 0;
}
