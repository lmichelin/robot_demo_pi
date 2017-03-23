#!/bin/bash

eval "omxplayer --no-osd --no-keys /home/pi/robot_demo_pi/audio/"$* > /dev/null &
