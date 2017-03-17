<?php

$letters = $_GET["letters"];
$stop = $_GET["stop"];
$battery = $_GET["battery"];
$text = $_GET["text"];
$sound = $_GET["sound"];
$arret = $_GET["arret"];

if ( isset($letters) ) exec("sudo /home/pi/robot_demo_pi/scripts/write.sh $letters");
if ( isset($sound) ) exec("sudo /home/pi/robot_demo_pi/scripts/playsound.sh $sound");
if ( isset($battery) ) {
  exec("sudo /home/pi/robot_demo_pi/scripts/battery.sh", $voltage);
  echo $voltage[0];
}
if ( isset($stop) ) exec("sudo /home/pi/robot_demo_pi/scripts/stop.sh");
if ( isset($text) ) exec("sudo /home/pi/robot_demo_pi/scripts/playtext.sh $text");
if ( isset($arret) ) exec("sudo /home/pi/robot_demo_pi/scripts/arret.sh");

?>
