#include "pid.h"
#include "motor.h"

float voie = 109; //voie/2 du robot (voie = distance entre les 2 roues d'un même essieu) en mm

double previous_right_error = 0;
double previous_left_error = 0;
double previous_right_output = 128;
double previous_left_output = 128;
double right_integral = 0;
double left_integral = 0;

int dt = 5000; //µs
float max_int = 40; // max integral value
float max_acc = 1.3; // max variation of output (acceleration)
float Kp = 0.4;
float Ki = 0.1;
float Kd = 0.3;
float tolerance = 0.0; //mm

int updateRightPid(double setpoint, double measured_value)
{
  double error = setpoint - measured_value;
  right_integral += error*dt;
  if (right_integral > max_int) right_integral = max_int;
  else if (right_integral < -max_int) right_integral = -max_int;
  double derivative = (error - previous_right_error)/dt;
  previous_right_error = error;
  double output = Kp*error + Ki*right_integral + Kd*derivative + 128;
  if (output > previous_right_output + max_acc) output = previous_right_output + max_acc;
  else if (output < previous_right_output - max_acc) output = previous_right_output - max_acc;
  previous_right_output = output;
  if (output < 0) return 0;
  else if (output > 254) return 254;
  else return output;
}

int updateLeftPid(double setpoint, double measured_value)
{
  double error = setpoint - measured_value;
  left_integral += error*dt;
  if (left_integral > max_int) left_integral = max_int;
  else if (left_integral < -max_int) left_integral = -max_int;
  double derivative = (error - previous_left_error)/dt;
  previous_left_error = error;
  double output = Kp*error + Ki*left_integral + Kd*derivative + 128;
  if (output > previous_left_output + max_acc) output = previous_left_output + max_acc;
  else if (output < previous_left_output - max_acc) output = previous_left_output - max_acc;
  previous_left_output = output;
  if (output < 0) return 0;
  else if (output > 254) return 254;
  else return output;
}

void translate(float mm)
{
  double update = 0;
  double current_left = readLeftEncoderMilli();
  double previous_left = current_left;
  double wanted_left = current_left + mm;
  previous_left_error = 0;
  left_integral = 0;

  while (abs(current_left - wanted_left) > tolerance || abs(previous_left - wanted_left) > tolerance)
  {
    update = updateLeftPid(wanted_left, current_left);
    driveRightMotor(update);
    driveLeftMotor(update);
    usleep(dt);
    previous_left = current_left;
    current_left = readLeftEncoderMilli();
  }
stopMotors();
}

void rotate(float degre)
{
  double update = 0;
  double rad = degre * 0.0174533; //conversion degre > radian
  double current_left = readLeftEncoderMilli();
  double previous_left = current_left;
  double wanted_left = current_left - voie*rad;
  previous_left_error = 0;
  left_integral = 0;

  while (abs(current_left - wanted_left) > tolerance || abs(previous_left - wanted_left) > tolerance)
  {
    update = updateLeftPid(wanted_left, current_left);
    driveRightMotor(update);
    driveLeftMotor(update);
    usleep(dt);
    previous_left = current_left;
    current_left = readLeftEncoderMilli();
    //printf("right %lf & left %lf\n", current_right, current_left);
  }
stopMotors();
//printf("END %lf %lf\n",current_right, current_left);
}

void courbe(float rayon, float degre)
{
  double rad = degre * 0.0174533; //conversion degre > radian
  double current_right = readRightEncoderMilli();
  double current_left = readLeftEncoderMilli();
  double previous = current_left;
  double wanted = 0;
  double update = 0;
  float coeff = (abs(rayon)-voie)/(abs(rayon)+voie);
  previous_right_error = 0;
  previous_left_error = 0;
  right_integral = 0;
  left_integral = 0;

  if (rayon * degre >= 0) {
    if (rayon >= 0) wanted = current_right + (rayon+voie)*rad;
    else wanted = current_right - (abs(rayon)+voie)*(-rad);
    while (abs(current_right - wanted) > tolerance || abs(previous - wanted) > tolerance)
    {
      update = updateRightPid(wanted, current_right);
      driveRightMotor(update);
      driveLeftMotor((update-128)*coeff+128);
      usleep(dt);
      previous = current_right;
      current_right = readRightEncoderMilli();
    }
  }
  else {
    if (rayon >= 0) wanted = current_left + (rayon+voie)*(-rad);
    else wanted = current_left - (abs(rayon)+voie)*rad;
    while (abs(current_left - wanted) > tolerance || abs(previous - wanted) > tolerance)
    {
      update = updateLeftPid(wanted, current_left);
      driveLeftMotor(update);
      driveRightMotor((update-128)*coeff+128);
      usleep(dt);
      previous = current_left;
      current_left = readLeftEncoderMilli();
    }
  }

stopMotors();
}
