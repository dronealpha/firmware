/*
Autor:Diego Silva/ Wagner Miyahira
Data: 04/11/2018
Descrição: SensoresMonitora
*/

#ifndef SensoresMonitora_h
#define SensoresMonitora_h

#include <Arduino.h>

class SensoresMonitora{
	public:
		SensoresMonitora(int luz, int proximidade);
		void setLuminosidade(int valorluz);
		void setProximidade(int valorproxi);
		int getLuminosidade(void);
		int getProximidade(void);
		int getFlagLuminosidade(void);
		int getFlagProximidade(void);
		int getSetPointLuz(void);
		int getSetPointProximidade(void);
	private:
		int _Luz;
		int _Proxi;	
		int setpointLuz;
		int setpointProxi;
		
};
#endif
