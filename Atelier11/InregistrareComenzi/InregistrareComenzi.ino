/*
  Inregistrare comenzi

  Acest exemplu de program salveaza in memoria eeprom un set de miscari citite la la joystick

  Folosim ca si hardware mBot si joystick

*/
//Includere librarii
#include "MeMCore.h"
#include <EEPROM.h>
//Definire constante
MeJoystick joystick(PORT_3);
MeDCMotor motorS(M1);
MeDCMotor motorD(M2);
//Definire variabile
int viteza = 150;
int eprom_cout = 1;
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
  motorD.run(0);
}
void stanga(int viteza) {
  motorS.run(0);
  motorD.run(viteza);
}
void stop() {
  motorS.run(0);
  motorD.run(0);
}
void miscari() {
  for (int x = 1; x <= 5; x++) {
    if (EEPROM.read(x) == 1) {
      inainte(150);
      delay(1000);
    }
    if (EEPROM.read(x) == 2) {
      inapoi(150);
      delay(1000);
    }
    if (EEPROM.read(x) == 3) {
      dreapta(150);
      delay(1000);
    }
    if (EEPROM.read(x) == 4) {
      stanga(150);
      delay(1000);
    }
  }
  stop();
}
void setup() {
  // acest cod este executat o singura data la pornire
  Serial.begin(9600);
  miscari();
}
void loop() {
  //acest cod este executat si repetat la infinit
  x = joystick.readX() + 4;
  y = joystick.readY() + 15;
  while (x < 100 && x > -100 && y < 100 && y > -100) {
    x = joystick.readX() + 4;
    y = joystick.readY() + 15;
  }
  Serial.print(x);
  Serial.print("    ");
  Serial.println(y);
  if (y > 10) {
    EEPROM.write(eprom_cout, 1); // inainte
    eprom_cout++;
    delay(10);
  }
  if ( y < -10) {
    EEPROM.write(eprom_cout, 2); //inapoi
    eprom_cout++;
    delay(10);
  }
  if (x > 10) {
    EEPROM.write(eprom_cout, 3); //dreapta
    eprom_cout++;
    delay(10);
  }
  if ( x < -10) {
    EEPROM.write(eprom_cout, 4); //Stanga
    eprom_cout++;
    delay(10);
  }
  EEPROM.write(0, eprom_cout);
  if (eprom_cout == 6)
    eprom_cout = 1;
  for (int x = 1; x < 6; x++) {
    int val = EEPROM.read(x);
    Serial.print(x);
    Serial.print("\t");
    Serial.println(val);
  }
  delay(1000);
}

