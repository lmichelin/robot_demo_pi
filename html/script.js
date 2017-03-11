function action(){
  var phrase = document.getElementById("phrase").value;
  var request = new XMLHttpRequest();
	request.open("GET", "write.php?phrase=" + phrase);
	request.send(null);
  window.location.reload();
}
