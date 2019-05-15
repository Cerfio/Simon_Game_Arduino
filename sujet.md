# Jeu du Simon

Durée : **Une après-midi**

Auteurs : **Cerfio** && **Zuma**

## Introduction

Bienvenue au **Coding Club**, aujourd'hui nous vous proposons de programmer en Arduino. Si vous avez un problème durant la séance appelez un Cobra !. ***N'hésitez surtout pas !!!***

### L'arduino

![Logo Arduino](https://cdn.iconscout.com/icon/free/png-256/arduino-4-569256.png)

Faire une brève présentation de l'arduino

### Séance d’Aujourd’hui

Le but de la séance d’aujourd’hui est de réaliser un jeu du Simon en Arduino.

# Introduction
## L'Arduino
L'Arduino, qu'est-ce que c'est ?

Une carte Arduino est une carte équipée d'un micro-contrôleur, d'entrées et de sorties.
Son micro-contrôleur est capable de lancer un programme écrit par l'utilisateur afin de gérer les entrées et les sorties de la carte.

## Au programme
Qu'allons-nous faire dans l'heure qui suit ?

Afin de découvrir l'Arduino, nous allons effectuer un montage électronique et un programme simple qui formeront un jeu du Simon.

## Règles du jeu du Simon
Le but du jeu est très simple, il faut être reproduire la séquence lumineuse en appuyant sur les bouttons.

<!-- TODO : ajout éventuel d'un exemple vidéo. -->

## 2. Environnement de travail
Ouvrez le logiciel Arduino.

> Le logiciel vous demandera si vous souhaitez créer un dossier de travail → répondez oui.

> Les Cobras vont vous montrer comment envoyer le code vers la carte Arduino. En cas de blocage, appelez les sans hésiter.

Durant toute la session vous utiliserez cette classe `Button` que vous mettrez tout en haut de votre code, elle vous permettra de savoir si vous avez appuyer sur votre boutton.

```c++
#define ISPRESSED 2
#define ISRELEASED 3
#define PRESSED true
#define UNPRESSED false

class Button {
    private:
        bool _state;
        uint8_t _pin;

    public:
        bool is_pressed;
        Button(uint8_t pin) : _pin(pin) {}

        void begin() {
            pinMode(_pin, INPUT_PULLUP);
            _state = digitalRead(_pin);
        }

        int StateButton() {
            bool v = digitalRead(_pin);
            if (v != _state) {
                _state = v;
                if (_state) {
                    is_pressed = PRESSED;
                    return ISRELEASED;
                }
                else {
                  is_pressed = PRESSED;
                  return ISPRESSED;
                }
            }
            is_pressed = UNPRESSED;
            return UNPRESSED;
        }
};
```

## 3. Allumer et éteindre une LED

Pour cette première partie, je vous propose de comprendre comment fonctionnent les bouttons.

Vous devrez donc allumer une led dès lors que vous appuyez sur le boutton.

<!-- Mettre une image du premier montage ici-->

```c++
Button myButton(3); 

void setup() {
    pinMode(11, OUTPUT);
    myButton.begin();
    Serial.begin(9600);
}
```

Je vous suggère de copier coller le code de la fonction `setup()`.
Ici la fonction setup initialisera la pin numéro 3 de la carte arduino, c'est à dire que nous pourrons détecter la pression du boutton.

```c++
pinMode(11, OUTPUT);
```

Permet de définir la pin en tant qu'émettrice d'énergie, les deux autres lignes quand à elle ne servent qu'à l'initialisation.

Vous devrez donc coder le code qui permettra de d'allumer la LED dès lors que vous appuyer sur le boutton.

Dès que vous bloquez n'hésitez pas à appeller un cobra, il sera capable de vous débloquer, et il pourra vous aider à avancer.
Si vous bloquez, mais que vous n'avez toujours pas appeller un Cobra, appellez en un.

## Le jeu du Simon
Maintenant que vous avez compris que nous pouvons allumer une led, en appuyant sur un boutton, nous allons coder un jeu du Simon.

Vous ne savez pas ce que c'est ? Pas de problème voici une 
<a href="https://www.youtube.com/watch?time_continue=9&v=4YhVyt4q5HI"> vidéo du jeu du Simon</a>

### Préliminaires
Vous devrez donc utiliser la classe boutton