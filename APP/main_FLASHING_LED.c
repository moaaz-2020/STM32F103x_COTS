/*
 * main.c
 *
 *  Created on: 23 Jul 2020
 *      Author: moaz1
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"


#include "RCC_int.h"
#include "RCC_reg.h"
#include "RCC_config.h"

#include "GPIO_int.h"

int main(void)
{
    RCC_enuSetPeripheralClock(APB2, GPIOA, RCC_ENABLE);
	GPIO_enuSetPinMode(PORTA , PIN1 , OUTPUT , OUTPUT_PUSHPULL , SPEED_10MHZ);


	while(1)
	{

		GPIO_enuSetPinValue(PORTA , PIN1 , HIGH);
		for(u32 i = 0; i<500000; i++);
		GPIO_enuSetPinValue(PORTA , PIN1 , LOW);
		for(u32 i = 0; i<500000; i++);
	}
	return 0;
}
