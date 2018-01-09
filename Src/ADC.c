/*
 * ADC.c
 *
 *  Created on: Jan 2, 2018
 *      Author: TARUC
 */
#include "ADC.h"

/*
 * In Single conversion mode the ADC does one conversion. This mode is started with the
CONT bit at 0 by either:
• setting the SWSTART bit in the ADC_CR2 register (for a regular channel only)
• setting the JSWSTART bit (for an injected channel)
• external trigger (for a regular or injected channel)
Once the conversion of the selected channel is complete:
• If a regular channel was converted:
– The converted data are stored into the 16-bit ADC_DR register
– The EOC (end of conversion) flag is set
– An interrupt is generated if the EOCIE bit is set
• If an injected channel was converted:
– The converted data are stored into the 16-bit ADC_JDR1 register
– The JEOC (end of conversion injected) flag is set
– An interrupt is generated if the JEOCIE bit is set
Then the ADC stops.
 */

/*
 * The ADC is powered on by setting the ADON bit in the ADC_CR2 register. When the ADON
bit is set for the first time, it wakes up the ADC from the Power-down mode.
Conversion starts when either the SWSTART or the JSWSTART bit is set.
You can stop conversion and put the ADC in power down mode by clearing the ADON bit. In
this mode the ADC consumes almost no power (only a few μA).
 */

/*
 * Managing a sequence of conversions without using the DMA
If the conversions are slow enough, the conversion sequence can be handled by the
software. In this case the EOCS bit must be set in the ADC_CR2 register for the EOC status
bit to be set at the end of each conversion, and not only at the end of the sequence. When
EOCS = 1, overrun detection is automatically enabled. Thus, each time a conversion is
complete, EOC is set and the ADC_DR register can be read. The overrun management is
the same as when the DMA is used.
To recover the ADC from OVR state when the EOCS is set, follow the steps below:
1. Clear the ADC OVR bit in ADC_SR register
2. Trigger the ADC to start the conversion.
It may be useful to let the ADC convert one or more channels without reading the data each
time (if there is an analog watchdog for instance). For that, the DMA must be disabled
(DMA = 0) and the EOC bit must be set at the end of a sequence only (EOCS = 0). In this
configuration, overrun detection is disabled.
 *
 */

void SingleConvConfig(int channel){
	adc1->CR2 = ADON_EN | ALIGN_R | CONT_EN ;
	adc1->SQR1 |= SQ_LENGTH_1;
	adc1->SQR3 = channel5;
	adc1->SMPR2 |= _480_CYCLES << (3*channel);
	//adc1->SMPR1 |= _144_CYCLES << 9;
	adc1->CR2 |= SWSTARTEN;
	//adc1->SQR3 = channel4;
}

void DoubleConvConfig(int first_channel , int second_channel){

	adc1->CR2 = ADON_EN | ALIGN_R | CONT_EN ;
	adc1->SQR1 |= SQ_LENGTH_2;
	adc1->SQR3 = channel5 | channel13;
	adc1->SMPR2 |= _480_CYCLES << (3 * first_channel);
	adc1->SMPR1 |= _144_CYCLES << (3 * second_channel);
	adc1->CR2 |= SWSTARTEN;
}

void adcSetChannelSamplingSequence(AdcReg *adc, int channels[], int numOfChan){

	int i;
	for(i=0 ; i<numOfChan ; i++)
		if(i > 9)
			adc->SMPR1 = channels[i]<<(3*(i-10));
		else
			adc->SMPR2 = channels[i]<<(3*i);

}
void adcChannelSamplingTime(AdcReg *adc, int channel, int cycles){
	if(channel > 9)
		adc->SMPR1 = cycles << (3*(channel-10));
	else
		adc->SMPR2 = cycles <<(3*channel);
}
