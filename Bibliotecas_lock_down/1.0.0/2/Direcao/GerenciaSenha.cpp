/*
Autor:Diego Silva/ Wagner Miyahira
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

//retorna o primeiro digito
char GerenciaSenha::getPDigito(){
	return _pdigito;
}

//setando valor do segundo digito
void GerenciaSenha::setSDigito(char sdigito){
	_sdigito=sdigito;
}

//retorna o segundo digito
char GerenciaSenha::getSDigito(){
	return _sdigito;
}

//setando valor do terceiro digito
void GerenciaSenha::setTDigito(char tdigito){
	_tdigito=tdigito;
}

//retorna o terceiro digito
char GerenciaSenha::getTDigito(){
	return _tdigito;
}


//escrevendo senha na memoria eeprom
void GerenciaSenha::EscreveSenha(){
	
	EEPROM.write(0, ConvertValor(getPDigito()));
	EEPROM.write(1, ConvertValor(getSDigito()));
	EEPROM.write(2, ConvertValor(getTDigito()));

}

//método para retornar valor armazenado na eeprom
int GerenciaSenha::PegaSenha(int posi){
	int valor = EEPROM.read(posi);
	return valor;
}

//método para limpar memoria eeprom
void GerenciaSenha::Limpasenha(){
	int i;
	
	for (i = 0 ; i < EEPROM.length() ; i++) {
		EEPROM.write(i, 0);
	  }
}

//método para converte char para int
int GerenciaSenha::ConvertValor(char num){
	int valorconvert = num - '0';
	return valorconvert;
}
