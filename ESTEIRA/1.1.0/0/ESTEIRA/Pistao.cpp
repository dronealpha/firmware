/*
 *Autor: Diego Silva
 *Data:10/11/2018
 *Descrição:Biblioteca para trabalhar com sensor REGB
 */
#include <Arduino.h>
#include "Pistao.h"

//setando portas
Pistao::Pistao(int P1, int P2, int P3){
	_psA = P1;
	_psB = P2;
	_psC = P3;
}


//método para retorno de portas
int Pistao::getPistA(){
	return _psA;
}

int Pistao::getPistB(){
	return _psB;
}

int Pistao::getPistC(){
	return _psC;
}

//retorna se porta for acionada
void Pistao::AcionaPistao(int act){
	digitalWrite(act, HIGH);
}

void Pistao::DesativaPistao(int dct){
	digitalWrite(dct, LOW);
}
