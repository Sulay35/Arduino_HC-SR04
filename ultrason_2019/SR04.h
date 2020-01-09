// déclaration du matériel :
#define echo_pin 5
#define trigger_pin 6

float temps_echo;

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
