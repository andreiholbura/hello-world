/*
  Text Display

  Acest exemplu va afisa un mesaj centrat si apoi un mesaj pe fiecare linie

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
  // aprinderea luminii
  lcd.setBacklight(HIGH);
}

void loop() {
  //acest cod este executat si repetat la infinit
  lcd.setCursor(2, 0);
  lcd.print("Hello world!");
  delay(5000);
  lcd.setCursor(1, 1);
  lcd.print("inventeaza.ro");
  delay(5000);
  lcd.clear();
}
