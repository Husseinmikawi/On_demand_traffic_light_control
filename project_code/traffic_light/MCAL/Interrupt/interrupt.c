/******************************************************************************
 *
 * Module: INTERRUPT
 *
 * File Name: interrupt.c
 *
 * Description: source file for the interrupt driver
 *
 * Author: Hussein Ahmed
 *
 *******************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include"../GPIO/std_types.h"

/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;

/* External INT0 Interrupt Service Routine */
ISR(INT0_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}

}

/* External INT0 enable and configuration function */
void INT0_Init(void)
{
	DDRD  &= (~(1<<PD2));               // Configure INT0/PD2 as input pin
	MCUCR |= (1<<ISC00) | (1<<ISC01);   // Trigger INT0 with the Rising Edge
	GICR  |= (1<<INT0);                 // Enable external interrupt pin INT0

}

/* Description:
 * Function to set the Call Back function address. */
void INT0_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr = a_ptr;
}


