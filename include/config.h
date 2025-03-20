#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <StateMachine.h>
#include <Button.h>

// Définition des états
#define ETAT_INITIAL 0
#define ETAT_ATTENTE 1
#define ETAT_ACTION  2
#define ETAT_FINAL   3

// Définition des pins
#define PIN_BOUTON   2
#define PIN_LED      13

// Constantes de temps
#define DELAI_ATTENTE 3000 // 3 secondes
#define DELAI_ACTION 5000  // 5 secondes

// Variables globales (déclarées comme extern pour être utilisées dans plusieurs fichiers)
extern StateMachine machine;
extern Button bouton;
extern unsigned long tempsDebut;

#endif // CONFIG_H