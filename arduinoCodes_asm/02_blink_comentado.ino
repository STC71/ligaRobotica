/*
  Archivo principal (.ino)
  Solo se encarga de llamar a las funciones escritas en ensamblador.
*/

// Declaramos las funciones que están escritas en el archivo .S
// "extern C" es obligatorio para que C++ y ensamblador se entiendan
extern "C" {
  void configurar_led();   // Función que configura el pin como salida
  void encender_led();     // Función que enciende el LED
  void apagar_led();       // Función que apaga el LED
}

void setup() {
  configurar_led();        // Llamamos a la función de ensamblador
}

void loop() {
  encender_led();          // Encendemos el LED
  delay(1000);             // Esperamos 1 segundo
  apagar_led();            // Apagamos el LED
  delay(1000);             // Esperamos 1 segundo
}

/*
	Instrucciones detalladas para el Arduino IDE (método .S)

		Abre el Arduino IDE.
		Crea un nuevo sketch (Archivo → Nuevo).
		Guárdalo con el nombre Blink_ASM (por ejemplo).
		En la ventana del código, borra todo y pega el contenido del archivo .ino de arriba.

		Ahora crea el archivo de ensamblador:
			Ve al menú Sketch → Añadir archivo...
			O más fácil: en la parte superior derecha del IDE hay una flechita hacia abajo → Nueva pestaña.
			Ponle de nombre exactamente: blink.S (la S mayúscula).

		En esa nueva pestaña pega el código del archivo blink.S.
		Conecta el Arduino, selecciona placa y puerto.
		Pulsa Subir.
*/