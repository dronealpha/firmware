/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "nvs_flash.h"

void Tarefa1(void *pvParameter)
{
   while(1){
	printf("Task 1\n");
	vTaskDelay(1000 / portTICK_PERIOD_MS);
   }
   vTaskDelete(NULL);
}


void Tarefa2(void *pvParameter)
{
   while(1){
	printf("Task 2\n");
	vTaskDelay(1000 / portTICK_PERIOD_MS);
   }
   vTaskDelete(NULL);
}

void app_main()
{
  nvs_flash_init();
  xTaskCreate(&Tarefa1, "Tarefa1", 1024, NULL, 1, NULL);
  xTaskCreate(&Tarefa2, "Tarefa1", 1022, NULL, 2, NULL);
}
