/*
  Stocarea valorilor de la senzori in vectori

  Vom citi valorile indicate de senzorul de distanta, respectiv cel de lumina, iar apoi le vom stoca in cate un vector.

  Folosim ca si hardware un mBot si ecranul LCD

*/

//Includere librarii
#include <MeMCore.h>
#include <Adafruit_LiquidCrystal.h>
//Definire constante
Adafruit_LiquidCrystal lcd(0);
MeUltrasonicSensor senzorUltrasunete(PORT_3);
//Definire variabile
int lumina[3];
int distanta[3];
//Functii
void setup() {
  //acest cod este executat o singura data la pornire
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  pinMode(6, INPUT);
}

void loop() {
  //acest cod este executat si repetat la infinit
  for (int i = 0; i < 3; i++) {
    distanta[i] = senzorUltrasunete.distanceCm();
    delay(100);
  }
  lcd.setCursor(0, 0);
  for (int i = 0; i < 3; i++) {
    lcd.print(distanta[i]);
    lcd.print(",");
  }
  delay(500);
  for (int i = 0; i < 3; i++) {
    lumina[i] = analogRead(6);
  }
  lcd.setCursor(0, 1);
  for (int i = 0; i < 3; i++) {
    lcd.print(lumina[i]);
    lcd.print(",");
  }
  delay(500);
  lcd.clear();
}
