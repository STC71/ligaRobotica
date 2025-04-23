// HC-SR04

byte TRIG = 9;
byte ECHO = 6;

float DURACION;
float DISTANCIA;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECHO, HIGH);
  DISTANCIA = DURACION / 58.2;
  // 52.2 es una constante especificada
  // por el fabricante del HC-SR04
  Serial.print("Distancia: ");
  Serial.print(DISTANCIA);
  Serial.println(" cms.");
  delay(500);
}