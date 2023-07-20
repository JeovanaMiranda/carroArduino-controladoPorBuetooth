#include <SoftwareSerial.h>
#include <Servo.h>     // Adiciona a biblitoeca Servo
#include <Arduino.h>

SoftwareSerial bluetooth(2, 3);
//Definindo os pinos
#define trigPin A0     //Pino TRIG do sensor no pino analógico A0
#define echoPin A1     //Pino ECHO do sensor no pino analógico A1
#define trigPine A2   //Pino TRIG do sensor no pino analógico A2
#define echoPine A3    //Pino ECHO do sensor no pino analógico A3
 
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
char comando;



int DistanciaDireita, DistanciaEsquerda;  // variavel de Distâncias de ambos os lados
float Distancia = 0.00; 

void setup() {
  //Define os pinos como saida
 Serial.begin(38400);
  bluetooth.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
 
void loop() {
  while (bluetooth.available()) {
    comando = bluetooth.read();
    if (comando == 'B') {
      frent1();
    }
    else if (comando == 'F') {
      tras();
    }
    else if (comando == 'R') {
      esquerda();
    }
    else if (comando == 'L') {
      direita();
    } 
    else{
      parado();
    }
  }
}
 
void frent1(){
  //Gira o Motor A e B no sentido horario
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
 
void tras() {
  //Gira o Motor A e B no sentido anti-horario
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
 
void esquerda() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
 
void direita() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
 
void parado() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}
