/*
  PROYECTO: SOS con Inline Assembly
  Descripción: Hace parpadear el LED del pin 13 simulando la señal SOS en código Morse.
  
  Temporización:
  - Punto (·)     : 200 ms encendido
  - Raya (—)      : 600 ms encendido
  - Entre elementos de una letra : 200 ms apagado
  - Entre letras (S-O y O-S)     : 300 ms apagado
  - Entre cada SOS completo      : 1000 ms apagado
*/

void setup() {
  // Configuramos el pin 13 como salida
  asm volatile (
    "sbi %[ddr], %[bit] \n"
    :
    : [ddr] "I" (_SFR_IO_ADDR(DDRB)),
      [bit] "I" (DDB5)
  );
}

void loop() {
  // ========== Letra S (···) ==========
  punto();
  punto();
  punto();

  delay(300);   // Pausa entre letras

  // ========== Letra O (———) ==========
  raya();
  raya();
  raya();

  delay(300);   // Pausa entre letras

  // ========== Letra S (···) ==========
  punto();
  punto();
  punto();

  delay(1000);  // Pausa larga entre cada SOS completo
}

// ------------------------------------------------------------
// Funciones auxiliares
// ------------------------------------------------------------

// Enciende el LED durante 200 ms (punto)
void punto() {
  encender();
  delay(200);
  apagar();
  delay(200);   // Espacio entre elementos de la misma letra
}

// Enciende el LED durante 600 ms (raya)
void raya() {
  encender();
  delay(600);
  apagar();
  delay(200);   // Espacio entre elementos de la misma letra
}

// Enciende el LED (pin 13 en HIGH)
void encender() {
  asm volatile (
    "sbi %[port], %[bit] \n"
    :
    : [port] "I" (_SFR_IO_ADDR(PORTB)),
      [bit] "I" (PORTB5)
  );
}

// Apaga el LED (pin 13 en LOW)
void apagar() {
  asm volatile (
    "cbi %[port], %[bit] \n"
    :
    : [port] "I" (_SFR_IO_ADDR(PORTB)),
      [bit] "I" (PORTB5)
  );
}
