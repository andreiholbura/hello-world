/*
  Controlare mbot din joystick

  Acest exemplu de program controleaza robotul cu ajutorul joystick-ului

  Folosim ca si hardware mBot si joystick

*/
//Includere librarii
#include "MeMCore.h"

//Definire constante
MeJoystick joystick(PORT_3);
MeDCMotor motorS(M1);
MeDCMotor motorD(M2);
MeIR ir;

//Definire variabile
int viteza = 150;
int x = 0;
int y = 0;

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
void control(){
  if (y > 10) {
    viteza = map(y, 0, 502, 0, 255);
    inainte(viteza);}
  if ( y < -10) {
    viteza = map(-y, 0, 475, 0, 255);
    inapoi(viteza);}
  if (x > 10) {
    viteza = map(x, 0, 490, 0, 255);
    dreapta(viteza);}
  if ( x < -10) {
    viteza = map(-x, 0, 487, 0, 255);
    stanga(viteza);}
  if (x > -10 && x < 10 && y > -10 && y < 10)
    oprire();
}
void setup() {
  // acest cod este executat o singura data la pornire
  Serial.begin(9600);
}


void loop() {
  //acest cod este executat si repetat la infinit
  x = joystick.readX()+3;
  y = joystick.readY()+15;
  Serial.print("X = ");
  Serial.print(x);
  Serial.print("  Y = ");
  Serial.println(y);
  delay(10);
  control();
}


