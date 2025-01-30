// 初回セットアップを実施する関数
void setup(){
  // Digital 7番ピンを入力に設定
  pinMode(7, INPUT);
  // シリアル通信の初期化
  Serial.begin(9600);
}

// メインループ
void loop(){
  // 7番ピンの入力がHIGHの場合は，「P」をシリアル通信に出力
  if(digitalRead(7) == HIGH) {
    Serial.print('P');
  }
  // 7番ピンの入力がLOWの場合は，「N」をシリアル通信に出力
  else {
    Serial.print('N');
  }
  delay(100);
}
