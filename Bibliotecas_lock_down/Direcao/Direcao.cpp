/*
 * Autor: Diego Silva
 * Data: 13/10/2018
 * Descrição:Classe para direcionar para ação desejada
 */

#include <Arduino.h>
#include "Direcao.h"
#include "ControleTrava.h"


//metodo para valida inicialização
void Direcao::setInit(char ini){
	stini = ini;
}

//metodo para definir funcao
void Direcao::setFun(char fun){
	stfun = fun;
}

//metodo para difinir ação
void Direcao::setAcao(char acao){
	stacao = acao;
}

//seta primeiro digito da senha
void Direcao::setSenhaDigito1(char senha1){
	stSenha1 = senha1;
}

//retorna primeiro digito da senha
char Direcao::getSenhaDigito1(){
	return stSenha1;
}

//seta segundo digito da senha
void Direcao::setSenhaDigito2(char senha2){
	stSenha2 = senha2;
}

//retorna segundo digito da senha
char Direcao::getSenhaDigito2(){
	return stSenha2;
}

//seta segundo digito da senha
void Direcao::setSenhaDigito3(char senha3){
	stSenha3 = senha3;
}

//retorna terceiro digito da senha
char Direcao::getSenhaDigito3(){
	return stSenha3;
}

//retorna byte de start
char Direcao::getByteStart(){
	return stini;
}

//retorna f para simbolizar função
char Direcao::getFuncao(){
	return stfun;
}

//retorna caracter de acao
char Direcao::getAcao(){
	return stacao;
}

//método para direcionar usuário até ação
void Direcao::executacao(){
	//instanciando objeto
	ControleTrava trava;
	
	//definido prova para controle de reles
	trava.setPorta(13);
	if(getByteStart()=='1'){//verifica byte de start
		
		if(getFuncao()=='f'){//verifica byte de função
			switch(getAcao()){
				case'0':
					Serial.println("acao 0");
				break;
				case'1':
					Serial.println("Cofre travado");
					trava.setTrava(getAcao());//define ação a ser tomada
					trava.operaTrava();//executa açao definidia
				break;
				case'2':
					Serial.println("Cofre destravado");
					trava.setTrava(getAcao());//define ação a ser tomada
					trava.operaTrava();//executa açao definidia
				break;
			}
				
		}else{
			Serial.println("Funcao Invalido");
		}
		
	}else{
		Serial.println("Comando Invalido");
	}
}
