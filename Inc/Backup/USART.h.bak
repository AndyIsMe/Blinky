/*
 * USART.h
 *
 *  Created on: Dec 26, 2017
 *      Author: TARUC
 */

#ifndef USART_H_
#define USART_H_

#include "Rcc.h"
#include "stdint.h"

#define USART1_BASE_ADDR		0x40011000
#define usart 			((UsartReg *)(USART1_BASE_ADDR))
//CR1 Configuration
#define USARTEN			(1<<13)
#define Data9bit		(1<<12)
#define Data8bit		~(1<<12)
#define TransmitEN		(1<<3)
#define OverSampling16 	0
#define OverSampling8	(1<<15)
#define ParityEN		(1<<10)
#define ParityRst		~(1<<10)
#define OddParity		(1<<9)
#define EvenParity		~(1<<9)
#define ReceiveEN		(1<<2)
#define ReceiveRst		~(1<<2)

//CR2 Stop bit configuration
#define STOP_1_bits		(0<<12)
#define STOP_0.5_bits	(1<<12)
#define STOP_2_bits		(2<<12)
#define STOP_1.5_bits	(3<<12)

//CR3 Configuration
#define DMATransmitEN	(1<<7)
#define DMATransmitRst	~(1<<7)
#define DMAReceiveEn	(1<<6)

// SR
#define USART_TXE		(1<<7)

#define usartIsTxEmpty() (usart->SR & USART_TXE)

#define USART_RXNE		(1<<5)

#define usartIsRxNEmpty() (usart->SR & USART_RXNE)


typedef struct UsartReg UsartReg;
struct UsartReg {
	volatile uint32_t SR;		//0h
	volatile uint32_t DR;		//4h
	volatile uint32_t BRR;		//8h
	volatile uint32_t CR1;		//ch
	volatile uint32_t CR2;		//10h
	volatile uint32_t CR3;		//14h
	volatile uint32_t GTPR;		//18h
};

#define uart1EnableDmaTx()		(usart->CR3 |= DMATransmitEN)
#define uart1EnableDmaRx()		(usart->CR3 |= DMAReceiveEN)

void USARTConfig(void);
void USARTTransmit(void);
void USARTConfigReceive(void);
//int writeData(uint32_t data);
void BaudRateSetting(int mantissa,int fraction);
void writeData(char *data);
void usart1Send(char ch);
uint8_t usart1Receive();
void usartReceiveTillRespond(char *data);
void serialPrint(char *format,...);


#endif /* USART_H_ */
