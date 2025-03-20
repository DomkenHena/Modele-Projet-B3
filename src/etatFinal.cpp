#include "etatFinal.h"

/**
 * Fonction exécutée lors de l'entrée dans l'état final
 * print de l'état et éteint la LED
 * @param aucun
 * @return aucun
 */
void surEntreeEtatFinal() {
  Serial.println("Entrée dans l'ÉTAT FINAL");
  digitalWrite(PIN_LED, LOW);
}

/**
 * Fonction exécutée pendant l'état final
 * Passage à l'état initial si le bouton est pressé.
 * Print de diverses fonctions avec le bouton.
 * @param aucun
 * @return aucun
 */
void pendantEtatFinal() {
  // Mettre à jour l'état du bouton
  bouton.read();
  
  // Attendre que le bouton soit pressé pour recommencer
  if (bouton.wasPressed()) {
    Serial.println("Bouton pressé dans l'état final");
    machine.transitionTo(ETAT_INITIAL);
  }
  
  // Exemple d'utilisation d'autres fonctionnalités de la librairie Button
  if (bouton.wasReleased()) {
    Serial.println("Bouton relâché dans l'état final");
  }
  
  if (bouton.pressedFor(2000)) {
    Serial.println("Bouton maintenu pendant 2 secondes dans l'état final");
  }
}
