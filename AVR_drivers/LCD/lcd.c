/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Description: Source file for the LCD driver
 *
 * Author: Mohamed Ammar
 *
 *******************************************************************************/

#include "lcd.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void LCD_init(void){
    LCD_CTRL_DIR |= (1<<E) | (1<<RW) | (1<<RS) ;
    LCD_DATA_DIR =0xFF ;

    LCD_sendCommand(TWO_LINE_LCD_EIGHT_BIT_MODE);
    LCD_sendCommand(CURSOR_OFF);
    LCD_sendCommand(CLEAR_COMMAND);
}

void LCD_sendCommand (uint8 command){
    CLEAR_BIT(LCD_CTRL_PORT,RS);
    CLEAR_BIT(LCD_CTRL_PORT,RW);
    _delay_ms(1);
    SET_BIT(LCD_CTRL_PORT,E);
    _delay_ms(1);
    LCD_DATA_PORT = command ;
    _delay_ms(1);
    CLEAR_BIT(LCD_CTRL_PORT,E);
    _delay_ms(1);
}

void LCD_displayCharacter (uint8 data){
    SET_BIT(LCD_CTRL_PORT,RS);
    CLEAR_BIT(LCD_CTRL_PORT,RW);
    _delay_ms(1);
    SET_BIT(LCD_CTRL_PORT,E);
    _delay_ms(1);
    LCD_DATA_PORT = data ;
    _delay_ms(1);
    CLEAR_BIT(LCD_CTRL_PORT,E);
    _delay_ms(1);
}

void LCD_displayString (const char *Str){
    for(uint8 i=0 ; Str[i] != '\0';i++){
        LCD_displayCharacter(Str[i]);
    }
}

void LCD_goToRowColumn (uint8 row , uint8 col){
    uint8 Address;
    switch (row){
        case 0: Address = col;
            break;
        case 1: Address = col + 0x40 ;
            break;
        case 2: Address = col + 0x10;
            break;
        case 3: Address + 0x50 ; 
            break;
    }
    LCD_sendCommand(Address | SET_CURSOR_LOCATION);
}

void LCD_displayStringRowColumn (uint8 row, uint8 col, const char *Str){
    LCD_goToRowColumn(row,col);
    LCD_displayString(Str);
}

void LCD_clearScreen (void){
    LCD_sendCommand(CLEAR_COMMAND);
}

void LCD_intgerToString (int data){
    char buff[16];         //string to hold the ascii result
    itoa (data,buff,10);    //10 for decimal
    LCD_displayString(buff);
}