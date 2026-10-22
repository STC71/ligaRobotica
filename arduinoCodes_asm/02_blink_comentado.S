; ============================================================
; ARCHIVO: blink.S
; Descripción: Funciones en ensamblador para controlar el LED del pin 13
; ============================================================

; Esta línea es obligatoria. Le dice al ensamblador dónde están los registros
#define __SFR_OFFSET 0
#include <avr/io.h>

; Hacemos que las funciones sean visibles desde el archivo .ino
.global configurar_led
.global encender_led
.global apagar_led

; ------------------------------------------------------------
; Función: configurar_led
; Qué hace: Pone el pin 13 (PB5) como SALIDA
; ------------------------------------------------------------
configurar_led:
    sbi DDRB, 5          ; sbi = Set Bit in I/O register
                         ; DDRB es el registro de dirección del Puerto B
                         ; El bit 5 controla el pin 13
                         ; Al ponerlo a 1 → el pin es SALIDA
    ret                  ; ret = return (volver a la función que nos llamó)

; ------------------------------------------------------------
; Función: encender_led
; Qué hace: Enciende el LED del pin 13
; ------------------------------------------------------------
encender_led:
    sbi PORTB, 5         ; Pone a 1 el bit 5 de PORTB → LED ON
    ret

; ------------------------------------------------------------
; Función: apagar_led
; Qué hace: Apaga el LED del pin 13
; ------------------------------------------------------------
apagar_led:
    cbi PORTB, 5         ; cbi = Clear Bit in I/O register
                         ; Pone a 0 el bit 5 de PORTB → LED OFF
    ret