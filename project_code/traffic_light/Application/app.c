/*
 * app.c
 *
 *  Created on: Nov 9, 2022
 *      Author: Hussein
 */


#include"app.h"

static volatile uint8 g_tick=0; /* global variable to increment with every 3 sec by timer1 interrupt*/
static uint8 g_state_color =0;
static volatile uint8 interrupt_flag=0;

static void pedestrian_mode(void);
/*function called by timer1*/
void delay_500mSEC(void)
{
	g_tick++;
}
void int0_flag(void)
{

	interrupt_flag++;

}
void Long_press(void)
{
	uint8 temp;
	temp=g_tick;
	g_tick=0;
	while(g_tick<1)
	{

	}
	g_tick=0;

	if(Get_Button_state(BUTTON_PORT, BUTTON_PIN) == PRESSED)
	{
		interrupt_flag++;
	}
	g_tick=temp;
}

void app(void)
{
	uint8 i;
	SREG|=(1<<7); /* enable Global interrupt*/
	LED_init();
	INT0_Init();
	Timer1_ConfigType Timer_Conf={0,7813,CLOCK_BY_64,COMPARE_MODE,};
	Timer1_setCallBack(delay_500mSEC);
	INT0_setCallBack(int0_flag);
	Timer1_init(&Timer_Conf);

	/**********Normal mode************/
	while(1)
	{
		/* turn on car_green_led & pedstrain_red_led for 5 second*/
		if(g_state_color ==0)
		{
			g_state_color =1;/* increment the state to enter the next operation*/
			LED_ON(CARS_LEDs_PORT, GREEN_LED);
			LED_ON(pedestrian_LEDs_PORT, RED_LED);
			while(g_tick<10){
				/* check if button pressed */
				if(interrupt_flag==1)
				{
					Long_press();/* check long press on button*/
					if(interrupt_flag==1)
					{
					g_state_color=0;/* clear the state to start from the beginning*/
					pedestrian_mode();
					break;
					}
				}
			}
			g_tick=0;
			LED_OFF(CARS_LEDs_PORT, GREEN_LED);

		}

		if(g_state_color==1)
		{
			g_state_color =2;
			for(i=0;i<5;i++)
			{
				if(interrupt_flag==1)
				{
					Long_press();
					if(interrupt_flag==1)
					{
					g_state_color=0;
					pedestrian_mode();
					break;
					}
				}
				LED_ON(CARS_LEDs_PORT, YELLOW_LED);
				while(g_tick<1){}
				g_tick=0;
				LED_OFF(CARS_LEDs_PORT, YELLOW_LED);
				while(g_tick<1){}
				g_tick=0;
			}
			LED_OFF(pedestrian_LEDs_PORT, RED_LED);

		}
		if(g_state_color==2)
		{

			LED_ON(CARS_LEDs_PORT, RED_LED);
			LED_ON(pedestrian_LEDs_PORT, GREEN_LED);
			while(g_tick<10){
				if(interrupt_flag==1)
				{
					Long_press();
					if(interrupt_flag==1)
					{
					g_state_color=0;
					pedestrian_mode();
					break;
					}
				}
			}
			if(g_tick==10)
				g_state_color=1;
			g_tick=0;
			LED_OFF(CARS_LEDs_PORT, RED_LED);
			LED_OFF(pedestrian_LEDs_PORT, GREEN_LED);


		}
		if(g_state_color==1)
		{
			g_state_color=0;
			for(i=0;i<5;i++)
			{
				if(interrupt_flag==1)
				{
					Long_press();
					if(interrupt_flag==1)
					{
					pedestrian_mode();
					break;
					}
				}
				LED_ON(CARS_LEDs_PORT, YELLOW_LED);
				while(g_tick<1){}
				g_tick=0;
				LED_OFF(CARS_LEDs_PORT, YELLOW_LED);
				while(g_tick<1){}
				g_tick=0;
			}
		}


	}

}

void pedestrian_mode(void)
{
	uint8 i;

	if(g_state_color==2)
	{
		g_tick=0;
		LED_ON(CARS_LEDs_PORT, RED_LED);
		LED_ON(pedestrian_LEDs_PORT, GREEN_LED);
		while(g_tick<10){}
		g_tick=0;
		LED_OFF(CARS_LEDs_PORT, RED_LED);
		LED_OFF(pedestrian_LEDs_PORT, GREEN_LED);
	}
	else
	{
		for(i=0;i<5;i++)
		{
			LED_ON(CARS_LEDs_PORT, YELLOW_LED);
			LED_ON(pedestrian_LEDs_PORT, YELLOW_LED);
			while(g_tick<1){}
			g_tick=0;
			LED_OFF(CARS_LEDs_PORT, YELLOW_LED);
			LED_OFF(pedestrian_LEDs_PORT, YELLOW_LED);
			while(g_tick<1){}
			g_tick=0;
		}

		LED_OFF(pedestrian_LEDs_PORT, RED_LED);
		LED_OFF(CARS_LEDs_PORT, GREEN_LED);
		g_tick=0;

		LED_ON(CARS_LEDs_PORT, RED_LED);
		LED_ON(pedestrian_LEDs_PORT, GREEN_LED);
		while(g_tick<10){}
		g_tick=0;
	}

	for(i=0;i<5;i++)
	{
		LED_ON(CARS_LEDs_PORT, YELLOW_LED);
		LED_ON(pedestrian_LEDs_PORT, YELLOW_LED);
		while(g_tick<1){}
		g_tick=0;
		LED_OFF(CARS_LEDs_PORT, YELLOW_LED);
		LED_OFF(pedestrian_LEDs_PORT, YELLOW_LED);
		while(g_tick<1){}
		g_tick=0;
	}
	LED_OFF(pedestrian_LEDs_PORT, GREEN_LED);
	LED_OFF(CARS_LEDs_PORT, RED_LED);
	LED_ON(pedestrian_LEDs_PORT, RED_LED);

	interrupt_flag=0;
}
