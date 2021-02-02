/***************************************************/
/****AUTHOR      : Moaaz Rashad Sewilam            */
/****Date        : 09/05/2020                      */
/****Version     : 1.0  V                          */
/****Description : RESET AND CLOCK CONTROL(RCC)    */
/****                 IMPLEMENTATION               */
/***************************************************/


/***************************************************/
/**********  STANDARD LIB DIRECTIVES ***************/
/***************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"


/***************************************************/
/********** COMPONENTS DIRECTIVES    ***************/
/***************************************************/

#include "RCC_reg.h"
#include "RCC_int.h"
#include "RCC_Config.h"
#include "RCC_Priv.h"

/************************************************/
/* THIS FUNCTION FOR INITIALIZATION RCC         */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void RCC_vidCLKInit(void)
{
  #if CLOCK_TYPE == HSI
    /* HSI CLOCK ENABLE */
    SET_BIT(RCC->CR , 0);
	/* HSI SELECTED AS SYSTEM CLOCK */
	CLR_BIT(RCC->CFGR , 0);
	CLR_BIT(RCC->CFGR , 1);
	/* HSI READY FLAG */
	while(!GIT_BIT(RCC->CR , 1));
  #elif CLOCK_TYPE == HSE
    /* HSE CLOCK ENABLE */
    SET_BIT(RCC->CR , 16);
	/* HSE SELECTED AS SYSTEM CLOCK */
	SET_BIT(RCC->CFGR , 0);
	CLR_BIT(RCC->CFGR , 1);
	/* HSE READY FLAG */
	while(!GIT_BIT(RCC->CR , 17));	
  #elif CLOCK_TYPE == PLL
  /*	The PLL output frequency must not exceed 72 MHz */  
  	/* PLL SELECTED AS SYSTEM CLOCK */
	CLR_BIT(RCC->CFGR , 0);
	SET_BIT(RCC->CFGR , 1);
	   /*PLL multiplication factor*/		
		#if CLOCK_FACTOR == MULTIPLY_BY_2
		CLR_BIT(RCC -> CFGR , 18 );
		CLR_BIT(RCC -> CFGR , 19 );
		CLR_BIT(RCC -> CFGR , 20 );
		CLR_BIT(RCC -> CFGR , 21 );
		#elif CLOCK_FACTOR == MULTIPLY_BY_3
		SET_BIT(RCC -> CFGR , 18 );
		CLR_BIT(RCC -> CFGR , 19 );
		CLR_BIT(RCC -> CFGR , 20 );
		CLR_BIT(RCC -> CFGR , 21 );
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_4
		CLR_BIT(RCC -> CFGR , 18 );
		SET_BIT(RCC -> CFGR , 19 );
		CLR_BIT(RCC -> CFGR , 20 );
		CLR_BIT(RCC -> CFGR , 21 );
		
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_5
		SET_BIT(RCC -> CFGR , 18 );
		SET_BIT(RCC -> CFGR , 19 );
		CLR_BIT(RCC -> CFGR , 20 );
		CLR_BIT(RCC -> CFGR , 21 );
		
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_6
		CLR_BIT(RCC -> CFGR , 18 );
		CLR_BIT(RCC -> CFGR , 19 );
		SET_BIT(RCC -> CFGR , 20 );
		CLR_BIT(RCC -> CFGR , 21 );
		
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_7
		SET_BIT(RCC -> CFGR , 18 );
		CLR_BIT(RCC -> CFGR , 19 );
		SET_BIT(RCC -> CFGR , 20 );
		CLR_BIT(RCC -> CFGR , 21 );
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_8
		CLR_BIT(RCC -> CFGR , 18 );
		SET_BIT(RCC -> CFGR , 19 );
		SET_BIT(RCC -> CFGR , 20 );
		CLR_BIT(RCC -> CFGR , 21 );
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_9
		SET_BIT(RCC -> CFGR , 18 );
		SET_BIT(RCC -> CFGR , 19 );
		SET_BIT(RCC -> CFGR , 20 );
		CLR_BIT(RCC -> CFGR , 21 );
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_10
		CLR_BIT(RCC -> CFGR , 18 );
		CLR_BIT(RCC -> CFGR , 19 );
		CLR_BIT(RCC -> CFGR , 20 );
		SET_BIT(RCC -> CFGR , 21 );
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_11
		SET_BIT(RCC -> CFGR , 18 );
		CLR_BIT(RCC -> CFGR , 19 );
		CLR_BIT(RCC -> CFGR , 20 );
		SET_BIT(RCC -> CFGR , 21 );
		
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_12
		CLR_BIT(RCC -> CFGR , 18 );
		SET_BIT(RCC -> CFGR , 19 );
		CLR_BIT(RCC -> CFGR , 20 );
		SET_BIT(RCC -> CFGR , 21 );
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_13
		SET_BIT(RCC -> CFGR , 18 );
		SET_BIT(RCC -> CFGR , 19 );
		CLR_BIT(RCC -> CFGR , 20 );
		SET_BIT(RCC -> CFGR , 21 );
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_14
		CLR_BIT(RCC -> CFGR , 18 );
		CLR_BIT(RCC -> CFGR , 19 );
		SET_BIT(RCC -> CFGR , 20 );
		SET_BIT(RCC -> CFGR , 21 );
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_15
		SET_BIT(RCC -> CFGR , 18 );
		CLR_BIT(RCC -> CFGR , 19 );
		SET_BIT(RCC -> CFGR , 20 );
		SET_BIT(RCC -> CFGR , 21 );
		
		#elif CLOCK_FACTOR == MULTIPLY_BY_16
		CLR_BIT(RCC -> CFGR , 18 );
		SET_BIT(RCC -> CFGR , 19 );
		SET_BIT(RCC -> CFGR , 20 );
		SET_BIT(RCC -> CFGR , 21 );
		
		#else
			#warning	"Wrong Multiplication factor!"
		
		#endif
		#if 	PLL_SOURCE	==	PLL_HSI_DIVIDED_BY_2
		  /*PLL entry clock source is HSI divdided by 2	*/
		CLR_BIT(RCC -> CFGR , 16 );	
		#elif	PLL_SOURCE	==	PLL_HSE
		  /*PLL entry clock source is HSE	*/
		SET_BIT(RCC -> CFGR , 16 );
		  /*HSE divider for PLL entry : clock not divided 	*/
		CLR_BIT(RCC -> CFGR , 17 );
		#elif	PLL_SOURCE	==	PLL_HSE_DIVIDED_BY_2
		  /*PLL entry clock source is HSE	*/
		SET_BIT(RCC -> CFGR , 16 );
		  /*HSE divider for PLL entry : clock divided	*/
		SET_BIT(RCC -> CFGR , 17 );
		#endif	
		
		  /*	PLL clock enable */
		  SET_BIT(RCC -> CR , 24 );
		  /*	PLL Ready Flag	*/
		  while(!GET_BIT(RCC -> CR , 25 ));
		#elif	CLOCK_TYPE == HSEPYPASS
				/*The HSEBYP bit can be written only if the HSE oscillator is disabled*/
				/*	HSE clock Disable				*/
		  CLR_BIT(RCC -> CR , 16 );
				
				/*	HSEBYPASS clock Enable			*/
	      SET_BIT(RCC -> CR , 18 );

				/*HSE selected as system clock		*/
		  SET_BIT(RCC -> CFGR , 0 );
		  CLR_BIT(RCC -> CFGR , 1 );
				
				/*	HSE clock Enable				*/
		  SET_BIT(RCC -> CR , 16 );
				
				/*	HSE Ready Flag					*/
		  while(!GET_BIT(RCC -> CR , 17 ) );

		
		#else
			
			#error		"Wrong Clock System type congiguration!"
		
		#endif
		/*FOR Clock Security System				*/
		#if		CLOCK_SECURITY_SYSTEM	==	OFF
		  CLR_BIT(RCC -> CR , 19 );
		
		#elif	CLOCK_SECURITY_SYSTEM	==	ON
		  SET_BIT(RCC -> CR , 19 );
		#else
				#warning	"Wrong clock security system configuration choice!"
		#endif				
}

/************************************************/
/* THIS FUNCTION FOR SETTING PERIPHERAL CLOCK   */
/* INPUTS :  3-UNSIGHNED CHARACTERS             */
/* RETURN :  ERROR_STATE                        */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus RCC_enuSetPeripheralClock(u8 Copy_u8PeripheralBus , u8 Copy_u8PeripheralName , u8 Copy_u8PeripheralState )
{
	Error_enuStatus	Local_enuState = ES_NOK ;
		switch( Copy_u8PeripheralState )
	{
		case	RCC_ENABLE 	:
							switch( Copy_u8PeripheralBus )
							{	
								case AHB  :	SET_BIT( RCC -> AHBENR  ,  Copy_u8PeripheralName );Local_enuState = ES_OK;break;
								case APB1 :	SET_BIT( RCC -> APB1ENR ,  Copy_u8PeripheralName );Local_enuState = ES_OK;break;
								case APB2 : SET_BIT( RCC -> APB2ENR ,  Copy_u8PeripheralName );Local_enuState = ES_OK;break;
								default	  :	Local_enuState = ES_OUT_OF_RANGE;
							}
							break;
		case	RCC_DISABLE :	
							switch( Copy_u8PeripheralBus )
							{	
								case AHB  :	CLR_BIT( RCC -> AHBENR  ,  Copy_u8PeripheralName );Local_enuState = ES_OK;break;
								case APB1 :	CLR_BIT( RCC -> APB1ENR ,  Copy_u8PeripheralName );Local_enuState = ES_OK;break;
								case APB2 : CLR_BIT( RCC -> APB2ENR ,  Copy_u8PeripheralName );Local_enuState = ES_OK;break;
								default	  :	Local_enuState = ES_OUT_OF_RANGE;
							}
							break;
		case	RCC_RESET	:	
							switch( Copy_u8PeripheralBus )
							{	
								case APB1 :	SET_BIT( RCC -> APB1RSTR ,  Copy_u8PeripheralName );Local_enuState = ES_OK;break;
								case APB2 : SET_BIT( RCC -> APB2RSTR ,  Copy_u8PeripheralName );Local_enuState = ES_OK;break;
								default	  :	Local_enuState = ES_OUT_OF_RANGE;
							}
							break;
	}
	return	Local_enuState ;
}
