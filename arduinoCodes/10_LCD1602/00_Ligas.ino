#include <LiquidCrystal.h>

// instancia un objeto lcd de la clase LiquidCrystal :
LiquidCrystal lcd(4, 5, 6, 7, 8, 9);

String hel = "  HELLO WORLD!";
String f42 = " FROM 42 MALAGA";
String wlc = "WE LOVE CODE :)";
String up2 = "AP TO YOU :|";
String don = "DON´T PANIC :(";
String w42 = "WELLCOME 42";

byte bot[8] = {
  0b01110,
  0b01110,
  0b00100,
  0b11111,
  0b00100,
  0b00100,
  0b01010,
  0b10001
};

byte S1[8] = {
  0b00000,
  0b00000,
  0b00011,
  0b00100,
  0b01000,
  0b01000,
  0b10000,
  0b10000
};  

byte S2[8] = {
  0b00000,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b11011,
  0b11011,
  0b11011
};  

byte S3[8] = {
  0b00000,
  0b00000,
  0b11000,
  0b00100,
  0b00010,
  0b00010,
  0b00001,
  0b00001
}; 

byte S4[8] = {
  0b10000,
  0b10010,
  0b01001,
  0b01000,
  0b00100,
  0b00011,
  0b00000
};

byte S5[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b00000,
  0b00000,
  0b11111
};

byte S6[8] = {
  0b00001,
  0b01001,
  0b10010,
  0b00010,
  0b00100,
  0b11000,
  0b00000
};

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  
  lcd.createChar(0,bot);
  
    // create a new character
  lcd.createChar(1,S1);
  // create a new character
  lcd.createChar(2,S2);
  // create a new character
  lcd.createChar(3,S3);
    // create a new character
  lcd.createChar(4,S4);
  // create a new character
  lcd.createChar(5,S5);
  // create a new character
  lcd.createChar(6,S6);
  
}

void loop() {
  printBot();
  printNormal();
  printAnimation();
  printBlink();
  printBot();
  printAutoscroll();
  printAnimation();
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

void printBot () {
  lcd.setCursor(0, 0);
  lcd.write(byte(0)); 
  delay(100);
  for (int j=0;j<2;j++) {
    if (j == 0) {
   		for (int i=0;i<16;i++) {
       		lcd.setCursor(i, j);
       		lcd.write(byte(0));
          	delay(100);
        }
     }
     else {
        for (int i=16;i>=0;i--) {
       		lcd.setCursor(i, j);
       		lcd.write(byte(0));
          	delay(100);
        }
     }
  }
  lcd.clear();
  delay(500);
}

void printAnimation () {// animación
// set the cursor to the top left
  for (int i = 0; i <= 16; i = i + 4) {
  	lcd.setCursor(i, 0);
  	lcd.write(byte(1)); 
  	lcd.write((byte)2); 
  	lcd.write((byte)3); 
  	lcd.setCursor(i, 1);
  	lcd.write((byte)4); 
  	lcd.write((byte)5); 
  	lcd.write((byte)6);
    delay(500);
    lcd.clear();
  }
  // set the cursor to the top right
  for (int i = 16; i >= 0; i = i - 4) {
  	lcd.setCursor(i, 0);
  	lcd.write(byte(1)); 
  	lcd.write((byte)2); 
  	lcd.write((byte)3); 
  	lcd.setCursor(i, 1);
  	lcd.write((byte)4); 
  	lcd.write((byte)5); 
  	lcd.write((byte)6);
    delay(500);
    lcd.clear();
  }
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