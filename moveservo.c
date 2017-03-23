/*
Script utilisé pour monter/descendre le servo dans le cas d'une commande via l'accéléromètre du smartphone
*/

#include "servo.h"

int main(int argc, char const *argv[]) {
  initServo();
  if (argc != 2) return -1;
  if (argv[1][0] == 'u') styloUp();
  else if (argv[1][0] == 'd') styloDown();
  return 0;
}
