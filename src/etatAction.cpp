#include "etatAction.h"

/**
 * Fonction exécutée lors de l'entrée dans l'état d'action
 * print de l'état et éteint la LED
 * mémorise le temps d'entrée
 * @param aucun
 * @return aucun
 */
void surEntreeEtatAction() {
  Serial.println("Entrée dans l'ÉTAT ACTION");
  digitalWrite(PIN_LED, LOW);
  tempsDebut = millis();
}

/**
 * Fonction exécutée pendant l'état d'action
 * Clignottement rapide de la LED 
 * passe à l'état FINAL après 5 secondes
 * @param aucun
 * @return aucun
 */
void pendantEtatAction() {
  // Mettre à jour l'état du bouton (même si on ne l'utilise pas dans cet état)
  bouton.read();
  
  // Faire clignoter la LED rapidement
  digitalWrite(PIN_LED, (millis() / 100) % 2);
  
  // Après 5 secondes, passer à l'état final
  if (millis() - tempsDebut >= DELAI_ACTION) {
    machine.transitionTo(ETAT_FINAL);
  }
}
