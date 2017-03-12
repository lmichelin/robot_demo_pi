function action(){
  var phrase = document.getElementById("phrase").value;
  var taille = document.getElementById("taille").value;
  var request = new XMLHttpRequest();
	request.open("GET", "write.php?params=" + taille + " " + phrase);
	request.send(null);
  document.getElementById("phrase").value = "";
  document.getElementById("phrase").focus();
}
