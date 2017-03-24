## Présentation

Ce robot est capable d'écrire du texte automatiquement à la demande de l'utilisateur. Celui-ci lui transmet les ordres via un smartphone préalablement connecté en Wi-Fi au Raspberry Pi.
Il est également possible de piloter le robot via l'accéléromètre du smartphone.

## Matériel & branchements

- Raspberry Pi utilisé : modèle 2B
- Carte moteur MD25 branchée aux pins SDA et SCL (GPIO 2 et 3) du Raspberry Pi
- Servo branché au Pin GPIO 4 du Raspberry Pi

## Prérequis

- Distribution : Raspbian Jessie Lite
- Module I2C du kernel activé : sudo raspi-config -> interfacing options
- librairie wiringpi : http://wiringpi.com/download-and-install/
- serveur Apache2 + php
- paquets hostapd et dnsmasq + script create_ap pour le point d'accès Wi-Fi : https://github.com/oblique/create_ap
- libttspico-utils pour la synthèse vocale

## Configuration initiale

- Dans `/etc/network/interfaces` configurer `wlan0` comme suit :
```
allow-hotplug wlan0
```
- Configurer le fichier `/etc/create_ap.conf` comme suit :
```bash
CHANNEL=default
GATEWAY=10.0.1.1
WPA_VERSION=2
ETC_HOSTS=0
DHCP_DNS=gateway
NO_DNS=0
HIDDEN=0
MAC_FILTER=0
MAC_FILTER_ACCEPT=/etc/hostapd/hostapd.accept
ISOLATE_CLIENTS=0
SHARE_METHOD=nat
IEEE80211N=0
IEEE80211AC=0
HT_CAPAB=[HT40+]
VHT_CAPAB=
DRIVER=nl80211
NO_VIRT=0
COUNTRY=
FREQ_BAND=2.4
NEW_MACADDR=
DAEMONIZE=0
NO_HAVEGED=0
WIFI_IFACE=wlan0
INTERNET_IFACE=eth0
SSID=ENSTAR :)
PASSPHRASE=robotique
USE_PSK=0
```
- activer le service create_ap : `sudo systemctl enable create_ap` (puis reboot)
- Apache2 : créer un symlink `html -> home/pi/robot_demo_pi/html/` dans `/var/www/`
- exécuter `sudo visudo` et ajouter la ligne suivante pour autoriser www-data à exécuter les scripts :
```
www-data ALL=(ALL) NOPASSWD:/home/pi/robot_demo_pi/scripts/*.sh
```

## Première utilisation

- Dans le dossier robot_demo_pi, compiler en exécutant `make`
- Sur le smartphone se rendre à l'adresse 10.0.1.1
