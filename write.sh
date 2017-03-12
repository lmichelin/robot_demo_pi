#!/bin/bash

params="$*"
nbparams="$#"
pgrep main.x
if [ "$?" = 1 ]
then
  eval sudo /home/pi/robot_demo_pi/main.x $params
fi
