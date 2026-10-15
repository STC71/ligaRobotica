/*
  PROYECTO: Blink con Inline Assembly (versión limpia)
  Descripción: Hace parpadear el LED integrado del Arduino (pin 13)
               usando instrucciones de ensamblador.
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
  // Encendemos el LED
  asm volatile (
    "sbi %[port], %[bit] \n"
    :
    : [port] "I" (_SFR_IO_ADDR(PORTB)),
      [bit] "I" (PORTB5)
  );

  delay(1000);

  // Apagamos el LED
  asm volatile (
    "cbi %[port], %[bit] \n"
    :
    : [port] "I" (_SFR_IO_ADDR(PORTB)),
      [bit] "I" (PORTB5)
  );

  delay(1000);
}
