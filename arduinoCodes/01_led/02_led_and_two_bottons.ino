//left botton (A) = on
//right botton (B) = off

/*	Este código enciende un led cuando se presiona el botón A y lo apaga 
	cuando se presiona el botón B.
	El botón A está conectado al pin 9 y el botón B al pin 8. El led está 
	conectado al pin 5.
	El código utiliza la librería Serial para imprimir mensajes en el 
	monitor serial; on cuando el led está encendido y off cuando está apagado.
	El botón A está configurado como INPUT_PULLUP, lo que significa que el pin 
	estará en HIGH cuando no se presione el botón y LOW cuando se presione.
	El botón B también está configurado como INPUT_PULLUP, lo que significa que 
	el pin estará en HIGH cuando no se presione el botón y LOW cuando se presione.
	El led está conectado al pin 5 y se enciende cuando el botón A se presiona 
	y se apaga cuando el botón B se presiona.
	El código utiliza la función digitalRead() para leer el estado de los botones 
	y la función digitalWrite() para encender y apagar el led.
	El código se ejecuta en un bucle infinito, verificando constantemente el 
	estado de los botones y encendiendo o apagando el led según corresponda.
	El código es un ejemplo básico de cómo usar botones y un led en Arduino. 
	Se puede utilizar como base para proyectos más complejos que requieran la 
	interacción del usuario a través de botones y la retroalimentación visual 
	a través de un led.
*/

const int ledPin = 5;
const int buttonApin = 9;
const int buttonBpin = 8;

byte leds = 0;

void setup() {
	Serial.begin(9600);
	pinMode(ledPin, OUTPUT);
	pinMode(buttonApin, INPUT_PULLUP);  
	pinMode(buttonBpin, INPUT_PULLUP);
}

void loop() {
	if (digitalRead(buttonApin) == LOW) {
    	digitalWrite(ledPin, HIGH);
		Serial.println("on");
    }
	if (digitalRead(buttonBpin) == LOW) {
		digitalWrite(ledPin, LOW);
        Serial.println("off");
	}
}