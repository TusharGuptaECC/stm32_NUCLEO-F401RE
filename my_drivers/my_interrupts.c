/*
 * my_interrupts.c
 *
 *  Created on: Nov 1, 2022
 *      Author: tushar
 */
#include "my_configuration.h"

void enablePinChangeInterrupt(void)
{

	__disable_irq();
	SYSCFG->EXTICR[3] = SYSCFG_EXTICR4_EXTI13_PC;
	//EXTI_IMR
	EXTI->IMR = EXTI_IMR_MR13;

	//EXTI_EMR
	// default

	//EXTI_RTSR
	EXTI->RTSR = EXTI_RTSR_TR13;

	//EXTI_FTSR
	// default

	//EXTI_SWIER
	// default
	//EXTI->SWIER = EXTI_SWIER_SWIER13;

	//EXTI_PR
	// default
	//EXTI->PR = EXTI_SWIER_SWIER13;

	NVIC_SetPriority(EXTI15_10_IRQn, 0);
	NVIC_EnableIRQ(EXTI15_10_IRQn);
	__enable_irq(); // Enable Interrupts

}
