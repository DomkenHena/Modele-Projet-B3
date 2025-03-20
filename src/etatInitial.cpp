#include "etatInitial.h"

/**
 * Fonction exécutée lors de l'entrée dans l'état initial
 * éteint la LED
 * @param aucun
 * @return aucun
 */
void surEntreeEtatInitial() {
  Serial.println("Entrée dans l'ÉTAT INITIAL");
  digitalWrite(PIN_LED, LOW);
}

/**
 * Fonction exécutée pendant l'état initial
 * passe à l'état ATTENTE sur appui du bouton
 * @param aucun
 * @return aucun
 */
void pendantEtatInitial() {
  // Mettre à jour l'état du bouton
  bouton.read();
  
  // Vérifier si le bouton est pressé (utilisation de la librairie Button)
  if (bouton.wasPressed()) {
    Serial.println("Bouton pressé dans l'état initial");
    machine.transitionTo(ETAT_ATTENTE);
  }
}
