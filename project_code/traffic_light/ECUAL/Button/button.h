/*
 * button.h
 *
 *  Created on: Nov 11, 2022
 *      Author: Hussein
 */

#ifndef ECUAL_BUTTON_BUTTON_H_
#define ECUAL_BUTTON_BUTTON_H_

#include"../../MCAL/GPIO/gpio.h"

#define PRESSED     LOGIC_HIGH
#define UNPRESSED   LOGic_LOw
#define BUTTON_PORT PORTD_ID
#define BUTTON_PIN  PIN2_ID


uint8 Get_Button_state(uint8 port_num, uint8 pin_num);

#endif /* ECUAL_BUTTON_BUTTON_H_ */
