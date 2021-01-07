#include "dc_motor.h"

void dc_motorInit(){

    SET_BIT (DDRA,PA3);
    SET_BIT(DDRA,PA4);
    CLEAR_BIT(PORTA,PA3);
    CLEAR_BIT(PORTA,PA4);
}

void dc_motor (uint8 state){
    if (state==STOP){
        CLEAR_BIT(PORTA,PA3);
        CLEAR_BIT(PORTA,PA4);
    }
    else if (state==START){
        SET_BIT(PORTA,PA3);
        CLEAR_BIT(PORTA,PA4);
    }
    else if (state==REVERSE){
        SET_BIT(PORTA,PA4);
        CLEAR_BIT(PORTA,PA3);
    }
}