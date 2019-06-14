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
void task_Envio1(void * pvParameter){

    uint32_t count = 0;
    uint32_t status;
    for(;;){
        status = xQueueSend(xQueue, &count, 0);
        if(status == pdPASS){
            ESP_LOGI(TAG, "O VALOR %d DE TASK1 FOI ENVIADO NA QUEUE.\n", count);
            count=count+2;
        }
        vTaskDelay(1000/portTICK_PERIOD_MS);

    }
    vTaskDelete(NULL);
}


void task_Envio2(void * pvParameter){

    uint32_t count = 0;
    uint32_t status;
    for(;;){
        status = xQueueSend(xQueue, &count, 1);
        if(status == pdPASS){
            ESP_LOGI(TAG, "O VALOR %d DE TASK2 FOI ENVIADO NA QUEUE.\n", count);
            count=count+3;
        }
        vTaskDelay(1000/portTICK_PERIOD_MS);

    }
    vTaskDelete(NULL);
}
void task_print(void * pvParameter){
    uint32_t count;
    uint32_t status;
    int lc = 0;
    
    for(;;){
        for(lc=0;lc<2;lc++){
            status = xQueueReceive(xQueue, &count, 0); 
            if(status == pdPASS)
            {		
                ESP_LOGI( TAG, "COUNT RECEBIDO. VALOR = %d\n", count );	
            }
            
            
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}


void app_main()
{
   
  if( (xQueue = xQueueCreate( 5, sizeof(uint32_t)) ) == NULL )
    {
	  ESP_LOGI( TAG, "error - nao foi possivel alocar xQueue.\n" );
	  /* app_main será finalizada e o programa finalizado */
	  return;
	} 
  if((xTaskCreate( task_Envio1, "task_adc", 4048, NULL, 5, NULL)) != pdTRUE ){
      ESP_LOGI( TAG, "error - nao foi possivel alocar task_adc.\n" );		
      return;
  }
 if((xTaskCreate( task_Envio2, "task_adc", 4048, NULL, 5, NULL)) != pdTRUE ){
      ESP_LOGI( TAG, "error - nao foi possivel alocar task_adc.\n" );		
      return;
  }

   if( (xTaskCreate( task_print, "task_print", 4048, NULL, 5, NULL)) != pdTRUE ){
      ESP_LOGI( TAG, "error - nao foi possivel alocar task_print.\n" );	
      return;
  }

}
