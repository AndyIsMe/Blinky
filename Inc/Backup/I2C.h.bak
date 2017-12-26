/*
 * I2C.h
 *
 *  Created on: Dec 26, 2017
 *      Author: TARUC
 */

#ifndef I2C_H_
#define I2C_H_
#include <stdint.h>

#define I2c1 				((I2cReg *)(I2C1_BASE_ADDR))
#define I2c2 				((I2cReg *)(I2C2_BASE_ADDR))
#define I2c3 				((I2cReg *)(I2C3_BASE_ADDR))
#define I2C1_BASE_ADDR		0x40005400
#define I2C2_BASE_ADDR		0x40005800
#define I2C3_BASE_ADDR		0x40005c00

typedef struct I2cReg I2cReg;
struct I2cReg{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t OAR1;
	volatile uint32_t OAR2;
	volatile uint32_t DR;
	volatile uint32_t SR1;
	volatile uint32_t SR2;
	volatile uint32_t CCR;
	volatile uint32_t TRISE;
	volatile uint32_t FLTR;
};

#define I2C1_			1
#define I2C2_			2
#define I2C3_			3

void initI2C1(void);
void testI2C(void);



#endif /* I2C_H_ */
