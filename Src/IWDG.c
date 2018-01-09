/*
 * IWDG.c
 *
 *  Created on: Jan 9, 2018
 *      Author: TARUC
 */
#include "IWDG.h"


/*
 * tPclk = 1/45Mhz
 * Warning : Always write 1 in the T6 bit to avoid generating immediate reset
 */
void IWDGConfig(void){
	iwdg->KR = Code_For_Modify;
	//iwdg->PR = Div_64;

	//iwdg->RLR = TWO_SEC_IN_Div_64;

	//iwdg->KR = Start_Count;
}

void IWDGPreScale(void)
{
	iwdg->PR = Div_64;
}

void StartIWDG(void)
{
	iwdg->KR = Start_Count;
}

void TicksInput(int numOfTicks)
{
	iwdg->RLR = numOfTicks;
}

void IWDGReset(void)
{
	iwdg->KR = IWDG_RESET;
}

void WWDGConfig(int countdownBit)
{
	wwdg->CFR |= CLOCK_DIV_BY_2;
	wwdg->CR = WWDG_EN | WWDG_T6 | (countdownBit);

}

void ClearwwdgInterrupt(void)
{
	wwdg->SR = 0;
}
