# Monitoring_system_MMD

Projet Arduino pour la surveillance environnementale
Ce projet permet de surveiller l'environnement intérieur en mesurant la température, l'humidité, la pression atmosphérique, le niveau de CO2 et le niveau sonore.

Matériel nécessaire :
- Arduino MKR1310
- Capteur de température, humidité et pression BME280
- Capteur de CO2 COZIR-LP-5000
- Capteur sonore SEN0487
- Écran E-Ink 2,9"
- Panneau solaire avec ...
- Batterie 1000 mAh

Installation :

Installez l'IDE Arduino sur votre ordinateur si ce n'est pas déjà fait.
Branchez les capteurs et l'écran E-Ink sur les broches correspondantes de l'Arduino MKR1310.

Téléchargez et installez les bibliothèques nécessaires :
- Adafruit_Sensor.h
- Adafruit_BME280.h
- SparkFun_SCD30_Arduino_Library.h
- Adafruit_GFX.h
- Adafruit_EPD.h
- MKRWAN.h

Ouvrez le fichier surveillance_env.ino dans l'IDE Arduino.
Compilez et téléversez le code sur votre Arduino MKR1310.

Utilisation :

Le système mesure les données environnementales toutes les 5 secondes (plus longtemps la nuit pour économiser l'énergie) et affiche les valeurs sur l'écran E-Ink. Si le niveau de CO2 dépasse le seuil défini (1000 ppm), les données sont envoyées via LoRaWAN à un serveur distant pour être analysées.
Les données peuvent être visualisées sur un dashboard TTN ou une application mobile.

Optimisation de la consommation d'énergie : 

Pour maximiser la durée de vie de la batterie et minimiser la consommation d'énergie, le système utilise les techniques suivantes :

- Attente plus longue la nuit pour économiser de l'énergie
- Attente plus courte le jour pour réduire le temps de prise de mesure
- Mise en veille du capteur de CO2 lorsqu'il n'est pas utilisé
- Utilisation d'un écran E-Ink pour minimiser la consommation d'énergie
- Utilisation d'un panneau solaire pour recharger la batterie

Contribution :

Si vous souhaitez contribuer à ce projet, n'hésitez pas à envoyer des pull requests ou des issues sur GitHub.

Auteurs :

Malo N (neuville.malo@gmail.com)

Mael O-S (saugerm@gmail.com)

Dylan LG (dylan.leguilloux@gmail.com)
