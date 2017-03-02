// MD25 example c code for the Raspberry pi.
//
// Drives both motors untill an encoder count of over 0x2000
// is reached and stops the motors. Displays the current decoder value.
//
// By James Henderson, 2016

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "motor.h"

int fd;														// File descrition
// For older raspberry pi modules use "/dev/i2c-0" instead of "/dev/i2c-1" for the i2c port
	char *fileName = "/dev/i2c-1";								// Name of the port we will be using
int  address = 0x58;										// Address of MD25 shifted one bit
unsigned char buf[10];										// Buffer for data being read/ written on the i2c bus

void resetEncoders(void) {
	buf[0] = 16;												// Command register
	buf[1] = 32;												// command to set decoders back to zero

	if ((write(fd, buf, 2)) != 2) {
		printf("Error writing to i2c slave\n");
		exit(1);
	}
}

long readRightEncoder (void) {

	long encoder;

	buf[0] = 2;													// register for start of encoder values

	if ((write(fd, buf, 1)) != 1) {
		printf("Error writing to i2c slave\n");
		exit(1);
	}

	if (read(fd, buf, 8) != 8) {								// Read back 8 bytes for the encoder values into buf[]
		printf("Unable to read from slave\n");
		exit(1);
	}
	else {
		encoder = (buf[0] <<24) + (buf[1] << 16) + (buf[2] << 8) + buf[3];	// Put encoder values together
		printf("Encoder : %08lX\n",encoder);
	}
	return encoder;
}

long readLeftEncoder (void) {

	long encoder;

	buf[0] = 2;													// register for start of encoder values

	if ((write(fd, buf, 1)) != 1) {
		printf("Error writing to i2c slave\n");
		exit(1);
	}

	if (read(fd, buf, 8) != 8) {								// Read back 8 bytes for the encoder values into buf[]
		printf("Unable to read from slave\n");
		exit(1);
	}
	else {
		encoder = (buf[4] <<24) + (buf[5] << 16) + (buf[6] << 8) + buf[7];
		printf("Encoder 1: %08lX\n",encoder);
	}
	return encoder;
}

void driveRightMotor(int speed){
	buf[0] = 0;													// Register to set speed of motor 1
	buf[1] = speed;												// speed to be set

	if ((write(fd, buf, 2)) != 2) {
		printf("Error writing to i2c slave\n");
		exit(1);
	}
}

void driveLeftMotor(int speed){
	buf[0] = 1;													// motor 2 speed
	buf[1] = speed;

	if ((write(fd, buf, 2)) != 2) {
		printf("Error writing to i2c slave\n");
		exit(1);
	}
}

void stopRightMotor(void){
	buf[0] = 0;
	buf[1] = 128;												// A speed of 128 stops the motor

	if ((write(fd, buf, 2)) != 2) {
		printf("Error writing to i2c slave\n");
		exit(1);
	}
}

void stopLeftMotor(void){
	buf[0] = 1;
	buf[1] = 128;

	if ((write(fd, buf, 2)) != 2) {
		printf("Error writing to i2c slave\n");
		exit(1);
	}
}
