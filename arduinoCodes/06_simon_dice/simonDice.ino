//Juego Simon dice

#define   BUZ   7
#define   BOTTON_A  13
#define   BOTTON_B  12
#define   BOTTON_C  11
#define   BOTTON_D  10
#define   LED_A   2
#define   LED_B   3
#define   LED_C   4
#define   LED_D   5

int melodia[ ] = {262, 196, 196, 220, 196, 0, 247, 262};
int duracionNotas[] = {4, 8, 8, 4, 4, 4, 4, 4};
int nivelActual = 1;
int velocidad = 500;
const int NIVEL_MAX = 100;
int secuencia[NIVEL_MAX];
int secuenciaUsuario[NIVEL_MAX];

void setup(){
   pinMode(BOTTON_D, INPUT);
   pinMode(BOTTON_C, INPUT);
   pinMode(BOTTON_B, INPUT);
   pinMode(BOTTON_A, INPUT);
   pinMode(LED_A, OUTPUT);
   pinMode(LED_B, OUTPUT);
   pinMode(LED_C, OUTPUT);
   pinMode(LED_D, OUTPUT);
   digitalWrite(LED_A, LOW);
   digitalWrite(LED_B, LOW);
   digitalWrite(LED_C, LOW);
   digitalWrite(LED_D, LOW);
}

void loop(){
   if(nivelActual == 1){
      generaSecuencia();
      muestraSecuencia();
      leeSecuencia();
   }
   if(nivelActual != 1){
      muestraSecuencia();
      leeSecuencia();
   }
}

void muestraSecuencia(){
   digitalWrite(LED_A, LOW);
   digitalWrite(LED_B, LOW);
   digitalWrite(LED_C, LOW);
   digitalWrite(LED_D, LOW);
   for(int i = 0; i < nivelActual; i++){
      if( secuencia[i] == LED_A ){
         tone(BUZ, 200);
         delay(200);
         noTone(BUZ);
      }
      if( secuencia[i] == LED_B ){
         tone(BUZ, 300);
         delay(200);
         noTone(BUZ);
      }
      if( secuencia[i] == LED_C ){
         tone(BUZ, 400);
         delay(200);
         noTone(BUZ);
      }
      if( secuencia[i] == LED_D ){
         tone(BUZ, 500);
         delay(200);
         noTone(BUZ);
      }
      digitalWrite(secuencia[i], HIGH);
      delay(velocidad);
      digitalWrite(secuencia[i], LOW);
      delay(200);
   }
}

void leeSecuencia(){
   int flag = 0;
   for(int i = 0; i < nivelActual; i++){
      flag = 0;
      while(flag == 0){
         if(digitalRead(BOTTON_D) == LOW){
            digitalWrite(LED_D, HIGH);
            tone(BUZ, 500);
            delay(300);
            noTone(BUZ);
            secuenciaUsuario[i] = LED_D;
            flag = 1;
            delay(200);
            if(secuenciaUsuario[i] != secuencia[i]){
               secuenciaError();
               return;
            }
            digitalWrite(LED_D, LOW);
         }
         if(digitalRead(BOTTON_C) == LOW){
            digitalWrite(LED_C, HIGH);
            tone(BUZ, 400);
            delay(300);
            noTone(BUZ);
            secuenciaUsuario[i] = LED_C;
            flag = 1;
            delay(200);
            if(secuenciaUsuario[i] != secuencia[i]){
               secuenciaError();
               return;
            }
            digitalWrite(LED_C, LOW);
         }
         if(digitalRead(BOTTON_B) == LOW){
            digitalWrite(LED_B, HIGH);
            tone(BUZ, 300);
            delay(300);
            noTone(BUZ);
            secuenciaUsuario[i] = LED_B;
            flag = 1;
            delay(200);
            if(secuenciaUsuario[i] != secuencia[i]){
               secuenciaError();
               return;
            }
            digitalWrite(LED_B, LOW);
         }
         if(digitalRead(BOTTON_A) == LOW){
            digitalWrite(LED_A, HIGH);
            tone(BUZ, 200);
            delay(300);
            noTone(BUZ);
            secuenciaUsuario[i] = LED_A;
            flag = 1;
            delay(200);
            if(secuenciaUsuario[i] != secuencia[i]){
               secuenciaError();
               return;
            }
            digitalWrite(LED_A, LOW);
         }
      }
   }
   secuenciaCorrecta();
}

void generaSecuencia(){
   randomSeed(millis());
   for(int i = 0; i < NIVEL_MAX; i++){
      secuencia[i] = random(2,6);
   }
}

void melodiaError(){
   for(int i = 0; i < 8; i++){
      int duracionNota = 1000/duracionNotas[i];
      tone(BUZ, melodia[i], duracionNota); // Corrección aquí
      int pausaEntreNotas = duracionNota * 1.30;
      delay(pausaEntreNotas);
      noTone(BUZ);
   }
}

void secuenciaError(){
   digitalWrite(LED_A, HIGH);
   digitalWrite(LED_B, HIGH);
   digitalWrite(LED_C, HIGH);
   digitalWrite(LED_D, HIGH);
   delay(250);
   digitalWrite(LED_A, LOW);
   digitalWrite(LED_B, LOW);
   digitalWrite(LED_C, LOW);
   digitalWrite(LED_D, LOW);
   delay(250);
   melodiaError();
   nivelActual = 1;
   velocidad = 500;
}

void secuenciaCorrecta(){
   if(nivelActual < NIVEL_MAX)
      nivelActual++;
   velocidad -= 50;
   delay(200);
}