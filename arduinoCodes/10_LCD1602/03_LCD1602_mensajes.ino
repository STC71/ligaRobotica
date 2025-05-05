#include <LiquidCrystal.h>

// instancia un objeto lcd de la clase LiquidCrystal :
LiquidCrystal lcd(4, 5, 6, 7, 8, 9);

String hel = "  HELLO WORLD!";
String f42 = " FROM 42 MALAGA";
String wlc = "WE LOVE CODE :)";
String up2 = "UP TO YOU :|";
String don = "DON´T PANIC :(";
String w42 = "WELLCOME 42";

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  printNormal();
  printBlink();
  printAutoscroll();
  printLeftRight();
  delay(1000);
}

void printNormal() {
  lcd.setCursor(0, 0);
  lcd.print(hel);
  delay(2000);
  lcd.setCursor(0, 1);
  lcd.print(f42);
  delay(2000);
  lcd.clear();
  delay(2000);
}
  
void printBlink() {
  lcd.blink();
  lcd.setCursor(0,0);
  for (int i = 0; i < wlc.length(); i++) {
    lcd.print(wlc.charAt(i));
    delay(250);
  }
  lcd.noBlink();
  delay(2000);
  lcd.clear();
}

void printAutoscroll() {
  lcd.setCursor(3, 0);
  for (int i = 0; i < up2.length(); i++) {
    lcd.print(up2.charAt(i));
    delay(400);
  }
  lcd.setCursor(16, 1);
  lcd.autoscroll();
  for (int i = 0; i < don.length(); i++) {
    lcd.print(don.charAt(i));
    delay(400);
  }
  lcd.noAutoscroll();
  delay(600);
  lcd.clear();
}

void printLeftRight() {
  lcd.setCursor(3,3);
  lcd.print(w42);
  for (int i = 0; i < 13; i++) {
    lcd.scrollDisplayLeft();
    delay(250);
  }
  for (int i = 0; i < 13; i++) {
    lcd.scrollDisplayRight();
    delay(250);
  }  
}