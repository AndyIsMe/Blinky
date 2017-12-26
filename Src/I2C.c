/*
 * I2C.c
 *
 *  Created on: Dec 26, 2017
 *      Author: TARUC
 */

#include "I2C.h"
#include "GPIO.h"
#include "Rcc.h"
#include "DbgMcu.h"

void initI2C1(void){
	enableI2C(I2C1_);
	enableI2C(I2C2_);


	//Configure master
	gpioConfig(GpioB,6, GPIO_MODE_AF , GPIO_OPEN_DRAIN , GPIO_PULL_UP , GPIO_HI_SPEED);
	gpioConfigAltFuncNum(GpioB,6,ALT_FUNC4);				//I2C1 SCL
	gpioConfig(GpioB,7, GPIO_MODE_AF , GPIO_OPEN_DRAIN , GPIO_PULL_UP , GPIO_HI_SPEED);
	gpioConfigAltFuncNum(GpioB,7,ALT_FUNC4);				//I2C1 SDA
	I2c1->OAR1 &= ~(1<<15);
	I2c1->OAR1 |= (1<<15);
	I2c1->CR2  |= 8;
	I2c1->CCR  &= ~(1<<15);
	//I2c1->CCR  &= ~(1<<14);
	//I2c1->CCR  |= 1<<14;
	I2c1->CCR  |= 80;
	I2c1->TRISE|= 9;
	I2c1->CR1  &= ~1;
	I2c1->CR1  |= 1;
	I2c1->CR1  &= ~(1<<8);
	I2c1->CR1  |= (1<<8);
	//Configure slave
	gpioConfig(GpioF,0, GPIO_MODE_AF , GPIO_OPEN_DRAIN , GPIO_PULL_UP , GPIO_HI_SPEED);
	gpioConfigAltFuncNum(GpioF,0,ALT_FUNC4);				//I2C2 SCL
	gpioConfig(GpioF,1, GPIO_MODE_AF , GPIO_OPEN_DRAIN , GPIO_PULL_UP , GPIO_HI_SPEED);
	gpioConfigAltFuncNum(GpioF,1,ALT_FUNC4);				//I2C2 SDA
	//I2c2->CR2 |= 8;
}

void testI2C(void){
	initI2C1();
	haltI2C1WhenDebugging();
	haltI2C1WhenDebugging();
}


