#!/bin/bash

params="$*"
nbparams="$#"
eval "pico2wave -l fr-FR -w /tmp/out.wav '$params';omxplayer --no-osd --no-keys /tmp/out.wav" > /dev/null &
