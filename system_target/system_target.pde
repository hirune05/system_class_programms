import processing.serial.*; // Serialライブラリのインポート
int count = 0;
 
Serial myPort; // シリアルポートオブジェクト
int x = 100; // シリアルデータの格納変数
int isShot; 
boolean isShotCountedFlag = false; // 連続して届いている信号は無視するためのフラグ
 
void setup() {
  size(800, 600);
  textSize(100);
  textAlign(CENTER, CENTER);
 
  // 利用可能なシリアルポートを表示
  printArray(Serial.list());
  String portName = "/dev/tty.22ESP32test";
  // シリアルポートを初期化
  myPort = new Serial(this, portName, 115200);
  print("Connected succeed!!");
  print(myPort);
}
 
void draw() {
  if (myPort.available() > 0) {
    String data = myPort.readStringUntil('\n');  // 改行で区切って受信
    if (data != null) {
      data = data.trim();  // 余計な空白や改行を削除
      println(data);

      isShot = int(data);  // 文字列を整数に変換

      background(255);
      fill(0);

      if (isShot == 1 && !isShotCountedFlag) {
        count++;
        isShotCountedFlag = true;
      }
      if (isShot == 0) {
        isShotCountedFlag = false;
      }
      text(count, width / 2, height / 2);
    }
  }
}
