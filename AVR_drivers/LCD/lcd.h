/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for the LCD driver
 *
 * Author: Mohamed Ammar
 *
 *******************************************************************************/

#ifndef _LCD_H_
#define _LCD_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
/* LCD HW Pins */
#define RS PD4
#define RW PD5
#define E  PD6
#define LCD_CTRL_PORT PORTD
#define LCD_CTRL_DIR  DDRD

#define LCD_DATA_PORT PORTC
#define LCD_DATA_DIR  DDRC

/* LCD Commands */
#define CLEAR_COMMAND 0x01
#define DEC_CURSOR 0x04
#define INC_CURSOR 0x06
#define TWO_LINE_LCD_EIGHT_BIT_MODE 0x38
#define CURSOR_OFF   0x0C
#define CURSOR_ON 0x0E    //BLINKING
#define SET_CURSOR_LOCATION 0x80

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void LCD_init(void);
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 data);
void LCD_displayString(const char *Str);
void LCD_goToRowColumn(uint8 row,uint8 col);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_clearScreen(void);
void LCD_intgerToString(int data);

#endif /* LCD_H_ */
