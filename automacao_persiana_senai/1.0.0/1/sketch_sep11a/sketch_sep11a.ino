//includi de bibliotecas para trabalhar com servo motor e modulo bluetooth
#include "SoftwareSerial.h"
#include <Servo.h>

//criando nova serial para bluetooth
SoftwareSerial bluetooth(2, 3); //TX, RX (Bluetooth)

//craindo novo objeto para servo motor
Servo servoPersiana;

const int serPin = 13; //constante para porta do servo
char incomingByte;      //varaivel para ler informacoes da porta serial


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
  bluetooth.println("----------------------------");
  bluetooth.println("------Persiana Senai--------");
  bluetooth.println("-------versio:1.0.0.0-------");
  bluetooth.println("---------Abrir = A----------");
  bluetooth.println("---------Fechar = F---------");
  bluetooth.println("----------------------------");
}
