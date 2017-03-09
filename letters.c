#include "servo.h"
#include "pid.h"

float letter_size = 1;

void writeLetter(char letter)
{
  switch (letter) {
    case 'A':
    {
      styloUp();
      usleep(500000);
      rotate(30);
      styloDown();
      usleep(500000);
      translate(200*letter_size);
      rotate(-60);
      translate(-200*letter_size);
      styloUp();
      usleep(500000);
      translate(100*letter_size);
      rotate(-60);
      styloDown();
      usleep(500000);
      translate(100*letter_size);
      styloUp();
      usleep(500000);
      translate(-150*letter_size);
      rotate(90);
      translate(-100*letter_size);
      styloUp();
      usleep(500000);
    }
  }
}
