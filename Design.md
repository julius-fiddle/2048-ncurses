# 2048 in der Konsole

Steffen Fischer und Julius Thomas

--- 

## Leistungsmermale

* Funktionierendes Spielfeld (W1) ✔
* Input via WASD oder Pfeiltasten (W1) ✔
* Zuglogik (W1) ✔
* Additionsregeln ✔
* Zahlengenerator ✔
* Gewinnbedingung (Muss nicht)
* Verlustbedingung ✔
* Scoreboard ✔
* Design/UI ✔...
* (Selbstpielender Bot)
* (Animationen)


## Design

1. Game-Loop ✔, IO ✔, Game-Over ✔.
2. Steuerung (Input -> Bewegung), Speilzug (Bewegung -> Zug), Gewinn (Spielfeld -> Abbruchbedingung)
3. Spiel-Array (int).

## Notes


NCurses Bibliothek

#include ncurses


https://de.wikibooks.org/wiki/Ncurses:_Einleitung


