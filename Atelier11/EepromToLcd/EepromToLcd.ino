/*
  Pastrare date

  Acest exemplu de program scrie in EEPROM o valoare si apoi afiseaza continutul EEPROM

  Folosim ca si hardware mBot si joystick

*/
//Includere librarii
#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"
#include <EEPROM.h>
//Definire constante
Adafruit_LiquidCrystal lcd(0);
//Definire variabile
int val = 3;
// Functii
void setup() {
  // acest cod este executat o singura data la pornire
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  for (int x = 0; x < 10; x++) {
    EEPROM.write(x, x);
  }
  lcd.setCursor(0, 0);
  for (int x = 0; x < 10; x++) {
    val = EEPROM.read(x);
    lcd.print(x);
    lcd.print(",");
    if (x == 7)
      lcd.setCursor(0, 1);
  }
}
void loop() {
  //acest cod este executat si repetat la infinit
}
