/*
  Sortarea Vectorilor

  Acest exemplu de cod exemplifica modul in care un vector poate fi sortat.

  Folosim ca si hardware un mBot si ecranul LCD

*/

//Includere librarii
#include <MeMCore.h>
#include <Adafruit_LiquidCrystal.h>
//Definire constante
Adafruit_LiquidCrystal lcd(0);
//Definire variabile
int vector[5] = {1, 0, 5, 7, 6};

//Functii
void setup() {
  //acest cod este executat o singura data la pornire
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  for (int i=0; i<4; i++)
  {
    for (int j=i+1; j<5; j++) {
      if(vector[i]>vector[j]){
        int temp = vector[i];
        vector[i]=vector[j];
        vector[j]=temp;
      }
    }
  }
  for (int i = 0; i < 5; i++) {
    lcd.print(vector[i]);
    lcd.print(",");
    delay(500);
  }
  //lcd.clear();

}

void loop() {
  //acest cod este executat si repetat la infinit

}
