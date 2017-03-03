#include "servo.h"
#include "motor.h"

int main(int argc, char const *argv[]) {

  initMotors();

  if (initServo() == -1)
      return -1 ;

  styloUp();
  usleep(2000000);
  styloDown();
  usleep(1000000);

  resetEncoders();

  //while(readRightEncoder() < 0x2000) {						// Check the value of encoder 1 and stop after it has traveled a set distance
		 driveRightMotor(110);
     driveLeftMotor(110);
		 usleep(2000000);										// This sleep just gives us a bit of time to read what was printed to the screen in driveMortors()
	//}

	stopRightMotor();
  stopLeftMotor();

  styloUp();
  usleep(2000000);
  styloDetach();

  return 0;
}
