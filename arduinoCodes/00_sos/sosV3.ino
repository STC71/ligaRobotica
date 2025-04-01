/*	Este código mostrara el parpadeo de SOS en Morse, basándose en tiempos 
	estándar: 
	puntos (on por 200ms, off por 200ms)
	rayas (on por 600ms, off por 200ms)
	con pausas de 600ms entre letras 
	y 1400ms al final antes de repetir.

	Si eliges el pin P, ten en cuenta que este pin tiene un LED integrado en la placa de Arduino.
	Si lo usas, el LED parpadeará junto con el LED externo conectado al pin P.
	Si no deseas que el LED integrado parpadee, puedes usar otro pin digital (por ejemplo, el pin 12 o 11)
	que no tenga un LED integrado o simplemente desconectar el LED externo y usar solo el LED integrado.
	Si decides usar otro pin, asegúrate de cambiar la constante P en el código para que coincida con el nuevo pin.

 	En esta versión se ha añadido un array de letras en código Morse para enviar SOS.
 	Esto hace que el código sea más modular y fácil de entender.
 	Además, se ha añadido una función para enviar letras en código Morse, lo que permite enviar
 	cualquier letra en el futuro si se desea.
 	Esta versión es más flexible y permite enviar letras en código Morse de manera más sencilla.	*/


const int T = 200; 								// Tiempo base en milisegundos
const int P = 13; 								// Pin de salida, puedes cambiarlo a otro pin si lo deseas
const char* letters[] = {"...", "---", "..."}; 	// Código Morse para S, O, S 
const int numLetters = 3; 
 
void setup() { 
  pinMode(P, OUTPUT); 						// Configura el pin P como salida 
} 
 
void loop() { 
  for (int l = 0; l < numLetters; l++) { 
    sendLetter(letters[l]); 				// Envía cada letra 
    if (l < numLetters - 1) { 
      delay(3 * T); 						// Pausa entre letras (600ms) 
    } else { 
      delay(7 * T); 						// Pausa al final de la palabra (1400ms) 
    } 
  } 
} 
 
void sendLetter(const char* morse) { 
  int i = 0; 
  while (morse[i] != '\0') { 
    if (morse[i] == '.') { 
      sendDot(); 							// Envía un punto 
    } else if (morse[i] == '-') { 
      sendDash(); 							// Envía una raya 
    } 
    i++; 
    if (morse[i] != '\0') { 
      delay(T); 							// Pausa entre elementos dentro de una letra (200ms) 
    } 
  } 
} 
 
void sendDot() { 
  digitalWrite(P, HIGH); 
  delay(T); 								// On por 200ms 
  digitalWrite(P, LOW); 
} 
 
void sendDash() { 
  digitalWrite(P, HIGH); 
  delay(3 * T); 							// On por 600ms 
  digitalWrite(P, LOW); 
} 
