/*
  Machine Learning robot

  Acest exemplu de program ajuta robotul sa invete singur cum sa ocoleasca un perete trecand
  cat mai aproape

  Folosim ca si hardware mBot si LCD

*/
//Includere librarii
#include <MeMCore.h>
#include "Wire.h"
#include <Adafruit_LiquidCrystal.h>

//Definire constante
MeDCMotor stanga(M1);
MeDCMotor dreapta(M2);
Adafruit_LiquidCrystal lcd(0);
MeUltrasonicSensor senzorUltrasunete(PORT_4);

//Definire variabile
int viteza = 100;
int distanta = 0;
int plecare = 50;
int invatare[20] = {100};
boolean perete = false;
int i = 0;
// Functii

void inainte(int s, int d) {
  stanga.run(-s);
  dreapta.run(d);
}
void oprire() {
  stanga.stop();
  dreapta.stop();
}
boolean buton() {
  delay(100);
  if (analogRead(7) < 10)
    return true;
  else return false;
}
void setup() {
  // acest cod este executat o singura data la pornire
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  lcd.setCursor(0, 0);
  pinMode(7, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  //acest cod este executat si repetat la infinit
  delay(100);
  distanta = senzorUltrasunete.distanceCm();
  Serial.println(distanta);
  while (distanta > 6 && perete == false) {
    inainte(viteza, invatare[i]);
    distanta = senzorUltrasunete.distanceCm();
    delay(100);
  }
  if ((distanta <= 6) && (distanta > 0) ) {
    oprire();
    perete = true;
  }
  if (buton()) {
    perete = false;
    i++;
    digitalWrite(13, LOW);
    invatare[i] = invatare[i - 1] - 10;
    lcd.setCursor(0, 0);
    lcd.print(invatare[i]);
  }
  distanta = senzorUltrasunete.distanceCm();
  if (distanta > 50) {
    oprire();
    digitalWrite(13, HIGH);
    perete = true;
  }
  Serial.println(distanta);
}
