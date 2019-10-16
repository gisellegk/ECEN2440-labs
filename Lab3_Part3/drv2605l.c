/*
 * drv2605l.c
 *
 *  Created on: Oct 16, 2019
 *
 */

#include "msp.h"
#include "i2c.h"
#include "gpio.h"
#define DRV2605L 0x5A // 7-bit address

#define STATUS 0x00
#define MODE 0x01
#define GO 0x0C
#define CONTROL3 0x1D

#define MODE_PWM 0x03
#define MODE_STANDBY (1<<6)
#define GO_GO 0x01
#define LIBRARY 0x3

void config_drv2605l(void(*toggle_routine)()) {
    config_drv_gpio(); //configure EN pin
    toggle_routine();   //remove from standby mode

    int i;
    for(i=0; i<100000; i++); //wait 250us before writing to it

   write_register(DRV2605L, MODE, 0b0000011); //come out of standby and set MODE register to 3
    uint8_t mode_reg = read_register(DRV2605L, MODE); //for debug
    write_register(DRV2605L, CONTROL3, 0b00);  //  set CONTROL3 to PWM
   write_register(DRV2605L, LIBRARY, 0x6);  //   select LRA library



//    MODE &= ~0b1000000;

 //   MODE |= 0x3; // set MODE reg. to 3
 //   CONTROL3 &= ~0x2;    //  set CONTROL3 to PWM
  //  LIBRARY |= 0x6; // select LRA library

    mode_reg = read_register(DRV2605L, MODE);
    if(mode_reg != (MODE_PWM)){
        P1->DIR |= BIT0;
        P1->OUT |= BIT0; //Indicates error occurred
    }
    uint8_t control_three_reg = read_register(DRV2605L, CONTROL3);
    if (control_three_reg != 0x00) {
        P1->DIR |= BIT0;
        P1->OUT |= BIT0; //Indicates error occurred
    }

}
