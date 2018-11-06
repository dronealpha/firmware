/*
Autor:Diego Silva
Data:06/11/2018
Descrição:Arquivo de cabeçalho para armazenar senha
*/

#ifndef GerenciaSenha_h
#define GerenciaSenha_h
#define n 3
#include <Arduino.h>
class GerenciaSenha{
	public:
		void Push(char digito);
		void Pop();
		int FlagSenhaCorreta(char pdigito,char sdigito,char tdigito);
	private:
		char pilhasenha[n];
		char SenhaDigito(int posi);
};

#endif
