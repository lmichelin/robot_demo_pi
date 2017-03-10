var bouton_valider = document.getElementById("bouton_valider");
        

function write(){
        //Requete vers la page php
	var request = new XMLHttpRequest();
	request.open( "GET" , "write.php");
	request.send(null);

        //Reception de la valeur de connexion
        request.onreadystatechange = function () {

            document.getElementById("texteRoues").innerHTML=request.responseText;
        }
}



//valider
bouton_valider.addEventListener("click", function () { write(); } );
