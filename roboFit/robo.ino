#include <Servo.h>
#include <HCSR04.h>

#define p1m1 4
#define p2m1 5
#define pvelm1 3

#define p1m2 7
#define p2m2 8
#define pvelm2 6

#define tmp 1000
#define tmp_giro 500

#define pservo 10

#define p_trigger 11
#define p_echo 12

Servo servo;
UltraSonicDistanceSensor distanceSensor(p_trigger, p_echo);

int vel;
float dist_cm, distanciaMinima=40;

class Motor{
  public:
    int p1, p2, pv;
    Motor(int p1, int p2, int v){
      this->p1=p1;
      this->p2=p2;
      this->pv=v;

      pinMode(p1, OUTPUT);
      pinMode(p2, OUTPUT);
      pinMode(pv, OUTPUT);
      digitalWrite(p1, LOW);
      digitalWrite(p2, LOW);
      analogWrite(pv, 0);

    }

    void frente(int v){
      digitalWrite(p1, HIGH);
      digitalWrite(p2, LOW);
      analogWrite(pv, v);
    }
    void tras(int v){
      digitalWrite(p1, LOW);
      digitalWrite(p2, HIGH);
      analogWrite(pv, v);
    }
    void para(){
      digitalWrite(p1, LOW);
      digitalWrite(p1, LOW);
      analogWrite(pv, 0);
    }
    void freia(){
      digitalWrite(p1, LOW);
      digitalWrite(p1, LOW);
      analogWrite(pv, 255);
    }
};

Motor *me= new Motor(p1m1, p2m1, pvelm1);
Motor *md= new Motor(p1m2, p2m2, pvelm2);


void esquerda(int v){
  md->frente(v);
  me->tras(v);
}
void direita(int v){
  md->tras(v);
  me->frente(v);
 
}
void frente(int v){
  md->frente(v);
  me->frente(v);
}
void tras(int v){
  md->tras(v);
  me->tras(v);
}
void para(){
  md->para();
  me->para();
}

void freia(){
  md->freia();
  me->freia();
}
void escolherLado(){
  float d1,d2;//d1 = direira, d2 = esqueda
  d1=d2=0;
  delay(500);
  servo.write(0);//direita
  delay(500);
  d1=distanceSensor.measureDistanceCm();
  delay(250);
  servo.write(180);
  delay(750);
  d2=distanceSensor.measureDistanceCm();
  delay(250);
  servo.write(90);
  delay(250);
  Serial.print("Direita.: ");Serial.println(d1);
  Serial.print("Esquerda.: ");Serial.println(d2);
  if(d1>d2){
    Serial.println("Virando para direita");
    direita(vel);
    delay(tmp_giro);
  }else{
    Serial.println("Virando para esquerda");
    esquerda(vel);
    delay(tmp_giro);
  }
  Serial.println("-----------------------------------------------");
}

void setup(){
  vel=255;
  servo.attach(pservo);
  servo.write(90); 
  Serial.begin(9600);
}

void loop(){
  dist_cm = distanceSensor.measureDistanceCm();
  if(dist_cm < distanciaMinima && dist_cm != -1){
    freia();
    escolherLado();
  }else{
    frente(vel);
  }
}




