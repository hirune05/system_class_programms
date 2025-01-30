#include "BluetoothSerial.h"
#define LED 32
BluetoothSerial SerialBT;

void setup() {
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  char c;

  if (SerialBT.available()) {
    c=SerialBT.read();

    if(c=='0'){
      SerialBT.println("LED OFF");
      digitalWrite(LED,LOW);
    }
    else if(c=='1'){
      SerialBT.println("LED ON");
      digitalWrite(LED,HIGH);
    }
  }
}