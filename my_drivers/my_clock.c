/*
 * my_clock.c
 *
 *  Created on: Nov 1, 2022
 *      Author: tushar
 */

#include "my_configuration.h"

void configureClock(void)
{
	//RCC_CR default
	// HSI on
	// PLLI2S off
	// PLL off
	// HSE off

	// RCC_PLLCFGR default as PLL is disabled and not used

	// RCC_CFGR default
	// HSI as system clock source
	// AHB clock undivided
	// APB 1 & 2 clock undivided
	// RCC_CFGR =

	// RCC_CIR
	RCC->CIR |= (1 << HSIRDYIE_bit);
	// RCC_AHB1RSTR
	// RCC_AHB2RSTR
	// RCC_APB1RSTR
	// RCC_APB2RSTR
	// some registers are related to peripheral clocks so skipped
	// RCC_BDCR
	// RCC_CSR
	// RCC_SSCGR
	// RCC_PLLI2SCFGR
	// RCC_DCKCFGR
//	while (!((1 << 2) & (RCC->CIR)));
//	RCC->CIR |= (1 << HSIRDYC_bit);
	// provide clock to system config
	RCC->APB2ENR |= (1 << SYSCFGEN_bit);
}
