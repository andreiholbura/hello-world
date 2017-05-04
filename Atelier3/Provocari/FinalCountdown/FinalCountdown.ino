/*
  Final Countdown

  Acest exemplu afisarea in ordine descrescatoare a numerelor (de exemplu) de la 10 la 0 pe LCD

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
}

void loop() {
  //acest cod este executat si repetat la infinit
  for (int i = 10; i >= 0; i--) {
    lcd.begin(16, 2);
    lcd.print(i);
    delay(1000);
    lcd.clear();
  }
  lcd.print("timpul a expirat");
  delay(5000);
}
