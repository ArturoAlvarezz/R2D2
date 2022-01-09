#include <Servo.h>      // incluye libreria de Servo

Servo servo1;     // crea objeto

int PINSERVO = 6;   // pin 2 conectado a señal del servo
int PULSOMIN = 1000;    // pulso minimo en microsegundos
int PULSOMAX = 2000;  

int IN13 = 2;      // IN1 de L298N a pin digital 2
int IN24 = 3;      // IN2 de L298N a pin digital 3
int ENAB = 5;      // ENA de L298N a pin digital 5

void setup(){
  pinMode(IN13, OUTPUT);   // pin 2 como salida
  pinMode(IN24, OUTPUT);   // pin 3 como salida  
  pinMode(ENAB, OUTPUT);   // pin 5 como salida
  servo1.attach(PINSERVO, PULSOMIN, PULSOMAX);  // inicializacion de servo
}


void loop(){
  digitalWrite(ENAB, HIGH);  // habilita motor A (giro en un sentido)
  digitalWrite(IN13, LOW); // IN1 a 0
  digitalWrite(IN24, HIGH);  // IN2 a 1
  //delay(3000);      // demora de 3 seg.

  digitalWrite(ENAB, LOW); // ENA en 0 para deshabilitar motor
  //delay(2000);      // demora de 2 seg.

  servo1.write(0);    // ubica el servo a 0 grados
  delay(5000);      // espera de 5 seg.
  servo1.write(180);    // ubica el servo a 180 grados
  delay(5000);    

}
