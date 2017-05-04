/*
  Is anybody there?

  Vom aprinde un led verde cand nu avem obiect in fata, si afisam pe LCD: Starea 1
  Vom aprinde un led rosu cand avem un obiect in fata, si afisam pe LCD: Starea 2

  Folosim ca si hardware un mBot si ecranul LCD

*/
//Includere librarii
#include <MeMCore.h>
#include <Adafruit_LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>
#include <Fsm.h>

//Definire constante
#define PIN            13
#define NUMPIXELS      2
Adafruit_LiquidCrystal lcd(0);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
MeUltrasonicSensor senzorUltrasunete(PORT_3);
//Definire variabile
// State machine variables
#define comutare 1

State stare1(intrare_stare1, &iesire_stare1);
State stare2(intrare_stare2, &iesire_stare2);
Fsm fsm(&stare1);

// Functii
void intrare_stare1()
{
  Serial.println("intrare in stare 1");
  pixels.setPixelColor(1, pixels.Color(0, 150, 0));
  pixels.show();
  lcd.setCursor(0, 0);
  lcd.print("Starea 1");
}

void iesire_stare1()
{
  Serial.println("iesire din stare 1");
  pixels.setPixelColor(1, pixels.Color(0, 0, 0));
  pixels.show();
  lcd.setCursor(0, 0);
  lcd.clear();
}

void intrare_stare2()
{
  Serial.println("intrare in stare 2");
  pixels.setPixelColor(1, pixels.Color(150, 0, 0));
  pixels.show();
  lcd.setCursor(0, 0);
  lcd.print("Starea 2");
}

void iesire_stare2()
{
  Serial.println("iesire din stare 2");
  pixels.setPixelColor(1, pixels.Color(0, 0, 0));
  pixels.show();
  lcd.setCursor(0, 0);
  lcd.clear();
}

void tranzitie_stare1_stare2()
{
  Serial.println("Tranzitie din stare 1 in stare 2");
}

void tranzitie_stare2_stare1()
{
  Serial.println("Tranzitie din stare 2 in stare 1");
}

int citire_distanta() {
  int distanta = senzorUltrasunete.distanceCm();
  delay(100);
  if (distanta != 0)
    return distanta;
}
void setup()
{
  Serial.begin(9600);
  fsm.add_transition(&stare1, &stare2,
                     comutare,
                     &tranzitie_stare1_stare2);
  fsm.add_transition(&stare2, &stare1,
                     comutare,
                     &tranzitie_stare2_stare1);
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  pixels.begin();
  lcd.setCursor(0, 0);
}

void loop()
{
  //acest cod este executat si repetat la infinit
  if (citire_distanta() <= 30) {
    fsm.trigger(comutare);
    while (citire_distanta() <= 30) {
    }

  } else {
    fsm.trigger(comutare);
    while (citire_distanta() > 30 )  {
    }
  }
}
