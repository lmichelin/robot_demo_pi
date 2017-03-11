#!/bin/bash

params="$*"
pgrep main.x
if [ "$?" = 1 ]
then
sudo /home/pi/robot_demo_pi/main.x "$params"
fi
