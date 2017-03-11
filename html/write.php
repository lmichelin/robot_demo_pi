<?php

$phrase = $_GET["phrase"];

if ( isset($phrase) ){
    exec("/home/pi/robot_demo_pi/write.sh $phrase");
}

else { echo ("fail"); }
?>
