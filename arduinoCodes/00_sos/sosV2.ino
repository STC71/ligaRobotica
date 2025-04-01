/*	Este código mostrara el parpadeo de SOS en Morse, basándose en tiempos 
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

 	En esta versión, el código está dividido en funciones para enviar puntos y rayas,
	y funciones específicas para enviar la letra S y O en Morse.
	Esto hace que el código sea más modular y fácil de entender.	*/

const int T = 200; 			// Tiempo base en milisegundos 
const int P = 13; 			// Pin de salida, puedes cambiarlo a otro pin si lo deseas
 
void setup() { 
	pinMode(P, OUTPUT);		//	pin P como salida (LED integrado) 
} 
 
void loop() { 
	sendS(); 				// Envía la letra S 
	delay(3 * T); 			// Pausa entre S y O (600ms) 
	sendO(); 				// Envía la letra O 
	delay(3 * T); 			// Pausa entre O y S (600ms) 
	sendS(); 				// Envía la letra S nuevamente 
	delay(7 * T); 			// Pausa al final de la palabra (1400ms) 
} 
 
void sendDot() { 
	digitalWrite(P, HIGH); 	// Enciende el LED 
	delay(T); 				// Mantiene encendido por 200ms 
	digitalWrite(P, LOW); 	// Apaga el LED 
} 
 
void sendDash() { 
	digitalWrite(P, HIGH); 	// Enciende el LED 
	delay(3 * T); 			// Mantiene encendido por 600ms 
	digitalWrite(P, LOW); 	// Apaga el LED 
} 
 
void sendS() { 
	sendDot(); 				// Primer punto 
	delay(T); 				// Pausa de 200ms entre puntos 
	sendDot(); 				// Segundo punto 
	delay(T); 				// Pausa de 200ms 
	sendDot(); 				// Tercer punto 
} 
 
void sendO() { 
	sendDash(); 			// Primera raya 
	delay(T); 				// Pausa de 200ms entre rayas 
	sendDash(); 			// Segunda raya 
	delay(T); 				// Pausa de 200ms 
	sendDash(); 			// Tercera raya 
} 
