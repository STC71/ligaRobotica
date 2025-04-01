/* 	Este código mostrara el parpadeo de SOS en Morse, basándose en tiempos 
	estándar: 
	puntos (on por 200ms, off por 200ms)
	rayas (on por 600ms, off por 200ms)
	con pausas de 600ms entre letras 
	y 1400ms al final antes de repetir.

	Si eliges el pin 13, ten en cuenta que este pin tiene un LED integrado en la placa de Arduino.
	Si lo usas, el LED parpadeará junto con el LED externo conectado al pin 13.
	Si no deseas que el LED integrado parpadee, puedes usar otro pin digital (por ejemplo, el pin 12 o 11)
	que no tenga un LED integrado o simplemente desconectar el LED externo y usar solo el LED integrado.
	Si decides usar otro pin, asegúrate de cambiar la constante P en el código para que coincida con el nuevo pin.

 	En esta versión todo el código está en el loop.	*/

const int T = 200;	// Tiempo base en milisegundos
const int P = 13; 	// Pin de salida, puedes cambiarlo a otro pin si lo deseas
 
void setup() { 
	pinMode(P, OUTPUT); 		// Configura el pin elegido como salida 
} 
 
void loop() { 
	// Envía S: tres puntos 
	digitalWrite(P, HIGH); 
	delay(T);					// On por 200ms 
	digitalWrite(P, LOW); 
	delay(T); 					// Off por 200ms 
	digitalWrite(P, HIGH); 
	delay(T); 
	digitalWrite(P, LOW); 
	delay(T); 
	digitalWrite(P, HIGH); 
	delay(T); 
	digitalWrite(P, LOW); 
	delay(3 * T); 				// Pausa entre S y O (600ms) 
 
	// Envía O: tres rayas 
	digitalWrite(P, HIGH); 
	delay(3 * T); 				// On por 600ms 
	digitalWrite(P, LOW); 
	delay(T); 					// Off por 200ms 
	digitalWrite(P, HIGH); 
	delay(3 * T); 
	digitalWrite(P, LOW); 
	delay(T); 
	digitalWrite(P, HIGH); 
	delay(3 * T); 
	digitalWrite(P, LOW); 
	delay(3 * T); 				// Pausa entre O y S (600ms) 
 
	// Envía S nuevamente: tres puntos 
	digitalWrite(P, HIGH); 
	delay(T); 
	digitalWrite(P, LOW); 
	delay(T); 
	digitalWrite(P, HIGH); 
	delay(T); 
	digitalWrite(P, LOW); 
	delay(T); 
	digitalWrite(P, HIGH); 
	delay(T); 
	digitalWrite(P, LOW);

	delay(7 * T); 				// Pausa al final (1400ms) 
	// Y repite el ciclo...
} 

// Fin del código
