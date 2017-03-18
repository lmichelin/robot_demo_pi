<?php

$params = $_GET["params"];

if (isset($params)) exec("sudo /home/pi/robot_demo_pi/scripts/command.sh $params");

?>
