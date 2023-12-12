//Autor: Mikael Mota Feitosa Sales
#include <Servo.h>

Servo meuServo;  // Cria um objeto de servo para controlar um servo motor

// --- Variáveis Globais --- 
int rpm;
volatile byte pulsos;
unsigned long timeold;
float v=0;
int pinoServo = 10;  // Pino ao qual o servo está conectado
int angulo = 0;


//Altere o numero abaixo de acordo com o seu disco encoder
unsigned int pulsos_por_volta = 20;

// ========================================================================================================
// --- Interrupção ---
void contador()
{
  //Incrementa contador
  pulsos++;
}


// ========================================================================================================
// --- Configurações Iniciais ---
void setup()
{
  Serial.begin(115200);
  meuServo.attach(pinoServo);  // Associa o objeto de servo ao pino de controle
 

  pinMode(2, INPUT);

  //Interrupcao 0 - pino digital 2
  //Aciona o contador a cada pulso
  attachInterrupt(0, contador, RISING);
  pulsos  = 0;
  rpm     = 0;
  timeold = 0;

} //end setup


// ========================================================================================================
// --- Loop Infinito ---
void loop()
{
 
  //Atualiza contador a cada segundo
  if (millis() - timeold >= 1000)
  {
    //Desabilita interrupcao durante o calculo
    detachInterrupt(0);
    rpm = (60 * 1000 / pulsos_por_volta ) / (millis() - timeold) * pulsos;
    timeold = millis();
    pulsos = 0;

    //m/s conversão
    v = (0.0038*rpm) + 1.479;
      Serial.print("M/S = "); 
      Serial.println(v, 2);

     if(v < 1.60){
      angulo = 0;
     }
     else if(v > 2.05 && v < 2.30){
       angulo = 15;
     }else if(v>2.30 && v < 3.2){
      angulo = 30;
     }

    meuServo.write(angulo); 
        Serial.print(angulo);
        Serial.println("º");
   
    attachInterrupt(0, contador, RISING);//2.40 ~ 2.60
    
  }
 
} //end loop


