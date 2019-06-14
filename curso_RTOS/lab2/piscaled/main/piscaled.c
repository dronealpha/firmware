/*
Autor: Diego Lopes da Silva
Data:13/06/2019
Descrição: programa espera 10 segundos e liga o led depois espera 10 segundo e desliga o led
*/

//include de biblioteca padrão C para usar o printf 
#include <stdio.h>

//FreeRTOS.h biblioteca para definições e configuraçções do sistema
#include "freertos/FreeRTOS.h"
//task.h biblioteca que contem as definições das task como a vTaskDelay
#include "freertos/task.h"


//biblioteca para utilizar gpio do esp32
#include "driver/gpio.h"

//bibliotecas responsaveis por para controle e obter informações do hardware
#include "esp_system.h"
#include "esp_spi_flash.h"

//definidnfo porta gpio
#define GPIOPORTA 16

//acionado porta para nivel alto ou nivel baixo
void ligaGPIO(int act){

	//verifica qual é ação e printa
	if(act==0){
		printf("Desligando LED");	
	}else{
		printf("Ligando LED");
	}

	//inforamando para o hardware qual é a porta de uso
	gpio_pad_select_gpio(GPIOPORTA);
	//setando a direção da porta neste caso saida
	gpio_set_direction(GPIOPORTA, GPIO_MODE_OUTPUT);
	//setando o nivel da porta alto ou baixo
	gpio_set_level(GPIOPORTA,act);
}

void delayTempo(){
	//conta a até 10 e imprime a contagem regressiva
    for(int i=10; i>=0;i--){
        printf("\nManipulando LED em %d\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
//metodo principal chamado pelo sistema
void app_main(){
    //printa ola mundo
    printf("Iniciando acionamento do led\n");
    ligaGPIO(1);

    //10 eguindos de delay
    delayTempo();

    ligaGPIO(0);
    //10 eguindos de delay
    delayTempo();
    //reboot de sistema
    printf("Reboot do sistema\n");
    fflush(stdout);
    esp_restart();
}
