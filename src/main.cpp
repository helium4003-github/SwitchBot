#include <Arduino.h>
#include "M5Atom.h"
#include "ESP32Servo.h"

Servo button;
//色指定用引数
int green = 0x00ff00;
int bule = 0x0000f0;
int red = 0xff0000;
int yellow = 0xfff000;
//調整用引数
uint32_t dly = 500;
int defult = 160;
int push = 180;
int pull = 140;

void Push(){
  M5.dis.drawpix(0, red);
  button.write(push);
  delay(dly);
  button.write(defult);
}

void Pull(){
  M5.dis.drawpix(0, red);
  button.write(pull);
  delay(dly);
  button.write(defult);
}

void setup() {
  M5.begin(true, false, true);
  M5.dis.drawpix(0, green);
  button.attach(25);
  button.write(defult);
}

void loop() {
  M5.update(); 
  M5.dis.drawpix(0, green);
  while(!M5.Btn.wasPressed()) {}
  Push();  
}
