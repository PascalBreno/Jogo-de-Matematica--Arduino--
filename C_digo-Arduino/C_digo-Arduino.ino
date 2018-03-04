#include <LiquidCrystal.h>
#define RIGHT  3100
#define WRONG  1000


//INICIO MUSICA MÁRIO

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
 
#define melodyPin 3
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

//FIM DO CÓDIGO DA MUSICA DO MARIO

LiquidCrystal lcd(52, 53, 50, 51, 48, 49);

int numero1, numero2, numero3,resultado;
int pontos =0;
int buzzer = 42;
int ledverd = 40;
int ledverm = 41;
int sim;
int nao;

float valida = 0; 
unsigned long time=0;
unsigned long inicio=0;             
int s, su=0,sd=0;
String operando="";

void setup() {
    randomSeed(analogRead(A0));
    pinMode(44, INPUT_PULLUP);
    pinMode(45, INPUT_PULLUP);
    pinMode(buzzer, OUTPUT);
    pinMode(ledverd, OUTPUT);
    pinMode(ledverm, OUTPUT);
    rodada();
}

void loop() { 
      if(sd<2){
       tempos();
       funcao();
     }     
}
void fim(){
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("FIM DE JOGO");
  lcd.setCursor(3, 1);
  lcd.print("Pontos:");
  lcd.setCursor(11, 1);
  lcd.print(pontos);
  sing();
}

void tempos(){
    time = millis()-inicio;  
    s=(time/1000)%60;
    su=s%10;                            
    sd=(s-su)/10;
    lcd.setCursor(12,0);
    lcd.print("T");
    lcd.setCursor(13,0);
    lcd.print(":");
    lcd.print(sd);
    lcd.print(su);
    lcd.setCursor(12, 2);
    lcd.print("P:");
    lcd.setCursor(14, 2);
    lcd.print(pontos);
}
void funcao(){
      do{
        tempos();
        sim = digitalRead(44);
        nao = digitalRead(45);
        if (sim==0) {
          sim = 0;
          check(sim);
          return;
        } else if (nao == 0) {
          nao = 1;
          check(nao);        
          return;          
        }
      }while(sd<2);
      fim();
}


int resposta(int *numero){
  int aleatorio = random(0, 3);
  if(aleatorio!=0){
    *numero = *numero+random(1,9);
  }
  return aleatorio;

}
void rodada(){
    numero1 = random(1,9);
    numero2 = random(1,9);
    numero3 = random(1,5);
    int temp =0;
    switch(numero3)
    {
      case 1:
        operando="+";
        resultado=numero1+numero2;
        break;
      case 2:
        operando="-";
          if(numero1<numero2)
          {
            temp=numero1;
            numero1=numero2;
            numero2=temp;
          }
        resultado=numero1-numero2;    
        break;
       case 3:
        operando="*";
        resultado=numero1*numero2;       
        break;
       case 4:
         operando="/";
         resultado=numero1%numero2;
         if(resultado!=0)
         {
           operando="*";
           resultado=numero1*numero2;       
         }
         else
         {
           resultado=numero1/numero2;
         }
    }
          
    valida = resposta(&resultado);
    lcd.begin(16, 2);
    lcd.print(numero1);
    lcd.setCursor(2,0);
    lcd.print(operando);
    lcd.setCursor(4,0);
    lcd.print(numero2);
    lcd.print(" = ");
    lcd.print(resultado);
}
   



void check(int ans) {
  
  if (ans == valida || ans == valida/2) {
      lcd.setCursor(0, 1);
      lcd.print("Acertou");
      pontos=pontos+1;
      ToneAcertar();
      rodada();
    } else {
      lcd.setCursor(0, 1);
      lcd.print("Errou");
      pontos=pontos-1;
      ToneErrar();
      rodada();
    }
}

void ToneAcertar(){
  tone(buzzer, RIGHT, 500);
  digitalWrite(ledverd,HIGH);
  delay(200);
  noTone(buzzer);
  digitalWrite(ledverd,LOW);
  delay(100);
}

void ToneErrar(){
  tone(buzzer, WRONG);
  digitalWrite(ledverm,HIGH);
  delay(100);
  noTone(buzzer);
  digitalWrite(ledverm,LOW);
  delay(100);
  tone(buzzer, WRONG);
  digitalWrite(ledverm,HIGH);
  delay(100);
  noTone(buzzer);
  digitalWrite(ledverm,LOW);
}

void buzz(int targetPin, long frequency, long length) {
  digitalWrite(ledverd, HIGH);
  digitalWrite(ledverm, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  digitalWrite(ledverd, LOW);
  digitalWrite(ledverm, LOW);
 
}

void sing() { 
    Serial.println(" 'Mario Theme'");
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 1000 / tempo[thisNote];
 
      buzz(buzzer, melody[thisNote], noteDuration);
 
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      buzz(buzzer, 0, noteDuration);
 
    }
}



