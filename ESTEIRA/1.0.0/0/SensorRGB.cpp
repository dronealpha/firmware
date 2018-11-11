/*
 *Autor: Diego Silva
 *Data:10/11/2018
 *Descrição:Biblioteca para trabalhar com sensor REGB
 */
#include <Arduino.h>
#include "SensorRGB.h"

//setando portas
SensorRGB::SensorRGB(int P1, int P2, int P3){
	_pA = P1;
	_pB = P2;
	_pC = P3;
}



//método para retorno de portas
int SensorRGB::getportA(){
	return _pA;
}

int SensorRGB::getportB(){
	return _pB;
}

int SensorRGB::getportC(){
	return _pC;
}

//retorna se porta for acionada
int SensorRGB::CheckInputGreen(){
	if(digitalRead(getportA()) == HIGH){
		return 1;
	}else{
		return 0;
	}
}


int SensorRGB::CheckInputYellow(){
	if(digitalRead(getportB()) == HIGH){
		return 1;
	}else{
		return 0;
	}
}

int SensorRGB::CheckInputBlue(){
	if(digitalRead(getportC()) == HIGH){
		return 1;
	}else{
		return 0;
	}
}
