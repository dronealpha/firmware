/*
 * Autor:Diego Silva
 * Data:27/10/2018
 * Descrição:Arquivo de cabeçalho para tramento de strings 
 * */

#include <Arduino.h>
#include "UsrInput.h"
void UsrInput::setComandoSerial(char comando[11]){
	int init;
	for(init=0; init < 11; init++){
		strComando[init] = comando[init];
		}
	
	
};


char UsrInput::RespotaComando(int posi){
	return strComando[posi];
}
