/*
 * IWDG.h
 *
 *  Created on: Jan 9, 2018
 *      Author: TARUC
 */

#ifndef IWDG_H_
#define IWDG_H_
#include <stdint.h>
#include "Rcc.h"
#define IWDG_BASE_ADDR		0x40003000
#define iwdg			((IwdgReg *)(IWDG_BASE_ADDR))

#define WWDG_BASE_ADDR		0x40002C00
#define wwdg			((WwdgReg *)(WWDG_BASE_ADDR))

typedef struct IwdgReg IwdgReg;
struct IwdgReg {
	volatile uint32_t KR;			//0h Key Register
	volatile uint32_t PR;			//4h Prescaler Register
	volatile uint32_t RLR;			//8h Reload Register
	volatile uint32_t SR;			//ch Status Register

};

typedef struct WwdgReg WwdgReg;
struct WwdgReg {
	volatile uint32_t CR;			//0h Control Register
	volatile uint32_t CFR;			//4h Configuration Register
	volatile uint32_t SR;			//ch Status Register

};

#define IWDG_RVU	(1<<1)
#define iwdgRVUIsEmpty() ((iwdg->SR & IWDG_RVU)>>1)
#define IWDG_PVU	1
#define iwdgPVUIsEmpty() (iwdg->SR & IWDG_PVU)


//Key Register(IWDG)
#define Code_For_Modify		0x5555
#define IWDG_RESET			0xAAAA
#define Start_Count			0xCCCC

//Precaler Register(IWDG)
#define Div_4				0x0
#define Div_8				0x1
#define Div_16				0x2
#define Div_32				0x3
#define Div_64				0x4
#define Div_128				0x5
#define Div_256				0x6
#define Div_256_1			0x7

//Control Register(WWDG)
#define WWDG_EN				(1<<7)
#define WWDG_T6				(1<<6)

//Configuration Register(WWDG)
#define CLOCK_DIV_BY_1		(0<<7)
#define CLOCK_DIV_BY_2		(1<<7)
#define CLOCK_DIV_BY_4		(2<<7)
#define CLOCK_DIV_BY_8		(3<<7)
#define WWDG_EWI_EN			(1<<9) //Early Wake Up Interrupt
#define WWDG_MASK			~(0x7f)
//wwdg->CFR &= WWDG_MASK;
#define wwdgSetWindowValue(val)					\
	do{											\
		wwdg->CFR = (WWDG_T6|val);				\
	} while(0)

//Status Register (WWDG)

#define FOUR_SEC_IN_Div_64	2000

#define EWIF		1
#define wwdgHasEarlyWakeUpInterruptFlagged() (wwdg->SR & EWIF)

void IWDGConfig(void);
void TicksInput(int numOfTicks);
void StartIWDG(void);
void IWDGReset(void);
void IWDGPreScale(void);
void ClearwwdgInterrupt(void);

//Reload Register

#endif /* IWDG_H_ */
