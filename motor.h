#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

long readRightEncoder();								// Reads encoder data for both motors and displays to the screen
long readLeftEncoder();								// Reads encoder data for both motors and displays to the screen
double readRightEncoderMilli();								// Reads encoder data for both motors and displays to the screen
double readLeftEncoderMilli();								// Reads encoder data for both motors and displays to the screen
void resetEncoders();									// Resets the encoders to 0
float readBatteryVoltage();
void driveRightMotor(int speed);										// Drive the motors forwards
void driveLeftMotor(int speed);										// Drive the motors forwards
void stopMotors();										// Stop the motors
void initMotors();
