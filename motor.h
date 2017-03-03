#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

long readRightEncoder(void);								// Reads encoder data for both motors and displays to the screen
long readLeftEncoder(void);								// Reads encoder data for both motors and displays to the screen
void resetEncoders(void);									// Resets the encoders to 0
void driveRightMotor(int speed);										// Drive the motors forwards
void driveLeftMotor(int speed);										// Drive the motors forwards
void stopRightMotor(void);										// Stop the motors
void stopLeftMotor(void);										// Stop the motors
void initMotors();
