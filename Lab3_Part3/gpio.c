/*
 * gpio.c
 *
 *  Created on: Oct 16, 2019
 *      Author: phaed
 */
#include "i2c.h"
#include"pwm.h"
#include "msp.h"

void config_drv_gpio(void){
    P3OUT |= 1; // Sets pin P3.0
    P3DIR |= 1; // Sets pin to output
    }
