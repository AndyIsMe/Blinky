/*
 * Timer.c
 *
 *  Created on: Dec 26, 2017
 *      Author: TARUC
 */

#include "Timer.h"
#include "GPIO.h"
#include "stm32f4xx_hal.h"

void initTimer8()
{

	//Enable Timer 8 --	Unreset , enable clock
	enableTimer8();

	//Configure the maximum counter value by setting ARR and the prescaler by setting PSC
	Timer8->ARR = 0xff;
	Timer8->PSC = 2;
	//Select the clock source (internal clock) -- Set SMCR:SMS[2:0] = 0
	//Timer8->SMCR |= sms <<(pin);
	Timer8->SMCR &= ~(TIM_CR1_SMS_MASK);
	//Enable Timer 8 -- Set CR1:CEN = 1
	//Timer8->CR1 &= 1<<4;
	Timer8->CR1 &= ~(TIM_CR1_EN);
	Timer8->CR1 |= TIM_CR1_EN;
}

void initTimer8wait500ms()
{

	//Enable Timer 8 --	Unreset , enable clock
	enableTimer8();

	//Configure the maximum counter value by setting ARR and the prescaler by setting PSC
	Timer8->ARR = 50000;
	Timer8->PSC = 18000;
	//Select the clock source (internal clock) -- Set SMCR:SMS[2:0] = 0
	//Timer8->SMCR |= sms <<(pin);
	Timer8->SMCR &= ~(TIM_CR1_SMS_MASK);
	//Enable Timer 8 -- Set CR1:CEN = 1
	//Timer8->CR1 &= 1<<	4;
	//Timer8->CR1 &= ~(TIM_CR1_EN);
	Timer8->CR1 |= TIM_CR1_EN;
}

void initTimer8Channel1()
{
	//Configure timer 8 Channel 1 pin (PC6) -- Enable Port C , set pin as AltFunc3 Out-PP
	*rccAhb1Rst &= ~(1<<2);
	//Start clock of GPIOC
	*rccAhb1En |= 1<<2;
	gpioConfigAltFuncNum(GpioC,6,ALT_FUNC3);
	gpioConfig(GpioC,6, GPIO_MODE_AF , GPIO_PUSH_PULL , GPIO_NO_PULL , GPIO_VHI_SPEED);
	timeSelectChn1AsOC();
	Timer8->CCER |= ActiveHighPolarity | CaptureEN;
	Timer8->CR2 |= NoPreload;
	Timer8->CR1 &= ~(TIM_CR1_EN);
	Timer8->CR1 |= TIM_CR1_EN;
	//Timer8->CCR1 |= CC1EN;
	Timer8->ARR = 125;
	Timer8->PSC = 2;
	Timer8->CCR1 = 12;
	Timer8->BDTR |= MOEEN;

}

void initTimer8Channel3(){
	//Configure timer 8 Channel 3 pin (PC8) -- Enable Port C , set pin as AltFunc3 Out-PP
	*rccAhb1Rst &= ~(1<<2);
	//Start clock of GPIOC
	*rccAhb1En |= 1<<2;
	gpioConfigAltFuncNum(GpioC,8,ALT_FUNC3);
	gpioConfig(GpioC,6, GPIO_MODE_AF , GPIO_PUSH_PULL , GPIO_NO_PULL , GPIO_VHI_SPEED);
	timeSelectChn3AsIn();
	timeSelectChn4AsIn();

}
void toggleOutCompareChannel1(){
	Timer8->CCMR1 &= ~(7<<4);
	Timer8->CCMR1 |= Toggle;
}
void forceOutCompareChannel1High(){
	Timer8->CCMR1 &= ~(7<<4);
	Timer8->CCMR1 |= ForceActiv;
}

void forceOutCompareChannel1Low(){
	Timer8->CCMR1 &= ~(7<<4);
	Timer8->CCMR1 |= ForceLow;
}

void toggleOutCompareChannel1WithForce(){
	forceOutCompareChannel1High();
	forceOutCompareChannel1Low();
}

/*
void initTimer8Channel3()
{
	//Configure timer 8 Channel 3 pin (PC8) -- Enable Port C , set pin as AltFunc3 In-
	*rccAhb1Rst &= ~(1<<2);
	//Start clock of GPIOC
	*rccAhb1En |= 1<<2;
	gpioConfigAltFuncNum(GpioC,6,ALT_FUNC3);
	gpioConfig(GpioC,6, GPIO_MODE_AF , GPIO_PUSH_PULL , GPIO_NO_PULL , GPIO_VHI_SPEED);
	timeSelectChn3AsOC();
	Timer8->CCR1 |= CC1EN;
	Timer8->ARR = 5000;
	Timer8->PSC = 36;

}*/

