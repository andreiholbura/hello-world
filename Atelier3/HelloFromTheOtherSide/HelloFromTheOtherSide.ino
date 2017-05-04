/*
  Hello from the other side.

  Acest exemplu de cod prin care robotul pe arata mesaje.

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
  // setarea numarului de randuri si coloane ale LCD-ului
  lcd.begin(16, 2);
  // aprinderea luminii
  lcd.setBacklight(HIGH);
  // afisarea mesajului pe LCD
  lcd.print("Hello World!");
}

void loop() {
  //acest cod este executat si repetat la infinit
}
