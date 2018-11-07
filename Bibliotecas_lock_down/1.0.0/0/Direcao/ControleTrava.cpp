/*
Autor:Diego Silva/ Wagner Miyahira
Data:21/10/2018
Descrição:Controle de trava
*/

#include <Arduino.h>
#include "ControleTrava.h"


void ControleTrava::setPorta(int porta){
	_porta=porta;//setando atributo privado _porta com parametro porta do metodo
}

void ControleTrava::setTrava(char acao){
	_acao=acao; //setando atributo privado _acao com parametro acao do metodo
}

int ControleTrava::getPorta(){
	return _porta; //retorna numero da porta arduino
}

char ControleTrava::getTrava(){
	return _acao; //retorna acao solicitada
}

void ControleTrava::operaTrava(){
	
	if(getTrava()=='2'){ //se get Trava receber comando 2 destrava porta
		digitalWrite(getPorta(),LOW);
	}
	
	if(getTrava()=='1'){ //se get Trava receber comando 1 trava porta
		digitalWrite(getPorta(),HIGH);
	}
}


