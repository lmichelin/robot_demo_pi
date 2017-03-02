import RPi.GPIO as GPIO
from time import sleep

#On ne veut pas d'avertissements dans le terminal lors de l'execution
GPIO.setwarnings(False)

#On prend le mode BCM de numerotation des pins i/o du Raspberry
GPIO.setmode(GPIO.BCM)

GPIO.setup(18, GPIO.OUT)

p = GPIO.PWM(18, 50)
p.start(50)
sleep(30)
