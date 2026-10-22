; ============================================================
; PROGRAMA COMPLETO EN ENSAMBLADOR PURO
; Hace parpadear el LED del pin 13 del Arduino Uno/Nano
; ============================================================

#define __SFR_OFFSET 0
#include <avr/io.h>

.global main                 ; El punto de entrada del programa se llama "main"

main:
    ; Configuramos el pin 13 como salida
    sbi DDRB, 5              ; DDRB bit 5 = 1 → pin 13 es SALIDA

bucle_principal:
    ; Encendemos el LED
    sbi PORTB, 5             ; PORTB bit 5 = 1 → LED ON

    ; Llamamos a la subrutina de retardo
    rcall retardo

    ; Apagamos el LED
    cbi PORTB, 5             ; PORTB bit 5 = 0 → LED OFF

    ; Volvemos a llamar al retardo
    rcall retardo

    ; Volvemos al principio del bucle
    rjmp bucle_principal     ; rjmp = Relative Jump (salta a la etiqueta)

; ------------------------------------------------------------
; Subrutina de retardo
; Crea una pausa aproximadamente de 1 segundo (a 16 MHz)
; ------------------------------------------------------------
retardo:
    ldi r18, 50              ; Cargamos el valor 50 en el registro r18
outer_loop:
    ldi r19, 255             ; Cargamos 255 en r19
middle_loop:
    ldi r20, 255             ; Cargamos 255 en r20
inner_loop:
    dec r20                  ; Restamos 1 a r20
    brne inner_loop          ; Si r20 no es cero, volvemos a inner_loop
    dec r19                  ; Restamos 1 a r19
    brne middle_loop         ; Si r19 no es cero, volvemos a middle_loop
    dec r18                  ; Restamos 1 a r18
    brne outer_loop          ; Si r18 no es cero, volvemos a outer_loop
    ret                      ; Volvemos a donde nos llamaron