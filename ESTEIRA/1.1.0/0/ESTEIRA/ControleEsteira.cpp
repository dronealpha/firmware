#include <Arduino.h>
#include <EEPROM.h>
#include "ControleEsteira.h"

void ControleEsteira::setDispenser(int cor){
		_cor=cor;
}

int ControleEsteira::getDispenser(){
		return _cor;
}


void ControleEsteira::RegistraPeca(){
	EEPROM.write(0, getDispenser());
}

int ControleEsteira::VerificaPeca(){
	int valor = EEPROM.read(0);
	return valor;
}
