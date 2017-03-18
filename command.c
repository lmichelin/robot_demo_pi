#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int fd;														// File descrition
// For older raspberry pi modules use "/dev/i2c-0" instead of "/dev/i2c-1" for the i2c port
char const* fileName = "/dev/i2c-1";								// Name of the port we will be using
int  address = 0x58;										// Address of MD25 shifted one bit
unsigned char buf[2];										// Buffer for data being read/ written on the i2c bus

int main(int argc, char const *argv[]) {

  if (argc != 3) return 1;

  int speed = atoi(argv[1]);
  int turn = atoi(argv[2]);

  if (speed>127) speed=127;
  else if (speed<-128) speed=-128;
  if (turn>127) turn=127;
  else if (turn<-128) turn=-128;

  if (speed+turn>127 || speed-turn>127) speed=127-turn;
  else if (speed+turn<-127 || speed-turn<-127) speed=-127-turn;

	if ((fd = open(fileName, O_RDWR)) < 0) {					// Open port for reading and writing
		printf("Failed to open i2c port\n");
		exit(1);
	}

	if (ioctl(fd, I2C_SLAVE, address) < 0) {					// Set the port options and set the address of the device we wish to speak to
		printf("Unable to get bus access to talk to slave\n");
		exit(1);
	}

  buf[0] = 15;												// This is the register we wish to write mode
  buf[1] = 3;                         // Set mode 3

	if ((write(fd, buf, 2)) != 2) {								// Send mode
		printf("Error writing to i2c slave\n");
		exit(1);
	}

	buf[0] = 0;
  buf[1] = speed;

  if ((write(fd, buf, 2)) != 2) {
		printf("Error writing to i2c slave\n");
		exit(1);
	}

  buf[0] = 1;
  buf[1] = turn;

	if ((write(fd, buf, 2)) != 2) {
		printf("Error writing to i2c slave\n");
		exit(1);
	}
  return 0;
}
