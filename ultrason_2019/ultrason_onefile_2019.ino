// Credits : Sulaymane Dagnet
// email : sulaymane.dagnet@laposte.net
// 07/12/2019
//



// déclaration du matériel :
#define echo_pin 5
#define trigger_pin 6
#define bouton 3

// Déclaration de variable :
float temps_echo;
float temps_capture;
float d;

boolean etat_bouton;

// Déclaration des fonctions : 

float mesure_SR04(){

  // envoi du signal 1 sur trigger pendant 10µs
  digitalWrite(trigger_pin, LOW);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin,LOW);

  //Lecture du temps sur la broche echo :
  temps_echo = pulseIn(echo_pin, HIGH);//temps en microsecondes
  return temps_echo;
}

float calcul_distance(float temps){
  const float vitesse_son = 0.0340;//cm.µs-1 
  if( temps <  30000){
    float distance; 
    distance = (vitesse_son * temps )/2;
    //Serial.print(distance);
    return distance;
  }else{
    return 00;
  }
}

// fonctions bouton :

void attente_appui(){
  while(etat_bouton == 0){
    etat_bouton = digitalRead(bouton);
  }
}

void attente_relache(){
  while(etat_bouton == 1){
    etat_bouton = digitalRead(bouton);
  }
}

void lecture_bouton(){
  attente_appui();
  attente_relache();
}


void affichage_console(float valeur){
  Serial.print("la distance est de : ");
  Serial.print(valeur);
  Serial.println(" cm");
}

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
  delay(10);  
}
