#include "BluetoothSerial.h"

#define IR_PIN 32  // 赤外線受信モジュールの出力ピン
#define LED_PIN 25 // LEDの接続ピン
#define MODULE_PIN 26 // MODULEピン

BluetoothSerial SerialBT;

void setup() {
  SerialBT.begin("IR_Detector");  // Bluetoothデバイス名を設定
  Serial.begin(115200);           // シリアル通信を初期化（デバッグ用）
  pinMode(IR_PIN, INPUT_PULLDOWN);  // 赤外線受信モジュールのピンを入力モードに設定
  pinMode(LED_PIN, OUTPUT);       // LEDのピンを出力モードに設定
  pinMode(MODULE_PIN, OUTPUT);    // MODULEピンを出力モードに設定

  digitalWrite(MODULE_PIN, HIGH); // GPIO26を3.3Vに設定
}

void loop() {
  int irState = digitalRead(IR_PIN);  // 赤外線受信モジュールの状態を読み取る

  if (irState == LOW) {
    // 赤外線が検知された場合
    digitalWrite(LED_PIN, HIGH);      // LEDを点灯
    SerialBT.println(1);              // Bluetooth経由で「1」を送信
    Serial.println("IR Detected: LOW (1)");  // シリアルモニタへ出力
  } else {
    // 赤外線が検知されていない場合
    digitalWrite(LED_PIN, LOW);       // LEDを消灯
    SerialBT.println(0);              // Bluetooth経由で「0」を送信
    Serial.println("IR Not Detected: HIGH (0)");  // シリアルモニタへ出力
  }

  delay(500);  // 500msごとに状態を確認
}
