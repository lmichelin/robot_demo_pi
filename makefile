all: main battery command servo

main: #script principal pour écrire les lettres
	gcc -Wall main.c motor.c servo.c pid.c letters.c -o main.x -lwiringPi -lm

battery: #récupère la tension de la batterie
	gcc -Wall battery.c motor.c -o battery.x

command: #commande les moteurs dans le cas d'un pilotage par accéléromètre
	gcc -Wall command.c -o cmain.x

servo: #commande les servos dans le cas d'un pilotage par accéléromètre
	gcc -Wall moveservo.c servo.c -o smain.x -lwiringPi

clean:
	rm -f *.x
