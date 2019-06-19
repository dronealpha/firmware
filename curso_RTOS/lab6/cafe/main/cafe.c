/*
Autor: Diego Lopes da Silva
Data:18/06/2019
Descrição: Programa para simular uma maquina de café
*/

//include de biblioteca padrão C para usar o printf 
#include <stdio.h>

//FreeRTOS.h biblioteca para definições e configuraçções do sistema
#include "freertos/FreeRTOS.h"
//task.h biblioteca que contem as definições das task como a vTaskDelay
#include "freertos/task.h"

//include biblioteca para controle do GPIO
#include "driver/gpio.h"

//importando biblioteca para prepara café
#include "preparacafe.h"

//definições de portas para preparação de cafe
#define LEDVERDE 16
#define LEDAMARELA 17
#define BUTTONTURNONCAFE 15
#define CHAVE 5


/*void taskPreparaCafe(void *pvParameter){
	gpioCafe(CHAVE,1);
	gpioCafe(LEDVERDE,0);
	gpioCafe(LEDAMARELA,0);
	while(1){
		if(buttonCafe(BUTTONTURNONCAFE) == 0){
			printf("Preparando cafe\n");
			delayTempo();
			gpioCafe(LEDVERDE,1);
			gpioCafe(LEDAMARELA,0);
			delayTempo();
			gpioCafe(LEDVERDE,0);
			gpioCafe(LEDAMARELA,1);
		}
		vTaskDelay(300/portTICK_PERIOD_MS);
	}
}*/
//metodo principal chamado pelo sistema
void app_main(){
	//xTaskCreate(taskPreparaCafe, "Prepara_cafe",1024, NULL,5, NULL);
	gpioCafe(CHAVE,1);
	gpio_pad_select_gpio(BUTTONTURNONCAFE);

	//SETA DIREÇÃO DO PIO DE GPIO
	gpio_set_direction(BUTTONTURNONCAFE , GPIO_MODE_INPUT);
	gpio_set_pull_mode(BUTTONTURNONCAFE, GPIO_PULLUP_ONLY);
	while(1){
		if(gpio_get_level(BUTTONTURNONCAFE) == 0){
			printf("Preparando cafe\n");
			delayTempo();
			gpioCafe(LEDVERDE,1);
			gpioCafe(LEDAMARELA,0);
			delayTempo();
			gpioCafe(LEDVERDE,0);
			gpioCafe(LEDAMARELA,1);
		}

		delayTempo();
	}
}
