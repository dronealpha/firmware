//definido porta e constantes
int port13 = 13;
const int LM35 = 0;
float temperatura = 0;
int ADClido = 0;
const int Buzzer = 12;


//metodo para carregar configuracoes
void setup(){
  Serial.begin(9600);//start porta seria com frequencia de 9600 de transmissao
  delay(1000);
  pinMode(port13,OUTPUT);//informa porta 13 que vai ser usada para o modulo de rele
  analogReference(INTERNAL);//porta analogica de leitura de temperatura
  pinMode(Buzzer, OUTPUT);//porta digital para acionar alarme
}

void loop(){
  LerDados();
  Defcon();  
}


//metodo para ler dados da porta serial
void LerDados(){
  if(Serial.available()){//verifica se porta esta habilitada
      char entrada = Serial.read();//ler dados da porta
      switch (entrada) {
          case 'A'://ativa rele
            digitalWrite(port13,HIGH);
            break;
          case 'D'://desativa rele
            digitalWrite(port13,LOW);
            break;
          case 'S'://verifica se rele esta ativado
            delay(1000);
            Serial.println(StatusPort());
            break;
          case 'I'://exibe infomraçes do firmware
            Letreiro();
            break;
          case 'T':
            Serial.println(temp());
            break;
          }
        
    }
  
}

//metodo que retornar se esta acionada ou nao porta
int StatusPort(){
  if(digitalRead(port13) == HIGH){//se porta estiver liga
    return 1; //retorna 1 = True
  }
  else{
    return 0; //retorna 0 = False
  }
}

int temp(){//funçao para verificar temperatura
  ADClido = analogRead(LM35);
  temperatura = ADClido * 0.1075268817204301;
  return temperatura;
}

void Defcon(){
  if(temp() > 200){
    digitalWrite(port13,LOW);
  }
}
//metodo para letreiro de apresentaçao
void Letreiro(){  
  Serial.println("###############################");
  Serial.println("#Firmware>>> Monge de Ferro   #");
  Serial.println("#Versao: 1.1.2                #");
  Serial.println("#Autor:Diego Lopes da Silva   #");
  Serial.println("#Propriedade: Drone Tecnologia#");
  Serial.println("###############################");
  
}

