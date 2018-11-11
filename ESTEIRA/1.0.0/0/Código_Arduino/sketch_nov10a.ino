#include <Pistao.h>
#include <SensorRGB.h>

//variaveis para sensor
int a=11;
int b=12;
int c=13;

//Variaveis para pistao
int p1=7;
int p2=8;
int p3=9;

SensorRGB prod(a,b,c);
Pistao pist(p1,p2,p3);


//Declarando variaveis para entradas
int entradaA=0;
int entradaB=0;
int entradaC=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(a,INPUT);
  pinMode(b,INPUT);
  pinMode(c,INPUT);
  pinMode(p1,OUTPUT);
  pinMode(p2,OUTPUT);
  pinMode(p3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(prod.CheckInputGreen());
  entradaA = prod.CheckInputGreen();
  entradaB = prod.CheckInputYellow();
  entradaC = prod.CheckInputBlue();

  if((entradaA==1)||(entradaB==1)||(entradaC==1)){
    if(entradaA == 1){
      Serial.println("Verde");
      pist.AcionaPistao(pist.getPistA());
      delay(5000);
      pist.DesativaPistao(pist.getPistA());
      
    }else if(entradaB == 1){
      Serial.println("Amarelo");
      pist.AcionaPistao(pist.getPistB());
      delay(5000);
      pist.DesativaPistao(pist.getPistB());
    }else{
      Serial.println("Azul");
      pist.AcionaPistao(pist.getPistC());
      delay(5000);
      pist.DesativaPistao(pist.getPistC());
    }
    
  }
  
}
