/* 

Instrucciones detalladas para usar Ensamblador Puro

Este método es un poco más avanzado. Hay dos formas:

-------------------------------------------------------------------------------

Opción A – Usando solo el Arduino IDE (más sencilla):

Crea un sketch nuevo y guárdalo.
Borra todo el contenido del .ino y deja solo esto:

	// Este archivo solo existe para que el IDE no se queje.
	// Todo el trabajo real está en el archivo .S

Crea una nueva pestaña llamada blink_puro.S y pega el código de ensamblador puro.
Sube el programa normalmente.

-------------------------------------------------------------------------------

Opción B – Compilación externa (más profesional)Esta forma consiste en no usar el 
Arduino IDE para compilar el programa. En su lugar, escribes el código en ensamblador 
puro, lo compilas tú mismo con herramientas de línea de comandos y luego lo subes al 
Arduino.

¿Qué herramientas se usan?

	Herramienta				Para qué sirve
	avr-gcc					Compilador. Convierte tu archivo .S o .asm en código máquina 
							que entiende el microcontrolador.
	avrdude					Programador. Es el que realmente sube el archivo .hex al 
							Arduino a través del cable USB.
							
Estas dos herramientas ya vienen incluidas cuando instalas el Arduino IDE 
(están “escondidas” dentro de la carpeta de instalación), 
pero también se pueden instalar por separado.

¿Cómo funciona el proceso? (pasos simplificados)

	Escribes el programa completo en un archivo de texto, por ejemplo blink.S.
	Compilas el archivo con avr-gcc → se genera un archivo .elf y luego un .hex.
	Subes el archivo .hex al Arduino usando avrdude.

Ejemplo muy simplificado de los comandos (en Linux/Mac o en la terminal de Windows):

	avr-gcc -mmcu=atmega328p -o blink.elf blink.S
	avr-objcopy -O ihex blink.elf blink.hex
	avrdude -c arduino -P /dev/ttyUSB0 -p m328p -U flash:w:blink.hex

¿Por qué se considera más profesional?

	Tienes control total sobre cómo se compila el programa.
	Puedes usar opciones avanzadas de optimización.
	Es el método que se usa en la industria y en proyectos serios de sistemas embebidos.
	No dependes del entorno gráfico del Arduino IDE.
	Te obliga a entender mejor qué está pasando realmente (registros, memoria, 
	vectores de interrupción, etc.).

*/