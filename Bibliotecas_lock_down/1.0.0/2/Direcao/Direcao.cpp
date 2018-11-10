/*
 * Autor: Diego Silva
 * Data: 13/10/2018
 * Descrição:Classe para direcionar para ação desejada
 */

#include <Arduino.h>
#include "Direcao.h"
#include "ControleTrava.h"
#include "GerenciaSenha.h"


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
	//instanciando classe para controle de trava
	ControleTrava trava;
	
	//instanciando classe para memoria eeprom
	GerenciaSenha GSenha;
	
	//definido prova para controle de reles
	trava.setPorta(13);
	if(getByteStart()=='1'){//verifica byte de start
		
		if(getFuncao()=='f'){//verifica byte de função
			
			//direciona para oção desejada
			switch(getAcao()){
				case'0':
					//limpano local de memoria
					GSenha.Limpasenha();
					
					//passando dados da senha
					Serial.println("Cadastrando senha");
					GSenha.setPDigito(getSenhaDigito1());
					GSenha.setSDigito(getSenhaDigito2());
					GSenha.setTDigito(getSenhaDigito3());
					
					//Cadastrando senha na memoria eeprom
					GSenha.EscreveSenha();
					
				break;
				case'1':
					Serial.println("Cofre travado");
					trava.setTrava(getAcao());//define ação a ser tomada
					trava.operaTrava();//executa açao definidia
				break;
				case'2':
					//converte valor para inteiro e verica com informações gravada na eeprom
					if((GSenha.ConvertValor(getSenhaDigito1()) == GSenha.PegaSenha(0))&&
					   (GSenha.ConvertValor(getSenhaDigito2()) == GSenha.PegaSenha(1))&&
					   (GSenha.ConvertValor(getSenhaDigito3()) == GSenha.PegaSenha(2))){
						
						//destrava tranca
						Serial.println("Cofre destravado");
						trava.setTrava(getAcao());//define ação a ser tomada
						trava.operaTrava();//executa açao definidia
					}
				break;
			}
				
		}else{
			Serial.println("Funcao Invalido");
		}
		
	}else{
		Serial.println("Comando Invalido");
	}
}
