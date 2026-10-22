# 🚀 Opción 1: Blink con Inline Assembly

> **Guía didáctica paso a paso**  
> Pensada para personas que **nunca** han tocado ensamblador.

---

## 🎯 ¿Qué vamos a hacer?

Vamos a hacer parpadear el LED del pin 13 del Arduino **mezclando** código C++ normal con unas pocas instrucciones de ensamblador.

Esta es la forma **más sencilla** de empezar a tocar ensamblador.

### Analogía cotidiana

Imagina que estás escribiendo una carta en español (C++), pero de repente necesitas decir una frase en otro idioma (ensamblador).  
En lugar de cambiar de libreta, simplemente pones esa frase entre comillas dentro de la misma carta.  
Eso es exactamente lo que hace el **Inline Assembly**.

---

## 🧰 ¿Qué necesitamos?

- Arduino Uno o Nano (el clásico, con ATmega328P)
- Cable USB
- Arduino IDE instalado
- **Nada más**. No hace falta instalar herramientas extra.

---

## 📄 El código completo

Crea un sketch nuevo en el Arduino IDE y pega este código:

```cpp
/*
  PROYECTO: Blink con Inline Assembly
  Descripción: Hace parpadear el LED integrado del pin 13
               usando instrucciones de ensamblador dentro de C++.
*/

void setup() {
  // Configuramos el pin 13 como SALIDA usando ensamblador
  asm volatile (
    "sbi %[ddr], %[bit] \n"     // Ponemos el bit 5 de DDRB a 1
    :
    : [ddr] "I" (_SFR_IO_ADDR(DDRB)),
      [bit] "I" (DDB5)
  );
}

void loop() {
  // Encendemos el LED
  asm volatile (
    "sbi %[port], %[bit] \n"    // Ponemos el bit 5 de PORTB a 1 → LED ON
    :
    : [port] "I" (_SFR_IO_ADDR(PORTB)),
      [bit] "I" (PORTB5)
  );

  delay(1000);                  // Esperamos 1 segundo (función normal de Arduino)

  // Apagamos el LED
  asm volatile (
    "cbi %[port], %[bit] \n"    // Ponemos el bit 5 de PORTB a 0 → LED OFF
    :
    : [port] "I" (_SFR_IO_ADDR(PORTB)),
      [bit] "I" (PORTB5)
  );

  delay(1000);                  // Esperamos otro segundo
}
```

---

## 🧠 Explicación detallada (para quien no sabe nada)

### 1. ¿Qué es `asm volatile`?

| Parte       | Significado                                                                 | Analogía                                      |
|-------------|-----------------------------------------------------------------------------|-----------------------------------------------|
| `asm`       | “A partir de aquí voy a escribir ensamblador”                               | Abrir una ventanita para hablar otro idioma   |
| `volatile`  | “No toques este código, es importante y sensible”                           | Poner un cartel de “No molestar” al compilador |

Sin la palabra `volatile`, el compilador (que es muy listo) podría borrar o reordenar estas instrucciones porque “no cambian ninguna variable de C++”.

### 2. ¿Qué son los registros?

Imagina que el microcontrolador es una oficina llena de cajones especiales:

- **DDRB** → El cajón que decide si un pin es de **entrada** o de **salida**  
  (como el interruptor que elige si un enchufe es para enchufar algo o para medir corriente).

- **PORTB** → El cajón que decide si el pin está en **HIGH** (encendido) o **LOW** (apagado)  
  (como el interruptor de la luz).

El **bit 5** de estos registros controla el pin digital 13 del Arduino Uno/Nano.

### 3. Instrucciones importantes

| Instrucción | Significado                        | Efecto en el LED      |
|-------------|------------------------------------|-----------------------|
| `sbi`       | Set Bit (poner un bit a 1)         | Enciende / Configura  |
| `cbi`       | Clear Bit (poner un bit a 0)       | Apaga                 |

### 4. La sintaxis rara de `asm`

```cpp
asm volatile (
  "sbi %[ddr], %[bit] \n"     // ← Instrucción de ensamblador (entre comillas)
  :                           // ← Separador de salidas (aquí no hay ninguna)
  : [ddr] "I" (_SFR_IO_ADDR(DDRB)),  // ← Entrada: nombre + tipo + valor
    [bit] "I" (DDB5)
);
```

- Las comillas `"..."` indican que es texto de ensamblador.
- `%[ddr]` y `%[bit]` son como “variables temporales” que luego enlazamos.
- `"I"` significa “valor constante inmediato”.
- La coma separa las diferentes entradas (como en una lista de la compra).

---

## 🛠️ Cómo usarlo en el Arduino IDE

1. Abre el **Arduino IDE**
2. Ve a **Archivo → Nuevo**
3. Borra todo el código que aparece
4. Pega el código de arriba
5. Conecta tu Arduino
6. Selecciona la placa: **Herramientas → Placa → Arduino Uno** (o Nano)
7. Selecciona el puerto correcto
8. Pulsa el botón **Subir** (→)

Si todo va bien, el LED del pin 13 empezará a parpadear.

---

## ⚠️ Alertas que pueden aparecer en el editor

Es normal que el editor muestre avisos como:

- `identifier "_SFR_IO_ADDR" is undefined`
- `identifier "DDB5" is undefined`
- `identifier "PORTB" is undefined`

**No te preocupes.**  
Son falsos positivos del analizador de código.  
Si al pulsar “Verificar” o “Subir” compila correctamente, puedes ignorarlos.

---

## ✅ Ventajas de esta Opción 1

- Es la más fácil para empezar
- Todo está en un solo archivo
- Puedes mezclar C++ y ensamblador libremente
- Ideal para aprender las primeras instrucciones (`sbi`, `cbi`…)

## ❌ Limitaciones

- Cuando el código ensamblador crece, se vuelve difícil de leer
- No es la forma más limpia para proyectos medianos o grandes

---

## 🎓 Resumen

La **Opción 1 (Inline Assembly)** es el “Hola Mundo” del ensamblador en Arduino.  
Te permite tocar el hardware de verdad sin salir del entorno cómodo del IDE.

Cuando te sientas cómodo con esta forma, el siguiente paso natural es la **Opción 2** (archivo `.S` separado).
