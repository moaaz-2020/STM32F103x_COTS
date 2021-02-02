/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam       **/
/*****Date        : 24/07/2020                 **/
/*****Version     : 1.0  V                     **/
/*****Description : LED FUNCTION IMPLEMENTATION**/
/************************************************/


/************************************************/
/**********  STANDARD LIB DIRECTIVES ************/
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"


/************************************************/
/********** COMPONENTS DIRECTIVES    ************/
/************************************************/
#include "GPIO_int.h"
#include "GPIO_reg.h"

#include "LED_int.h"



/************************************************/
/********** FUNCTION IMPLEMENTATION  ************/
/************************************************/

/************************************************/
/*    THIS FUNCTION USED TO SET LED PIN         */
/*    INPUTS : UNSIGHNED INT, UNSIGHNED INT     */
/*    RETURN : VOID                             */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/


void                    LED_enumSetLedPin(u8 Copy_u8PortId ,u8 Copy_u8PinId)
{
	GPIO_enuSetPinMode( Copy_u8PortId , Copy_u8PinId , OUTPUT , OUTPUT_PUSHPULL , SPEED_10MHZ);
}

/************************************************/
/*    THIS FUNCTION USED TO SET LED ON          */
/*    INPUTS : UNSIGHNED INT, UNSIGHNED INT     */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus        LED_enumSetLedOn(u8 Copy_u8PortId ,u8 Copy_u8PinId)
{
	Error_enuStatus Local_enuError = ES_NOK;
	if( Copy_u8PortId < 6 && Copy_u8PinId < 16 )
	{
		     switch(Copy_u8PortId)
		        {
			     case PORTA: SET_BIT(GPIOA -> ODR , Copy_u8PinId); Local_enuError = ES_OK; break;
			     case PORTB: SET_BIT(GPIOB -> ODR , Copy_u8PinId); Local_enuError = ES_OK; break;
			     case PORTC: SET_BIT(GPIOC -> ODR , Copy_u8PinId); Local_enuError = ES_OK; break;
			     default:  Local_enuError = ES_NOK; break;
       		    }
	}			
	else
	{
		Local_enuError = ES_OUT_OF_RANGE;
	}		
	return Local_enuError ;
}

/************************************************/
/*    THIS FUNCTION USED TO SET LED OFF         */
/*    INPUTS : UNSIGHNED INT, UNSIGHNED INT     */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus        LED_enumSetLedOff(u8 Copy_u8PortId ,u8 Copy_u8PinId)
{
	Error_enuStatus Local_enuError = ES_NOK;
	if( Copy_u8PortId < 6 && Copy_u8PinId < 16 )
	{
		     switch(Copy_u8PortId)
		        {
			     case PORTA: CLR_BIT(GPIOA -> ODR , Copy_u8PinId); Local_enuError = ES_OK; break;
			     case PORTB: CLR_BIT(GPIOB -> ODR , Copy_u8PinId); Local_enuError = ES_OK; break;
			     case PORTC: CLR_BIT(GPIOC -> ODR , Copy_u8PinId); Local_enuError = ES_OK; break;
			     default:  Local_enuError = ES_NOK; break;
       		    }
	}			
	else
	{
		Local_enuError = ES_OUT_OF_RANGE;
	}		
	return Local_enuError ;
}

/************************************************/
/*    THIS FUNCTION USED TO SET LED TOGGLE      */
/*    INPUTS : UNSIGHNED INT, UNSIGHNED INT     */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus        LED_enumSetLedTog(u8 Copy_u8PortId ,u8 Copy_u8PinId)
{
	Error_enuStatus Local_enuError = ES_NOK;
	if( Copy_u8PortId < 6 && Copy_u8PinId < 16 )
	{
               
		     switch(Copy_u8PortId)
		        {
			     case PORTA: TOG_BIT(GPIOA -> ODR , Copy_u8PinId); Local_enuError = ES_OK; break;
			     case PORTB: TOG_BIT(GPIOA -> ODR , Copy_u8PinId); Local_enuError = ES_OK; break;
			     case PORTC: TOG_BIT(GPIOA -> ODR , Copy_u8PinId); Local_enuError = ES_OK; break;
			     default:  Local_enuError = ES_NOK; break;
       		    }
	}			
	else
	{
		Local_enuError = ES_OUT_OF_RANGE;
	}		
	return Local_enuError ;
}