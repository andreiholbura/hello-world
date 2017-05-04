/*
  FSM + Comunnication

  Acest exemplu va combina FSM cu instructiuni primite prin bluetooth

  Folosim ca si hardware mBot, LCD telefon mobil

*/
//Includere librarii
#include <Adafruit_NeoPixel.h>
#include "MeMCore.h"
#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"
#include "String.h" //biblioteca String
Adafruit_LiquidCrystal lcd(0);
#define PIN            13
#define NUMPIXELS      2
//Definire constante
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
MeUltrasonicSensor senzorUltrasunete(PORT_3);
MeDCMotor stanga(M1);
MeDCMotor dreapta(M2);
//Definire variabile
int viteza = 150;
int distanta = 0;
String sir;
int citire;
int stare = 1;
//Functii
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
void setup() {
  // acest cod este executat o singura data la pornire
  // setarea numarului de randuri si coloane ale LCD-ului
  lcd.begin(16, 2);
  // aprinderea luminii
  lcd.setBacklight(HIGH);
  // deschiderea conexiunii seriale
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(115200);
  Serial.println("Start");
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  pixels.begin();
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  pixels.setPixelColor(1, pixels.Color(0, 0, 0));
  pixels.show();
}

void stare1() {
  pixels.setPixelColor(0, pixels.Color(150, 150, 0));
  pixels.setPixelColor(1, pixels.Color(150, 150, 0));
  pixels.show();
  oprire();
}

void stare2() {
  distanta = senzorUltrasunete.distanceCm();
  if (distanta < 20) {
    inapoi(viteza);
    delay(500);
    dreaptaD(viteza);
    delay(500);
    pixels.setPixelColor(0, pixels.Color(150, 0, 0));
    pixels.setPixelColor(1, pixels.Color(150, 0, 0));
    pixels.show();
  }
  else {
    inainte(viteza);
    pixels.setPixelColor(0, pixels.Color(0, 150, 0));
    pixels.setPixelColor(1, pixels.Color(0, 150, 0));
    pixels.show();
  }
}
void loop() {
  sir = "";
  while (Serial.available()) {
    delay(1);
    //Serial.write(mySerial.read());
    citire = Serial.read(); //citeste mesajul
    sir += char(citire);
  }
  if (sir == "start") {
    stare = 2;
  }
  if (sir == "stop") {
    stare = 1;
  }
  switch (stare) {
    case 1: stare1(); lcd.setCursor(0, 0); lcd.print("stare 1"); break;
    case 2: stare2(); lcd.setCursor(0, 0); lcd.print("stare 2"); break;
  }
}
