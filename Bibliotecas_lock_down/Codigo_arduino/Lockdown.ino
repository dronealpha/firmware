#include <Direcao.h>
#include <Gamatron.h>
//#include <UsrInput.h>

//Instanciando classe Gamatron
Gamatron gama;
//UsrInput in;
String a;

//Carregando configurações de porta serial
void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);//start porta serial com frequencia de 9600 de transmissao
  delay(1000);

}

void loop() {
  delay(2000);
   while(Serial.available()){
    a = Serial.readString();
    //in.setComandoSerial(a);
    Serial.println(a);
      gama.Entrada();
      char senha[4]="789";
      Serial.print("Entrada Recebida");
      //Serial.println(entry);
      //Carregando para métodos set parametros de comando 
      gama.setInicio(Posi(0));
      gama.setFuncao(Posi(8));
      gama.setAcao(Posi(9));
    
      //Exibindo parametros
      Serial.println(gama.getInicio());
      Serial.println(gama.getFuncao());
      Serial.println(gama.getAcao());
    
      //Instanciando classe direção e inicializando atributos
      Direcao direct;
      direct.setSenhaDigito1('A');
      direct.setSenhaDigito2('B');
      direct.setSenhaDigito3('C');

      direct.setInit(gama.getInicio());
      direct.setFun(gama.getFuncao());
      direct.setAcao(gama.getAcao());
      
      //digitalWrite(13,HIGH);
      //delay(2000);
      direct.executacao();
      delay(2000);
      direct.setAcao('2');
      direct.executacao();
  }
  
  
}


char Posi(int po){
  char comando[11]="10078900f1";
  return comando[po]; 
}
