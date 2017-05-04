/*
  Parcurgerea Vectorilor

  Acest exemplu de cod exemplifica modul in care declaram un vector si cum in parcurgem pentru a extrage valorile din el

  Folosim ca si hardware un mBot si ecranul LCD

*/

//Includere librarii
#include <MeMCore.h>
#include <Adafruit_LiquidCrystal.h>
//Definire constante
Adafruit_LiquidCrystal lcd(0);
//Definire variabile
int vector[7] = {22, 33, 44, 55, 66,77,88};

//Functii
void setup() {
  //acest cod este executat o singura data la pornire
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  for (int i = 0; i < 7; i++) {
    lcd.print(vector[i]);
    lcd.print(",");
    delay(500);
  }
  //lcd.clear();

}

void loop() {
  //acest cod este executat si repetat la infinit

}