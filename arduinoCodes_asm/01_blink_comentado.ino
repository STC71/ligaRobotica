/*
  PROYECTO: Blink con Inline Assembly
  Descripción: Hace parpadear el LED integrado del Arduino (pin 13)
    			usando instrucciones de ensamblador directamente dentro del código C++.
  Instrucciones: Ver al final del código.	
*/

void setup() {
  // Configuramos el pin 13 como salida usando ensamblador
  
  // "sbi" significa "Set Bit in I/O register" (poner un bit a 1)
  // DDRB es el registro que controla si los pines del Puerto B son entrada o salida
  // El bit 5 de DDRB corresponde al pin 13 del Arduino Uno/Nano
  // Al poner ese bit a 1, el pin 13 se convierte en SALIDA
  
  /*
    ============================================================
    EXPLICACIÓN DETALLADA DE "asm volatile"
    ============================================================

    1. ¿Qué significa "asm"?
       - "asm" es una palabra clave especial de C/C++.
       - Le dice al compilador:
         “A partir de aquí no voy a escribir C++, voy a escribir
         instrucciones de ensamblador del microcontrolador”.
       - Es como abrir una ventanita dentro del código C++ para
         hablar directamente con el chip en su idioma nativo.

    2. ¿Y qué significa "volatile"?
       - "volatile" es una indicación muy importante que le damos
         al compilador:
         “Este código ensamblador es importante y sensible.
         No lo borres, no lo muevas de sitio y no lo optimices
         aunque te parezca que no hace nada útil.”

       - Sin la palabra "volatile", el compilador (que es muy listo)
         podría pensar cosas como:
           • “Este código no cambia ninguna variable de C++,
             así que lo elimino.”
           • “Puedo reordenar estas instrucciones para que el
             programa vaya más rápido.”

       - Y entonces tu LED no parpadearía o se comportaría de
         forma extraña.

       - Por eso casi siempre se escribe "asm volatile" cuando
         trabajamos con hardware (pines, registros, temporizadores…).
    ============================================================
  */

  /*
    ============================================================
    ¿QUÉ SON LOS REGISTROS? (explicación sencilla)
    ============================================================

    Imagina que el microcontrolador es una oficina muy organizada.

    - Los REGISTROS son como pequeños cajones o interruptores
      especiales que están dentro del chip.
    - Cada cajón tiene un nombre (DDRB, PORTB, etc.) y sirve
      para una cosa concreta.

    Ejemplos cotidianos:

    1. DDRB (Data Direction Register B)
       Es como el panel de interruptores que decide si un pin
       es "de entrada" o "de salida".
       - Si pones el interruptor en OFF (0) → el pin escucha (entrada)
       - Si pones el interruptor en ON  (1) → el pin habla (salida)

       Ejemplo real: es como decidir si un enchufe de tu casa
       es solo para conectar un aparato (salida) o para medir
       si hay corriente (entrada).

    2. PORTB (Port B Data Register)
       Es el cajón que decide si el pin está en HIGH (5V / encendido)
       o en LOW (0V / apagado).
       Solo tiene sentido cuando el pin ya está configurado como salida.

       Ejemplo real: es el interruptor de la luz.
       - 1 = luz encendida
       - 0 = luz apagada

    Resumen fácil:
    - Primero decides si el pin es entrada o salida (DDRB)
    - Después decides si lo enciendes o lo apagas (PORTB)
    ============================================================
  */

  asm volatile (
    "sbi %[ddr], %[bit] \n"   // Pone a 1 el bit del pin 13 en DDRB (lo hace salida)

    /*
      ¿Por qué está entre comillas esta línea?
      -----------------------------------------
      Todo lo que va entre comillas dobles ("...") es texto que el
      compilador debe tratar como instrucciones de ensamblador puras.
      No es código C++. Por eso lo escribimos como una cadena de texto.

      ¿Qué significa el símbolo % ?
      -----------------------------
      El símbolo % se usa para indicar un "operando con nombre".
      %[ddr] y %[bit] son como variables temporales que luego
      enlazamos con valores reales de C++ en las secciones de abajo.

      ¿Qué es "ddr" y qué es "bit"?
      -----------------------------
      Son simplemente nombres que nosotros elegimos libremente.
      - "ddr" lo usamos para referirnos al registro DDRB
      - "bit" lo usamos para referirnos al número del bit (5)

      Más abajo le decimos al compilador qué valor concreto
      corresponde a cada uno de esos nombres.

      ¿Por qué el \n al final?
      ------------------------
      \n significa "nueva línea".
      En ensamblador cada instrucción debe ir en su propia línea.
      El \n le indica al ensamblador que termine esta instrucción
      y pase a la siguiente (aunque en este caso solo hay una).
    */

    :   // <-- Este primer ":" separa la sección de CÓDIGO de la sección de SALIDAS
        //     (en este ejemplo no tenemos variables de salida, por eso no hay nada después)

    : [ddr] "I" (_SFR_IO_ADDR(DDRB)),   // Dirección del registro DDRB
      [bit] "I" (DDB5)                  // Número del bit (5)

    /*
      ¿Qué significan los ":" ?
      -------------------------
      La sintaxis completa de un bloque asm es:

        asm volatile (
          "instrucciones de ensamblador"
          :  // sección de SALIDAS (valores que el ensamblador devuelve a C++)
          :  // sección de ENTRADAS (valores que C++ pasa al ensamblador)
          :  // sección de CLOBBER (registros que el ensamblador modifica)
        );

      - El primer ":" separa el código ensamblador de las salidas.
      - El segundo ":" separa las salidas de las entradas.
      - El tercer ":" (si existiera) separaría las entradas de los clobbers.

      En este ejemplo solo usamos entradas, por eso hay dos ":" y nada
      en la sección de salidas.

      ¿Qué hace esta línea?
      [ddr] "I" (_SFR_IO_ADDR(DDRB))
      --------------------------------
      - [ddr]                  → Es el nombre que le dimos dentro de la
                                 cadena de ensamblador (%[ddr]).
      - "I"                    → Es una restricción. Significa "Immediate"
                                 (valor constante que se puede usar
                                 directamente en la instrucción).
      - _SFR_IO_ADDR(DDRB)     → Es una macro de Arduino/AVR que obtiene
                                 la dirección real del registro DDRB en la
                                 memoria de entrada/salida del microcontrolador.

      ¿Y esta otra línea?
      [bit] "I" (DDB5)
      -----------------
      - [bit]     → Nombre que usamos en el ensamblador (%[bit]).
      - "I"       → Otra vez "Immediate" (valor constante).
      - DDB5      → Es una constante definida por Arduino que vale 5.
                    Representa el bit 5 del registro DDRB (pin 13).

      ¿Por qué hay una coma (,) al final de la primera línea de entradas?
      -----------------------------------------------------------------
      Porque estamos pasando VARIAS entradas al ensamblador.
      La coma simplemente separa una entrada de la siguiente,
      igual que cuando escribes una lista:

        manzanas, peras, plátanos

      En este caso la lista es:

        [ddr] "I" (_SFR_IO_ADDR(DDRB)),
        [bit] "I" (DDB5)

      La última línea no lleva coma (es la última de la lista).
    */
  );
}

void loop() {
  // Encendemos el LED
  asm volatile (
    "sbi %[port], %[bit] \n"  // Pone a 1 el bit del pin 13 en PORTB → LED ON
    :
    : [port] "I" (_SFR_IO_ADDR(PORTB)),
      [bit] "I" (PORTB5)
  );

  /*
    Diferencia entre sbi y cbi:
    ---------------------------
    - sbi = Set Bit in I/O register   → Pone un bit a 1 (enciende)
    - cbi = Clear Bit in I/O register → Pone un bit a 0 (apaga)

    Ambas instrucciones son muy eficientes porque modifican un solo bit
    sin afectar a los demás bits del mismo registro.

    Ejemplo cotidiano:
    Imagina un panel de 8 interruptores (un registro de 8 bits).
    Con sbi o cbi puedes subir o bajar UN solo interruptor sin
    tocar los otros siete.
  */

  delay(1000);   // Esperamos 1 segundo (esta función sí es de Arduino normal)

  // Apagamos el LED
  asm volatile (
    "cbi %[port], %[bit] \n"  // Pone a 0 el bit del pin 13 en PORTB → LED OFF
    :
    : [port] "I" (_SFR_IO_ADDR(PORTB)),
      [bit] "I" (PORTB5)
  );

  delay(1000);   // Esperamos otro segundo
}

/*
	Instrucciones detalladas para el Arduino IDE (Inline Assembly)

		Abre el Arduino IDE.
		Ve a Archivo → Nuevo.
		Borra todo el código que aparece por defecto.
		Copia y pega el código de arriba completo.
		Conecta tu Arduino Uno o Nano al ordenador.
		En el menú Herramientas:
		Selecciona la placa correcta (Arduino Uno o Arduino Nano).
		Selecciona el puerto COM correcto.

	Pulsa el botón Subir (la flecha hacia la derecha).

	El LED del pin 13 debería empezar a parpadear.
*/

/*
	El sketch usa ensamblador AVR específico, por eso aparecen errores si la placa seleccionada no es compatible.

	En concreto, el código depende de:

		DDRB, PORTB, DDB5 y PORTB5
		La instrucción AVR sbi / cbi
		_SFR_IO_ADDR(...)

	Esto funciona principalmente con placas como:

		Arduino Uno
		Arduino Nano clásico
		Arduino Mega — con posibles ajustes de pines
	
	Puede fallar si has seleccionado, por ejemplo:

		Arduino Uno R4
		Arduino Nano Every
		ESP32
		ESP8266
		Raspberry Pi Pico

	Esas placas usan otro microcontrolador y no tienen necesariamente esos registros ni instrucciones AVR.

	También es posible que VS Code marque _SFR_IO_ADDR, DDRB o PORTB como errores aunque Arduino IDE compile 
	correctamente, porque el analizador de C++ no conoce automáticamente las cabeceras generadas por Arduino.

	Seleccionamos en el IDE:

		Herramientas → Placa → Arduino AVR Boards → Arduino Uno ... y volvemos a compilar.
*/

/*
  ============================================================
  ¿POR QUÉ APARECEN ESTAS ALERTAS / ERRORES EN EL EDITOR?
  ============================================================

  1. identifier "_SFR_IO_ADDR" is undefined
  2. identifier "DDB5" is undefined
  3. identifier "PORTB" is undefined
  4. identifier "delay" is undefined

  Explicación:
  ------------
  Estas alertas suelen aparecer en editores como VS Code, Cursor o
  el analizador de C++ del propio Arduino IDE cuando todavía no se
  ha seleccionado correctamente la placa o cuando el analizador no
  ha cargado las librerías de Arduino.

  - _SFR_IO_ADDR, DDRB, PORTB, DDB5, PORTB5:
    Son definiciones que están dentro de las cabeceras de AVR
    (archivos que Arduino incluye automáticamente cuando compilas
    para una placa AVR como el Uno o el Nano clásico).

    El analizador del editor a veces no las encuentra hasta que:
      • Seleccionas la placa correcta (Arduino Uno / Nano)
      • Se genera el archivo de configuración de la placa

  - delay:
    Es una función de la librería core de Arduino.
    También puede aparecer como "undefined" si el analizador no
    ha cargado todavía las cabeceras de Arduino.

  ¿Es grave?
  ----------
  Normalmente NO. Si al pulsar "Verificar" o "Subir" el programa
  compila correctamente, puedes ignorar esas alertas del editor.
  Son falsos positivos del analizador de código, no errores reales
  de compilación.

  Solución recomendada:
  ---------------------
  1. Ve a Herramientas → Placa → Arduino AVR Boards → Arduino Uno
  2. Vuelve a verificar/compilar el sketch
  3. Si usas VS Code con la extensión de Arduino, asegúrate de que
     la placa está seleccionada también en la barra de estado inferior.
*/
