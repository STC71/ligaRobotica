/*	Este código enciende un LED RGB de forma aleatoria al presionar un botón.
	El LED RGB se conecta a los pines 9, 10 y 11 del Arduino.
	El botón se conecta al pin 3 del Arduino.
	Además, utiliza la función analogWrite() para establecer el brillo de cada 
	color del LED, representando así el color obtenido.
	El código utiliza una función para generar valores aleatorios para cada color del LED.
	En concreto utiliza la función randomSeed() para inicializar la semilla del 
	generador de números aleatorios utilizando una lectura analógica del pin 0.
	Esto asegura que los valores aleatorios generados sean diferentes mientras se
	ejecuta el programa.
	se ejecuta el programa.
	El código también utiliza la función Serial.println() para imprimir los valores 
	aleatorios generados en el monitor serial.
	El código utiliza la función delay() para mantener el LED encendido durante un 
	tiempo determinado (T).
	Del mismo modo, a la vez que se representan los colores eleatorios, el buzzer 
	conectado al mismo pin 9 del LED RGB se activa, emitiendo un sonido según el valor del color.	*/

const int RED = 11;
const int BLUE = 10;
const int GREEN = 9;
const int buttonApin = 3;
const int T = 1000;

void setup(){

	pinMode(RED, OUTPUT);
	pinMode(BLUE, OUTPUT);
	pinMode(GREEN, OUTPUT);
	randomSeed(analogRead(0));
  	pinMode(buttonApin, INPUT_PULLUP);
  	Serial.begin(9600);
}

void loop(){

	if (digitalRead(buttonApin) == LOW) {
		byte valorR = random(0, 256);
  		byte valorB = random(0, 256);
  		byte valorG = random(0, 256);
      
      	Serial.println(valorR);
      	Serial.println(valorB);
      	Serial.println(valorG);
      	Serial.println();
  
		analogWrite(RED, valorR);
		analogWrite(BLUE, valorB);
		analogWrite(GREEN, valorG);
  
		delay(T);
    }
	else{
		analogWrite(RED, 0);
		analogWrite(BLUE, 0);
		analogWrite(GREEN, 0);
    }

}