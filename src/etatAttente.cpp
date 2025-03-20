#include "etatAttente.h"

/**
 * Fonction exécutée lors de l'entrée dans l'état d'attente
 * Allume la LED et mémorise le temps de début
 * @param aucun
 * @return aucun
 */
void surEntreeEtatAttente() {
  Serial.println("Entrée dans l'ÉTAT ATTENTE");
  tempsDebut = millis();
  digitalWrite(PIN_LED, HIGH);
}

/**
 * Fonction exécutée pendant l'état d'attente
 * passe à l'état ACTION après 3 secondes
 * @param aucun
 * @return aucun
 */
void pendantEtatAttente() {
  // Mettre à jour l'état du bouton (même si on ne l'utilise pas dans cet état)
  bouton.read();
  
  // Vérifier si le délai est écoulé
  if (millis() - tempsDebut >= DELAI_ATTENTE) {
    machine.transitionTo(ETAT_ACTION);
  }
}
