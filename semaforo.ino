#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int s1  = 49;
int s2  = 48;
int s3  = 47;
int s4  = 44;
int s5 = 43;
int s6  = 52;
int s7  = 38;
int s8  = 42;
int s9  = 41;
int s10 = 53;

int auxDirecao = -1;
int direcao = 0; /*1 - direita; 2 - esquerda*/

const int A1E = 35;
const int A2E = 34;
const int A1D = 37;
const int A2D = 36;

const int B1E = 31;
const int B2E = 30;
const int B1D = 33;
const int B2D = 32;

const int C1D = 29;
const int C2D = 28;
const int C1E = 27;
const int C2E = 26;

const int D1D = 25;
const int D2D = 24;
const int D1E = 23;
const int D2E = 22;

int sentido(int sensor1, int sensor2){
     int estado = -1;
     if(digitalRead(sensor1) == 1){
          estado = 1;//HIGH
     }else if(digitalRead(sensor1) == 0){
          estado = 0;//LOW
     }
     if(digitalRead(sensor2)==HIGH && estado == 0){
          direcao = 2;//esquerda
     }
     else if(estado == 1 && digitalRead(sensor2)==HIGH ){
          direcao = 1;//direita
     }
     return direcao;
}

int detecta(int sensor1, int sensor2){
     int x = 1;
     if(digitalRead(sensor1) == HIGH || digitalRead(sensor2) == HIGH){
          x = 0;
     }
     return x;
}

int preferencia(int sensor1, int sensor2){
     int decide = -1;
     if(digitalRead(sensor1) == HIGH && digitalRead(sensor2) == HIGH){
          decide = 1;
     }else {
          decide = 0;
     }
     return decide;
}

void setup(){

lcd.begin(20, 4);

 //Mostra informacoes no display
  lcd.setCursor(3,0);
  lcd.print("Sinalização Subterrânia");
  lcd.setCursor(2,1);
  lcd.print("Display LCD 20x4");
  lcd.setCursor(1,3);
  lcd.print("arduinoecia.com.br");

Serial.begin(9600);

  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);
  pinMode(s6, INPUT);
  pinMode(s7, INPUT);
  pinMode(s8, INPUT);
  pinMode(s9, INPUT);
  pinMode(s10, INPUT);

  pinMode(A1E, OUTPUT);
  digitalWrite(A1E, HIGH);//verde

  pinMode(A2E, OUTPUT);
  digitalWrite(A2E, LOW);//vermelho

  pinMode(A1D, OUTPUT);
  digitalWrite(A1D, HIGH);//verde

  pinMode(A2D, OUTPUT);
  digitalWrite(A2D, LOW);//vermelho

  pinMode(B1D, OUTPUT);
  digitalWrite(B1D, HIGH);//verde

  pinMode(B1E, OUTPUT);
  digitalWrite(B1E, HIGH);//verde

  pinMode(B2D, OUTPUT);
  digitalWrite(B2D, LOW);//vermelho

  pinMode(B2E, OUTPUT);
  digitalWrite(B2E, LOW);//vermelho

  pinMode(C1D, OUTPUT);
  digitalWrite(C1D, HIGH);//verde

  pinMode(C2D, OUTPUT);
  digitalWrite(C2D, LOW);//vermeho

  pinMode(C1E, OUTPUT);
  digitalWrite(C1E, HIGH);//verde

  pinMode(C2E, OUTPUT);
  digitalWrite(C2E, LOW);//vermelho

  pinMode(D1D, OUTPUT);
  digitalWrite(D1D, HIGH);//verde

  pinMode(D2D, OUTPUT);
  digitalWrite(D2D, LOW);//vermelho

  pinMode(D2E, OUTPUT);
  digitalWrite(D2E, LOW);//vermelho

  pinMode(D1E, OUTPUT);
  digitalWrite(D1E, HIGH);//verde

}

void loop(){
   
 //SEMAFORO A
  if(detecta(s1,s2) == 0){
     auxDirecao = sentido(s1,s2);
          if(auxDirecao == 2){
               digitalWrite(A2E, LOW);//vermelho
               digitalWrite(A1E, HIGH);//verde
               digitalWrite(A1D, LOW);//verde
               digitalWrite(A2D, HIGH);//vermelho

               digitalWrite(B2E, LOW);//vermelho
               digitalWrite(B1E, HIGH);//verde
               digitalWrite(B1D, LOW);//verde
               digitalWrite(B2D, HIGH);//vermelho

               digitalWrite(C1E, HIGH);//verde
               digitalWrite(C2E, LOW);//vermelho
               digitalWrite(C1D, HIGH);//verde
               digitalWrite(C2D, LOW);//vermelho

               digitalWrite(D1E, HIGH);//verde
               digitalWrite(D2E, LOW);//vermelho
               digitalWrite(D1D, HIGH);//verde
               digitalWrite(D2D, LOW);//vermelho

          }else if(auxDirecao==1){
               digitalWrite(A2D, LOW);
               digitalWrite(A1D, HIGH);
               digitalWrite(A1E, HIGH);
               digitalWrite(A2E, LOW);

               digitalWrite(B2E, LOW);//vermelho
               digitalWrite(B1E, HIGH);//verde
               digitalWrite(B1D, HIGH);//verde
               digitalWrite(B2D, LOW);//vermelho

               digitalWrite(C1E, HIGH);//verde
               digitalWrite(C2E, LOW);//vermelho
               digitalWrite(C1D, HIGH);//verde
               digitalWrite(C2D, LOW);//vermelho

               digitalWrite(D1E, HIGH);//verde
               digitalWrite(D2E, LOW);//vermelho
               digitalWrite(D1D, HIGH);//verde
               digitalWrite(D2D, LOW);//vermelho

          }
     }

     //SEMAFORO B

     if(  preferencia(s3, s7)==1){
           //SEMAFORO D
     if(detecta(s7,s8) == 0){
     auxDirecao = sentido(s7,s8);
     Serial.println(auxDirecao);
          if(auxDirecao == 2){    
               digitalWrite(A1E, HIGH);//verde
               digitalWrite(A2E, LOW);//vermelho
               digitalWrite(A1D, HIGH);//verde
               digitalWrite(A2D, LOW);//vermelho

               digitalWrite(B1E, HIGH);//verde
               digitalWrite(B2E, LOW);//vermelho
               digitalWrite(B1D, HIGH);//verde
               digitalWrite(B2D, LOW);//vermelho

               digitalWrite(C1E, HIGH);//verde
               digitalWrite(C2E, LOW);//vermelho
               digitalWrite(C1D, HIGH);//verde
               digitalWrite(C2D, LOW);//vermelho

               digitalWrite(D1E, HIGH);//verde
               digitalWrite(D2E, LOW);//vermelho
               digitalWrite(D1D, LOW);//verde
               digitalWrite(D2D, HIGH);//vermelho
          }else if(auxDirecao==1){

               digitalWrite(A1E, HIGH);//verde
               digitalWrite(A2E, LOW);//vermelho
               digitalWrite(A1D, HIGH);//verde
               digitalWrite(A2D, LOW);//vermelho

               digitalWrite(B1E, LOW);//verde
               digitalWrite(B2E, HIGH);//vermelho
               digitalWrite(B1D, HIGH);//verde
               digitalWrite(B2D, LOW);//vermelho

               digitalWrite(C1E, LOW);//verde
               digitalWrite(C2E, HIGH);//vermelho
               digitalWrite(C1D, HIGH);//verde
               digitalWrite(C2D, LOW);//vermelho

               digitalWrite(D1E, HIGH);//verde
               digitalWrite(D2E, LOW);//vermelho
               digitalWrite(D1D, HIGH);//verde
               digitalWrite(D2D, LOW);//vermelho
          }
     }
     }else if(detecta(s3,s4) == 0){
     auxDirecao = sentido(s4,s3);
     
          if(auxDirecao == 2){
               digitalWrite(A1E, HIGH);//verde
               digitalWrite(A2E, LOW);//vermelho
               digitalWrite(A1D, HIGH);//verde
               digitalWrite(A2D, LOW);//vermelho

               digitalWrite(B1E, HIGH);//verde
               digitalWrite(B2E, LOW);//vermelho
               digitalWrite(B1D, LOW);//verde
               digitalWrite(B2D, HIGH);//vermelho

               digitalWrite(C1E, HIGH);//verde
               digitalWrite(C2E, LOW);//vermelho
               digitalWrite(C1D, LOW);//verde
               digitalWrite(C2D, HIGH);//vermelho
          }else if(auxDirecao==1){
               digitalWrite(A1E, LOW);//verde
               digitalWrite(A2E, HIGH);//vermelho
               digitalWrite(A1D, HIGH);//verde
               digitalWrite(A2D, LOW);//vermelho

               digitalWrite(B1E, HIGH);//verde
               digitalWrite(B2E, LOW);//vermelho
               digitalWrite(B1D, HIGH);//verde
               digitalWrite(B2D, LOW);//vermelho
          }
     }
     //SEMAFORO C
     if(detecta(s5,s6) == 0){
     auxDirecao = sentido(s5,s6);
     Serial.println(auxDirecao);
          if(auxDirecao == 2){     
               digitalWrite(A1E, HIGH);//verde
               digitalWrite(A2E, LOW);//vermelho
               digitalWrite(A1D, HIGH);//verde
               digitalWrite(A2D, LOW);//vermelho

               digitalWrite(B1E, HIGH);//verde
               digitalWrite(B2E, LOW);//vermelho
               digitalWrite(B1D, HIGH);//verde
               digitalWrite(B2D, LOW);//vermelho

               digitalWrite(C1E, HIGH);//verde
               digitalWrite(C2E, LOW);//vermelho
               digitalWrite(C1D, LOW);//verde
               digitalWrite(C2D, HIGH);//vermelho

               digitalWrite(D1E, HIGH);//verde
               digitalWrite(D2E, LOW);//vermelho
               digitalWrite(D1D, LOW);//verde
               digitalWrite(D2D, HIGH);//vermelho
          }else if(auxDirecao==1){
               digitalWrite(A1E, LOW);//verde
               digitalWrite(A2E, HIGH);//vermelho
               digitalWrite(A1D, HIGH);//verde
               digitalWrite(A2D, LOW);//vermelho

               digitalWrite(B1E, LOW);//verde
               digitalWrite(B2E, HIGH);//vermelho
               digitalWrite(B1D, HIGH);//verde
               digitalWrite(B2D, LOW);//vermelho

               digitalWrite(C1E, HIGH);//verde
               digitalWrite(C2E, LOW);//vermelho
               digitalWrite(C1D, HIGH);//verde
               digitalWrite(C2D, LOW);//vermelho

               digitalWrite(D1E, HIGH);//verde
               digitalWrite(D2E, LOW);//vermelho
               digitalWrite(D1D, HIGH);//verde
               digitalWrite(D2D, LOW);//vermelho
          }
     }

     //SEMAFORO D
     if(detecta(s7,s8) == 0){
     auxDirecao = sentido(s7,s8);
     Serial.println(auxDirecao);
          if(auxDirecao == 2){    
               digitalWrite(A1E, HIGH);//verde
               digitalWrite(A2E, LOW);//vermelho
               digitalWrite(A1D, HIGH);//verde
               digitalWrite(A2D, LOW);//vermelho

               digitalWrite(B1E, HIGH);//verde
               digitalWrite(B2E, LOW);//vermelho
               digitalWrite(B1D, HIGH);//verde
               digitalWrite(B2D, LOW);//vermelho

               digitalWrite(C1E, HIGH);//verde
               digitalWrite(C2E, LOW);//vermelho
               digitalWrite(C1D, HIGH);//verde
               digitalWrite(C2D, LOW);//vermelho

               digitalWrite(D1E, HIGH);//verde
               digitalWrite(D2E, LOW);//vermelho
               digitalWrite(D1D, LOW);//verde
               digitalWrite(D2D, HIGH);//vermelho
          }else if(auxDirecao==1){

               digitalWrite(A1E, HIGH);//verde
               digitalWrite(A2E, LOW);//vermelho
               digitalWrite(A1D, HIGH);//verde
               digitalWrite(A2D, LOW);//vermelho

               digitalWrite(B1E, LOW);//verde
               digitalWrite(B2E, HIGH);//vermelho
               digitalWrite(B1D, HIGH);//verde
               digitalWrite(B2D, LOW);//vermelho

               digitalWrite(C1E, LOW);//verde
               digitalWrite(C2E, HIGH);//vermelho
               digitalWrite(C1D, HIGH);//verde
               digitalWrite(C2D, LOW);//vermelho

               digitalWrite(D1E, HIGH);//verde
               digitalWrite(D2E, LOW);//vermelho
               digitalWrite(D1D, HIGH);//verde
               digitalWrite(D2D, LOW);//vermelho
          }
     }
     // if(digitalRead(s9)==HIGH){
     //      Serial.print("aquifunciona");
     // }

     if(detecta(s9,s10) == 0){
     auxDirecao = sentido(s9,s10);
     Serial.println(auxDirecao);
          if(auxDirecao == 2){    
               digitalWrite(A1E, HIGH);//verde
               digitalWrite(A2E, LOW);//vermelho
               digitalWrite(A1D, HIGH);//verde
               digitalWrite(A2D, LOW);//vermelho

               digitalWrite(B1E, HIGH);//verde
               digitalWrite(B2E, LOW);//vermelho
               digitalWrite(B1D, HIGH);//verde
               digitalWrite(B2D, LOW);//vermelho

               digitalWrite(C1E, HIGH);//verde
               digitalWrite(C2E, LOW);//vermelho
               digitalWrite(C1D, HIGH);//verde
               digitalWrite(C2D, LOW);//vermelho

               digitalWrite(D1E, HIGH);//verde
               digitalWrite(D2E, LOW);//vermelho
               digitalWrite(D1D, HIGH);//verde
               digitalWrite(D2D, LOW);//vermelho
          }else if(auxDirecao==1){

               digitalWrite(A1E, HIGH);//verde
               digitalWrite(A2E, LOW);//vermelho
               digitalWrite(A1D, HIGH);//verde
               digitalWrite(A2D, LOW);//vermelho

               digitalWrite(B1E, HIGH);//verde
               digitalWrite(B2E, LOW);//vermelho
               digitalWrite(B1D, HIGH);//verde
               digitalWrite(B2D, LOW);//vermelho

               digitalWrite(C1E, LOW);//verde
               digitalWrite(C2E, HIGH);//vermelho
               digitalWrite(C1D, HIGH);//verde
               digitalWrite(C2D, LOW);//vermelho

               digitalWrite(D1E, LOW);//verde
               digitalWrite(D2E, HIGH);//vermelho
               digitalWrite(D1D, HIGH);//verde
               digitalWrite(D2D, LOW);//vermelho
          }
     }
}

