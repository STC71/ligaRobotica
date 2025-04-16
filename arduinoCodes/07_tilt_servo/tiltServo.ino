//	Tilt Switch & Servo

#include <Servo.h>

byte TILT = 2;
byte SERV = 6;
byte LEDR = 4;
byte LEDG = 3;
byte BUZZ = 5;

Servo miservo;

void setup() {
  pinMode(TILT, INPUT_PULLUP);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDR, OUTPUT);
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDR, LOW);
  miservo.attach(SERV);
  pinMode(BUZZ, OUTPUT);
}
  
void loop() {
  int tilt = digitalRead(TILT);
  if (tilt == 0) {
   	miservo.write(i);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, HIGH);
    tone(BUZZ, 800, 200);
  	delay(300);
  	noTone(BUZZ);
  	delay(300);
  } 
  else {
    miservo.write(0);
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, HIGH);
    noTone(BUZZ);
  }
  delay(200);
}