/*
 * Autor: Diego Silva
 * Data: 13/10/2018
 * Descrição:Classe para direcionar para ação desejada
 */

#include <Arduino.h>
#include "Direcao.h"


//Construtor da classe 
Direcao::Direcao(char ini, char fun, char acao){
	stini = ini;
	stfun = fun;
	stacao = acao;
}

void Direcao::setSenhaDigito1(char senha1){
	stSenha = senha;
}

char Direcao::getSenhaDigito1(){
	return stSenha;
}

void Direcao::setSenhaDigito2(char senha2){
	stSenha = senha;
}

char Direcao::getSenhaDigito2(){
	return stSenha1;
}


void Direcao::setSenhaDigito3(char senha3){
	stSenha = senha2;
}

char Direcao::getSenhaDigito3(){
	return stSenha3;
}
//método para direcionar usuário até ação
void Direcao::executacao(){
	if(stini=='1'){//verifica byte de start
		if(stfun=='f'){//verifica byte de função
			if(stacao=='0'){//verifica ação a ser realizada
			}else{
				Serial.println("Acao Invalido");
				}
		}else{
			Serial.println("Funcao Invalido");
		}
	}else{
		Serial.println("Comando Invalido");
	}
}
