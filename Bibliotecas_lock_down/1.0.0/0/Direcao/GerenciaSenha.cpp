/*
Autor:Diego Silva
Data:06/11/2018
Descrição:código responsavel pela pilha de senhas e valida
*/

#include <Arduino.h>
#include "GerenciaSenha.h"



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

int GerenciaSenha::FlagSenhaCorreta(char dig1,char dig2,char dig3){
	if((dig1==getPDigito())&&(dig2==getSDigito())&&(dig3==getTDigito())){
		return 1;
	}else{
		return 0;
	}
}
