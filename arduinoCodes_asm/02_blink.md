# 🚀 Opción 2: Blink con archivo .S separado

> **Guía didáctica paso a paso**  
> Pensada para personas que **nunca** han tocado ensamblador.

---

## 🎯 ¿Qué vamos a hacer?

Vamos a hacer el mismo Blink, pero de una forma **más limpia y profesional**:  
separaremos el código ensamblador en su propio archivo (`.S`) y lo llamaremos desde el archivo normal de Arduino (`.ino`).

Esta es la forma **recomendada** cuando empiezas a escribir más de unas pocas líneas de ensamblador.

### Analogía cotidiana

Imagina que estás escribiendo un trabajo.  
En la Opción 1 (Inline) metías las frases en otro idioma dentro del mismo párrafo.  
En esta Opción 2 creas una **hoja aparte** solo para esas frases en otro idioma, y desde tu trabajo principal simplemente dices:  
“Mira la hoja de ensamblador, sección tal”.

El resultado es mucho más ordenado y fácil de mantener.

---

## 🧰 ¿Qué necesitamos?

- Arduino Uno o Nano (ATmega328P)
- Cable USB
- Arduino IDE
- **Nada más** (el IDE se encarga de compilar el archivo `.S` automáticamente)

---

## 📁 Estructura del proyecto

Necesitamos **dos archivos** dentro del mismo sketch:

```
Blink_ASM/
├── Blink_ASM.ino     ← Archivo principal (C++)
└── blink.S           ← Archivo de ensamblador (¡S mayúscula!)
```

---

## 📄 Archivo 1: `Blink_ASM.ino`

```cpp
/*
  Archivo principal
  Solo se encarga de llamar a las funciones escritas en ensamblador
*/

// Declaramos las funciones que están en el archivo .S
// "extern C" es obligatorio para que C++ y ensamblador se entiendan
extern "C" {
  void configurar_led();   // Configura el pin 13 como salida
  void encender_led();     // Enciende el LED
  void apagar_led();       // Apaga el LED
}

void setup() {
  configurar_led();        // Llamamos a la función de ensamblador
}

void loop() {
  encender_led();          // Encendemos
  delay(1000);             // Esperamos 1 segundo
  apagar_led();            // Apagamos
  delay(1000);             // Esperamos otro segundo
}
```

---

## 📄 Archivo 2: `blink.S`

```asm
; ============================================================
;  ARCHIVO: blink.S
;  Funciones en ensamblador para controlar el LED del pin 13
; ============================================================

; Estas dos líneas son obligatorias
#define __SFR_OFFSET 0
#include <avr/io.h>

; Hacemos que las funciones sean visibles desde el archivo .ino
.global configurar_led
.global encender_led
.global apagar_led

; ------------------------------------------------------------
; Función: configurar_led
; Pone el pin 13 (PB5) como SALIDA
; ------------------------------------------------------------
configurar_led:
    sbi DDRB, 5          ; Bit 5 de DDRB = 1 → pin 13 es salida
    ret                  ; Volvemos al código C++

; ------------------------------------------------------------
; Función: encender_led
; Enciende el LED del pin 13
; ------------------------------------------------------------
encender_led:
    sbi PORTB, 5         ; Bit 5 de PORTB = 1 → LED ON
    ret

; ------------------------------------------------------------
; Función: apagar_led
; Apaga el LED del pin 13
; ------------------------------------------------------------
apagar_led:
    cbi PORTB, 5         ; Bit 5 de PORTB = 0 → LED OFF
    ret
```

---

## 🛠️ Cómo crear el proyecto en el Arduino IDE

1. Abre el **Arduino IDE**
2. Crea un nuevo sketch (**Archivo → Nuevo**)
3. Guárdalo con el nombre que quieras (ejemplo: `Blink_ASM`)
4. Borra el contenido del archivo `.ino` y pega el código del **Archivo 1**
5. Crea el archivo de ensamblador:
   - En la parte superior derecha del IDE hay una flechita hacia abajo
   - Pulsa **Nueva pestaña**
   - Ponle exactamente el nombre: `blink.S` (la **S** debe ser mayúscula)
6. Pega en esa pestaña el código del **Archivo 2**
7. Selecciona la placa **Arduino Uno** (o Nano) y el puerto correcto
8. Pulsa **Subir**

¡Listo! El LED debería parpadear.

---

## 🧠 Explicación de los conceptos nuevos

### 1. ¿Qué es `extern "C"`?

Cuando mezclas C++ y ensamblador, los nombres de las funciones se “decoran” de forma diferente.  
`extern "C"` le dice al compilador:

> “No cambies el nombre de estas funciones, déjalas tal cual para que el ensamblador las pueda encontrar”.

### 2. ¿Qué significa `.global`?

En el archivo `.S`, la directiva `.global` hace que una etiqueta (función) sea visible desde fuera del archivo.  
Es como poner una puerta pública en una habitación.

### 3. ¿Por qué `ret` al final de cada función?

`ret` significa **return** (volver).  
Es la forma que tiene el ensamblador de decir:  
“Ya terminé, vuelve al sitio desde donde me llamaste”.

---

## ✅ Ventajas de esta Opción 2

- El código queda **mucho más limpio y organizado**
- Puedes tener muchas funciones de ensamblador sin ensuciar el `.ino`
- Es la forma más recomendada para proyectos medianos
- El Arduino IDE compila el `.S` automáticamente (no tienes que hacer nada extra)

## ❌ Cuándo no es la mejor opción

- Si solo vas a escribir 2 o 3 instrucciones → Inline Assembly es más rápido
- Si quieres control total absoluto del programa → Opción 3 (ensamblador puro)

---

## 🎓 Comparación rápida de las tres opciones

| Opción                      | Dificultad | Organización | Control total | Recomendado para          |
|----------------------------|------------|--------------|---------------|---------------------------|
| 1. Inline Assembly         | Muy fácil  | Baja         | Medio         | Primeros pasos            |
| 2. Archivo .S separado     | Fácil      | Alta         | Medio-Alto    | **La más recomendada**    |
| 3. Ensamblador puro        | Media      | Alta         | Total         | Cuando ya tienes soltura  |

---

## ✅ Resumen

La **Opción 2** es el punto dulce entre comodidad y buena organización.  
Una vez que dominas esta forma, ya estás preparado para escribir proyectos serios mezclando C++ y ensamblador de manera profesional.

Cuando quieras el control absoluto (sin `setup()`, sin `loop()`, sin librerías de Arduino), entonces pasas a la **Opción 3**.
