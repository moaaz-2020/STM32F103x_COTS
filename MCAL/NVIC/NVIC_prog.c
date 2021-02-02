/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 31/08/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : NESTED VECTORED INTERRUPT   */
/***** CONTROLLER(NVIC) FUNCTION IMPLEMENTATION */
/************************************************/


/***************************************************/
/**********  STANDARD LIB DIRECTIVES ***************/
/***************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"


/***************************************************/
/********** COMPONENTS DIRECTIVES    ***************/
/***************************************************/


#include "NVIC_int.h"
#include "NVIC_config.h"
#include "NVIC_reg.h"



/************************************************/
/* THIS FUNCTION FOR ENABLING INTERRUPT         */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : ERROR_STATE                         */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus NVIC_voidEnableInterrupt    (u8 Copy_u8IntNumber)
{
	Error_enuStatus  Local_enuError = ES_NOK;
	
	if ( Copy_u8IntNumber <= 31)
	{
		Local_enuError = ES_OK;
		NVIC_ISER0 = (1 << Copy_u8IntNumber);
	}
	
	else if (  Copy_u8IntNumber <= 59)
	{
		Local_enuError = ES_OK;
		Copy_u8IntNumber -= 32;
		NVIC_ISER1 = (1 << Copy_u8IntNumber);
	}
	
	else
	{
		Local_enuError = ES_OUT_OF_RANGE;
	}
	return Local_enuError;
}

/************************************************/
/* THIS FUNCTION FOR DISABLING INTERRUPT        */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : ERROR_STATE                         */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus NVIC_voidDisableInterrupt   (u8 Copy_u8IntNumber)
{
		Error_enuStatus  Local_enuError = ES_NOK;
	
	if ( Copy_u8IntNumber <= 31)
	{
		Local_enuError = ES_OK;
		NVIC_ICER0 = (1 << Copy_u8IntNumber);
	}
	
	else if (  Copy_u8IntNumber <= 59)
	{
		Local_enuError = ES_OK;
		Copy_u8IntNumber -= 32;
		NVIC_ICER1 = (1 << Copy_u8IntNumber);
	}
	
	else
	{
		Local_enuError = ES_OUT_OF_RANGE;
	}
	return Local_enuError;
}

/************************************************/
/* THIS FUNCTION FOR SETTING PENDING FLAG       */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : ERROR_STATE                         */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus NVIC_voidSetPendingFlag     (u8 Copy_u8IntNumber)
{
	Error_enuStatus  Local_enuError = ES_NOK;
	
	if ( Copy_u8IntNumber <= 31)
	{
		Local_enuError = ES_OK;
		NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	}
	
	else if (  Copy_u8IntNumber <= 59)
	{
		Local_enuError = ES_OK;
		Copy_u8IntNumber -= 32;
		NVIC_ISPR1 = (1 << Copy_u8IntNumber);
	}
	
	else
	{
		Local_enuError = ES_OUT_OF_RANGE;
	}
	return Local_enuError;  	
}

/************************************************/
/* THIS FUNCTION FOR CLEARING PENDING FLAG      */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : ERROR_STATE                         */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus NVIC_voidClearPendingFlag   (u8 Copy_u8IntNumber)
{
		Error_enuStatus  Local_enuError = ES_NOK;
	if ( Copy_u8IntNumber <= 31)
	{
		Local_enuError = ES_OK;
		NVIC_ICPR0 = (1 << Copy_u8IntNumber);
	}
	
	else if (  Copy_u8IntNumber <= 59)
	{
		Local_enuError = ES_OK;
		Copy_u8IntNumber -= 32;
		NVIC_ICPR1 = (1 << Copy_u8IntNumber);
	}
	
	else
	{
		Local_enuError = ES_OUT_OF_RANGE;
	}
	return Local_enuError;  	
}

/************************************************/
/* THIS FUNCTION FOR GETTING ACTIVE FLAG        */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : UNSIGHNED CHARACTER                 */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

u8   NVIC_u8GetActiveFlag        (u8 Copy_u8IntNumber)
{
		u8 Local_u8Result = 0;

	if ( Copy_u8IntNumber <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	}
	
	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
	}
	
	else
	{
		/* NONE */
	}
	return Local_u8Result;
}

/*****************************************************/
/* THIS FUNCTION FOR SETTING PRIORITY                */
/* INPUTS : 2*UNSIGHNED CHARACTER & SIGHNED CHARACTER*/
/* RETURN : ERROR_STATE                              */
/*****************************************************/
/*    PRECONDITION :                                 */
/*                                                   */
/*****************************************************/

Error_enuStatus NVIC_voidSetPriority(s8 Copy_s8IntId , u8 Copy_u8GroupPriority ,u8 Copy_u8SubPriority )
{
    	Error_enuStatus  Local_enuError = ES_NOK;
		
		u8 Local_u8Priority = Copy_u8SubPriority|(Copy_u8GroupPriority<<((NVIC_GROUP_SUB_DISTRIBUTION - 0x05FA0300)/256));
	/* core peripheral 			*/
	if(Copy_s8IntId < 0)
	{

	}
	/* external peripheral		*/ /*EXTI0 = 6*/
	else if(Copy_s8IntId >= 0)
	{
		Local_enuError = ES_OK;
		NVIC_IPR[Copy_s8IntId] = Local_u8Priority << 4 ;
	}
	SCB_AIRCR = NVIC_GROUP_SUB_DISTRIBUTION ;
	
	return Local_enuError;
}