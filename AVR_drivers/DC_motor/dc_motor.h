#ifndef _DC_MOTOR_H_
#define _DC_MOTOR_H_

#include"micro_config.h"
#include"std_types.h"
#include"common_macros.h"

typedef enum {
    STOP,START,REVERSE
};

void dc_motorInit();
void dc_motor(uint8 state);

#endif