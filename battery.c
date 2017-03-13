#include "motor.h"
int main(int argc, char const *argv[]) {
  initMotors();
  printf("%.1f\n", readBatteryVoltage());
  return 0;
}
