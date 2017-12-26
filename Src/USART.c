/*
 * USART.c
 *
 *  Created on: Dec 26, 2017
 *      Author: TARUC
 */

#include "USART.h"
#include <stm32f4xx.h>
#include <stdarg.h>

/*Procedure for transmit:
1. Enable the USART by writing the UE bit in USART_CR1 register to 1.
2. Program the M bit in USART_CR1 to define the word length.
3. Program the number of stop bits in USART_CR2.
4. Select DMA enable (DMAT) in USART_CR3 if Multi buffer Communication is to take
place. Configure the DMA register as explained in multibuffer communication.
5. Select the desired baud rate using the USART_BRR register.
6. Set the TE bit in USART_CR1 to send an idle frame as first transmission.
7. Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this
for each data to be transmitted in case of single buffer.
8. After writing the last data into the USART_DR register, wait until TC=1. This indicates
that the transmission of the last frame is complete. This is required for instance when
the USART is disabled or enters the Halt mode to avoid corrupting the last
transmission.*/


/**
 * Usart.c
 *
 * The connection between UART1 pins on STM32F429ZIT6 and the USB-to-serial
 * (CH340) are as follow:
 *
 * STM32F429ZIT6  |  CH340
 * Name   Pin	  |  Name
 * ------------------------
 * 	Tx	  PA9     |   Rx
 * 	Rx    PA10    |   Tx
 * 	GND   GND     |   GND
 * 	-----------------------
 *
 */
void USARTConfig(void){
	usart->CR1 = USARTEN | Data9bit |OverSampling16<<15|ParityEN|OddParity;
	usart->CR2 |= STOP_2_bits;

}

void USARTTransmit(void){
	usart->CR1 |= TransmitEN;
}

/*Procedure for receive:
1. Enable the USART by writing the UE bit in USART_CR1 register to 1.
2. Program the M bit in USART_CR1 to define the word length.
3. Program the number of stop bits in USART_CR2.
4. Select DMA enable (DMAR) in USART_CR3 if multibuffer communication is to take
place. Configure the DMA register as explained in multibuffer communication. STEP 3
5. Select the desired baud rate using the baud rate register USART_BRR
6. Set the RE bit USART_CR1. This enables the receiver which begins searching for a
start bit.*/

void USARTConfigReceive(void){
	usart->CR1 |= ReceiveEN;
}

void writeData(char *data) {

	while((((USART1->SR)>>7)*0x01)!=1);
	usart->DR = *data;
}

void usart1Send(char ch) {
  while(!usartIsTxEmpty());
  usart->DR = ch;
}

uint8_t usart1Receive(){
	while(!usartIsRxNEmpty());
	return (uint8_t)usart->DR;
}

void usartReceiveTillRespond(char *data){
	*(data) = usart1Receive();
	while(*(data)!=0xA){
		data++;
		*(data) = usart1Receive();
	}
	*data=0;
}

void BaudRateSetting(int mantissa,int fraction){
	usart->BRR = (mantissa<<4) | fraction;
}

/**
 * Print to the serial communication
 *
 * Requirement :
 * 		Serial terminal or any terminal console that can display the character
 * 		strings send through the USART
 *
 * 		Usage example :
 * 			serialPrint("Data: %d,%f,%s,%c,123,doubleVal,"Hello",charVal);
 *
 * WARNING : Cannot be called from interrupt !
 */

void serialPrint(char *format,...){
	va_list args;
	uint8_t *buffer;
	int i,length;

	va_start(args,format);

	length = vsnprintf(buffer , 0 , format , args);
	buffer = malloc(length +1);
	vasnprintf((char *)buffer , length +1 , format , args);

	for(i=0 ; i<length ; i++){
		//Send the character byte by byte
		writeData(&buffer[i]);
	}
	free(buffer);
}

