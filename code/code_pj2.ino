#include <MKRWAN.h>
#include "DHT.h"

#define DHTPIN 2  
#define DHTTYPE DHT11
LoRaModem modem;
String appEui = "0000000000000000";
String appKey = "D4379CF960659806F75CB42B6312B0BE";
bool connected;
short con;
DHT dht(DHTPIN, DHTTYPE);

int soundPin = A1; // Broche de signal du capteur de bruit
int sampleWindow = 50; // Fenêtre d'échantillonnage en millisecondes
unsigned int sample;


void setup() {
 Serial.begin(115200);
 while (!Serial);
 //Serial.println("Welcome to MKR WAN 1300/1310 ");
 modem.begin(EU868);
 //Serial.println(F("DHTxx test!"));
 dht.begin();
 connected=false;
 if ( !connected ) {
 //Serial.print("Join test : ");
 //Serial.println(++con);
 int ret=modem.joinOTAA(appEui, appKey);
 if ( ret ) {
 connected=true;
 modem.minPollInterval(60);
 //Serial.println("Connected");
 modem.dataRate(5); // switch to SF7
 delay(100); // because ... more stable
 }
 }
 delay(1000); // apparently the murata dislike if this tempo is removed...
 con =0;

}
void loop() {
  if ( !connected ) {
 //Serial.print("Join test : ");
 //Serial.println(++con);
 int ret=modem.joinOTAA(appEui, appKey);
 if ( ret ) {
 connected=true;
 modem.minPollInterval(60);
 //Serial.println("Connected");
 modem.dataRate(5); // switch to SF7
 delay(100); // because ... more stable
 }
 }

 if ( connected ) {

  // Lecture capteur
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  
  unsigned long startMillis = millis(); // Début de la fenêtre d'échantillonnage
  unsigned int peakToPeak = 0; // Amplitude de crête à crête du signal

  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;

  // Échantillonnage du signal
  while (millis() - startMillis < sampleWindow) {
    sample = analogRead(soundPin);
    if (sample < 1024) {
      if (sample > signalMax) {
        signalMax = sample; // Mise à jour de la valeur maximale
      } else if (sample < signalMin) {
        signalMin = sample; // Mise à jour de la valeur minimale
      }
    }
  }
  peakToPeak = signalMax - signalMin; // Calcul de l'amplitude de crête à crête

  // Conversion en dB
  float value = (peakToPeak * 10.0) / 1024.0; // Conversion de la tension du signal en volts
  float dB = 20 * log10(value/0.001); // Conversion de la tension en dB

  // Conversion en short
  int16_t t_short = (int16_t)(t * 100);
  int16_t h_short = (int16_t)(h * 100);
  int16_t dB_short = (int16_t)(dB * 100);

  // Envoi LoRaWAN
  modem.beginPacket();
  modem.write((uint8_t*)&t_short, sizeof(t_short));
  modem.write((uint8_t*)&h_short, sizeof(h_short));
  modem.write((uint8_t*)&dB_short, sizeof(dB_short));
  modem.endPacket();

 /* // Affichage console
  Serial.print("Température : ");
  Serial.print(t, 2); // Affiche deux décimales
  Serial.print(" °C, Humidité : ");
  Serial.print(h, 2); // Affiche deux décimales
  Serial.print(" %");
  Serial.print(" Bruit : ");
  Serial.print(dB, 2); // Affiche deux décimales
  Serial.println(" dB");*/

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  delay(30000);
 }
 
 }

