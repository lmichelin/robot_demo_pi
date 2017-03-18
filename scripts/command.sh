#!/bin/bash

params="$*"
nbparams="$#"
pgrep main.x > /dev/null
if [ "$?" = 1 ]
then
  eval /home/pi/robot_demo_pi/cmain.x $params
fi
