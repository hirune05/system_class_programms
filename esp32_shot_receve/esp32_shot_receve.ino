#include "BluetoothSerial.h"

#define BUILTIN_LED 2
#define LED_PIN 14 // LED接続ピン

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Receiver"); 
  Serial.println("The device started, now you can pair it with bluetooth!");

  // LEDピンを出力モードに設定
  pinMode(BUILTIN_LED, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  // Bluetooth接続完了サイン
  for (int i = 0; i < 3; i++) {
    digitalWrite(BUILTIN_LED, HIGH);
    delay(50);
    digitalWrite(BUILTIN_LED, LOW);
    delay(50);
  }
}

void loop() {
  if (SerialBT.available()) {
    char data = SerialBT.read(); // 1バイトのデータを受信

    if (data == '1') {
      digitalWrite(LED_PIN, HIGH); // LEDを点灯
    } else if (data == '0') {
      digitalWrite(LED_PIN, LOW); // LEDを消灯
    }
  }

  delay(20); // データの処理間隔
}
