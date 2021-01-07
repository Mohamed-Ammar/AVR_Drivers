/******************************************************************************
 *
 * Module: Micro - Configuration
 *
 * File Name: Micro_Config.h
 *
 * Description: File include all Microcontroller libraries
 *
 * Engineer: Mohamed Ammar
 *
 *******************************************************************************/

#ifndef MICRO_CONFIG_H_
#define MICRO_CONFIG_H_

#ifndef __AVR_ATmega16__
#define __AVR_ATmega16__
#endif
#define F_CPU 1000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#endif /* MICRO_CONFIG_H_ */
