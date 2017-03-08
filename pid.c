#include "pid.h"
#include "motor.h"

double previous_right_error = 0;
double previous_left_error = 0;
double right_integral = 0;
double left_integral = 0;
int dt = 5000; //µs
float tolerance = 0.5; //mm
float Kp = 0.5;
float Ki = 0;
float Kd = 0;

int updateRightPid(double setpoint, double measured_value)
{
  double error = setpoint - measured_value;
  right_integral += error*dt;
  double derivative = (error - previous_right_error)/dt;
  previous_right_error = error;
  double output = Kp*error + Ki*right_integral + Kd*derivative + 128;
  if (output < 0) return 0;
  else if (output > 254) return 254;
  else return output;
}

int updateLeftPid(double setpoint, double measured_value)
{
  double error = setpoint - measured_value;
  left_integral += error*dt;
  double derivative = (error - previous_left_error)/dt;
  previous_left_error = error;
  double output = Kp*error + Ki*left_integral + Kd*derivative + 128;
  if (output < 0) return 0;
  else if (output > 254) return 254;
  else return output;
}

void translate(float mm)
{
  float current_right = readRightEncoderMilli();
  float current_left = readLeftEncoderMilli();
  float wanted_right = current_right + mm;
  float wanted_left = current_left + mm;
  previous_right_error = 0;
  previous_left_error = 0;
  right_integral = 0;
  left_integral = 0;

  while (abs(current_right - wanted_right) > tolerance || abs(current_left - wanted_left) > tolerance)
  {
    driveRightMotor(updateRightPid(wanted_right, current_right));
    driveLeftMotor(updateLeftPid(wanted_left, current_left));
    usleep(dt);
    current_right = readRightEncoderMilli();
    current_left = readLeftEncoderMilli();
    //printf("right %f & left %f\n", current_right, current_left);
  }
stopMotors();
printf("end\n");
}
