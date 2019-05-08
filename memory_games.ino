#include "list.hpp"

LinkedList<int> ia;
bool buttonState0 = false;
bool buttonState1 = false;
bool buttonState2 = false;
bool buttonState3 = false;

void setup()
{
//  pinMode(A0, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  randomSeed(analogRead(0));
}

void wait_button(void)
{
  while (true) {
    if (digitalRead(A2) == HIGH) {
      buttonState0 = true;
      return;
    }
    else
      buttonState0 = false;
    if (digitalRead(A3) == HIGH) {
      buttonState1 = true;
      return;
    }
    else
      buttonState1 = false;
    if (digitalRead(A4) == HIGH) {
      buttonState2 = true;
      return;
    }
    else
      buttonState2 = false;
    if (digitalRead(A5) == HIGH) {
      buttonState3 = true;
      return;
    }
    else
      buttonState3 = false;
  }
}

bool check_input(int pin)
{
  if (pin == 10 && buttonState0 == true)
    return true;
  if (pin == 11 && buttonState1 == true)
    return true;
  if (pin == 12 && buttonState2 == true)
    return true;
  if (pin == 13 && buttonState3 == true)
    return true;
  return false;
}

void loop()
{
  ia.Append(random(10, 14));
  if(ia.moveToStart())
    do{
        wait_button();
        int button_ia = ia.getCurrent();
        if (check_input(button_ia) == false)
          puts("Cool");
    }while(ia.next());
}
