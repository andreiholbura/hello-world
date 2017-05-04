/*
  Modificarea unui element dintr-un vector

  Acest exemplu de cod va cauta o valoare intr-un vector si daca o gaseste o va inlocui cu o alta valoare
  Cautam numarul 5 si il vom inlocui cu 25

  Folosim ca si hardware un mBot si ecranul LCD

*/

//Includere librarii
#include <MeMCore.h>
#include <Adafruit_LiquidCrystal.h>
//Definire constante
Adafruit_LiquidCrystal lcd(0);
//Definire variabile
int vector[5] = {23, 13, 5, 69, 45};
//Functii
void setup() {
  //acest cod este executat o singura data la pornire
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);

  for (int i = 0; i < 5; i++) {
    lcd.print(vector[i]);
    lcd.print(",");
    if (vector[i] == 5)
      vector[i] = 25;
  }
  delay(5000);
  lcd.clear();
  for (int i = 0; i < 5; i++) {
    lcd.print(vector[i]);
    lcd.print(",");
  }
}

void loop() {
  //acest cod este executat si repetat la infinit

}
