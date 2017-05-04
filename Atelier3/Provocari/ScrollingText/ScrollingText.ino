/*
  Scrolling Text

  Acest exemplu va derula un text mai mare de 16 caractere.

  Folosim ca si hardware un mBot si LCD

*/
//Includere librarii
#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"
// Conectare prin i2c, la adresa prestabilita #0
Adafruit_LiquidCrystal lcd(0);

//Functii
void setup() {
  //acest cod este executat o singura data la pornire
  //setarea numarului de randuri si coloane ale LCD-ului
  lcd.begin(16, 2);
  // aprinderea luminii de fundal
  lcd.setBacklight(HIGH);
  lcd.print("academia inventeaza.ro");
}

void loop() {
  //acest cod este executat o singura data la pornire
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll catre stanga cu o pozitie
    lcd.scrollDisplayLeft();
    // asteapta un pic
    delay(350);
  }
}
