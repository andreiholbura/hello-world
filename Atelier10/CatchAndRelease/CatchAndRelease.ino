/*
  Catch and Release

  Acest exemplu de program mentine robotul in cerc, cauta un obiect, il prinde cu gripper-ul
  si apoi il scoate afara din cerc

  Folosim ca si hardware mBot si gripper

*/
//Includere librarii
#include "MeMCore.h"
//Definire constante
MeUltrasonicSensor senzorUltrasunete(PORT_4);
MeLineFollower lineFinder(PORT_2);
MeDCMotor motorS(M1);
MeDCMotor motorD(M2);
MeIR ir;

//Definire variabile
int distanta = 0;
int ok = 0;
int viteza = 100;
int stare = 0;

// Functii
void inainte(int viteza) {
  motorS.run(-viteza);
  motorD.run(viteza);
}
void inapoi(int viteza) {
  motorS.run(viteza);
  motorD.run(-viteza);
}
void dreapta(int viteza) {
  motorS.run(-viteza);
  motorD.run(viteza / 10);
}
void stanga(int viteza) {
  motorS.run(-viteza / 10);
  motorD.run(viteza);
}
void oprire() {
  motorS.run(0);
  motorD.run(0);
}
uint32_t value = 0x00;
int m1p1 = 11; // pe pinul D10 Mcore - IN2 driver
int m1p2 = 12; // pe pinul D11 Mcore - IN1 driver
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

void lineFollower() {
  stare = lineFinder.readSensors();
  Serial.println(stare);
  switch (stare) {
    case 0: inainte(viteza); ok = 1; break;
    case 1: inainte(viteza); ok = 2; break;
    case 2: inainte(viteza); ok = 3; break;
    case 3: inapoi(100); delay(500); stanga(100); delay(1500);
      break;
  }
}
void setup() {
  // acest cod este executat o singura data la pornire
  pinMode(m1p1, OUTPUT);
  pinMode(m1p2, OUTPUT);
  ir.begin();
  Serial.begin(9600);
  deschide();
  delay(300);
  stai();
}


void loop() {
  //acest cod este executat si repetat la infinit
  lineFollower();
  distanta = senzorUltrasunete.distanceCm();
  // Serial.println(distanta);
  if (distanta < 7) {
    oprire();
    inchide();
    delay(700);
    stai();
    stare = lineFinder.readSensors();
    while (stare == 0) {
      inainte(viteza);
      stare = lineFinder.readSensors();
    }
    oprire();
    deschide();
    delay(800);
    stai();
  }
}


