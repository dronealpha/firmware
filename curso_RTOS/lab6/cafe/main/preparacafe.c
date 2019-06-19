
/*
Autor:Diego Silva
Data:18/06/2019
Descrição:biblioteca para acionar GPIO
*/
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "preparacafe.h"

//metodo para prepara café
void gpioCafe(int portCafe, int nivel){
	gpio_pad_select_gpio(portCafe);
	gpio_set_direction(portCafe, GPIO_MODE_OUTPUT);
	gpio_set_level(portCafe, nivel);

}


//delay de 10 segundos
void delayTempo(){
    //conta a até 10 e imprime a contagem regressiva
    for(int i=10; i>=0;i--){
        printf("\nManipulando LED em %d\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

//metodo retorna se botão esta ativado 
int buttonCafe(int btn){
	//seleciona porta gpio
	gpio_pad_select_gpio(btn);

	//SETA DIREÇÃO DO PIO DE GPIO
	gpio_set_direction(btn , GPIO_MODE_INPUT);
	gpio_set_pull_mode(btn, GPIO_PULLUP_ONLY);

	return gpio_get_level( btn );
}