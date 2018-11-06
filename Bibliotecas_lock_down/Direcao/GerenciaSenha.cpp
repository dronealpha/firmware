/*
Autor:Diego Silva
Data:06/11/2018
Descri��o:c�digo responsavel pela pilha de senhas e valida
*/

#include <Arduino.h>
#include "GerenciaSenha.h"

//m�todo para percorrer as posi��es da pilha para guardar os dados de senha
void GerenciaSenha::Push(char digito){
	int cont=0;
	if(cont < 3){
		pilhasenha[cont]=digito;
		cont++;
	}
}

//m�todo para reset da pilha de senha
void GerenciaSenha::Pop(){
	int reset=0;
	pilhasenha[reset];
}

//m�todo privado para retornar o valor da posi��o informada
char GerenciaSenha::SenhaDigito(int posi){
	return pilhasenha[posi];
}

//m�todo recebe os tres digitos de senha informado 
int GerenciaSenha::FlagSenhaCorreta(char pdigito,char sdigito,char tdigito){
	//se a senha bater, ele retorna 1
	if((pdigito==SenhaDigito(0))&&(sdigito==SenhaDigito(1))&&(tdigito==SenhaDigito(2))){
		return 1;
	}else{
		//sen�o retorna 0
		return 0;
	}
}


