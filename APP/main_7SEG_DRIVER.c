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

#include "SevSeg_int.h"

int main(void)
{
    RCC_enuSetPeripheralClock(APB2, GPIOA, RCC_ENABLE);
    RCC_enuSetPeripheralClock(APB2, GPIOB, RCC_ENABLE);
    RCC_enuSetPeripheralClock(APB2, GPIOC, RCC_ENABLE);
    SevSeg_vidInit();


	while(1)
	{
       for(u8 j= 0 ; j<=9 ; j++)
       {
    	   SevSeg_vidDisplayNumber(j);
          for(u32 i = 0 ; i<8000000 ; i++);
          if(j == 10)
          {
        	  j = 0;
          }
          else
          {
        	  continue;
          }
       }
	}
	return 0;
}
