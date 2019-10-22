/*
 * drv2605l.h
 *
 *  Created on: Sep 30, 2019
 *      Author: jack
 */

#ifndef DRV2605L_H_
#define DRV2605L_H_

//Device address
#define DRV2605L    0x5A        // 7-bit address (8.5.3.1 note)

// register addresses
#define STATUS 0x00
#define MODE 0x01
#define LIBRARY 0x3
#define GO 0x0C
#define CONTROL3 0x1D

// reg values

// MODE register
#define STANDBY_READY 0x00
#define MODE_PWM 0x03
#define MODE_STANDBY (1<<6)

// LIBRARY register
#define  LRA_LIBRARY 0x06

// GO register
#define GO_GO 0x01

// Control3 Register
#define PWM_INPUT 0x0


void config_drv2605l(void);

#endif /* DRV2605L_H_ */
