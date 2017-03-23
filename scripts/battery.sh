#!/bin/bash

#on teste si main.x, cmain.x ou smain.x sont déjà en cours d'exécution pour éviter les conflits
pgrep main.x > /dev/null
if [ "$?" = 1 ]
then
  eval /home/pi/robot_demo_pi/battery.x
else
  echo "--"
fi
