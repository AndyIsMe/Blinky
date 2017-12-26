/*
 * SysCfg.h
 *
 *  Created on: Dec 26, 2017
 *      Author: TARUC
 */

#ifndef SYSCFG_H_
#define SYSCFG_H_
#include <stdint.h>

#define SysCfg_BASE_ADDR	0x40013800
#define SysCfg			((SysCfgReg *)(SysCfg_BASE_ADDR))

typedef struct SysCfgReg	SysCfgReg;
struct SysCfgReg{
	volatile uint32_t	MEMRMP;						//SYSCFG memory remap register
	volatile uint32_t	PMC;						//SYSCFG peripheral mode configuration register
	volatile uint32_t	EXTICR[4];					//SYSCFG external interrupt configuration register 1-4
	volatile uint32_t	CMPCR;						//Compensation cell control register
};
#define PORTA		0
#define PORTB		1
#define PORTC		2
#define PORTD		3
#define PORTE		4
#define PORTF		5
#define PORTG		6
#define PORTH		7


#define sysCfgSelectExtIntrGpio(bits)			\
				do{								\
				(SysCfg->EXTICR &= ~()
#define ExtiIMRUnMasked(bits)		(Exti->IMR &= ~(1<<bits))
#define ExtiEMRMasked(bits)			(Exti->EMR |= (1<<bits))
#define ExtiEMRUnMasked(bits)		(Exti-EIMR &= ~(1<<bits))
#define ExtiSetRise(bits)		(Exti->RTSR |= (bits))
#define ExtiResetRise(bits)		(Exti->RTSR &= ~(bits))
#define ExtiSetFall(bits)		(Exti->FTSR |= (bits))
#define ExtiResetFall(bits)		(Exti->FTSR &= ~(bits))
#define ExtiSoftwareTrigger(bits)	(Exti->SWIER |= (bits))
#define ExtiReadPendingInterrupt()	(Exti->PR)
#define ExtiClrPendingInterrupt(x)	(Exti->PR |= (x))



#endif /* SYSCFG_H_ */
