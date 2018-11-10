/*
 * Autor: Diego Silva
 * Data: 13/10/2018
 * Descrição:Arquivo para direcionamento de ações
 */

#ifndef Direcao_h
#define Direcao_h
#include <Arduino.h>
#include "ControleTrava.h"
#include "GerenciaSenha.h"

class Direcao{
	public :
		//Direcao(char ini, char fun, char acao);
		void setInit(char ini);
		void setFun(char fun);
		void setAcao(char acao);
		
		void executacao(void);
		
		void setSenhaDigito1(char senha1);
		char getSenhaDigito1(void);
		
		void setSenhaDigito2(char senha2);
		char getSenhaDigito2(void);
		
		void setSenhaDigito3(char senha3);
		char getSenhaDigito3(void);
		
		char getByteStart(void);
		char getFuncao(void);
		char getAcao(void);
		
	private:
		char stini;
		char stfun;
		char stacao;
		char stSenha1;
		char stSenha2;
		char stSenha3;
};
#endif
