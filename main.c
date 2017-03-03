#include "servo.h"
#include "motor.h"

int main(int argc, char const *argv[]) {

  initMotors();

  resetEncoders();

  if (initServo() == -1)
      return -1 ;

  styloUp();
  usleep(2000000);

  rotation(180.0);
  usleep(10000000);


  int i = 128;

  while(readRightEncoderMilli() < 1000) {						// Check the value of encoder 1 and stop after it has traveled a set distance
     if (i < 145) i++;
		 driveRightMotor(i);
     driveLeftMotor(i);
		 usleep(10000);										// This sleep just gives us a bit of time to read what was printed to the screen in driveMotors()
	}
  printf("%lf\n", readRightEncoderMilli());
  stopMotors();

  printf("Fin\n");
  usleep(5000000);

  while(readRightEncoderMilli() > 10) {						// Check the value of encoder 1 and stop after it has traveled a set distance
		 driveRightMotor(100);
     driveLeftMotor(100);
		 usleep(50000);										// This sleep just gives us a bit of time to read what was printed to the screen in driveMotors()
  }
	stopMotors();

  styloUp();
  usleep(2000000);
  styloDetach();

  return 0;
}
