function action(){
  playtext("à vos ordres, c’est parti !");
  var phrase = document.getElementById("phrase").value;
  var taille = document.getElementById("taille").value;
  var request = new XMLHttpRequest();
  if (document.getElementById("buttonAction").innerHTML == "Action !!") {
    request.onreadystatechange = function() {
      if (request.readyState == 4) {
        document.getElementById("buttonAction").className = "btn btn-success btn-lg";
        document.getElementById("buttonAction").innerHTML = "Action !!";
        batteryUpdate();
        playsound("tada.mp3");
      }
    }
  	request.open("GET", "script.php?letters=" + taille + " " + phrase);
  	request.send(null);
    document.getElementById("buttonAction").className = "btn btn-danger btn-lg";
    document.getElementById("buttonAction").innerHTML = "Stop";
    document.getElementById("phrase").value = "";
    document.getElementById("phrase").focus();
  }
  else if (document.getElementById("buttonAction").innerHTML == "Stop") {
  	request.open("GET", "script.php?stop");
  	request.send(null);
    document.getElementById("phrase").value = "";
    document.getElementById("phrase").focus();
  }
}

function batteryUpdate(){
  //document.getElementById("battery").innerHTML = "";
  var battery = new XMLHttpRequest();
  battery.onreadystatechange = function() {
    if (battery.readyState == 4) {
      document.getElementById("battery").innerHTML = battery.response;
    }
  }
  battery.open("GET", "script.php?battery");
  battery.send(null);
  document.getElementById("phrase").focus();
}

function shutdown(){
  if (confirm("Voulez-vous vraiment éteindre le Raspberry Pi ?"))
  {
    document.getElementById("shutdownButton").innerHTML = "Ordre d'arrêt envoyé, arrêt en cours...";
    var request = new XMLHttpRequest();
    request.open("GET", "script.php?arret");
  	request.send(null);
  }
}

function playtext(text)
{
  var request = new XMLHttpRequest();
  request.open("GET", "script.php?text=" + text);
  request.send(null);
}

function playsound(sound)
{
  var request = new XMLHttpRequest();
  request.open("GET", "script.php?sound=" + sound);
  request.send(null);
}
