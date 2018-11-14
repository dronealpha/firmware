/*
 *Autor:Diego Silva
 *Data:10/11/2018
 *Descrição:Biblioteca para sensor RGB
 * */


#ifndef SensorRGB_h
#define SensorRGB_h
#include <Arduino.h>

class SensorRGB{
	public:
		//declarando métodos de entra para seta portas
		SensorRGB(int P1, int P2, int P3);
		int getportA(void);
		int getportB(void);
		int getportC(void);

		//decalrando métodos para retorna de portas
		int CheckInputGreen();
		int CheckInputYellow();
		int CheckInputBlue();
		
	private:
	    int _pA;
	    int _pB;
	    int _pC;
};
#endif
