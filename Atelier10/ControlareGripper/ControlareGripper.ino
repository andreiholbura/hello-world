/*
  Controlare gripper

  Prin acest exemplu vom crea functii de inchidere, deschidere si oprire gripper

  Folosim ca si hardware un mBot si gripper

*/
//Includere librarii
#include "MeMCore.h"

//Definire constante

//Definire variabile
int m1p1 = 11; // pe pinul D10 Mcore - IN2 driver
int m1p2 = 12; // pe pinul D11 Mcore - IN1 driver
// Functii
void inchide()
{
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW);
  delay(50);
}
void deschide()
{
  digitalWrite(m1p2, HIGH);
  digitalWrite(m1p1, LOW);
  delay(50);
}
void stai () {
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, LOW);
}
void setup() {
  // acest cod este executat o singura data la pornire
  pinMode(m1p1, OUTPUT);
  pinMode(m1p2, OUTPUT);
  Serial.begin(9600);
  deschide();
  delay(500);
}
void loop() {
  //acest cod este executat si repetat la infinit
  deschide();
  delay(1000);
  stai();
  delay(500);
  inchide();
  delay(1000);
  stai();
  delay(500);
}


