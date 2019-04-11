/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
//biblioteca padrão C
#include <stdio.h>
#include <stdint.h>

//biblioteca freeRTOS
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

//GPIO
#include "driver/gpio.h"

//definindo gpio port
#define BLINK_GPIO 16

//task para ligar led
void vTaskPiscaLedON(void *pvParameter){
	printf("Liga Led\n");
	gpio_pad_select_gpio(BLINK_GPIO);//informando porta gpio desejada
	gpio_set_direction(BLINK_GPIO,GPIO_MODE_OUTPUT);//informando direção do gpio
	gpio_set_level(BLINK_GPIO,0);//acionando gpio
	vTaskDelay(1000 / portTICK_PERIOD_MS);//bloqueia task para execução de outra task
	vTaskDelete(NULL);
}

void vTaskPiscaLedOFF(void *pvParameter){
	printf("Desliga Led\n");
	gpio_pad_select_gpio(BLINK_GPIO);//informando porta gpio desejada
	gpio_set_direction(BLINK_GPIO,GPIO_MODE_OUTPUT);//informando direção do gpio
	gpio_set_level(BLINK_GPIO,1);//acionando gpio
	vTaskDelay(1000 / portTICK_PERIOD_MS);//bloqueia task para execução de outra task
	vTaskDelete(NULL);
}

void app_main()
{
  while(1){
	  xTaskCreate(vTaskPiscaLedON, "Liga", 1024, NULL, 2, NULL);
	  xTaskCreate(vTaskPiscaLedOFF, "Desliga", 1024, NULL, 3, NULL);
	}
}