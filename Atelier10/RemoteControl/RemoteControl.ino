/*
  Remote Control

  Acest exemplu deschide si inchide gripper-ul folosint tasta 1, respectiv 2 de pe telecomanda

  Folosim ca si hardware un mBot si gripper

*/
//Includere librarii
#include "MeMCore.h"

//Definire constante
MeIR ir;
//Definire variabile
uint32_t value = 0x00;
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
  ir.begin();
  Serial.begin(9600);
}
void loop() {
  //acest cod este executat si repetat la infinit
  if (ir.decode()) {
    value = (ir.value >> 16) & 0xFF; //decode
  } else value = 0;
  switch (value) {
    case 0xC:        // 1
      deschide();
      break;
    case 0x18:       // 2
      inchide();
      break;
    default:
      stai();
      break;
  }
}


