/*
 *Autor:Diego Silva
 *Data:10/11/2018
 *Descrição:Biblioteca para sensor RGB
 * */

#ifndef Pistao_h
#define Pistao_h
#include <Arduino.h>

class Pistao{
	public:
		//declarando métodos de entra para seta portas
		Pistao(int P1, int P2, int P3);
		int getPistA(void);
		int getPistB(void);
		int getPistC(void);

		//Ativa pistao
		void AcionaPistao(int act);
		void DesativaPistao(int dct);
	private:
	    int _psA;
	    int _psB;
	    int _psC;
};
#endif
