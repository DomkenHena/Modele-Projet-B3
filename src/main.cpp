#include "config.h"
#include "etatInitial.h"
#include "etatAttente.h"
#include "etatAction.h"
#include "etatFinal.h"

// Définition des variables globales
StateMachine machine = StateMachine();
Button bouton(PIN_BOUTON);
unsigned long tempsDebut = 0;

void setup() {
  // Initialisation de la communication série
  Serial.begin(9600);
  Serial.println("Démarrage de la machine d'état");
  
  // Configuration des broches
  pinMode(PIN_LED, OUTPUT);
  // Pas besoin de configurer PIN_BOUTON car la librairie Button s'en charge
  
  // Configuration des états de la machine
  machine.addState(ETAT_INITIAL, &surEntreeEtatInitial, &pendantEtatInitial, NULL);
  machine.addState(ETAT_ATTENTE, &surEntreeEtatAttente, &pendantEtatAttente, NULL);
  machine.addState(ETAT_ACTION, &surEntreeEtatAction, &pendantEtatAction, NULL);
  machine.addState(ETAT_FINAL, &surEntreeEtatFinal, &pendantEtatFinal, NULL);
  
  // Démarrer la machine dans l'état initial
  machine.transitionTo(ETAT_INITIAL);
}

void loop() {
  // Mettre à jour la machine d'état
  machine.update();
  
  // Petit délai pour éviter une utilisation excessive du CPU
  delay(10);
}
