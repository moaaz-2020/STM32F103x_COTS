/*
 * main.c
 *
 *  Created on: 24 Jul 2020
 *      Author: moaz1
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"


#include "RCC_int.h"
#include "RCC_reg.h"
#include "RCC_config.h"

#include "GPIO_int.h"

#include "LED_int.h"

int main(void)
{
    RCC_enuSetPeripheralClock(APB2, GPIOA, RCC_ENABLE);
	LED_enumSetLedPin(PORTA , PIN10);


	while(1)
	{
       LED_enumSetLedOn(PORTA , PIN10);
       for(u32 i = 0 ; i<8000000 ; i++);
       LED_enumSetLedOff(PORTA , PIN10);
       for(u32 i = 0 ; i<8000000 ; i++);
	}
	return 0;
}
