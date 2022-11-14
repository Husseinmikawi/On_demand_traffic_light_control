/*
 * button.c
 *
 *  Created on: Nov 11, 2022
 *      Author: Hussein
 */

#include"button.h"
uint8 Get_Button_state(uint8 port_num, uint8 pin_num)
{
	GPIO_setupPinDirection(port_num, pin_num, PIN_OUTPUT);
	return GPIO_readPin(port_num, pin_num);
}
