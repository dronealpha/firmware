#include <Pistao.h>
#include <SensorRGB.h>
#include <ControleEsteira.h>

//variaveis para sensor
int a=11;
int b=12;
int c=13;

//Variaveis para pistao
int p1=7;
int p2=8;
int p3=9;

//instanciando classea
SensorRGB prod(a,b,c);
Pistao pist(p1,p2,p3);
ControleEsteira cst;

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

    //verifica qual peça
    if((entradaA==1)||(entradaB==1)||(entradaC==1)){

      //validação se peça verde ja passou
      if(entradaA == 1){
        Serial.println("Verde");
        if(cst.VerificaPeca()==1){
          Serial.println("Peça Repetida");
        }else{
          pist.AcionaPistao(pist.getPistB());
          delay(7000);
          pist.DesativaPistao(pist.getPistB());
          cst.setDispenser(1);
          cst.RegistraPeca();
        }
        
      }else if(entradaB == 1){
        Serial.println("Amarelo");

        //validação se peça amarelo ja passou
        if(cst.VerificaPeca()==2){
          Serial.println("Peça Repetida");
        }else{
          pist.DesativaPistao(pist.getPistC());
          delay(7000);
          pist.AcionaPistao(pist.getPistC());
          cst.setDispenser(2);
          cst.RegistraPeca();
        }
        
      }else if(entradaC==1){
        Serial.println("Azul");

        //validação se peça Azul ja passou
        if(cst.VerificaPeca()==3){
          Serial.println("Peça Repetida");
        }else{
          pist.AcionaPistao(pist.getPistC());
          delay(7000);
          pist.DesativaPistao(pist.getPistC());
          cst.setDispenser(3);
          cst.RegistraPeca();
        }
        
      }else{
        Serial.println("Vermelha");

        //validação se peça Vermelha ja passou
        if(cst.VerificaPeca()==4){
          Serial.println("Peça Repetida");
        }else{
          pist.AcionaPistao(pist.getPistB());
          delay(7000);
          pist.DesativaPistao(pist.getPistB());
          cst.setDispenser(4);
          cst.RegistraPeca();
        }
        
      }
    }
}
