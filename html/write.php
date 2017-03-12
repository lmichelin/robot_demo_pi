<?php

$params = $_GET["params"];

if ( isset($params) ) exec("/home/pi/robot_demo_pi/write.sh $params");

?>
