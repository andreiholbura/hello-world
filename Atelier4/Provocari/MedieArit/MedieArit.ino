/*
  Determinarea mediei aritmetice in vector

  Vom declara un vector iar apoi vom calcula media aritmetica a valorilor

  Folosim ca si hardware un mBot si ecranul LCD

*/

//Includere librarii
#include <MeMCore.h>
#include <Adafruit_LiquidCrystal.h>
//Definire constante
Adafruit_LiquidCrystal lcd(0);
//Definire variabile
int vector[7] = {22, 33, 44, 55, 66, 77, 88};
int medie = 0;
int suma = 0;
int i = 0;
//Functii
void setup() {
  //acest cod este executat o singura data la pornire
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);

  for (i = 0; i < 7; i++) {
    suma += vector[i];
  }
  medie = suma / i;
  lcd.setCursor(0, 0);
  lcd.print("medie=");
  lcd.print(medie);
}


void loop() {
  //acest cod este executat si repetat la infinit

}
