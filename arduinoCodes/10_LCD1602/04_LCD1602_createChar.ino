#include <LiquidCrystal.h>

// instancia un objeto lcd de la clase LiquidCrystal :
LiquidCrystal lcd(4, 5, 6, 7, 8, 9);

// Definicion de un caracter personalizado
// El caracter es un bot (robot) de 8x8
// En lugar de bot se puede poner cualquier nombre
// Se define el caracter como un array de 8 bytes
// Cada byte representa una fila del caracter
// Cada bit del byte representa un pixel del caracter
// 1 = pixel encendido - 0 = pixel apagado
// El caracter se almacena en la memoria de caracteres personalizados del LCD
// Se puede almacenar hasta 8 caracteres personalizados
// Se pueden usar los caracteres personalizados en el LCD como si fueran caracteres normales
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

void setup() {
  // Inicializa el LCD con el numero de columnas y filas
  lcd.begin(16, 2);
  // Se inicializa la comunicacion serie
  Serial.begin(9600); 
  // Se inicializa el caracter personalizado
  // 0 = posicion en la memoria de caracteres personalizados del LCD
  // bot = nombre del array que contiene el caracter
  lcd.createChar(0,bot);
  lcd.clear();
  delay(2000);
}

void loop() {
  // Se pone el cursor en la posicion (0,0)
  lcd.setCursor(0, 0);
  // Se imprime el caracter personalizado en la posicion (0,0)
  // byte(0) = posicion en la memoria de caracteres personalizados del LCD
  // Si hubiera mas de un caracter personalizado se puede usar byte(1), byte(2), etc.
  // Hasta un maximo de 8 caracteres personalizados
  lcd.write(byte(0)); 
  delay(6000);
  for (int j=0;j<2;j++) {
   for (int i=0;i<16;i++){
       lcd.setCursor(i, j);
       lcd.write(byte(0)); 
       delay(100);
   }
  }
}