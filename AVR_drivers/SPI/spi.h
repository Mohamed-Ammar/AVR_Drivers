/******************************************************************************
 *
 * Module: SPI
 *
 * File Name: spi.h
 *
 * Description: Header file for the SPI AVR driver
 *
 * Author: Mohamed Ammar
 *
 *******************************************************************************/

#ifndef SPI_H_
#define SPI_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void  SPI_initMaster(void);
void  SPI_initSlave (void);
void  SPI_sendByte (const uint8 data);
void  SPI_sendString (const uint8 *Str);
uint8 SPI_receiveByte (void);
void  SPI_receiveString (uint8 *Str);

#endif