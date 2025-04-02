#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <StateMachine.h>
#include <Button.h>

// Définition des broches
#define PIN_LED 13
#define PIN_BOUTON 2

// Définition des délais
#define DELAI_ATTENTE 3000  // 3 secondes
#define DELAI_ACTION 5000   // 5 secondes

// Déclaration des variables globales (définies dans main.cpp)
extern StateMachine machine;
extern Button bouton;
extern unsigned long tempsDebut;

#endif
