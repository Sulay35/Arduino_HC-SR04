// Credits : Sulaymane Dagnet
// email : sulaymane.dagnet@laposte.net
// 07/12/2019

// Fichiers externes
#include "bouto.h"
#include "SR04.h"
#include "affichage.h"

// Déclaration de variable :

float temps_capture;
float d;

void setup() {
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  
  pinMode(bouton, INPUT);
  etat_bouton = 0;

  Serial.begin(9600);
}

void loop() {
  
  lecture_bouton();
  
  temps_capture = mesure_SR04();
  d = calcul_distance(temps_capture);
  affichage_console(d);
 // delay(10);
}
