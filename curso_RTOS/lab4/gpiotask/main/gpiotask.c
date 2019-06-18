/*
Autor: Diego Lopes da Silva
Data:13/06/2019
Descrição: programa printa "ola mundo" conta até 10 e reinicia o hardware
*/

//include de biblioteca padrão C para usar o printf 
#include <stdio.h>

//FreeRTOS.h biblioteca para definições e configuraçções do sistema
#include "freertos/FreeRTOS.h"

//task.h biblioteca que contem as definições das task como a vTaskDelay
#include "freertos/task.h"

//include de biblioteca para acionar gpio
#include "driver/gpio.h"

//definindo porta gpio
#define PORTA 16
//criando tas para execução de gpio
void blink_task(){
	//informando a placa qual porta vai ser usada
	gpio_pad_select_gpio(PORTA);

	//definindo porta como output
	gpio_set_direction(PORTA,GPIO_MODE_OUTPUT);
	printf("Blink led GPIO\n");

	//variavel contadora
	int cnt=0;

	//loop infinito para 
	while(1){
		gpio_set_level(PORTA,cnt%2);//verifica se o numero é para
		cnt++;//incrementa mais um 
		vTaskDelay(1000/portTICK_PERIOD_MS);//vTaskDelay é uma tarefa não bloqueante que passa o controle para outa task
	}

}
//metodo principal chamado pelo sistema
void app_main(){
   xTaskCreate(blink_task, "blink_task",1024,NULL,5,NULL);//Lembrando que a prioridade da task nunca pode ser zero pois esse valor ja é schudele
   printf("blink task  started\n");
}
