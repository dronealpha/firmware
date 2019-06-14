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


//incluindo biblioteca gpio
# include "driver/gpio.h"

//definindo portas gpio
#define VERDE 16
#define AMARELO 17
#define VERMELHO 18

//aciona portas gpio
void ligaLED(int porta, int liga){
    //inforamando para o hardware qual é a porta de uso
    gpio_pad_select_gpio(porta);
    //setando a direção da porta neste caso saida
    gpio_set_direction(porta, GPIO_MODE_OUTPUT);
    //setando o nivel da porta alto ou baixo
    gpio_set_level(porta,liga);
}

//delay de 10 segundos
void delayTempo(){
    //conta a até 10 e imprime a contagem regressiva
    for(int i=10; i>=0;i--){
        printf("\nManipulando LED em %d\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

//metodo principal chamado pelo sistema
void app_main(){
    //variavel para selecionar a função
    int op = VERDE;
    //loop infinito
    while(1){
        switch(op){
            case VERDE://aciona led verde
                ligaLED(VERMELHO,0);
                ligaLED(AMARELO,0);
                ligaLED(VERDE,1);
                delayTempo();
                op=AMARELO;
            break;
            case AMARELO://aciona led amarelo
                ligaLED(VERMELHO,0);
                ligaLED(VERDE,0);
                ligaLED(AMARELO,1);
                delayTempo();
                op=VERMELHO;
            break;
            case VERMELHO://aciona led vermelho
                ligaLED(VERDE,0);
                ligaLED(AMARELO,0);
                ligaLED(VERMELHO,1);
                delayTempo();
                op=VERDE;
            break;
        }
    }
}
