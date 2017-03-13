function action(){
  var phrase = document.getElementById("phrase").value;
  var taille = document.getElementById("taille").value;
  var request = new XMLHttpRequest();
	request.open("GET", "write.php?params=" + taille + " " + phrase);
	request.send(null);
  document.getElementById("phrase").value = "";
  document.getElementById("phrase").focus();
}

function batteryUpdate(){
  document.getElementById("battery").innerHTML = "";
  var battery = new XMLHttpRequest();
  battery.onreadystatechange = function() {
    if (battery.readyState == 4) {
      document.getElementById("battery").innerHTML = battery.response;
    }
  }
  battery.open("GET", "battery.php");
  battery.send(null);
  document.getElementById("phrase").focus();
}
