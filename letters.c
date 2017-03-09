#include "servo.h"
#include "pid.h"

float letter_size = 0.7;

void writeLetter(char letter)
{
  switch (letter)
  {
    case 'A':
    {
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
      translate(-200*letter_size);
      rotate(90);
      translate(-100*letter_size);
      break;
    }
    case 'B':
    {
      styloDown();
      usleep(500000);
      translate(200*letter_size);
      rotate(90);
      courbe(50*letter_size,180);
      rotate(180);
      courbe(50*letter_size,180);
      styloUp();
      usleep(500000);
      translate(-150*letter_size);
      rotate(90);
      break;
    }
    case 'E':
    {
      styloDown();
      usleep(500000);
      translate(200*letter_size);
      rotate(90);
      translate(100*letter_size);
      styloUp();
      usleep(500000);
      rotate(90);
      translate(100*letter_size);
      rotate(90);
      styloDown();
      usleep(500000);
      translate(100*letter_size);
      styloUp();
      usleep(500000);
      rotate(90);
      translate(-100*letter_size);
      rotate(90);
      styloDown();
      usleep(500000);
      translate(100*letter_size);
      styloUp();
      usleep(500000);
      translate(50*letter_size);
      rotate(-90);
      break;
    }
    case 'N':
    {
      styloDown();
      usleep(500000);
      translate(200*letter_size);
      rotate(-30);
      translate(-230.94*letter_size);
      rotate(30);
      translate(200*letter_size);
      styloUp();
      usleep(500000);
      rotate(-90);
      translate(-50*letter_size);
      rotate(90);
      translate(-200*letter_size);
      break;
    }
    case 'S':
    {
      rotate(90);
      styloDown();
      usleep(500000);
      courbe(50*letter_size,-180);
      courbe(50*letter_size,180);
      styloUp();
      usleep(500000);
      translate(50*letter_size);
      rotate(-90);
      translate(-200*letter_size);
      break;
    }
    case 'T':
    {
      translate(200*letter_size);
      rotate(90);
      styloDown();
      usleep(500000);
      translate(100*letter_size);
      styloUp();
      usleep(500000);
      translate(-50*letter_size);
      rotate(-90);
      styloDown();
      usleep(500000);
      translate(-200*letter_size);
      styloUp();
      usleep(500000);
      rotate(-90);
      translate(-100*letter_size);
      rotate(90);
      break;
    }
  }
}
