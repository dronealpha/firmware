/*
 *Autor:Diego Silva 
 *Data:13/10/2018
 *Descrição: Arquivo headle para classe Gamatron
 */
#ifndef Gamatron_h
#define Gamatron_h
#include <Arduino.h>
class Gamatron{
	public :
		void setInicio(char ini);
		char getInicio(void);
		void setFuncao(char fun);
		char getFuncao(void);
		void setAcao(char aco);
		char getAcao(void);
	private:
		char stini;
		char stfun;
		char stacao;
};
#endif
