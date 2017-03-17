#!/bin/bash

params="$*"
nbparams="$#"
eval "pico2wave -l fr-FR -w /home/pi/robot_demo_pi/audio/out.wav '$params';omxplayer --no-osd --no-keys /home/pi/robot_demo_pi/audio/out.wav" &
