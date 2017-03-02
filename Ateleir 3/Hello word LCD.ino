#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"
// Conectare prin i2c, la adresa prestabilita #0
Adafruit_LiquidCrystal lcd(0);

void setup() {
  // setarea numarului de randuri si coloane ale LCD-ului
  lcd.begin(16, 2);
  // aprinderea luminii
  lcd.setBacklight(HIGH);
  // afisarea mesajului pe LCD
  lcd.print("Hello World!");
}

void loop() {

}
  