<?php

//On recupere la donnee
$accel = $_GET["accel"];

//Si les valeurs existent alors...
if ( isset($accel) ){

    exec("sudo main.x $accel");

}
//Si on a pas pu utiliser ce qui a ete recu
else { echo ("fail"); }
?>
