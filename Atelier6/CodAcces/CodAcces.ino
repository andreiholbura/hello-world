/*
  Cod Acces

  Robotul sa poata fi controlat din telecomanda doar dupa introducerea unui cod de deblocare de pe telecomanda

  Folosim ca si hardware mBot si LCD

*/
//Includere librarii
#include <MeMCore.h>
#include "Wire.h"
#include <Adafruit_LiquidCrystal.h>
#include <Fsm.h>

//Definire constante
MeDCMotor stanga(M1);
MeDCMotor dreapta(M2);
MeIR ir;
#define PIN            13
#define NUMPIXELS      2
Adafruit_LiquidCrystal lcd(0);
MeUltrasonicSensor senzorUltrasunete(PORT_3);
//Definire variabile
int viteza = 150;
int distanta = 0;
int cod = 2;
int codCitit = 0;
uint32_t value = 0x00;
// State machine variables
#define comutare 1

State blocat(intrare_blocat, &iesire_blocat);
State deblocat(intrare_deblocat, &iesire_deblocat);
Fsm fsm(&deblocat);

// Functii
void inainte(int viteza) {
  stanga.run(-viteza);
  dreapta.run(viteza);
}
void inapoi(int viteza) {
  stanga.run(viteza);
  dreapta.run(-viteza);
}
void stangaD(int viteza) {
  stanga.stop();
  dreapta.run(viteza);
}
void dreaptaD(int viteza) {
  stanga.run(-viteza);
  dreapta.stop();
}
void oprire() {
  stanga.stop();
  dreapta.stop();
}
void miscare(uint32_t value) {
  switch (value) {
    case 0x40:  inainte(viteza); delay(100); break;
    case 0x19:  inapoi(viteza); delay(100); break;
    case 0x9: dreaptaD(viteza); delay(100); break;
    case 0x7: stangaD(viteza); delay(100); break;
    default: stanga.stop(); dreapta.run(0); break;
  }
}
void intrare_blocat()
{
  Serial.println("intrare in stare blocat");
  lcd.setCursor(0, 0);
  lcd.print("blocat");
}

void iesire_blocat()
{
  Serial.println("iesire din stare blocat");
  lcd.clear();
}

void intrare_deblocat()
{
  Serial.println("intrare in stare deblocat");
  lcd.print("deblocat");
}

void iesire_deblocat()
{
  Serial.println("iesire din stare deblocat");
  lcd.setCursor(0, 0);
  lcd.clear();
}

void tranzitie_blocat_deblocat()
{
  Serial.println("Tranzitie din stare blocat in stare deblocat");
}

void tranzitie_deblocat_blocat()
{
  Serial.println("Tranzitie din stare deblocat in stare blocat");
}

void setup()
{
  // acest cod este executat o singura data la pornire
  Serial.begin(9600);
  fsm.add_transition(&blocat, &deblocat,
                     comutare,
                     &tranzitie_blocat_deblocat);
  fsm.add_transition(&deblocat, &blocat,
                     comutare,
                     &tranzitie_deblocat_blocat);
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  lcd.setCursor(0, 0);
  ir.begin();
  fsm.trigger(comutare);
  while (codCitit != cod) {
    if (ir.decode()) {
      value = (ir.value >> 16) & 0xFF; //decode
      Serial.print("0x");
      Serial.println(value, HEX); //printare pe seriala in hexazecimal
      //  if (x == 1) {
      //    codCitit = 0;
      //   }
      switch (value) {
        case 0xC:  codCitit = 1; break; //tasta 1
        case 0x18: codCitit = 2; break; //tasta 2
        case 0x5E: codCitit = 3; break;  //tasta 3
        case 0x8:  codCitit = 4; break; //tasta 4
        case 0x1C: codCitit = 5; break;  //tasta 5
        case 0x5A: codCitit = 6; break;  //tasta 6
        case 0x42: codCitit = 7; break;  //tasta 7
        case 0x52: codCitit = 8; break;  //tasta 8
        case 0x4A: codCitit = 9; break;  //tasta 9
      }
    }
  }
  if (codCitit == cod)
    fsm.trigger(comutare);
  lcd.setCursor(0, 0);
  lcd.print("deblocat");
}

void loop()
{ //acest cod este executat si repetat la infinit
  if (ir.decode()) {
    value = (ir.value >> 16) & 0xFF; //decode
    Serial.print("0x");
    Serial.println(value, HEX); //printare pe seriala in hexazecimal
    if (value == 0x18) {
      fsm.trigger(comutare);
    }
  }
  else
    value = 0;
  miscare(value);
  lcd.setCursor(0, 0);
}
