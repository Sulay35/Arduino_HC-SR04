
#define bouton 3

boolean etat_bouton;

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
