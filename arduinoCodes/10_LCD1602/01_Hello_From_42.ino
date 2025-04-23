#include <LiquidCrystal.h>

/*	Se crea una instancia de la librería LiquidCrystal
	Los parámetros son los pines a los que está conectado el LCD
	En este caso, se utilizan los pines 7, 8, 9, 10, 11 y 12
	Estos pines son los pines de control y datos del LCD	*/
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Variable para almacenar el tiempo de inicio
unsigned long startTime;

void setup() {
  // configura el número de columnas y filas del LCD
  lcd.begin(16, 2);
  // imprime un mensaje en el LCD.
  lcd.print("Hello From 42!");
}

void loop() {
  // Calcula los segundos transcurridos desde startTime
  unsigned long seconds = (millis() - startTime) / 1000;

  // Si los segundos llegan a 42, reinicia el conteo
  if (seconds > 42) {
    startTime = millis(); // Actualiza el tiempo de inicio
    seconds = 0; // Reinicia los segundos a 0
  }

  // Posiciona el cursor en columna 0, línea 1
  lcd.setCursor(0, 1);
  // Imprime el número de segundos
  lcd.print("Segundos: ");
  lcd.print(seconds);

  // Asegura que el resto de la línea se limpie (evita "basura")
  lcd.print("   ");
}