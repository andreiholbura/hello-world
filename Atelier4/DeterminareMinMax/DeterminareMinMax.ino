/*
  Determinarea maximului si a minumului din vector

  Vom declara un vector iar apoi il vom parcurge si vom cauta cel mai mic si cel mai mare numar din vector. Iar la sfarsit afisam minimul si maximul  pe LCD.

  Folosim ca si hardware un mBot si ecranul LCD

*/

//Includere librarii
#include <MeMCore.h>
#include <Adafruit_LiquidCrystal.h>
//Definire constante
Adafruit_LiquidCrystal lcd(0);
//Definire variabile
int vector[7] = {22, 33, 44, 55, 66, 77, 88};
int maxim = 0;
int minim = 0;
//Functii
void setup() {
  //acest cod este executat o singura data la pornire
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  maxim = vector[0];
  minim = vector[0];
  for (int i = 0; i < 7; i++) {
    if (vector[i] > maxim)
      maxim = vector[i];
    else if (vector[i] < minim)
      minim = vector[i];
  }
  lcd.setCursor(0, 0);
  lcd.print("maxim=");
  lcd.print(maxim);
  lcd.setCursor(0, 1);
  lcd.print("minim=");
  lcd.print(minim);
}


void loop() {
  //acest cod este executat si repetat la infinit

}
