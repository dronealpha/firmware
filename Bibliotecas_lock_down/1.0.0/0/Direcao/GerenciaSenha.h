/*
Autor:Diego Silva
Data:06/11/2018
Descrição:Arquivo de cabeçalho para armazenar senha
*/

#ifndef GerenciaSenha_h
#define GerenciaSenha_h

#include <Arduino.h>
class GerenciaSenha{
	public:
		void setPDigito(char pdigito);
		char getPDigito(void);
		void setSDigito(char sdigito);
		char getSDigito(void);
		void setTDigito(char tdigito);
		char getTDigito(void);
		int FlagSenhaCorreta(char dig1,char dig2,char dig3);
	private:
		char _pdigito;
		char _sdigito;
		char _tdigito;
		
};

#endif
