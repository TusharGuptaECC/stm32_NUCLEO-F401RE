/*
 * my_gpio.c
 *
 *  Created on: Nov 1, 2022
 *      Author: tushar
 */

#include "my_configuration.h"

void gpioInit(void)
{
	// RCC_AHB1ENR
	// provide clock to GPIOA
	RCC->AHB1ENR = RCC_AHB1LPENR_GPIOALPEN | RCC_AHB1LPENR_GPIOCLPEN;
	//RCC_AHB1LPENR
	// default

	GPIOA->MODER = GPIO_MODER_MODER5_0;
	GPIOC->MODER = 0x00000000;
	GPIOC->PUPDR = GPIO_PUPDR_PUPDR13_0;
}


