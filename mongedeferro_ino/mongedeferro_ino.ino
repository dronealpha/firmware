
//definido porta a ser usada
int port1 = 13;

//metodo para carregar configuracoes
void setup(){
  Serial.begin(9600);
  delay(1000);
  Letreiro();
  pinMode(port1,OUTPUT);
}

void loop(){
  LerDados();
  
}

//mtodo para letreiro de apresentaçao
void Letreiro(){  
  Serial.println("###############################");
  Serial.println("#Firmware>>> Monge de Ferro   #");
  Serial.println("#Versao: 1.0.0                #");
  Serial.println("#Autor:Diego Lopes da Silva   #");
  Serial.println("#Propriedade: Drone Tecnologia#");
  Serial.println("###############################");
  
}

//metodo para ler dados da porta serial
void LerDados(){
  if(Serial.available()){
    char entrada = Serial.read();
    switch (entrada) {
    case 'A':
      digitalWrite(port1,HIGH);
      break;
    case 'D':
      digitalWrite(port1,LOW);
      break;
    }
  
  }
  
}

