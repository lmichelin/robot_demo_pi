<?php

exec("/home/pi/robot_demo_pi/battery.sh", $voltage);
echo $voltage[0];

?>
