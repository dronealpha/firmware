#ifndef Direcao_h
#define Direcao_h
#include <Arduino.h>
class Direcao{
	public :
		Direcao(char ini, char fun, char acao);
		void executacao(void);
		void setSenhaDigito1(char senha1);
		char getSenhaDigito1(void);
		void setSenhaDigito2(char senha2);
		char getSenhaDigito2(void);
		void setSenhaDigito2(char senha3);
		char getSenhaDigito2(void);
	private:
		char stini;
		char stfun;
		char stacao;
		char stSenha1;
		char stSenha2;
		char stSenha3;
};
#endif
