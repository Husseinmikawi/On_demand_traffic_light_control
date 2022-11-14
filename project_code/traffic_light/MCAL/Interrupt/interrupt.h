/******************************************************************************
 *
 * Module: INTERRUPT
 *
 * File Name: interrupt.h
 *
 * Description: Header file for the interrupt driver
 *
 * Author: Hussein Ahmed
 *
 *******************************************************************************/

#ifndef MCAL_INTERRUPT_INTERRUPT_H_
#define MCAL_INTERRUPT_INTERRUPT_H_

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/* External INT0 enable and configuration function */
void INT0_Init(void);
/* Description:
 * Function to set the Call Back function address. */
void INT0_setCallBack(void(*a_ptr)(void));


#endif /* MCAL_INTERRUPT_INTERRUPT_H_ */
