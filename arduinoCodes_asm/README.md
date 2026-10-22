# 🤖 Taller de Ensamblador en Arduino  
### Liga Robótica – 42 Málaga

> Guía de inicio completo para aprender a programar Arduino en lenguaje ensamblador desde cero.

---

## 🎯 ¿Qué es este repositorio?

Este material forma parte del taller de iniciación al **lenguaje ensamblador AVR** organizado por la **Liga Robótica** de 42 Málaga.

El objetivo es que cualquier compañero, independientemente de su nivel, pueda dar sus primeros pasos reales en programación de bajo nivel usando un Arduino Uno o Nano.

Empezamos desde **cero absoluto**. No se necesita experiencia previa en ensamblador.

---

## 📚 Las tres formas de programar Arduino en ensamblador

Existen tres caminos principales. Cada uno tiene su momento ideal:

| Opción | Nombre                        | Dificultad | Archivo de guía          | ¿Cuándo usarla?                     |
|--------|-------------------------------|------------|---------------------------|-------------------------------------|
| 1      | Inline Assembly               | Muy fácil  | [01_blink.md](01_blink.md) | Primeros pasos y pruebas rápidas   |
| 2      | Archivo `.S` separado         | Fácil      | [02_blink.md](02_blink.md) | **Forma recomendada** para aprender |
| 3      | Ensamblador puro (avr-gcc)    | Media      | [03_blink.md](03_blink.md) | Control total y nivel profesional  |

---

## 🛤️ Camino de aprendizaje recomendado

1. **Empieza aquí** → Lee y prueba la **Opción 1** (Inline Assembly)  
   Es la forma más sencilla de ver cómo se habla directamente con el hardware.

2. **Da el siguiente paso** → Pasa a la **Opción 2** (archivo `.S`)  
   Aprenderás a organizar mejor el código y a crear funciones en ensamblador.

3. **Nivel avanzado** → Prueba la **Opción 3** (compilación externa)  
   Cuando quieras entender realmente qué ocurre por debajo del Arduino IDE.

---

## 📂 Archivos disponibles

### Guías didácticas
- `01_blink.md` → Inline Assembly (explicación completa + código)
- `02_blink.md` → Archivo `.S` separado (explicación completa + código)
- `03_blink.md` → Ensamblador puro con avr-gcc y avrdude

### Códigos listos para usar
- `01_blink_comentado.ino` → Versión muy comentada de Inline Assembly
- `02_blink.ino` → Versión limpia de Inline Assembly
- `01_blink_sos.ino` → Ejemplo práctico: señal SOS en código Morse

---

## 💡 Proyecto base: Blink

Todos los ejemplos giran alrededor del clásico **Blink**: hacer parpadear el LED del pin 13.

Es el “Hola Mundo” de los microcontroladores.  
Aunque parece simple, nos permite aprender:

- Qué son los registros (`DDRB`, `PORTB`)
- Cómo se manipulan bits individuales (`sbi` / `cbi`)
- Cómo se crea un retardo
- Cómo se estructura un programa en ensamblador

---

## 🔌 Esquema electrónico

### Opción más simple (recomendada al principio)
Usa el **LED integrado** del Arduino (el pequeño LED marcado con la letra **L** junto al pin 13).  
No necesitas ningún componente externo.

### Opción con LED externo
Si quieres practicar el cableado:

- Pin 13 → Resistencia 220 Ω → Ánodo (pata larga) del LED  
- Cátodo (pata corta) del LED → GND

---

## 🧠 Conceptos clave que aprenderás

- Qué es el lenguaje ensamblador y por qué existe
- Diferencia entre C++ y ensamblador
- Qué son los registros del microcontrolador
- Cómo se enciende y apaga un pin a bajo nivel
- Cómo se organizan los programas en ensamblador
- Cómo compilar y subir código sin usar el Arduino IDE (Opción 3)

---

## 🛠️ Requisitos

- Arduino Uno o Arduino Nano (versión clásica con ATmega328P)
- Cable USB
- Arduino IDE (cualquier versión reciente)
- Ganas de entender cómo funcionan realmente los microcontroladores

> **Importante**: Estas prácticas están pensadas para placas con microcontrolador **AVR** (Uno, Nano clásico…).  
> No funcionarán directamente en Arduino Uno R4, Nano Every, ESP32, ESP8266, etc.

---

## ❤️ Filosofía del taller

Este material está diseñado con tres principios:

1. **Cero asumir conocimientos previos**
2. **Explicar el “porqué” además del “cómo”**
3. **Usar analogías cotidianas** para que los conceptos abstractos se entiendan mejor

Si en algún momento algo no se entiende, el problema no es tuyo: es que la explicación se puede mejorar.

---

## 🚀 ¿Listo para empezar?

Te recomendamos este orden:

1. Abre **[01_blink.md](01_blink.md)** y prueba el Inline Assembly  
2. Cuando lo domines, pasa a **[02_blink.md](02_blink.md)**  
3. Si tienes curiosidad por el siguiente nivel, explora **[03_blink.md](03_blink.md)**

¡Bienvenido al mundo del bajo nivel!

---

**Liga Robótica – 42 Málaga**  
*Entender el hardware es el primer paso para dominarlo.*
