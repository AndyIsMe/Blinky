/*
 * Flash.c
 *
 *  Created on: Dec 26, 2017
 *      Author: TARUC
 */

#include "Flash.h"
#include "string.h"

/**
 * Section erase the flash memory (STM32F429ZIT6 MCU only)
 * Input  :
 *      sectionNum is the section to erase
 *
 * Return :
 * 		0 : Fail to Erase
 * 		1 : Successful
 */

int flashEraseSection(int sectionNum){
	//Unlock through KEYR

	//Set the sector number to erase
	//Set to sector erase
	//Start Erase
	//Check for failure or success[Check OPERR bit(failure if set) and EOP bit(success if set)]
	//Return status
//	flash->KEYR = KEY1;
//	flash->KEYR = KEY2;
	//flash->CR |= sectorEraseEn<<1;
	if(sectionNum > 11){
		sectionNum = sectionNum + 4 ;
	}
	flash->CR = (sectionNum<<3);
	flash->CR |= sectorEraseEn;
	flash->CR |= FLASHSTART;
	//flash->CR |= sectionNum << 3;
	//flash->CR |= STARTErase<<16;
	return 1;

}

int writeMessage(char *message,char *memoryToWrite){
	strcpy(memoryToWrite,message);
	/*while(*message !=0){
		*(memoryToWrite++) = *(message++);
	}*/
}

/**
 * Enable flash programming with the stated program size
 * Input :
 * 	programSize is the size when writing into the flash
 * 				FLASH_BYTE_SIZE
 * 				FLASH_HALFWORD_SIZE
 * 				FLASH_WORD_SIZE
 * 				FLASH_DOUBLEWORD_SIZE
 */

int flashEnableProgramming(int programSize){
	flash->KEYR = KEY1;
	flash->KEYR = KEY2;
	flash->CR   = (programSize << 8)|ProgEn;
	//flash->CR 	|= 1;
	return 1;
}

int flashDisable(){
	flash->CR &= ~1;

}


