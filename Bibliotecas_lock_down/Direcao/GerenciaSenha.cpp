/*
Autor:Diego Silva
Data:06/11/2018
Descrição:código responsavel pela pilha de senhas e valida
*/

#include <Arduino.h>
#include "GerenciaSenha.h"

//método para percorrer as posições da pilha para guardar os dados de senha
void GerenciaSenha::Push(char digito){
	int cont=0;
	if(cont < 3){
		pilhasenha[cont]=digito;
		cont++;
	}
}

//método para reset da pilha de senha
void GerenciaSenha::Pop(){
	int reset=0;
	pilhasenha[reset];
}

//método privado para retornar o valor da posição informada
char GerenciaSenha::SenhaDigito(int posi){
	return pilhasenha[posi];
}

//método recebe os tres digitos de senha informado 
int GerenciaSenha::FlagSenhaCorreta(char pdigito,char sdigito,char tdigito){
	//se a senha bater, ele retorna 1
	if((pdigito==SenhaDigito(0))&&(sdigito==SenhaDigito(1))&&(tdigito==SenhaDigito(2))){
		return 1;
	}else{
		//senão retorna 0
		return 0;
	}
}


