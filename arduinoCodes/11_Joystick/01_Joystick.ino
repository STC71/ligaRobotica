/*	El objetivo del código es encender los 4 LEDS, dependiendo de los valores
	que reciba el joystick. Además, se muestra en el monitor serie el valor leido
	por el joystick, tanto para VRx como para VRy.	*/

// Pines analógicos donde entra la información del joystick
const int VRy = 0;  // A0
const int VRx = 1;  // A1
// Pines digitales donde se conectan los LEDs
const int ledVRy1 = 9;
const int ledVRy2 = 10;
const int ledVRx1 = 11;
const int ledVRx2 = 12;

// Variable para almacenar los valores VRx y VRy 
int lectura = 0;

/*	Se inicializan los pines digitales de los LEDs y el puerto serie.
	Las entradas analógicas, a diferencia de las digitales, no pueden funcionar
	como salidas, por lo que no hace falta inicializarlas.	*/
void setup() {
  Serial.begin(9600);
  pinMode(ledVRx1, OUTPUT);
  pinMode(ledVRx2, OUTPUT);
  pinMode(ledVRy1, OUTPUT);
  pinMode(ledVRy2, OUTPUT);
}

/*	Leer una entrada analógica es muy sencillo con la función analogRead()
	En este caso se leen los valores tando de VRx como de VRy y se guarda en la
	variable lectura.
	Con if se comprueba si los valores están en cierto margen. Dependiendo de 
	esto, se encenderán unos LEDs u otros.	*/
void loop() {
  lectura = analogRead(VRx);
  if(lectura<350){
    digitalWrite(ledVRx1, HIGH);
    digitalWrite(ledVRx2, LOW);
  }
  else if(lectura>700){
    digitalWrite(ledVRx1, LOW);
    digitalWrite(ledVRx2, HIGH);
  }
  else{
    digitalWrite(ledVRx1, LOW);
    digitalWrite(ledVRx2, LOW);
  }
  Serial.print("Lectura Eje X: ");
  Serial.println(lectura);
  delay(100);

  lectura = analogRead(VRy);
  if(lectura<350){
    digitalWrite(ledVRy1, HIGH);
    digitalWrite(ledVRy2, LOW);
  }
  else if(lectura>700){
    digitalWrite(ledVRy1, LOW);
    digitalWrite(ledVRy2, HIGH);
  }
  else{
    digitalWrite(ledVRy1, LOW);
    digitalWrite(ledVRy2, LOW);
  }
  Serial.print("Lectura Eje Y: ");
  Serial.println(lectura);
  delay(500);
}