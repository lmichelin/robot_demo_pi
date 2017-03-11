#include "servo.h"
#include "pid.h"

float letter_size = 10; //hauteur des lettres en cm

void writeLetter(char letter)
{
  switch (letter)
  {
    case ' ':
    {
      translate(5*letter_size);
      break;
    }
    case 'A':
    {
      rotate(-60);
      styloDown();
      usleep(500000);
      translate(11.547*letter_size);
      rotate(-60);
      translate(-11.547*letter_size);
      styloUp();
      usleep(500000);
      translate(5.7735*letter_size);
      rotate(-60);
      styloDown();
      usleep(500000);
      translate(5.7735*letter_size);
      styloUp();
      usleep(500000);
      rotate(90);
      translate(-5*letter_size);
      rotate(90);
      translate(11.16*letter_size);
      break;
    }
    case 'B':
    {
      rotate(-90);
      styloDown();
      usleep(500000);
      translate(10*letter_size);
      rotate(90);
      courbe(2.5*letter_size,180);
      courbe(-2.5*letter_size,180);
      styloUp();
      usleep(500000);
      translate(5*letter_size);
      break;
    }
    case 'C':
    {
      rotate(-90);
      translate(10*letter_size);
      rotate(-90);
      translate(-5*letter_size);
      styloDown();
      usleep(500000);
      courbe(5*letter_size,-180);
      styloUp();
      usleep(500000);
      translate(2.5*letter_size);
      break;
    }
    case 'D':
    {
      rotate(-90);
      styloDown();
      usleep(500000);
      translate(10*letter_size);
      rotate(-90);
      courbe(-5*letter_size,180);
      styloUp();
      usleep(500000);
      translate(7.5*letter_size);
      break;
    }
    case 'E':
    {
      rotate(-90);
      styloDown();
      usleep(500000);
      translate(10*letter_size);
      rotate(90);
      translate(5*letter_size);
      styloUp();
      usleep(500000);
      rotate(-90);
      translate(-5*letter_size);
      rotate(90);
      styloDown();
      usleep(500000);
      translate(-5*letter_size);
      styloUp();
      usleep(500000);
      rotate(-90);
      translate(-5*letter_size);
      rotate(90);
      styloDown();
      usleep(500000);
      translate(5*letter_size);
      styloUp();
      usleep(500000);
      translate(2.5*letter_size);
      break;
    }
    case 'F':
    {
      rotate(-90);
      styloDown();
      usleep(500000);
      translate(10*letter_size);
      rotate(90);
      translate(5*letter_size);
      styloUp();
      usleep(500000);
      rotate(-90);
      translate(-5*letter_size);
      rotate(90);
      styloDown();
      usleep(500000);
      translate(-5*letter_size);
      styloUp();
      usleep(500000);
      rotate(-90);
      translate(-5*letter_size);
      rotate(90);
      translate(7.5*letter_size);
      break;
    }
    case 'G':
    {
      translate(5*letter_size);
      styloDown();
      usleep(500000);
      courbe(-5*letter_size,180);
      styloUp();
      usleep(500000);
      translate(2.5*letter_size);
      rotate(90);
      translate(-5*letter_size);
      rotate(-90);
      styloDown();
      usleep(500000);
      translate(-2.5*letter_size);
      rotate(90);
      translate(-5*letter_size);
      styloUp();
      usleep(500000);
      rotate(90);
      translate(2.5*letter_size);
      break;
    }
    case 'N':
    {
      rotate(-90);
      styloDown();
      usleep(500000);
      translate(10*letter_size);
      rotate(-30);
      translate(-11.547*letter_size);
      rotate(30);
      translate(10*letter_size);
      styloUp();
      usleep(500000);
      translate(-10*letter_size);
      rotate(90);
      translate(2.5*letter_size);
      break;
    }
    case 'S':
    {
      styloDown();
      usleep(500000);
      courbe(2.5*letter_size,-180);
      courbe(2.5*letter_size,180);
      styloUp();
      usleep(500000);
      translate(2.5*letter_size);
      rotate(-90);
      translate(-10*letter_size);
      break;
    }
    case 'T':
    {
      translate(10*letter_size);
      rotate(90);
      styloDown();
      usleep(500000);
      translate(5*letter_size);
      styloUp();
      usleep(500000);
      translate(-2.5*letter_size);
      rotate(-90);
      styloDown();
      usleep(500000);
      translate(-10*letter_size);
      styloUp();
      usleep(500000);
      rotate(-90);
      translate(-5*letter_size);
      rotate(90);
      break;
    }
  }
}
