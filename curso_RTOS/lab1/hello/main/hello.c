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

//bibliotecas responsaveis por para controle e obter informações do hardware
#include "esp_system.h"
#include "esp_spi_flash.h"

//metodo principal chamado pelo sistema
void app_main(){
    //printa ola mundo
    printf("ola mundo");

    //conta a até 10 e imprime a contagem regressiva
    for(int i=10; i>=0;i--){
        printf("\nFinalizando tarefa %d\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

    //reboot de sistema
    printf("Reboot do sistema\n");
    fflush(stdout);
    esp_restart();
}
