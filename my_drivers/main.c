/*
 * main.c
 *
 *  Created on: Oct 27, 2022
 *      Author: tushar
 */

//#define STM32F40xx
#include "my_configuration.h"

volatile unsigned char count = 0;

void EXTI15_10_IRQHandler(void)
{
  if (EXTI->PR & (1<<13)) {                       // EXTI0 interrupt pending?
    EXTI->PR |= (1<<13);                          // clear pending interrupt

    count ^= 1;       // switch on  LED
  }
}

int main(void)
{
	configureClock();
	gpioInit();
	enablePinChangeInterrupt();
	//__enable_irq();
	GPIOA->ODR = 0x00000000;//GPIO_ODR_ODR_5;
	GPIOA->ODR = GPIO_ODR_ODR_5;
	while (1)
	{
		if (count)
		{
			GPIOA->ODR = 0x00000000;
		}
		else
		{
			GPIOA->ODR = GPIO_ODR_ODR_5;
		}
		//count^=1;
	}
//	if (count==0)
//	{
//		GPIOA->ODR = 0x00000000;
//	}
	return 0;
}




