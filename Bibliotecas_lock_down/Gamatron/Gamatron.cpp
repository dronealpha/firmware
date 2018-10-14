/*
 * Autor:Diego Silva
 * Data:13/10/2018
 * Descrição:Classe para pegar dados de ação do dispositivo
 * 
*/
#include <Arduino.h>
#include "Gamatron.h"

//método set e get para inicio de operacao
void Gamatron::setInicio(char ini){
	stini = ini;
}

char Gamatron::getInicio(){
	return stini;
}

//método set e get para inicio de funcao
void Gamatron::setFuncao(char fun){
	stfun = fun;
}

char Gamatron::getFuncao(){
	return stfun;
}


//método set get para acionar acao
void Gamatron::setAcao(char aco){
	stacao = aco;
}


char Gamatron::getAcao(){
	return stacao;
}

