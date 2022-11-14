/******************************************************************************
 *
 * Module: LED
 *
 * File Name: LED.h
 *
 * Description: Header file for the LED driver
 *
 * Author: Hussein Ahmed
 *
 *******************************************************************************/

#ifndef ECUAL_LED_LED_H_
#define ECUAL_LED_LED_H_

#include"../../MCAL/GPIO/gpio.h"

#define CARS_LEDs_PORT          PORTA_ID
#define pedestrian_LEDs_PORT    PORTB_ID
#define GREEN_LED               PIN0_ID
#define YELLOW_LED              PIN1_ID
#define RED_LED                 PIN2_ID

void LED_init(void);
void LED_ON(uint8 port_num, uint8 pin_num);
void LED_OFF(uint8 port_num, uint8 pin_num);


#endif /* ECUAL_LED_LED_H_ */
