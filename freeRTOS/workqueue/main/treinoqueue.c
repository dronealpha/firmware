/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
//bibliotecas C
#include <stdio.h>
#include <stdint.h>

//bibliotecas freertos
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

//biblioteca para GPIO
#include "driver/gpio.h"

//logs
#include "esp_log.h"

#define BLINK_GPIO 2
static const char * TAG ="MAIN: ";

//criando lista
QueueHandle_t xQueue;


//leitura do canal ADC
void task_adc(void * pvParameter){

    uint32_t count = 0;
    uint32_t status;
    for(;;){
        status = xQueueSend(xQueue, &count, 0);
        if(status == pdPASS){
            ESP_LOGI(TAG, "O VALOR %d DE COUNT FOI ENVIADO NA QUEUE.\n", count);
            count++;
        }
        vTaskDelay(1000/portTICK_PERIOD_MS);

    }
    vTaskDelete(NULL);
}

void task_print(void * pvParameter){
    uint32_t count;
    uint32_t status;
    
    for(;;){
        status = xQueueReceive(xQueue, &count, 0); 
		if(status == pdPASS)
		{		
			ESP_LOGI( TAG, "COUNT RECEBIDO. VALOR = %d\n", count );	
		}
		
		vTaskDelay(1000 / portTICK_PERIOD_MS);	
    }
    vTaskDelete(NULL);
}

void blink_task(void * pvParameter){
     gpio_pad_select_gpio(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
	
    for(;;)
	{
        /* Liga Led */
        gpio_set_level(BLINK_GPIO, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        /* Delisga Led */
        gpio_set_level(BLINK_GPIO, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

}
void app_main()
{
  if((xQueue = xQueueCreate(5, sizeof(uint32_t)))==NULL){
      ESP_LOGI(TAG, "error - nao foi possivel alocar xQueue.\n");
      return;
  }

  if((xTaskCreate(blink_task, "blink_task", configMINIMAL_STACK_SIZE, NULL, 5, NULL))!= pdTRUE){
      ESP_LOGI( TAG, "error - nao foi possivel alocar task_print.\n" );	
      return;
  }

  if( (xTaskCreate( task_print, "task_print", 4048, NULL, 5, NULL)) != pdTRUE ){
      ESP_LOGI( TAG, "error - nao foi possivel alocar task_print.\n" );	
      return;
  }

  if((xTaskCreate( task_adc, "task_adc", 4048, NULL, 5, NULL)) != pdTRUE ){
      ESP_LOGI( TAG, "error - nao foi possivel alocar task_adc.\n" );		
      return;
  }


}
