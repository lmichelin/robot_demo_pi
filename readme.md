## Présentation

Ce robot est capable d'écrire du texte automatiquement à la demande de l'utilisateur. Celui-ci lui transmet les ordres via un smartphone préalablement connecté en Wi-Fi au Raspberry Pi.
Il est également possible de piloter le robot via l'accéléromètre du smartphone.

## Prérequis

- Distribution : Raspbian
- Module I2C du kernel activé : https://www.google.fr/search?q=enable+i2c+raspberry
- librairie wiringpi : http://wiringpi.com/download-and-install/
- serveur Apache2 + php
- script create_ap pour le point d'accès Wi-Fi : https://github.com/oblique/create_ap
- libttspico-utils pour la synthèse vocale

## Configuration initiale

- Dans `/etc/network/interfaces` configurer `wlan0` comme suit :
```
allow-hotplug wlan0
```
- Configurer le fichier `/etc/create_ap.conf` comme suit :
```
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
- activer le service create_ap : `sudo systemctl enable create_ap` et `sudo systemctl start create_ap`
- Apache2 : créer un symlink `html -> home/pi/robot_demo_pi/html/` dans `/var/www/`
- exécuter `sudo visudo` et ajouter la ligne suivante pour autoriser www-data à exécuter les scripts :
```
www-data ALL=(ALL) NOPASSWD:/home/pi/robot_demo_pi/scripts/*.sh
```

## Première utilisation

- Compiler en exécutant `make`
- Sur le smartphone se rendre à l'adresse 10.0.1.1
