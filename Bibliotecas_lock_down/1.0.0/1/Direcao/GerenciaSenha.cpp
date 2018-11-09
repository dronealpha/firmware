/*
Autor:Diego Silva
Data:06/11/2018
Descrição:código responsavel pela pilha de senhas e valida
*/

#include <Arduino.h>
#include "GerenciaSenha.h"
#include <EEPROM.h>



//setando valor do primeiro digito
void GerenciaSenha::setPDigito(char pdigito){
	_pdigito=pdigito;
}

char GerenciaSenha::getPDigito(){
	return _pdigito;
}

//setando valor do segundo digito
void GerenciaSenha::setSDigito(char sdigito){
	_sdigito=sdigito;
}

char GerenciaSenha::getSDigito(){
	return _sdigito;
}

//setando valor do terceiro digito
void GerenciaSenha::setTDigito(char tdigito){
	_tdigito=tdigito;
}

char GerenciaSenha::getTDigito(){
	return _tdigito;
}


//escrevendo senha na memoria eeprom
void GerenciaSenha::EscreveSenha(){
	int v1 = getPDigito() - '0';
	int v2 = getSDigito() - '0';
	int v3 = getTDigito() - '0';
	
	EEPROM.write(0, v1);
	EEPROM.write(1, v2);
	EEPROM.write(2, v3);

}

int GerenciaSenha::PegaSenha(int posi){
	int valor = EEPROM.read(posi);
	//int original=valor;
	return valor;
}


void GerenciaSenha::Limpasenha(){
	int i;
	
	for (i = 0 ; i < EEPROM.length() ; i++) {
		EEPROM.write(i, 0);
	  }
}
