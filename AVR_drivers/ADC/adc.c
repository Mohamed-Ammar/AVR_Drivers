/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Mohamed Ammar
 *
 *******************************************************************************/

#include "adc.h"

/*******************************************************************************
 *                          Global Variables                                   *
 *******************************************************************************/

volatile uint16 g_adcResult = 0;

/*******************************************************************************
 *                          ISR's Definitions                                  *
 *******************************************************************************/

    ISR(ADC_vect)
{
	/* Read ADC Data after conversion complete */
	g_adcResult = ADC;
}

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init (void)
{
    /* ADMUX Register Bits Description:
	 * REFS1:0 = 00 to choose to connect external reference voltage by input this voltage through AREF pin
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
    ADMUX = 0x00; //channel 0

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 1 enable ADC Interrupt
	 * ADPS2:0 = 011 to choose ADC_Clock=F_CPU/8=1Mhz/8=125Khz --> ADC must operate in range 50-200Khz
	 */
    ADCSRA = (1<<ADEN) | (1<<ADIE) | (1<<ADPS1) | (1<<ADPS0); 
}

uint16 ADC_readChannel (uint8 channel_num)
{
    channel_num &= 0x07;
    ADMUX &= 0xE0;
    ADMUX |= channel_num;
    SET_BIT(ADCSRA,ADSC);
    //if not interrupted
    /*
    while(BIT_IS_CLEAR(ADCSRA,ADIF));
    SET_BIT(ADCSRA,ADIF);
    return ADC;*/
}

