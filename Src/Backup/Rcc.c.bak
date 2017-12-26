/*
 * Rcc.c
 *
 *  Created on: Dec 26, 2017
 *      Author: TARUC
 */

#include "Rcc.h"

uint32_t *rccAhb1Rst = (uint32_t *)(RCC_BASE_ADDR + RCC_AHB1RST_OFF);
uint32_t *rccAhb1En = (uint32_t *)(RCC_BASE_ADDR + RCC_AHB1EN_OFF);

void enableGpioA(void){
	//Unreset GPIOG
	*rccAhb1Rst &= ~1;
	//Start clock of GPIOA
	*rccAhb1En |= 1;
}

void enableGpioB(void){
	//Unreset GPIOG
	*rccAhb1Rst &= ~(1<<1);
	//Start clock of GPIOG
	*rccAhb1En |= 1<<1;
}

void enableGpioG(void){
	//Unreset GPIOG
	*rccAhb1Rst &= ~(1<<6);
	//Start clock of GPIOG
	*rccAhb1En |= 1<<6;
}

void enableRng(void){
	//Unreset RNG
	Rcc-> AHB2RSTR &= ~(1 << 6);
	//Start clock of RNG
	Rcc-> AHB2ENR |= 1 << 6;
}

void enableTimer8(void){
	//unreset
	Rcc->APB2RSTR &= ~(1<<1);
	//enable timer8
	Rcc->APB2ENR |= 1<<1;
}

void enableI2C(int number){
	//Unreset I2C
	Rcc-> APB1RSTR &= ~(1<<(20+number));
	//Start clock of I2C
	Rcc-> APB1ENR |= (1<<(20+number));
}

void  enableUSART1(void){
	//Unreset USART1
	Rcc->APB2RSTR &= ~(1<<4);
	//Start clock of USART1
	Rcc->APB2ENR |= (1<<4);
}

/**
 * Enable and clock DMA
 * @parameter dmaNumber is one of the following :
 * 						DMA1_DEV or DMA2_DEV
 *
 */

void enableDMA(int dmaNumber){
	//Unreset USART1
	Rcc->AHB1RSTR &= ~(1 <<(21 + dmaNumber));
	//Start clock of USART1
	Rcc->AHB1ENR |= 1 << (21 + dmaNumber);
}


