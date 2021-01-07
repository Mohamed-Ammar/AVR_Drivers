/******************************************************************************
 *
 * Module: SPI
 *
 * File Name: spi.c
 *
 * Description: Source file for the SPI AVR driver
 *
 * Author: Mohamed Ammar
 *
 *******************************************************************************/

#include "spi.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void SPI_initMaster(void) 
{
    	/******** Configure SPI Master Pins *********
	 * SS(PB4)   --> Output
	 * MOSI(PB5) --> Output 
	 * MISO(PB6) --> Input
	 * SCK(PB7) --> Output
	 ********************************************/
    SET_BIT(DDRB,PB4);
    SET_BIT(DDRB,PB5);
    CLEAR_BIT(DDRB,PB6);
    SET_BIT(DDRB,PB7);

    SPCR = (1<<SPE) | (1<<MSTR);  // enable SPI + enable Master + choose SPI clock = Fosc/4
}

void SPI_initSlave(void)
{ 
	/******** Configure SPI Slave Pins *********
	 * SS(PB4)   --> Input
	 * MOSI(PB5) --> Input
	 * MISO(PB6) --> Output
	 * SCK(PB7) --> Input
	 ********************************************/
    CLEAR_BIT(DDRB,PB4);
    CLEAR_BIT(DDRB,PB5);
    SET_BIT(DDRB,PB6);
    CLEAR_BIT(DDRB,PB7);

    SPCR = (1<<SPE); // just enable SPI + choose SPI clock = Fosc/4
}

void SPI_sendByte (const uint8 data)
{
    SPDR = data;
	while(BIT_IS_CLEAR(SPSR,SPIF)){} //wait until SPI interrupt flag=1 (data is sent correctly)
}

uint8 SPI_receiveByte (void)
{
    while(BIT_IS_CLEAR(SPSR,SPIF)){} //wait until SPI interrupt flag=1(data is receive correctly)
    return SPDR ;
}

void SPI_sendString (const uint8 *Str)
{
    uint8 i = 0;
    while (Str[i] != '\0')
    {
        SPI_sendByte(Str[i]);
        i++;
    }
}

void SPI_receiveString (uint8 *Str)
{
    uint8 i = 0;
    Str[i] = SPI_receiveByte();
    while (Str[i] != '#')
    {
        i++;
        Str[i] = SPI_receiveByte();
    }
    Str[i]= '\0';
}