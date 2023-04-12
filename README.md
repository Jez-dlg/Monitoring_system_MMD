# Monitoring_system_MMD
<Div Align=Justify>
Projet académique EI2I4 HF système de monitoring <br>
<dt>Ce projet permet de surveiller l'environnement intérieur en mesurant la température, l'humidité, la pression atmosphérique, le niveau de CO2 et le niveau sonore d'une salle de classe permettant d'alerter un gestionnaire si les taux deviennent trop élevés. </Div> <br>
  
<B> Matériel nécessaire : </B>
  
  - Arduino MKR1310 permettant une connexion LoraWan pour envoyer les données et les afficher en ligne sur Ubidots
  - Le capteur BME280 qui permet de récupérer la température, l'humidité et la pression atmosphérique
  - Le capteur de CO2 COZIR-LP-5000
  - Le capteur sonore SEN0487
  - Un écran E-Ink 2,9"
  - Deux panneaux solaires d'intérieur
  - Une batterie de 1000 mA

<B> Installation : </B>

<Div Align=Justify>Installez l'IDE Arduino sur votre ordinateur si ce n'est pas déjà fait. <br>
Créez un compte sur The Things Network (https://www.thethingsnetwork.org/) et Ubidots (https://ubidots.com/) <br>
Branchez les capteurs et l'écran E-Ink sur les broches correspondantes de l'Arduino MKR1310 en suivant le schéma suivant : </Div>

![github-small](https://github.com/Jez-dlg/Monitoring_system_MMD/blob/main/sche%CC%81ma%20elec/sche%CC%81ma%20electrique.jpg)

  <B>Téléchargez et installez les bibliothèques nécessaires sur Aduino IDE :</B>
  
- Wire.h
- SPI.h
- Adafruit_Sensor.h
- Adafruit_BME280.h
- Arduino.h
- cozir.h
- Adafruit_ThinkInk.h
- avr/dtostrf.h
- MKRWAN.h
- ArduinoLowPower.h

Ouvrez le fichier code_pj2.ino dans l'IDE Arduino. <br>
Compilez et téléversez le code sur votre Arduino MKR1310.

  <B>Utilisation :</B>

<Div Align=Justify>Le système mesure les données d'une salle de classe toutes les 10 minutes (la mesure se fait moins souvent la nuit pour économiser l'énergie) et affiche les valeurs sur l'écran E-Ink. Si le niveau de CO2 dépasse le seuil défini (2000 ppm) pendant 10 minutes, les données sont envoyées via LoRaWAN à un serveur distant pour être analysées. <br>
Les données peuvent être visualisées sur un dashboard Ubidots ou sur l'écran directement. </Div>

<br>
  <B>Optimisation de la consommation d'énergie :</B><br>
  
  Pour maximiser la durée de vie de la batterie et minimiser la consommation d'énergie, le système utilise les techniques suivantes :
  - Attente plus longue la nuit pour économiser de l'énergie
  - Attente plus courte le jour pour réduire le temps de prise de mesure
  - Mise en veille du capteur de CO2 lorsqu'il n'est pas utilisé
  - Utilisation d'un écran E-Ink pour minimiser la consommation d'énergie
  - Utilisation d'un panneau solaire pour recharger la batterie

  <B>Contribution :</B>

Si vous souhaitez contribuer à ce projet, n'hésitez pas à envoyer des pull requests ou des issues sur GitHub.

  <B>Auteurs :</B>

Malo N (neuville.malo@gmail.com)<br>
Mael O-S (saugerm@gmail.com)<br>
Dylan LG (dylan.leguilloux@gmail.com)

