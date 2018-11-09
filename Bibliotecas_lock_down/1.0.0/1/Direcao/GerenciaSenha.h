/*
Autor:Diego Silva
Data:06/11/2018
Descrição:Arquivo de cabeçalho para armazenar senha
*/

#ifndef GerenciaSenha_h
#define GerenciaSenha_h

//Bibliotecas para arduinoe memoria eeprom
#include <Arduino.h>
#include <EEPROM.h>

class GerenciaSenha{
	public:
		//primeiro Digito
		void setPDigito(char pdigito);
		char getPDigito(void);
		
		//Segundo Digito
		void setSDigito(char sdigito);
		char getSDigito(void);
		
		//Terceiro Digito
		void setTDigito(char tdigito);
		char getTDigito(void);
		
		//metodo para escrita de senha
		void EscreveSenha(void);
		
		//metodo de consulta senha
		int PegaSenha(int posi);
		
		void Limpasenha();
	private:
		char _pdigito;
		char _sdigito;
		char _tdigito;
		
};

#endif
