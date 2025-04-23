/*	Este código muestra cómo usar un LCD1602 y un sensor de distancia HC-SR04
	El LCD1602 se conecta a los pines 4, 5, 6, 7, 8 y 9 del Arduino
	El sensor HC-SR04 se conecta a los pines 2 y 3 del Arduino
	El código muestra la distancia medida por el sensor en centímetros y pulgadas
	El LCD1602 se utiliza para mostrar la distancia medida por el sensor
	El sensor HC-SR04 se utiliza para medir la distancia a un objeto
	El código utiliza la librería LiquidCrystal para controlar el LCD1602
	Utiliza la función pulseIn() para medir el tiempo que tarda el 	sonido en ir
	y volver al sensor
	La fórmula DISTANCIA = DURACION / 58.2 para calcula la distancia
	La constante 58.2 es el tiempo que tarda el sonido en recorrer 1 cm
	El código utiliza la fórmula DISTANCIA / 2.54 para convertir la distancia a pulgadas
	Con la función Serial.print() para imprimir la distancia medida
	en el monitor serie
	El código utiliza la función lcd.print() para imprimir la distancia medida
	en el LCD1602
	La función lcd.setCursor() posiciona el cursor en el LCD
	El código utiliza la función delay() para esperar 500 ms entre cada medición	*/

#include <LiquidCrystal.h>

// instancia un objeto lcd de la clase LiquidCrystal :
LiquidCrystal lcd(4, 5, 6, 7, 8, 9);

// Se definen los pines a los que se conecta el sensor HC-SR04 :
// TRIG es el pin de disparo del sensor y ECHO es el pin de eco
byte TRIG = 2;
byte ECHO = 3;

// Se definen las variables para almacenar la duración entre el disparo
// y la recepción del eco y la distancia medida
// DURACION es el tiempo que tarda el sonido en ir y volver al sensor
// DISTANCIA es la distancia medida por el sensor atendiendo a la fórmula
// DISTANCIA = DURACION / 58.2
float DURACION;
float DISTANCIA;

void setup() {
  // configura el número de columnas y filas del LCD :
  lcd.begin(16, 2); lcd.print("Robotics");
  // configura el HC-SR04 :
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  // configura el monitor serie :
  Serial.begin(9600);
}

void loop() {
  // Se envía una señal high al prin TRIG para iniciar la medición
  digitalWrite(TRIG, HIGH);
  // Se espera un milisegundo para que el sensor se estabilice
  delay(1);
  // Se envía una señal low al pin TRIG para finalizar la medición
  digitalWrite(TRIG, LOW);
  // pulseIn() mide el tiempo que tarda el sonido en ir y volver al sensor
  // y se almacena el tiempo en la variable DURACION
  DURACION = pulseIn(ECHO, HIGH);
  // Se calcula la distancia medida por el sensor
  // atendiendo a la fórmula DISTANCIA = DURACION / 58.2

  // 52.2 es una constante especificada y equivale a la distancia en cm
  // que recorre el sonido en un segundo
  // Es la constante especificada por el fabricante del HC-SR04
  DISTANCIA = DURACION / 58.2;  
  // Se imprime la distancia medida en el monitor serie en cm y en pulgadas 
  lcd.setCursor(0, 0); lcd.print(DISTANCIA); lcd.print(" cms.");
  lcd.setCursor(0, 1); lcd.print(DISTANCIA / 2.54); lcd.print (" inc.");
  // Se imprime la distancia medida en el monitor serie en cm y en pulgadas 
  Serial.print("Distancia: ");
  Serial.print(DISTANCIA);
  Serial.print(" cms. ");
  Serial.print(DISTANCIA / 2.54);
  Serial.println(" inc.");
  // Se espera 500 ms entre cada medición para no saturar el monitor serie.
  delay(500);
}