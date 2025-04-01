/*	Este código mostrara el parpadeo de un LED RGB, cambiando de color entre rojo, verde y azul.
	El LED RGB se conecta a los pines 6, 5 y 3 del Arduino, que son pines PWM.
	El código utiliza la función analogWrite() para controlar la intensidad de cada color.
	La velocidad de cambio de color se puede ajustar modificando la variable delayTime.	
	
	PWDM (Pulse Width Modulation) es una técnica que permite simular una señal analógica
	mediante la modulación de la anchura de los pulsos digitales.
	En este caso, se utiliza para controlar la intensidad de los colores del LED RGB.
	La función analogWrite() genera una señal PWM en el pin especificado, donde el valor
	que se le pasa (entre 0 y 255) determina el ciclo de trabajo de la señal.
	Un valor de 0 significa que el LED está apagado (0% de ciclo de trabajo) y un valor de 255
	significa que el LED está encendido al máximo (100% de ciclo de trabajo).
	La función analogWrite() se utiliza para controlar la intensidad de cada color del LED RGB.	*/

const int RED = 6;  			// Pin PWM para el rojo​
const int GREEN = 5;	 		// Pin PWM para el verde​
const int BLUE =3; 		  		// Pin PWM para el azul
const int delayTime = 10	 	// Tiempo entre cambios (en milisegundos)

void setup() { ​
	// Configuramos los pines del LED RGB como salidas
	pinMode(RED, OUTPUT);   	// El pin rojo es una salida ​
	pinMode(GREEN, OUTPUT);  	// El pin verde es una salida ​
	pinMode(BLUE, OUTPUT);   	// El pin azul es una salida 
	// Inicializamos el LED RGB en rojo
	digitalWrite(RED, HIGH);    // Empezamos con rojo encendido ​
	digitalWrite(GREEN, LOW);   // Verde apagado ​
	digitalWrite(BLUE, LOW);    // Azul apagado ​
}​

int redValue = 255;    	// Rojo al máximo ​
int greenValue = 0;		// Verde apagado ​
int blueValue = 0;     	// Azul apagado ​

void loop() {

	// De rojo a verde ​
	for (int i = 0; i < 255; i++) {
		redValue--; greenValue++; ​
		analogWrite(RED, redValue); analogWrite(GREEN, greenValue); ​
		delay(delayTime); ​
	}
	// De verde a azul ​
	for (int i = 0; i < 255; i++) {	
		greenValue--; blueValue++; ​
		analogWrite(GREEN, greenValue); analogWrite(BLUE, blueValue); ​
		delay(delayTime); ​
	}
	// De azul a rojo ​
	for (int i = 0; i < 255; i++) {	
		blueValue--; redValue++; ​
		analogWrite(BLUE, blueValue); analogWrite(RED, redValue);​
		delay(delayTime); ​
	}	
}