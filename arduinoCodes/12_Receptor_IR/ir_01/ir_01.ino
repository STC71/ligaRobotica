/*
  Este código está diseñado para decodificar señales IR de un mando remoto y 
  mostrar los resultados tanto en el Serial Monitor como en un LCD I2C, 
  además de controlar un LED como indicador. La virtualización en TinkerCad 
  no es adecuada para este proyecto debido a las siguientes razones:
  1. TinkerCad utiliza una versión antigua de la biblioteca IRremote (~v2.6.0) 
     con limitaciones en la emulación de señales IR, lo que resulta en que todos 
     los botones del mando simulado generen el mismo código hexadecimal 
     (ej. 0x5F75E47D) con protocolo "UNKNOWN", independientemente de la pulsación, 
     dificultando la distinción entre botones.
  2. La simulación del mando IR en TinkerCad no emula protocolos estándar como NEC, 
     produciendo datos raw inconsistentes (diferencias solo en posiciones específicas 
     como 7 y 35), lo que requiere un mapeo manual y poco fiable.
  3. La falta de soporte para la sintaxis moderna de IRremote (ej. decodedIRData) 
     en TinkerCad obliga a usar una estructura antigua (decode_results), pero 
     incluso así, la simulación no captura las señales de forma realista.
  En contraste, la adaptación física funciona porque:
  1. Un mando IR real (especialmente del kit Arduino con protocolo NEC) genera 
     códigos HEX únicos por botón (ej. 0xFF6897 para "1"), permitiendo un mapeo 
     preciso y directo.
  2. El hardware real soporta la biblioteca IRremote v2.6.0 de manera estable, 
     decodificando correctamente los protocolos y reflejando las señales en el 
     Serial Monitor y LCD.
  3. Los componentes físicos (receptor IR, LED, LCD I2C) funcionan según sus 
     especificaciones, eliminando las limitaciones de la emulación y proporcionando 
     resultados consistentes.
  Por estas razones, este código está optimizado para hardware real, requiriendo 
  ajustes en el mapeo de códigos HEX según el mando utilizado.
*/

#include <IRremote.h>          // Biblioteca IRremote (shirriff, v2.6.0)
#include <LiquidCrystal_I2C.h> // Para LCD I2C

// Configuración de pines
const int RECV_PIN = 11;       // Pin para receptor IR
const int LED_PIN = 13;        // Pin para LED

// Inicializar objetos
IRrecv irrecv(RECV_PIN);
decode_results results;
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Dirección I2C común (prueba 0x3F si no funciona)

// Variables
unsigned long lastCode = 0;    // Último código IR recibido
int t_led = 500;               // Tiempo de encendido del LED en cada pulsación del mando emisor

void setup() {
  // Iniciar Serial
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");

  // Configurar LED
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // Iniciar IR
  irrecv.enableIRIn();

  // Iniciar LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Esperando IR...");
  lcd.setCursor(0, 1);
  lcd.print("Listo");
}

void loop() {
  if (irrecv.decode(&results)) {
    // Encender LED
    digitalWrite(LED_PIN, HIGH);
    delay(t_led);
    digitalWrite(LED_PIN, LOW);

    // Verificar repetición
    bool isRepeat = (results.value == lastCode && results.value != 0);
    lastCode = results.value;

    // Mostrar en Serial
    if (isRepeat) {
      Serial.println("REPEAT!");
    } else {
      Serial.print("IR code:0x");
      Serial.println(results.value, HEX);
    }
    // Mapear botón
    String buttonName = translateIR(results.value, isRepeat);
    Serial.println(buttonName);

    // Mostrar en LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    if (isRepeat) {
      lcd.print("REPEAT");
    } else {
      lcd.print("IR:0x");
      lcd.print(results.value, HEX);
    }
    lcd.setCursor(0, 1);
    lcd.print("Btn: ");
    lcd.print(buttonName);

    // Reiniciar
    irrecv.resume();
    delay(500); // Evitar repeticiones inmediatas
  }
}

// Función para mapear y traducir el código IR
String translateIR(unsigned long code, bool isRepeat) {
  if (isRepeat) {
    return "REPEAT!";
  }
  switch (code) {
    case 0xBA45FF00: return "POWER";
    case 0xB847FF00: return "FUNC/STOP";
    case 0xB946FF00: return "VOL+";
    case 0xBB44FF00: return "FAST BACK";
    case 0xBF40FF00: return "PAUSE";
    case 0xBC43FF00: return "FAST FORWARD";
    case 0xF807FF00: return "DOWN";
    case 0xEA15FF00: return "VOL-";
    case 0xF609FF00: return "UP";
    case 0xE619FF00: return "EQ";
    case 0xF20DFF00: return "ST/REPT";
    case 0xE916FF00: return "0";
    case 0xF30CFF00: return "1";
    case 0xE718FF00: return "2";
    case 0xA15EFF00: return "3";
    case 0xF708FF00: return "4";
    case 0xE31CFF00: return "5";
    case 0xA55AFF00: return "6";
    case 0xBD42FF00: return "7";
    case 0xAD52FF00: return "8";
    case 0xB54AFF00: return "9";
    default: return "other button";
  }
}