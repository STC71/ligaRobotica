/*************************************************
 * MUSIC NOTES
 *************************************************/
 
 #define NOTE_B0	31
 #define NOTE_C1	33
 #define NOTE_CS1 35
 #define NOTE_D1	37
 #define NOTE_DS1 39
 #define NOTE_E1	41
 #define NOTE_F1	44
 #define NOTE_FS1 46
 #define NOTE_G1	49
 #define NOTE_GS1 52
 #define NOTE_A1	55
 #define NOTE_AS1 58
 #define NOTE_B1	62
 #define NOTE_C2	65
 #define NOTE_CS2 69
 #define NOTE_D2	73
 #define NOTE_DS2 78
 #define NOTE_E2	82
 #define NOTE_F2	87
 #define NOTE_FS2 93
 #define NOTE_G2	98
 #define NOTE_GS2 104
 #define NOTE_A2	110
 #define NOTE_AS2 117
 #define NOTE_B2	123
 #define NOTE_C3	131
 #define NOTE_CS3 139
 #define NOTE_D3	147
 #define NOTE_DS3 156
 #define NOTE_E3	165
 #define NOTE_F3	175
 #define NOTE_FS3 185
 #define NOTE_G3	196
 #define NOTE_GS3 208
 #define NOTE_A3	220
 #define NOTE_AS3 233
 #define NOTE_B3	247
 #define NOTE_C4	262
 #define NOTE_CS4 277
 #define NOTE_D4	294
 #define NOTE_DS4 311
 #define NOTE_E4	330
 #define NOTE_F4	349
 #define NOTE_FS4 370
 #define NOTE_G4	392
 #define NOTE_GS4 415
 #define NOTE_A4	440
 #define NOTE_AS4 466
 #define NOTE_B4	494
 #define NOTE_C5	523
 #define NOTE_CS5 554
 #define NOTE_D5	587
 #define NOTE_DS5 622
 #define NOTE_E5	659
 #define NOTE_F5	698
 #define NOTE_FS5 740
 #define NOTE_G5	784
 #define NOTE_GS5 831
 #define NOTE_A5	880
 #define NOTE_AS5 932
 #define NOTE_B5	988
 #define NOTE_C6	1047
 #define NOTE_CS6 1109
 #define NOTE_D6	1175
 #define NOTE_DS6 1245
 #define NOTE_E6	1319
 #define NOTE_F6	1397
 #define NOTE_FS6 1480
 #define NOTE_G6	1568
 #define NOTE_GS6 1661
 #define NOTE_A6	1760
 #define NOTE_AS6 1865
 #define NOTE_B6	1976
 #define NOTE_C7	2093
 #define NOTE_CS7 2217
 #define NOTE_D7	2349
 #define NOTE_DS7 2489
 #define NOTE_E7	2637
 #define NOTE_F7	2794
 #define NOTE_FS7 2960
 #define NOTE_G7	3136
 #define NOTE_GS7 3322
 #define NOTE_A7	3520
 #define NOTE_AS7 3729
 #define NOTE_B7	3951
 #define NOTE_C8	4186
 #define NOTE_CS8 4435
 #define NOTE_D8	4699
 #define NOTE_DS8 4978
 #define REST 0

 #define BUZZER_PIN 2
 #define BOTTON1_PIN 13
 #define BOTTON2_PIN 12
 #define BOTTON3_PIN 11
 #define BOTTON4_PIN 10
 #define BOTTON5_PIN 9
 #define T 1000

// 1 TETRIS

int melody1[] = {
  NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4,
  NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
  NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
  NOTE_C5, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_C5,
  
  NOTE_D5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_F5,
  NOTE_E5, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
  NOTE_B4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
  NOTE_C5, NOTE_A4, NOTE_A4, REST, 
  
  NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4,
  NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
  NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
  NOTE_C5, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_C5,
  
  NOTE_D5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_F5,
  NOTE_E5, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
  NOTE_B4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
  NOTE_C5, NOTE_A4, NOTE_A4, REST, 
  
  NOTE_E5, NOTE_C5,
  NOTE_D5, NOTE_B4,
  NOTE_C5, NOTE_A4,
  NOTE_GS4, NOTE_B4, REST, 
  NOTE_E5, NOTE_C5,
  NOTE_D5, NOTE_B4,
  NOTE_C5, NOTE_E5, NOTE_A5,
  NOTE_GS5
};

int durations1[] = {
  4, 8, 8, 4, 8, 8,
  4, 8, 8, 4, 8, 8,
  4, 8, 4, 4,
  4, 4, 8, 4, 8, 8,
  
  4, 8, 4, 8, 8,
  4, 8, 4, 8, 8,
  4, 8, 8, 4, 4,
  4, 4, 4, 4,
  
  4, 8, 8, 4, 8, 8,
  4, 8, 8, 4, 8, 8,
  4, 8, 4, 4,
  4, 4, 8, 4, 8, 8,
  
  4, 8, 4, 8, 8,
  4, 8, 4, 8, 8,
  4, 8, 8, 4, 4,
  4, 4, 4, 4,
  
  2, 2,
  2, 2,
  2, 2,
  2, 4, 8, 
  2, 2,
  2, 2,
  4, 4, 2,
  2
};

// END TETRIS

// 2 THE GODFATHER
int melody2[] = {
  REST, REST, REST, REST, NOTE_E4, NOTE_A4, NOTE_C5,
  
  NOTE_B4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_F4, NOTE_G4,
  NOTE_E4, NOTE_E4, NOTE_A4, NOTE_C5,
  NOTE_B4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_E4, NOTE_DS4,

  NOTE_D4, NOTE_D4, NOTE_F4, NOTE_GS4,
  NOTE_B4, NOTE_D4, NOTE_F4, NOTE_GS4,
  NOTE_A4, NOTE_C4, NOTE_C4, NOTE_G4,
  NOTE_F4, NOTE_E4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_GS4,

  NOTE_A4, REST, NOTE_A4, NOTE_A4, NOTE_GS4,
  NOTE_G4, NOTE_B4, NOTE_A4, NOTE_F4,
  NOTE_E4, NOTE_E4, NOTE_G4, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_DS4,

  NOTE_E4, REST, NOTE_E4, NOTE_A4, NOTE_C5,

  //repeat
  NOTE_B4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_F4, NOTE_G4,
  NOTE_E4, NOTE_E4, NOTE_A4, NOTE_C5,
  NOTE_B4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_E4, NOTE_DS4,

  NOTE_D4, NOTE_D4, NOTE_F4, NOTE_GS4,
  NOTE_B4, NOTE_D4, NOTE_F4, NOTE_GS4,
  NOTE_A4, NOTE_C4, NOTE_C4, NOTE_G4,
  NOTE_F4, NOTE_E4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_GS4,

  NOTE_A4, REST, NOTE_A4, NOTE_A4, NOTE_GS4,
  NOTE_G4, NOTE_B4, NOTE_A4, NOTE_F4,
  NOTE_E4, NOTE_E4, NOTE_G4, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_DS4,

  NOTE_E4
};

int durations2[] = {
  4, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  2, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,

  2, 8, 8, 8,
  2, 8, 8, 8,
  2, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,

  2, 8, 8, 8, 8,
  2, 8, 8, 8,
  2, 8, 8, 8,
  2, 8, 8, 8, 8,

  2, 8, 8, 8, 8,

  //repeats
  8, 8, 8, 8, 8, 8, 8, 8,
  2, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,

  2, 8, 8, 8,
  2, 8, 8, 8,
  2, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,

  2, 8, 8, 8, 8,
  2, 8, 8, 8,
  2, 8, 8, 8,
  2, 8, 8, 8, 8,

  2
};
// END THE GODFATHER

// 3 PINK PANTHER

int melody3[] = {
  REST, REST, REST, NOTE_DS4, 
  NOTE_E4, REST, NOTE_FS4, NOTE_G4, REST, NOTE_DS4,
  NOTE_E4, NOTE_FS4,  NOTE_G4, NOTE_C5, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_B4,   
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4, 
  NOTE_E4, REST, REST, NOTE_DS4,
  
  NOTE_E4, REST, NOTE_FS4, NOTE_G4, REST, NOTE_DS4,
  NOTE_E4, NOTE_FS4,  NOTE_G4, NOTE_C5, NOTE_B4, NOTE_G4, NOTE_B4, NOTE_E5,
  NOTE_DS5,   
  NOTE_D5, REST, REST, NOTE_DS4, 
  NOTE_E4, REST, NOTE_FS4, NOTE_G4, REST, NOTE_DS4,
  NOTE_E4, NOTE_FS4,  NOTE_G4, NOTE_C5, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_B4,   
  
  NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4, 
  NOTE_E4, REST,
  REST, NOTE_E5, NOTE_D5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4,
  NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_AS4, NOTE_A4,   
  NOTE_G4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_E4
};

int durations3[] = {
  2, 4, 8, 8, 
  4, 8, 8, 4, 8, 8,
  8, 8,  8, 8, 8, 8, 8, 8,   
  2, 16, 16, 16, 16, 
  2, 4, 8, 4,
  
  4, 8, 8, 4, 8, 8,
  8, 8,  8, 8, 8, 8, 8, 8,
  1,   
  2, 4, 8, 8, 
  4, 8, 8, 4, 8, 8,
  8, 8,  8, 8, 8, 8, 8, 8,   
  
  2, 16, 16, 16, 16, 
  4, 4,
  4, 8, 8, 8, 8, 8, 8,
  16, 8, 16, 8, 16, 8, 16, 8,   
  16, 16, 16, 16, 16, 2
};

// END PINK PANTHER

// 4 GAME OF THRONES
int melody4[] = {
  NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
  NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
  NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4,
  NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4,
  NOTE_G4, NOTE_C4,
  
  NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
  NOTE_D4,
  NOTE_F4, NOTE_AS3,
  NOTE_DS4, NOTE_D4, NOTE_F4, NOTE_AS3,
  NOTE_DS4, NOTE_D4, NOTE_C4,
  
  NOTE_G4, NOTE_C4,
  
  NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
  NOTE_D4,
  NOTE_F4, NOTE_AS3,
  NOTE_DS4, NOTE_D4, NOTE_F4, NOTE_AS3,
  NOTE_DS4, NOTE_D4, NOTE_C4,
  NOTE_G4, NOTE_C4,
  NOTE_DS4, NOTE_F4, NOTE_G4,  NOTE_C4, NOTE_DS4, NOTE_F4,
  
  NOTE_D4,
  NOTE_F4, NOTE_AS3,
  NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_AS3,
  NOTE_C4,
  NOTE_C5,
  NOTE_AS4,
  NOTE_C4,
  NOTE_G4,
  NOTE_DS4,
  NOTE_DS4, NOTE_F4,
  NOTE_G4,
  
  NOTE_C5,
  NOTE_AS4,
  NOTE_C4,
  NOTE_G4,
  NOTE_DS4,
  NOTE_DS4, NOTE_D4,
  NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_AS4,
  NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_AS4,
  
  REST, NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_G5, NOTE_GS5, NOTE_AS5,
  NOTE_C6, NOTE_G5, NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_G5, NOTE_GS5, NOTE_AS5
};

int durations4[] = {
	8, 8, 16, 16, 8, 8, 16, 16,
	8, 8, 16, 16, 8, 8, 16, 16,
	8, 8, 16, 16, 8, 8, 16, 16,
	8, 8, 16, 16, 8, 8, 16, 16,
	4, 4,
	
	16, 16, 4, 4, 16, 16,
	1,
	4, 4,
	16, 16, 4, 4,
	16, 16, 1,
	
	4, 4,
	
	16, 16, 4, 4, 16, 16,
	1,
	4, 4,
	16, 16, 4, 4,
	16, 16, 1,
	4, 4,
	16, 16, 4, 4, 16, 16,
	
	2,
	4, 4,
	8, 8, 8, 8,
	1,
	2,
	2,
	2,
	2,
	2,
	4, 4,
	1,
	
	2,
	2,
	2,
	2,
	2,
	4, 4,
	8, 8, 16, 16, 8, 8, 16, 16,
	8, 8, 16, 16, 8, 8, 16, 16,
	
	4, 16, 16, 8, 8, 16, 16,
	8, 16, 16, 16, 8, 8, 16, 16
};
// END GAME OF THRONES

// THE SIMPSONS
int melody5[] = {
  NOTE_C4, NOTE_E4, NOTE_FS4, REST, NOTE_A4,
  NOTE_G4, NOTE_E4, NOTE_C4, NOTE_A3,
  NOTE_FS3, NOTE_FS3, NOTE_FS3, NOTE_G3, REST,
  NOTE_FS3, NOTE_FS3, NOTE_FS3, NOTE_G3, NOTE_AS3,
  NOTE_B3, REST
};

int durations5[] = {
  2, 4, 4, 32, 8,
  2, 4, 4, 8,
  8, 8, 8, 4, 2,
  8, 8, 8, 4, 2,
  2, 2
};
// END THE SIMPSONS

void setup()
{
	pinMode(BUZZER_PIN, OUTPUT);
    pinMode(BOTTON1_PIN, INPUT_PULLUP);
    pinMode(BOTTON2_PIN, INPUT_PULLUP);
  	pinMode(BOTTON3_PIN, INPUT_PULLUP);
	pinMode(BOTTON4_PIN, INPUT_PULLUP);
  	pinMode(BOTTON5_PIN, INPUT_PULLUP);
}

void loop() {

  	if (digitalRead(BOTTON1_PIN) == LOW) {

		int size = sizeof(durations1) / sizeof(int);

		for (int note = 0; note < size; note++) {
			//to calculate the note duration, take one second divided by the note type.
			//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
			int duration = T / durations1[note];
			tone(BUZZER_PIN, melody1[note], duration);

			//to distinguish the notes, set a minimum time between them.
			//the note's duration + 30% seems to work well:
			int pauseBetweenNotes = duration * 1.30;
			delay(pauseBetweenNotes);

			//stop the tone playing:
			noTone(BUZZER_PIN);
		}
	} 
  
  	if (digitalRead(BOTTON2_PIN) == LOW) {

		int size = sizeof(durations2) / sizeof(int);

		for (int note = 0; note < size; note++) {
			//to calculate the note duration, take one second divided by the note type.
			//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
			int duration = T / durations2[note];
			tone(BUZZER_PIN, melody2[note], duration);

			//to distinguish the notes, set a minimum time between them.
			//the note's duration + 30% seems to work well:
			int pauseBetweenNotes = duration * 1.30;
			delay(pauseBetweenNotes);

			//stop the tone playing:
			noTone(BUZZER_PIN);
		}
	} 
  
	if (digitalRead(BOTTON3_PIN) == LOW) {

		int size = sizeof(durations3) / sizeof(int);

		for (int note = 0; note < size; note++) {
			//to calculate the note duration, take one second divided by the note type.
			//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
			int duration = T / durations3[note];
			tone(BUZZER_PIN, melody3[note], duration);

			//to distinguish the notes, set a minimum time between them.
			//the note's duration + 30% seems to work well:
			int pauseBetweenNotes = duration * 1.30;
			delay(pauseBetweenNotes);

			//stop the tone playing:
			noTone(BUZZER_PIN);
		}
	}  
  
  	if (digitalRead(BOTTON4_PIN) == LOW) {

		int size = sizeof(durations4) / sizeof(int);

		for (int note = 0; note < size; note++) {
			//to calculate the note duration, take one second divided by the note type.
			//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
			int duration = T / durations4[note];
			tone(BUZZER_PIN, melody4[note], duration);

			//to distinguish the notes, set a minimum time between them.
			//the note's duration + 30% seems to work well:
			int pauseBetweenNotes = duration * 1.30;
			delay(pauseBetweenNotes);

			//stop the tone playing:
			noTone(BUZZER_PIN);
		}
	}
  
  	if (digitalRead(BOTTON5_PIN) == LOW) {

		int size = sizeof(durations5) / sizeof(int);

		for (int note = 0; note < size; note++) {
			//to calculate the note duration, take one second divided by the note type.
			//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
			int duration = T / durations5[note];
			tone(BUZZER_PIN, melody5[note], duration);

			//to distinguish the notes, set a minimum time between them.
			//the note's duration + 30% seems to work well:
			int pauseBetweenNotes = duration * 1.30;
			delay(pauseBetweenNotes);

			//stop the tone playing:
			noTone(BUZZER_PIN);
		}
	}
  
}