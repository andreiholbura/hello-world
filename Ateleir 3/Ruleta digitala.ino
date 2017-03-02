/*
  Ruleta digitala
 
  Acest exemplu de cod prin transformam robotul intr-o ruleta digitala

  Folosim ca si hardware mBot si LCD

*/
//Includere librarii
#include "MeMCore.h"
#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"
// Conectare prin i2c, la adresa prestabilita #0
Adafruit_LiquidCrystal lcd(0);

//Definire constante
MeUltrasonicSensor senzorUltrasunete(PORT_3);

//Definire variabile
int distanta = 0;

//Functii
void setup() {
  // acest cod este executat o singura data la pornire
  // setarea numarului de randuri si coloane ale LCD-ului
  lcd.begin(16, 2);
  // aprinderea luminii
  lcd.setBacklight(HIGH);
  // deschiderea conexiunii seriale
  Serial.begin(9600);
}

void loop() {
  //acest cod este executat si repetat la infinit
  distanta = senzorUltrasunete.distanceCm();
  lcd.setCursor(0, 0);
  lcd.print(distanta);
  lcd.setCursor(3, 0);
  lcd.print("Cm");
  delay(100);
  lcd.clear();
}