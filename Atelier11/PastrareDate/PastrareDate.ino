/*
  Pastrare date

  Acest exemplu de program scrie in EEPROM o valoare si apoi afiseaza continutul EEPROM

  Folosim ca si hardware mBot si joystick

*/
//Includere librarii
#include <EEPROM.h>
//Definire variabile
int val = 3;
// Functii
void setup() {
  // acest cod este executat o singura data la pornire
  Serial.begin(9600);
  for (int x = 0; x < 10; x++) {
    EEPROM.write(x, val);
  }
  for (int x = 0; x < 100; x++) {
    val = EEPROM.read(x);
    Serial.print(x);
    Serial.print("\t");
    Serial.println(val);
  }
}
void loop() {
  //acest cod este executat si repetat la infinit
}
