// the number of the LED pin
const int ledPin = 14;  // 14 corresponds to GPIO14

// setting PWM properties
const int freq = 5000;
const int resolution = 8;
 
void setup(){
  // configure LED PWM
  ledcAttach(ledPin, freq, resolution);
  
  // if you want to attach a specific channel, use the following instead
  //ledcAttachChannel(ledPin, freq, resolution, 0);
}
 
void loop(){
  // increase the LED brightness
  ledcWrite(ledPin, 255);

  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(ledPin, dutyCycle);   
    delay(15);
  }
}
