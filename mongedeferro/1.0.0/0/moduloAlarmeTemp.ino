//definindo variaveis e constantes

const int LM35 = 0;
float temperatura = 0;
int ADClido = 0;
const int Buzzer = 13;

//carrega configuraçes de portas
void setup(){
  Serial.begin(9600);
  analogReference(INTERNAL);//porta analogica de leitura de temperatura
  pinMode(Buzzer, OUTPUT);//porta digital para acionar alarme
}

//loop de funcoes
void loop(){
  
  //verifica se a porta serial est habilitada
  if(Serial.available()){
    char entrada = Serial.read();//captura entrada
    switch(entrada){
      case 'L'://sendo entra L ligar
        tone(Buzzer,2000);
        break;
      case 'D'://sendo entrada D desligar
        noTone(Buzzer);
        break;
    }
  }
  MonitoraTemp();  
}

//funcao para monitorar temperatura
void MonitoraTemp(){
  ADClido = analogRead(LM35);
  temperatura = ADClido * 0.1075268817204301;
  
  if(temperatura > 25){
    delay(2000);
    Serial.println("Nivel Critico");
    Serial.println("Temperatura atual  de");
    Serial.println(temperatura);
  }
  else{
    delay(2000);
    Serial.println("Nivel Baixo");
    Serial.println("Temperatura atual  de");
    Serial.println(temperatura);
  }
}


