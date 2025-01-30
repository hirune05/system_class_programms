#include "BluetoothSerial.h"
#define OUT_vol 25
#define IN_vol 32
BluetoothSerial SerialBT;

void setup() {
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.begin(115200);
  pinMode(OUT_vol, OUTPUT);
  pinMode(IN_vol,ANALOG);
}

void loop() {
  char c;
  dacWrite(OUT_vol,0);
  SerialBT.println(analogRead(IN_vol));
  delay(1000);
  dacWrite(OUT_vol,128);
  SerialBT.println(analogRead(IN_vol));
  delay(1000);
  dacWrite(OUT_vol,250);
  SerialBT.println(analogRead(IN_vol));
  delay(1000);
  }