/*
 * ADC.h
 *
 *  Created on: Jan 2, 2018
 *      Author: TARUC
 */

#ifndef ADC_H_
#define ADC_H_
#include "GPIO.h"

#define ADC1_BASE_ADDR		0x40012000
#define ADC2_BASE_ADDR		0x40012100
#define ADC3_BASE_ADDR		0x40012200
#define ADC_COMMON_BASE_ADDR		0x40012300
#define adc1			((AdcReg *)(ADC1_BASE_ADDR))
#define adc2			((AdcReg *)(ADC2_BASE_ADDR))
#define adc3			((AdcReg *)(ADC3_BASE_ADDR))

typedef struct AdcReg AdcReg;
struct AdcReg {
	volatile uint32_t SR;			//0h Status Register
	volatile uint32_t CR1;			//4h Control Register 1
	volatile uint32_t CR2;			//8h Control Register 2
	volatile uint32_t SMPR1;		//ch Sample Time Register 1
	volatile uint32_t SMPR2;		//10h Sample Time Register 2
	volatile uint32_t JOFR1;		//14h Injected Channel 1 Data
	volatile uint32_t JOFR2;		//18h Injected Channel 2 Data
	volatile uint32_t JOFR3;		//1ch Injected Channel 3 Data
	volatile uint32_t JOFR4;		//20h Injected Channel 4 Data
	volatile uint32_t HTR;			//24h Watchdog Higher Threshold Register
	volatile uint32_t LTR;			//28h Watchdog Lower Threshold Register
	volatile uint32_t SQR1;			//2ch Regular Sequence Register 1
	volatile uint32_t SQR2;			//30h Regular Sequence Register 2
	volatile uint32_t SQR3;			//34h Regular Sequence Register 3
	volatile uint32_t JSQR;			//38h Injected Sequence Register
	volatile uint32_t JDR1;			//3ch Injected Data Register 1
	volatile uint32_t JDR2;			//40h Injected Data Register 2
	volatile uint32_t JDR3;			//44h Injected Data Register 3
	volatile uint32_t JDR4;			//48h Injected Data Register 4
	volatile uint32_t DR;			//4ch Regular Data Register

};

typedef struct AdcCommonReg AdcCommonReg;
struct AdcCommonReg {

	volatile uint32_t CSR;			//0h Common Status Register
	volatile uint32_t CCR;			//4h Common Control Register
	volatile uint32_t CDR;			//8h Common Data Register

};
//Control Register 2
#define SWSTARTEN	(1<<30)
#define JWSTART		(1<<22)
#define ADON_EN     1
#define EXTEN_RISE	(1<<28)

//Control Register 1
#define AWDEN_EN    (1<<23)
#define AWDCH_CH5	(1<<5)
#define EOC_EN		(1<<10)
#define CONT_EN		(1<<1)
#define ALIGN_R     (0<<11)
#define ALIGN_L		(1<<11)
#define Reso_10bit	(1<<24)
#define SCAN_EN		(1<<8)

//Regular Sequence Register 1
#define SQ_LENGTH_1 (0<<20)
#define SQ_LENGTH_2 (1<<20)
#define SQ_LENGTH_4 (4<<20)

//Sample Time Register 1
#define _3_CYCLES		0
#define _15_CYCLES		1
#define _28_CYCLES		2
#define _56_CYCLES		3
#define _84_CYCLES		4
#define _112_CYCLES		5
#define _144_CYCLES		6
#define _480_CYCLES		7

#define channel5	 	5
#define channel13   (13<<5)
#define channel1		1
#define channel6	(6<<5)
#define channel10	(10<<10)
#define channel14	(14<<15)

void SingleConvConfig(int channel);
void DoubleConvConfig(int first_channel , int second_channel);
#endif /* ADC_H_ */
