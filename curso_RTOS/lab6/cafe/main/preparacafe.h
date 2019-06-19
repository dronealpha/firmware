/*
Autor:Diego Silva
Data:18/06/2019
Descrição:biblioteca para acionar GPIO
*/

#ifndef PREPARACAFE_S
#define PREPARACAFE_S
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

	//metodo para preparar café
	void gpioCafe(int, int);

	//metodo para time de 10 segundos
	void delayTempo();

	//retorna se o botão foi pressionado
	int buttonCafe(int);

#endif