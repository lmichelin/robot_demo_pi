#include "servo.h"
#include "pid.h"

void writeLetter(char letter, int letter_size) //letter_size = hauteur des lettres en cm
{
  switch (letter)
  {
    case ' ':
    {
      translate(5*letter_size);
      break;
    }
    case '-':
    {
      rotate(-90);
      translate(5*letter_size);
      rotate(90);
      styloDown();
      translate(5*letter_size);
      styloUp();
      translate(2.5*letter_size);
      rotate(-90);
      translate(-5*letter_size);
      rotate(90);
      break;
    }
    case '.':
    {
      styloDown();
      styloUp();
      translate(2.5*letter_size);
      break;
    }
    case 'A': case 'a':
    {
      rotate(-60);
      styloDown();
      translate(11.547*letter_size);
      rotate(-60);
      translate(-11.547*letter_size);
      styloUp();
      translate(5.7735*letter_size);
      rotate(-60);
      styloDown();
      translate(5.7735*letter_size);
      styloUp();
      rotate(90);
      translate(-5*letter_size);
      rotate(90);
      translate(11.16*letter_size);
      break;
    }
    case 'B': case 'b':
    {
      rotate(-90);
      styloDown();
      translate(10*letter_size);
      rotate(90);
      courbe(2.5*letter_size,180);
      courbe(-2.5*letter_size,180);
      styloUp();
      translate(5*letter_size);
      break;
    }
    case 'C': case 'c':
    {
      rotate(-90);
      translate(10*letter_size);
      rotate(-90);
      translate(-5*letter_size);
      styloDown();
      courbe(5*letter_size,-180);
      styloUp();
      translate(2.5*letter_size);
      break;
    }
    case 'D': case 'd':
    {
      rotate(-90);
      styloDown();
      translate(10*letter_size);
      rotate(-90);
      courbe(-5*letter_size,180);
      styloUp();
      translate(7.5*letter_size);
      break;
    }
    case 'E': case 'e':
    {
      rotate(-90);
      styloDown();
      translate(10*letter_size);
      rotate(90);
      translate(5*letter_size);
      styloUp();
      rotate(-90);
      translate(-5*letter_size);
      rotate(90);
      styloDown();
      translate(-5*letter_size);
      styloUp();
      rotate(-90);
      translate(-5*letter_size);
      rotate(90);
      styloDown();
      translate(5*letter_size);
      styloUp();
      translate(2.5*letter_size);
      break;
    }
    case 'F': case 'f':
    {
      rotate(-90);
      styloDown();
      translate(10*letter_size);
      rotate(90);
      translate(5*letter_size);
      styloUp();
      rotate(-90);
      translate(-5*letter_size);
      rotate(90);
      styloDown();
      translate(-5*letter_size);
      styloUp();
      rotate(-90);
      translate(-5*letter_size);
      rotate(90);
      translate(7.5*letter_size);
      break;
    }
    case 'G': case 'g':
    {
      translate(5*letter_size);
      styloDown();
      courbe(-5*letter_size,180);
      styloUp();
      translate(2.5*letter_size);
      rotate(90);
      translate(-5*letter_size);
      rotate(-90);
      styloDown();
      translate(-2.5*letter_size);
      rotate(90);
      translate(-5*letter_size);
      styloUp();
      rotate(90);
      translate(2.5*letter_size);
      break;
    }
    case 'H': case 'h':
    {
      rotate(-90);
      styloDown();
      translate(10*letter_size);
      styloUp();
      translate(-5*letter_size);
      rotate(90);
      styloDown();
      translate(5*letter_size);
      styloUp();
      rotate(-90);
      translate(5*letter_size);
      styloDown();
      translate(-10*letter_size);
      styloUp();
      rotate(90);
      translate(2.5*letter_size);
      break;
    }
    case 'I': case 'i':
    {
      rotate(-90);
      translate(10*letter_size);
      rotate(90);
      styloDown();
      translate(5*letter_size);
      styloUp();
      translate(-2.5*letter_size);
      rotate(-90);
      styloDown();
      translate(-10*letter_size);
      styloUp();
      rotate(90);
      translate(-2.5*letter_size);
      styloDown();
      translate(5*letter_size);
      styloUp();
      translate(2.5*letter_size);
      break;
    }
    case 'J': case 'j':
    {
      rotate(-90);
      translate(10*letter_size);
      rotate(90);
      styloDown();
      translate(5*letter_size);
      styloUp();
      translate(-2.5*letter_size);
      rotate(-90);
      styloDown();
      translate(-7.5*letter_size);
      courbe(-2.5*letter_size,90);
      styloUp();
      translate(7.5*letter_size);
      break;
    }
    case 'K': case 'k':
    {
      rotate(-90);
      styloDown();
      translate(10*letter_size);
      styloUp();
      translate(-5*letter_size);
      rotate(30);
      styloDown();
      translate(5.7735*letter_size);
      styloUp();
      translate(-5.7735*letter_size);
      rotate(-60);
      styloDown();
      translate(-5.7735*letter_size);
      styloUp();
      rotate(120);
      translate(2.5*letter_size);
      break;
    }
    case 'L': case 'l':
    {
      rotate(-90);
      translate(10*letter_size);
      styloDown();
      translate(-10*letter_size);
      rotate(90);
      translate(5*letter_size);
      styloUp();
      translate(2.5*letter_size);
      break;
    }
    case 'M': case 'm':
    {
      rotate(-90);
      styloDown();
      translate(10*letter_size);
      rotate(-30);
      translate(-5.7735*letter_size);
      rotate(60);
      translate(5.7735*letter_size);
      rotate(-30);
      translate(-10*letter_size);
      styloUp();
      rotate(90);
      translate(2.5*letter_size);
      break;
    }
    case 'N': case 'n':
    {
      rotate(-90);
      styloDown();
      translate(10*letter_size);
      rotate(-30);
      translate(-11.547*letter_size);
      rotate(30);
      translate(10*letter_size);
      styloUp();
      translate(-10*letter_size);
      rotate(90);
      translate(2.5*letter_size);
      break;
    }
    case 'O': case 'o':
    {
      translate(5*letter_size);
      styloDown();
      courbe(5*letter_size,-360);
      styloUp();
      translate(7.5*letter_size);
      break;
    }
    case 'P': case 'p':
    {
      rotate(-90);
      translate(5*letter_size);
      rotate(90);
      styloDown();
      courbe(2.5*letter_size,-180);
      rotate(90);
      translate(-10*letter_size);
      styloUp();
      rotate(90);
      translate(7.5*letter_size);
      break;
    }
    case 'Q': case 'q':
    {
      translate(5*letter_size);
      styloDown();
      courbe(5*letter_size,-360);
      styloUp();
      translate(5*letter_size);
      rotate(45);
      styloDown();
      translate(-5*letter_size);
      styloUp();
      translate(5*letter_size);
      rotate(-45);
      translate(2.5*letter_size);
      break;
    }
    case 'R': case 'r':
    {
      rotate(-90);
      styloDown();
      translate(10*letter_size);
      rotate(-90);
      courbe(-2.5*letter_size,180);
      rotate(63.435);
      translate(5.59*letter_size);
      styloUp();
      rotate(-63.43);
      translate(2.5*letter_size);
      break;
    }
    case 'S': case 's':
    {
      rotate(-90);
      translate(0.147*letter_size);
      rotate(-71.47);
      styloDown();
      courbe(-2.574*letter_size,-180);
      courbe(-2.574*letter_size,180);
      styloUp();
      rotate(71.47);
      translate(-9.85281*letter_size);
      rotate(90);
      translate(2.5*letter_size);
      break;
    }
    case 'T': case 't':
    {
      rotate(-90);
      translate(10*letter_size);
      rotate(90);
      styloDown();
      translate(5*letter_size);
      styloUp();
      translate(-2.5*letter_size);
      rotate(-90);
      styloDown();
      translate(-10*letter_size);
      styloUp();
      rotate(90);
      translate(5*letter_size);
      break;
    }
    case 'U': case 'u':
    {
      rotate(90);
      translate(-10*letter_size);
      styloDown();
      translate(7.5*letter_size);
      courbe(2.5*letter_size,-180);
      translate(7.5*letter_size);
      styloUp();
      translate(-10*letter_size);
      rotate(90);
      translate(2.5*letter_size);
      break;
    }
    case 'V': case 'v':
    {
      rotate(-90);
      translate(10*letter_size);
      rotate(-30);
      styloDown();
      translate(-11.547*letter_size);
      rotate(60);
      translate(11.547*letter_size);
      styloUp();
      rotate(-30);
      translate(-10*letter_size);
      rotate(90);
      translate(2.5*letter_size);
      break;
    }
    case 'W': case 'w':
    {
      rotate(-90);
      translate(10*letter_size);
      rotate(-30);
      styloDown();
      translate(-11.547*letter_size);
      rotate(60);
      translate(5.7735*letter_size);
      rotate(-60);
      translate(-5.7735*letter_size);
      rotate(60);
      translate(11.547*letter_size);
      styloUp();
      rotate(-30);
      translate(-10*letter_size);
      rotate(90);
      translate(2.5*letter_size);
      break;
    }
    case 'X': case 'x':
    {
      rotate(-60);
      styloDown();
      translate(11.547*letter_size);
      styloUp();
      translate(-5.7735*letter_size);
      rotate(-60);
      translate(5.7735*letter_size);
      styloDown();
      translate(-11.547*letter_size);
      styloUp();
      rotate(120);
      translate(2.5*letter_size);
      break;
    }
    case 'Y': case 'y':
    {
      rotate(-60);
      styloDown();
      translate(11.547*letter_size);
      styloUp();
      translate(-5.7735*letter_size);
      rotate(-60);
      styloDown();
      translate(5.7735*letter_size);
      styloUp();
      translate(-11.547*letter_size);
      rotate(120);
      translate(2.5*letter_size);
      break;
    }
    case 'Z': case 'z':
    {
      rotate(-90);
      translate(10*letter_size);
      rotate(90);
      styloDown();
      translate(5*letter_size);
      rotate(-60);
      translate(-11.547*letter_size);
      rotate(60);
      translate(5*letter_size);
      styloUp();
      translate(2.5*letter_size);
      break;
    }
  }
}
