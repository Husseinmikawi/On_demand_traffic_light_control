/******************************************************************************
 *
 * Module: LED
 *
 * File Name: LED.c
 *
 * Description: source file for the LED driver
 *
 * Author: Hussein Ahmed
 *
 *******************************************************************************/

#include"LED.h"

void LED_init(void)
{
	GPIO_setupPinDirection(CARS_LEDs_PORT, GREEN_LED, PIN_OUTPUT);
	GPIO_setupPinDirection(CARS_LEDs_PORT, YELLOW_LED, PIN_OUTPUT);
	GPIO_setupPinDirection(CARS_LEDs_PORT, RED_LED, PIN_OUTPUT);
	GPIO_setupPinDirection(pedestrian_LEDs_PORT, GREEN_LED, PIN_OUTPUT);
	GPIO_setupPinDirection(pedestrian_LEDs_PORT, YELLOW_LED, PIN_OUTPUT);
	GPIO_setupPinDirection(pedestrian_LEDs_PORT, RED_LED, PIN_OUTPUT);

}

void LED_ON(uint8 port_num, uint8 pin_num)
{
	GPIO_writePin(port_num, pin_num, LOGIC_HIGH);
}

void LED_OFF(uint8 port_num, uint8 pin_num)
{
	GPIO_writePin(port_num, pin_num, LOGIC_LOW);
}
