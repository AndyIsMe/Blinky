/*
 * DMA.h
 *
 *  Created on: Dec 26, 2017
 *      Author: TARUC
 */

#ifndef DMA_H_
#define DMA_H_
#include "Rcc.h"
#include "USART.h"
#include "Timer.h"


#define DMA1_BASE_ADDR		0x40026000
#define dma1			((DmaReg *)(DMA1_BASE_ADDR))
#define DMA2_BASE_ADDR		0x40026400
#define dma2 			((DmaReg *)(DMA2_BASE_ADDR))

#define dmaStreamHasTransferCompleted(d,s)  	dmaStreamCheckFlag(d,s,DMA_TCIF)
#define dmaStreamHasHalfTransferCompleted(d,s)  dmaStreamCheckFlag(d,s,DMA_HCIF)
#define dmaStreamIsTransferError(d,s)  			dmaStreamCheckFlag(d,s,DMA_TEIF)
#define dmaStreamIsDirectModeError(d,s)  		dmaStreamCheckFlag(d,s,DMA_DMEIF)
#define dmaStreamIsFIFOError(d,s)  				dmaStreamCheckFlag(d,s,DMA_FEIF)

// DMA Interrupt Status Register (xISR)
#define DMA_TCIF	(1<<5)
#define DMA_HTIF	(1 << 4)
#define DMA_TEIF	(1 << 3)
#define DMA_DMEIF	(1 << 2)
#define DMA_FEIF	1



typedef struct DmaStreamReg DmaStreamReg;
struct DmaStreamReg {
	volatile uint32_t CR;		//0h
	volatile uint32_t NDTR;		//4h
	volatile uint32_t PAR;		//8h
	volatile uint32_t M0AR;		//ch
	volatile uint32_t M1AR;		//10h
	volatile uint32_t FCR;		//14h

};


typedef struct DmaReg DmaReg;
struct DmaReg {
	volatile uint32_t LISR;		//0h
	volatile uint32_t HISR;		//4h
	volatile uint32_t LIFCR;	//8h
	volatile uint32_t HIFCR;	//ch
	DmaStreamReg S[8];
};


//SxFCR register
#define FIFO_QUARTER 		0
#define FIFO_HALF 			1
#define FIFO_THREE_QUARTER 	(1<<1)
#define FIFO_FULL 			(3<<1)

//SxCr register
#define StreamEN	1
#define DMAFlowControl	(0<<5)
#define MemoryPointerIn (1<<10)
#define LowPrio			(0<<17)
#define MediumPrio		(1<<17)
#define HighPrio		(1<<17)
#define VHPrio			(3<<16)
#define MBURST_SINGLE	(0<<23)
#define MBURST_INCR4	(1<<23)
#define MBURST_INCR8	(1<<24)
#define MBURST_INCR16	(3<<24)
#define CIRC_MODE_EN	(1<<8)

#define MINC_EN			(1<<10)

//Data Transfer Direction
#define Peripheral_To_Memory	(0<<6)
#define Memory_To_Peripheral	(1<<6)
#define Memory_To_Memory		(1<<7)

//Channel Selection
#define channel_0	(0<<25)
#define channel_1	(1<<25)
#define channel_2	(1<<26)
#define channel_3	(3<<26)
#define channel_4	(1<<27)
#define channel_5	(5<<27)
#define channel_6	(6<<27)
#define channel_7	(7<<27)


//PSIZE
#define PSIZE_ONEBYTE	(0<<12)
#define PSIZE_HALFWORD	(1<<12)
#define PSIZE_WORD		(2<<12)

//MSIZE
#define MSIZE_onebyte		(0<<14)
#define MSIZE_halfword	(1<<14)
#define MSIZE_word		(2<<14)

void DmainitForUsart1(/*char *str*/);
int dmaStreamCheckFlag(DmaReg *dma , int streamNum , int flag);
void sendBitPattern(uint8_t data);
void DmainitForTimer8(/*char *str*/);

//dma1->LIFCR = ?;
//dma1->S[4].M0AR = ?;



#endif /* DMA_H_ */
