/*
Autor:Diego Silva/ Wagner Miyahira
Data: 04/11/2018
Descrição: SensoresMonitora
*/


#include <Arduino.h>
#include "SensoresMonitora.h"

SensoresMonitora::SensoresMonitora(int luz, int proximidade){//chamando construtor para chamar atributo
	setpointLuz=luz;
	setpointProxi=proximidade;
}
void SensoresMonitora::setLuminosidade(int valorluz){
	_Luz=valorluz; 
}

void SensoresMonitora::setProximidade(int valorproxi){
	_Proxi=valorproxi;
}

int SensoresMonitora::getLuminosidade(){
	return _Luz;
}

int SensoresMonitora::getProximidade(){
	return _Proxi;
}

int SensoresMonitora::getSetPointLuz(){
	return setpointLuz;
}

int SensoresMonitora::getSetPointProximidade(){
	return setpointProxi;
}

int SensoresMonitora::getFlagLuminosidade(){
	if (getLuminosidade()>getSetPointLuz()){
		return 1;
	} 	else{
		return 0;
	}
	
}
	
int SensoresMonitora::getFlagProximidade(){
	if (getProximidade()==getSetPointProximidade()){
		return 0;
	}	else{
		return 1;
	}
	
}
