/*
 * EXTI.h
 *
 *  Created on: Dec 26, 2017
 *      Author: TARUC
 */

#ifndef EXTI_H_
#define EXTI_H_

#include <stdint.h>

#define EXTI_BASE_ADDR	0x40013C00
#define Exti			((ExtiReg *)(EXTI_BASE_ADDR))

typedef struct ExtiReg	ExtiReg;
struct ExtiReg{
	volatile uint32_t	IMR;						//Interrupt mask register
	volatile uint32_t	EMR;						//Event mask register
	volatile uint32_t	RTSR;						//Rising trigger selection register
	volatile uint32_t	FTSR;						//Falling trigger selection register
	volatile uint32_t	SWIER;						//Software interrupt event register
	volatile uint32_t	PR;							//Pending register
};

#define ExtiSetIT(x)			(Exti->IMR |= (1<<x))
#define ExtiCLRIT(x)			(Exti->IMR &= ~(1<<x))
#define ExtiSetET(x)			(Exti->EMR |= (1<<x))
#define ExtiCLRET(x)			(Exti->EMR &= ~(1<<x))
#define ExtiSetRise(x)				(Exti->RTSR |= (1<<x))
#define ExtiResetRise(x)			(Exti->RTSR &= ~(1<<x))
#define ExtiSetFall(x)				(Exti->FTSR |= (1<<x))
#define ExtiResetFall(x)			(Exti->FTSR &= ~(x))
#define ExtiSoftwareTrigger(x)		(Exti->SWIER |= (1<<x))
#define ExtiReadPendingInterrupt(x)	(Exti->PR)
#define ExtiClrPendingInterrupt(x)	(Exti->PR |= (1<<x))

#endif /* EXTI_H_ */
