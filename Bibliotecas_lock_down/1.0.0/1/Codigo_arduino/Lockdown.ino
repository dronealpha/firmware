#include <Direcao.h>
#include <Gamatron.h>
#include <UsrInput.h>


//Instanciando classes
Gamatron gama;//classe para seta informações de entrada
UsrInput input;//classe para pegar informações de input via porta
Direcao direct;//classe para direcionar operações a serem realizadas


//variaveis globais para lidar com entrada de dados
String a; 
char comando[11];

//Carregando configurações de porta serial
void setup() {
  pinMode(13,OUTPUT);//porta de saida para trava
  Serial.begin(9600);//start porta serial com frequencia de 9600 de transmissao
  delay(1000);

}

void loop() {
   while(Serial.available()){

      /*
        Entrada de dados via serial
      */
      
      a = Serial.readString();
      DadosEntrada(a);
      gama.Entrada();
      //Serial.println(entry);
      //Carregando para métodos set parametros de comando 
      input.setComandoSerial(comando);
      
      gama.setInicio(input.RespotaComando(0));
      gama.setFuncao(input.RespotaComando(8));
      gama.setAcao(input.RespotaComando(9));
    
      //Exibindo parametros
      Serial.println(gama.getInicio());
      Serial.println(gama.getFuncao());
      Serial.println(gama.getAcao());

      direct.setSenhaDigito1(input.RespotaComando(3));
      direct.setSenhaDigito2(input.RespotaComando(4));
      direct.setSenhaDigito3(input.RespotaComando(5));

      direct.setInit(gama.getInicio());
      direct.setFun(gama.getFuncao());
      direct.setAcao(gama.getAcao());
      
      direct.executacao();
      Serial.println("Fim de operacao");
  }
   
  
}

//função para carregar dados de entrada no vetor de comandos
void DadosEntrada(String dados){
  int laco;
  char copy[11];
  dados.toCharArray(copy,11);
  for(laco=0;laco<11; laco++){
    comando[laco]=copy[laco];
  }
}
