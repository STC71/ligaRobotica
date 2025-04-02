/*	Este código reproduce una melodía simple utilizando un buzzer conectado al 
	pin 8 del Arduino. La melodía consiste en una secuencia de notas musicales 
	almacenadas en un arreglo llamado "melody". Cada nota se reproduce durante 
	500 milisegundos, y después de tocar todas las notas, el código
	reproduce la melodía en orden inverso. Entre cada nota, hay un retraso de 
	medio segundo en el primer ciclo y un cuarto de segundo en el segundo ciclo.
	Finalmente, después de completar ambos ciclos, el código espera 1 segundo
	antes de reiniciar la melodía.	*/
 
	#define DO  523
	#define RE  587
	#define MI  659
	#define FA  698
	#define SOL  784
	#define LA  880
	#define SI  988
	#define DOO  1047
	 
	// notes in the melody:
	int melody[] = {DO, RE, MI, FA, SOL, LA, SI, DOO};
	int duration = 500;  	// 500 miliseconds
	int T = 1000; 			// 1 second
	int PIN = 8;			// pin 8
	
	void setup() {
	 
	}
	 
	void loop() {  
		for (int thisNote = 0; thisNote < 8; thisNote++) {
			// pin8 output the voice, every scale is 0.5 sencond
			tone(PIN, melody[thisNote], duration);
			
			// Output the voice after several minutes
			delay(T / 2);
		  }
	  
		  for (int thisNote = 7; thisNote >= 0; thisNote--) {
			tone(PIN, melody[thisNote], duration);
			delay(T / 4);
		  }
	   
		  // restart after two seconds 
		delay(T);
	}