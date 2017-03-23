/*
Script utilisé pour afficher la tension de la batterie sur la page web
*/

#include "motor.h"
int main(int argc, char const *argv[]) {
  initMotors();
  printf("%.1f\n", readBatteryVoltage());
  return 0;
}
