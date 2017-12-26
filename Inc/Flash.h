/*
 * Flash.h
 *
 *  Created on: Dec 26, 2017
 *      Author: TARUC
 */

#ifndef FLASH_H_
#define FLASH_H_
#include "Rcc.h"
#include <stdint.h>

#define FLASH_BASE_ADDR		0x40023C00
#define flash 			((FlashReg *)(FLASH_BASE_ADDR))

#define Sector13ADDR			0x08084000

//Flash Control Register
#define sectorEraseEn				1<<1
#define MassEraseEn					1<<2
#define ProgEn						1
#define FLASHSTART					1<<16
#define FLASH_BYTE_SIZE				0
#define FLASH_HALFWORD_SIZE			1
#define FLASH_WORD_SIZE				2
#define FLASH_DOUBLEWORD_SIZE		3

//Flash Status Register
#define FLASH_BUSY					1<<16

typedef struct FlashReg FlashReg;
struct FlashReg {
	volatile uint32_t ACR;		//0h
	volatile uint32_t KEYR;		//4h
	volatile uint32_t OPTKEYR;	//8h
	volatile uint32_t SR;		//ch
	volatile uint32_t CR;		//10h
	volatile uint32_t OPTCR;	//14h [Write Protection Program(Not Using)]
	volatile uint32_t OPTCR1;	//18h [Write Protection Program(Not Using)]
};

#define KEY1	0x45670123
#define KEY2	0xCDEF89AB

int flashEraseSection(int sectionNum);
int writeMessage(char *message,char *memoryToWrite);
int flashEnableProgramming(int programSize);
int flashDisable();


#endif /* FLASH_H_ */
