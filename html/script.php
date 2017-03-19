<?php

$letters = $_GET["letters"];
$kill = $_GET["kill"];
$battery = $_GET["battery"];
$text = $_GET["text"];
$sound = $_GET["sound"];
$arret = $_GET["arret"];
$params = $_GET["params"];

if ( isset($letters) ) exec("sudo /home/pi/robot_demo_pi/scripts/write.sh $letters");
if ( isset($sound) ) exec("sudo /home/pi/robot_demo_pi/scripts/playsound.sh $sound");
if ( isset($battery) ) {
  exec("sudo /home/pi/robot_demo_pi/scripts/battery.sh", $voltage);
  echo $voltage[0];
}
if ( isset($kill) ) exec("sudo /home/pi/robot_demo_pi/scripts/kill.sh");
if ( isset($text) ) exec("sudo /home/pi/robot_demo_pi/scripts/playtext.sh $text");
if ( isset($arret) ) exec("sudo /home/pi/robot_demo_pi/scripts/arret.sh");
if ( isset($params) ) exec("sudo /home/pi/robot_demo_pi/scripts/command.sh $params");

?>
