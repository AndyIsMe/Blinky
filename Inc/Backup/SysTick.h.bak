/*
 * SysTick.h
 *
 *  Created on: Dec 26, 2017
 *      Author: TARUC
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <stdint.h>

/*	Freq = 22.5 Mhz ---> 1 SysTick Period = 1/(22.5*10^6)
 * reload * systick_period = 500ms
 * reload = 500ms/systick_period =
 *
 *
 */

#define SYSTICK_BASE_ADDR	0xE000E010
#define Tick			((SysTickReg *)(SYSTICK_BASE_ADDR))

#define SYSTICK_EN							1
#define SYSTICK_INTR_EN					(1 << 1)
#define SYSTICK_PROC_CLK_SRC			(1 << 2)
#define SYSTICK_CNTR_OVERFLOW			(1 << 16)

typedef struct SysTickReg	SysTickReg;
struct SysTickReg{
	volatile uint32_t	CTRL;						//SysTick control and status register
	volatile uint32_t	LOAD;						//SysTick reload value register
	volatile uint32_t	VAL;						//SysTick current value register
	volatile uint32_t	CALIB;						//SysTick calibration value register
};

#define sysTickEnable()				(Tick->CTRL |= SYSTICK_EN)
#define sysTickDisable()			(Tick->CTRL &= ~SYSTICK_EN)
#define sysTickIntrEnable()			(Tick->CTRL |= SYSTICK_INTR_EN)
#define sysTickIntrDisable()		(Tick->CTRL &= ~SYSTICK_INTR_EN)
#define sysTickSetReload(x)			(Tick->LOAD = (x))
#define sysTickReadCounter(x)		(Tick->VAL)
#define sysTickClrCounter()			(Tick->VAL = 0xbadface)
//Set SysTick to run @ processor speed
#define sysTickFullSpeed()			(Tick->CTRL |= SYSTICK_PROC_CLK_SRC)
//Set SysTick to run @ 1/8 of AHB frequency
#define sysTickPrescaledSpeed()		(Tick->CTRL &= ~SYSTICK_PROC_CLK_SRC)
//Determine if SysTick timer has expired.Return none zero if has expired
#define sysTickHasExpired()			(Tick->CTRL & SYSTICK_CNTR_OVERFLOW)


#endif /* SYSTICK_H_ */
