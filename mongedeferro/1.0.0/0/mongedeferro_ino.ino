
//definido porta a ser usada
int port1 = 13;

//metodo para carregar configuracoes
void setup(){
  Serial.begin(9600);
  delay(1000);
  pinMode(port1,OUTPUT);
}

void loop(){
  LerDados();
  
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
    case 'S':
      delay(1000);
      Serial.println(StatusPort());
      break;
    case 'I':
      Letreiro();
      break;
    }
  
  }
  
}

//metodo que retornar se esta acionada ou nao porta
int StatusPort(){
  if(digitalRead(port1) == HIGH){//se porta estiver liga
    return 1; //retorna 1 = True
  }
  else{
    return 0; //retorna 0 = False
  }
}

//metodo para letreiro de apresentaçao
void Letreiro(){  
  Serial.println("###############################");
  Serial.println("#Firmware>>> Monge de Ferro   #");
  Serial.println("#Versao: 1.1.1                #");
  Serial.println("#Autor:Diego Lopes da Silva   #");
  Serial.println("#Propriedade: Drone Tecnologia#");
  Serial.println("###############################");
  
}

