# 🚀 Opción B: Compilación Externa de Blink en Ensamblador Puro

> **Guía didáctica paso a paso**  
> Pensada para personas que **nunca** han tocado ensamblador ni la terminal.

---

## 🎯 ¿Qué vamos a hacer?

Vamos a crear el clásico programa **Blink** (hacer parpadear el LED del pin 13) escribiendo **todo en ensamblador puro**, sin usar el Arduino IDE para compilar.

Imagina que el Arduino IDE es como un restaurante de comida rápida: tú pides y te lo preparan.  
La **Opción B** es como cocinar en casa: tú controlas cada ingrediente y cada paso. Es más trabajo, pero aprendes de verdad y el resultado puede ser mejor.

---

## 🧰 Herramientas que vamos a usar

| Herramienta     | ¿Para qué sirve?                                      | Analogía cotidiana                     |
|-----------------|-------------------------------------------------------|----------------------------------------|
| **avr-gcc**     | Traduce tu código ensamblador a lenguaje máquina     | El traductor que convierte tus instrucciones al idioma del chip |
| **avr-objcopy** | Convierte el archivo a formato `.hex`                 | El empaquetador que prepara el regalo para enviarlo |
| **avrdude**     | Sube el archivo `.hex` al Arduino por USB             | El cartero que entrega el paquete al Arduino |

Estas herramientas ya vienen incluidas cuando instalas el **Arduino IDE**. Solo tenemos que encontrarlas.

---

## 📁 1. El código ensamblador puro

Crea un archivo de texto llamado `blink.S` (la **S** debe ser mayúscula) y copia este código:

```asm
; ============================================================
;  BLINK PURO EN ENSAMBLADOR AVR
;  Hace parpadear el LED del pin 13 del Arduino Uno / Nano
; ============================================================

; Esta línea le dice al ensamblador dónde están los registros del chip
#define __SFR_OFFSET 0
#include <avr/io.h>

; El programa empieza en la etiqueta "main"
.global main

main:
    ; Configuramos el pin 13 como SALIDA
    ; DDRB = Data Direction Register del Puerto B
    ; El bit 5 de DDRB controla el pin 13
    sbi DDRB, 5          ; sbi = "Set Bit" → pone el bit a 1 (salida)

bucle:
    ; Encendemos el LED
    sbi PORTB, 5         ; PORTB bit 5 = 1 → LED ON

    ; Llamamos a la subrutina de retardo
    rcall retardo

    ; Apagamos el LED
    cbi PORTB, 5         ; cbi = "Clear Bit" → pone el bit a 0 (LED OFF)

    ; Otra vez el retardo
    rcall retardo

    ; Volvemos al principio del bucle (parpadeo infinito)
    rjmp bucle

; ------------------------------------------------------------
; Subrutina de retardo (aproximadamente 1 segundo a 16 MHz)
; Es como contar hasta un número muy grande muy despacio
; ------------------------------------------------------------
retardo:
    ldi r18, 50          ; Cargamos el número 50 en el registro r18
outer:
    ldi r19, 255         ; Cargamos 255 en r19
middle:
    ldi r20, 255         ; Cargamos 255 en r20
inner:
    dec r20              ; Restamos 1 a r20
    brne inner           ; Si r20 no es cero, volvemos a "inner"
    dec r19
    brne middle
    dec r18
    brne outer
    ret                  ; Volvemos a donde nos llamaron
```

> **Nota**: Este código no usa `setup()` ni `loop()`. Es un programa completo de verdad.

---

## 💻 2. Cómo compilar y subir (Linux)

Abre la terminal y sigue estos pasos:

### Paso 1 – Ve a la carpeta donde guardaste `blink.S`
```bash
cd ~/ruta/donde/esta/tu/archivo
```

### Paso 2 – Compila el ensamblador
```bash
avr-gcc -mmcu=atmega328p -o blink.elf blink.S
```
- `-mmcu=atmega328p` → le decimos que es un Arduino Uno/Nano  
- Se genera el archivo `blink.elf`

### Paso 3 – Convierte a formato .hex
```bash
avr-objcopy -O ihex -R .eeprom blink.elf blink.hex
```

### Paso 4 – Sube al Arduino
Primero averigua el puerto (normalmente `/dev/ttyUSB0` o `/dev/ttyACM0`):
```bash
ls /dev/tty*
```

Luego sube el programa:
```bash
avrdude -c arduino -p m328p -P /dev/ttyUSB0 -b 115200 -D -U flash:w:blink.hex:i
```

> Sustituye `/dev/ttyUSB0` por el puerto real de tu Arduino.

---

## 🪟 3. Cómo compilar y subir (Windows)

### Paso 1 – Abre la “Terminal” o “PowerShell” o “Símbolo del sistema”

### Paso 2 – Localiza las herramientas del Arduino IDE

Normalmente están en una ruta parecida a esta:

```
C:\Users\TU_USUARIO\AppData\Local\Arduino15\packages\arduino\tools\avr-gcc\...\bin\
```

o

```
C:\Program Files (x86)\Arduino\hardware\tools\avr\bin\
```

Copia la ruta completa de la carpeta `bin`.

### Paso 3 – Compila (ejemplo)

```cmd
"C:\ruta\completa\avr-gcc.exe" -mmcu=atmega328p -o blink.elf blink.S
```

### Paso 4 – Convierte a .hex

```cmd
"C:\ruta\completa\avr-objcopy.exe" -O ihex -R .eeprom blink.elf blink.hex
```

### Paso 5 – Sube al Arduino

Primero mira en el Administrador de dispositivos qué puerto COM tiene tu Arduino (ejemplo: `COM5`).

Luego ejecuta:

```cmd
"C:\ruta\completa\avrdude.exe" -C "C:\ruta\completa\avrdude.conf" -c arduino -p m328p -P COM5 -b 115200 -D -U flash:w:blink.hex:i
```

---

## 🧠 Explicación sencilla de los comandos más importantes

| Comando / Opción              | ¿Qué hace?                                      | Analogía                          |
|-------------------------------|-------------------------------------------------|-----------------------------------|
| `-mmcu=atmega328p`            | Indica el modelo exacto del chip                | Decirle al sastre la talla exacta |
| `-o blink.elf`                | Nombre del archivo de salida                    | Ponerle nombre al pastel          |
| `-O ihex`                     | Formato Intel HEX (el que entiende avrdude)     | Empaquetar para el transporte     |
| `-c arduino`                  | Protocolo de comunicación del Arduino           | El idioma que habla el cartero    |
| `-p m328p`                    | Modelo del microcontrolador                     | La dirección exacta               |
| `-P COM5` o `/dev/ttyUSB0`    | Puerto USB donde está conectado el Arduino      | La puerta de entrada de tu casa   |
| `-U flash:w:blink.hex:i`      | “Escribe este archivo en la memoria flash”      | Meter el programa en el chip      |

---

## ⚠️ Errores frecuentes y cómo solucionarlos

| Error                                      | Causa más habitual                          | Solución                              |
|--------------------------------------------|---------------------------------------------|---------------------------------------|
| `avr-gcc: command not found`               | No está en el PATH                          | Usa la ruta completa al ejecutable    |
| `Permission denied` (Linux)                | No tienes permiso en el puerto              | `sudo usermod -a -G dialout $USER` y reinicia sesión |
| `stk500_getsync() not in sync`             | Puerto incorrecto o cable malo              | Prueba otro puerto COM / tty          |
| El LED no parpadea                         | El retardo es demasiado corto o largo       | Ajusta los valores de r18, r19, r20   |

---

## 🎓 ¿Qué has aprendido con esta Opción B?

- Cómo se traduce realmente el ensamblador a código máquina
- Qué es un archivo `.hex`
- Cómo habla el ordenador con el Arduino a bajo nivel
- Que el Arduino IDE no es magia: por debajo usa exactamente estas mismas herramientas

---

## ✅ Resumen rápido

1. Escribes `blink.S`
2. Compilas con `avr-gcc`
3. Generas el `.hex` con `avr-objcopy`
4. Subes con `avrdude`

¡Y listo! Ya tienes un Blink 100 % puro y profesional.

---

> **Consejo final**:  
> Empieza siempre con la Opción A (archivo `.S` dentro del Arduino IDE).  
> Cuando te sientas cómodo, prueba esta Opción B. Es el salto que te convierte de “usuario de Arduino” en alguien que realmente entiende los microcontroladores.

¿Listo para el siguiente nivel? 💪
