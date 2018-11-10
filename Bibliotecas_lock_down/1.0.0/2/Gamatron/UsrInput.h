/*
 * Autor:Diego Silva
 * Data:27/10/2018
 * Descrição:Arquivo de cabeçalho para tramento de strings 
 * */

#ifndef UsrInput_h
#define UsrInput_h

#include <Arduino.h>

class UsrInput{
	public:
		void setComandoSerial(char comando[11]);
		char RespotaComando(int posi);
	private:
		char strComando[11];
};

#endif
