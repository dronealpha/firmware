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

//include biblioteca para controle do GPIO
#include "driver/gpio.h"


//definições de porta
#define LED 16
#define BUTTON 17

//task para leitura de pgio
void taskLed(void *pvParameter){
        int cnt=0;

        //configurando gpio 16 como output
        gpio_set_direction(LED, GPIO_MODE_OUTPUT);

        //configurando porta gpio 17 como input
        gpio_set_direction(BUTTON, GPIO_MODE_INPUT);
        gpio_set_pull_mode(BUTTON, GPIO_PULLUP_ONLY);

        printf("Piscando LED gpio 16\n");
        while(1){
            if(gpio_get_level( BUTTON ) == 0){
                gpio_set_level( LED, 1 );
                printf("Valor de cnt %d",cnt);
                printf("GPIO foi acionado");
            }
            vTaskDelay(300/portTICK_PERIOD_MS);
        }
}

//metodo principal chamado pelo sistema
void app_main(){
   xTaskCreate(taskLed, "Blink Task", 1024, NULL, 5 , NULL);
   printf("TASK_LED iniciada com sucesso\n");
}
