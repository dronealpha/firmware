/*
Autor:Diego Silva/ Wagner Miyahira
Data:21/10/2018
Descri��o:Controle de trava
*/

#ifndef ControleTrava_h
#define ControleTrava_h

#include <Arduino.h>

class ControleTrava{
	public:
		void setPorta(int porta); //void pois n�o retorna info seta numero da porta arduino
		void setTrava(char acao);//void pois n�o retorna info seta acao trava 
		int getPorta(void); //int pois retorna o numero da porta do arduino
		char getTrava(void); // entrada de comando trava, deste sai a inteligencia para comandar portas
		void operaTrava(void); // administra o que devemos fazer com as portas de saida
	private:
		int _porta;
		int _acao;
			
	
};

	


#endif
