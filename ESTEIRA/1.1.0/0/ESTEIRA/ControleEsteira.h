

#ifndef ControleEsteira_h
#define ControleEsteira_h

#include <Arduino.h>
#include <EEPROM.h>

class ControleEsteira{
	
	public:
		void setDispenser(int cor);
		int getDispenser(void);
		void RegistraPeca(void);
		int VerificaPeca(void);
	private:
		int _cor;
	
};

#endif


