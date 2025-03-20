# Machine d'État - Projet Exemple

Ce projet pourra vous servir de base pour la programmation de vos véhicules autonomes. Il montre comment utiliser une machine d'état avec la librairie StateMachine et la gestion des boutons avec la librairie Button.

## Librairies utilisées

### StateMachine
La librairie StateMachine (https://github.com/jrullan/StateMachine) permet de créer facilement une machine d'état en définissant :
- Des états avec leurs fonctions associées (entrée, pendant, sortie)
- Des transitions entre ces états

### Button
La librairie Button (https://registry.platformio.org/libraries/mark170987/Button) offre une gestion avancée des boutons :
- Gestion automatique du debouncing
- Détection de différents événements (pression, relâchement, pression longue)
- Configuration automatique des pins en mode INPUT_PULLUP

Voici quelques exemples d'utilisation :
- `bouton.wasPressed()` : Détecte si le bouton vient d'être pressé
- `bouton.wasReleased()` : Détecte si le bouton vient d'être relâché
- `bouton.pressedFor(ms)` : Détecte si le bouton est maintenu enfoncé pendant une durée spécifique
- `bouton.releasedFor(ms)` : Détecte si le bouton est relâché pendant une durée spécifique

N'oubliez pas d'appeler `bouton.read()` régulièrement pour mettre à jour l'état du bouton.

## Fonctionnement de l'exemple

Cette machine d'état simple comporte quatre états :
1. **État Initial** : Attend qu'un bouton soit pressé
2. **État Attente** : Attend pendant 3 secondes (LED allumée)
3. **État Action** : Fait clignoter la LED pendant 5 secondes
4. **État Final** : Attend qu'un bouton soit pressé pour recommencer

## Structure du projet

Le projet suit la structure standard platformIO. LEs fichiers cpp, contenus dans le dossier src/ continent le code en lui même (gestion de la machine d'état, du bouton,...). Les fichiers h, contenus dans le dossier include/ contiennent les déclarations des fonctions et des variables utilisées dans le code.
Dans cette structure, chaque état du système a été intégré dans un fichier séparé, ce qui permet de mieux organiser le code et de faciliter la maintenance. Chaque fichier contient les fonctions spécifiques à l'état correspondant.
Voici une représentation de la structure du projet :

projet/
├── include/          # Fichiers d'en-tête (.h)
│   ├── config.h      # Configuration globale
│   ├── etatInitial.h
│   ├── etatAttente.h
│   ├── etatAction.h
│   └── etatFinal.h
├── src/              # Fichiers source (.cpp)
│   ├── main.cpp      # Fichier principal
│   ├── etatInitial.cpp
│   ├── etatAttente.cpp
│   ├── etatAction.cpp
│   └── etatFinal.cpp
├── platformio.ini    # Configuration PlatformIO et dépendances
└── README.md         # Documentation


## Configuration du projet

Le fichier `platformio.ini` doit inclure les dépendances suivantes :
```ini
lib_deps = 
    https://github.com/jrullan/StateMachine.git
    mark170987/Button@^1.0.0
