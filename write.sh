#!/bin/bash

params="$*"
nbparams="$#"
pgrep main.x
if [ "$?" = 1 ] && [ "$nbparams" != 0 ]
then
sudo /home/pi/robot_demo_pi/main.x "$params"
fi
