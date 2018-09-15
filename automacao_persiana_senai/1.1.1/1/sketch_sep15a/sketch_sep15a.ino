//includi de bibliotecas para trabalhar com servo motor e modulo bluetooth
#include "SoftwareSerial.h"
#include <Servo.h>

//criando nova serial para bluetooth
SoftwareSerial bluetooth(2, 3); //TX, RX (Bluetooth)

//craindo novo objeto para servo motor
Servo servoPersiana;

const int serPin = 13; //constante para porta do servo
char incomingByte;//varaivel para ler informacoes da porta serial
const int analogInPin = A0;// Pino analógico que o sensor está conectado
const int setpoint = 200;
int sensor = 0;


//carregando configuracoes do hardware
void setup() {
  //Inicializando serial bluetooth
  bluetooth.begin(9600);
  servoPersiana.attach(serPin);
  servoPersiana.write(0);
  delay(2000);
}

void loop() {
  //verifica se chegou alguma informaçao na porta
  if (bluetooth.available() > 0) {
    incomingByte = bluetooth.read();  
    switch(incomingByte){
      case'A':
        AbrirFechar(180,"Abrindo");
      break;
      case'F':
        AbrirFechar(0,"Fechando");
      break;
      case'M':
        LuminuVoid();
      break;
      case'C':
        ControleAuto();
      break;
      case'I':
        InfoMsg();
      break;      
    }
  }
}

//metodo para fechar e abrir persiana
void AbrirFechar(int i, char msg[25]){
  servoPersiana.write(i);
  bluetooth.println(msg);
}

void InfoMsg(){
  bluetooth.println("Persiana Senai");
  bluetooth.println("versio:1.1.1.1");
  bluetooth.println("Abrir = A");
  bluetooth.println("Fechar = F");
  bluetooth.println("Monitorar = M");
  bluetooth.println("Controle Automatico = C");
}

//Exibi luminosidade atual
void LuminuVoid(){
    sensor = analogRead(analogInPin);
    bluetooth.println("Luminosidade Atual");
    bluetooth.println(sensor);
    if(sensor >= setpoint){
      bluetooth.println("Claro");
    }else{
      bluetooth.println("Escuro");
    }
    delay(2000);
}

void ControleAuto(){
  while(true){
    sensor = analogRead(analogInPin);
    if(sensor >= setpoint){
      bluetooth.println("Luz OK");
    }
    else{
      sensor = map(sensor, 0, setpoint, 0, 180);
      bluetooth.println("Luminosidade Atual");
      bluetooth.println(sensor);
      servoPersiana.write(sensor);
    }
    
    delay(2000);
  }
}
