#!/bin/bash

pgrep main.x > /dev/null
if [ "$?" = 1 ]
then
  eval /home/pi/robot_demo_pi/battery.x
else
  echo "--"
fi