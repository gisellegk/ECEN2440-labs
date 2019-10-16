/*
 * gpio.c
 *
 *  Created on: Oct 16, 2019
 *      Author: phaed
 */
#include "i2c.h"
#include"pwm.h"

void config_drv_gpio(void){
    config_i2c();
    config_pwm_gpio();
}
