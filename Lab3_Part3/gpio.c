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
//    config_i2c();
//    config_pwm_gpio();
    P3OUT |= 1; // set pin P3.0
    P3DIR |= 1; // set dir to output

    }
