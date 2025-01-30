#define TONE_USE_INT
#define TONE_PITCH 440
#include <TonePitch.h>
#include "BluetoothSerial.h"

#define BUILTIN_LED 2
#define BUTTON_PIN 14 // ボタン接続ピン（GPIO14に変更）
#define BUZER_PIN 25

BluetoothSerial SerialBT;

String MACadd = "08:D1:F9:36:F9:1A";  // MACアドレスを文字列として記述
uint8_t address[6] = {0x08, 0xD1, 0xF9, 0x36, 0xF9, 0x1A}; 
bool connected;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Sender", true); 
  Serial.println("The device started in master mode, make sure remote BT device is on!");

  // ボタンピンを入力モードに設定
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUILTIN_LED, OUTPUT);

  // Bluetooth接続
  connected = SerialBT.connect(address);
  if (connected) {
    Serial.println("Connected Successfully!");
  } else {
    while (!SerialBT.connected(10000)) {
      Serial.println("Failed to connect. Make sure remote device is available and in range, then restart app.");
    }
  }

  // Bluetooth接続完了サイン
  for (int i = 0; i < 3; i++) {
    digitalWrite(BUILTIN_LED, HIGH);
    delay(50);
    digitalWrite(BUILTIN_LED, LOW);
    delay(50);
  }
}

void loop() {
  // ボタンの状態を読み取る
  bool buttonPressed = digitalRead(BUTTON_PIN) == LOW; // LOWは押されている状態

  // データを送信
  if (buttonPressed) {
    SerialBT.write('1'); // ボタンが押された場合
    tone(BUZER_PIN, NOTE_C4);
    delay(500);
    noTone(BUZER_PIN);
  } else {
    SerialBT.write('0'); // ボタンが押されていない場合
    ledcWrite(0, 0); 
  }

  delay(50); // 少し待機して再度チェック
}
