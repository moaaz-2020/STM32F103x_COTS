/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 22/07/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : GENERAL PURPOSE I/O REGISTER*/
/*****                 IMPLEMENTATION           */
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


#include "GPIO_int.h"
#include "GPIO_priv.h"
#include "GPIO_config.h" 
#include "GPIO_reg.h"



/************************************************/
/* THIS FUNCTION FOR SETTING PIN MODE           */
/* INPUTS : 4 UNSIGHNED CHARACTERS              */
/* RETURN : ERROR STATE                         */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus GPIO_enuSetPinMode(u8 Copy_u8PortId ,u8 Copy_u8PinId ,u8 Copy_u8Direction ,u8 Copy_u8Mode ,u8 Copy_u8Speed)
{
	/*	Default Error Status						*/
	Error_enuStatus	Local_enuState = ES_NOK ;
	/*	Range check for PORTS						*/
	
		switch(Copy_u8PortId)
		{
			/*	Range check for PINS Of PORT LOW	*/
			case PORTA  : 	if(Copy_u8PinId < 8)
							{
								Local_enuState = ES_OK ;
								/*check about Direaction Input or Output*/
								switch(Copy_u8Direction)
								{
									case OUTPUT		:
									/*to avoid SPEED_INPUT in output Mode*/
										if(Copy_u8Speed != SPEED_INPUT)
										{
											Local_enuState = ES_OK ;
											/*	output speed Seletion	*/
											switch(Copy_u8Speed)
											{
												case SPEED_10MHZ 	:	SET_BIT( GPIOA -> CRL , (Copy_u8PinId * 4) );	CLR_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+1) );	break;
												case SPEED_2MHZ		:	CLR_BIT( GPIOA -> CRL , (Copy_u8PinId * 4) );	SET_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+1) );	break;
												case SPEED_50MHZ 	:	SET_BIT( GPIOA -> CRL , (Copy_u8PinId * 4) );	SET_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+1) );	break;
												default				:	Local_enuState = ES_OUT_OF_RANGE ;
											}
											/*	output Mode Seletion	*/
											switch(Copy_u8Mode)
											{
												case OUTPUT_PUSHPULL 		:	CLR_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+3) );break;
												case OUTPUT_OPEN_DRAIN		:	SET_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+3) );break;
												case AF_OUTPUT_PUSHPULL 	:	CLR_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+3) );break;
												case AF_OUTPUT_OPEN_DRAIN 	:	SET_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+3) );break;
												default						:	Local_enuState = ES_OUT_OF_RANGE ;
											}
											
										}
										/*SPEED_INPUT in the output Mode is wrong choice	*/
										else
										{
											Local_enuState = ES_NOK ;
										}			break;	/* End of OUTPUT case */
									
									case INPUT		:
									/*to avoid SPEED_OUTPUT in input Mode*/
										if(Copy_u8Speed == SPEED_INPUT)
										{
											Local_enuState = ES_OK ;
											/* SET INPUT mode */
											CLR_BIT( GPIOA -> CRL , ( Copy_u8PinId * 4) );
											CLR_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+1) );
											/*	INPUT Mode Seletion	*/
											switch(Copy_u8Mode)
											{
												case INPUT_ANALOG 		:	CLR_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+3) );break;
												case INPUT_FLOATING		:	SET_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+3) );break;
												case INPUT_PULLDOWN 	:	CLR_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+3) );CLR_BIT( GPIOA -> ODR , Copy_u8PinId);break;
												case INPUT_PULLUP	 	:	SET_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+3) );SET_BIT( GPIOA -> ODR , Copy_u8PinId);break;
												default					:	Local_enuState = ES_OUT_OF_RANGE ;
											}
										}
									break;	/* End of INPUT case */
									/*	if the direction is not input or output	*/
									default			:	Local_enuState = ES_OUT_OF_RANGE ;
								}
							}/*	Range check for PINS Of PORT HIGH		*/
							else if(Copy_u8PinId < 16)
							{
								Local_enuState = ES_OK ;
								/*	modification of Pin Numer of HIGH port with bit number of GPIO_CRH Reg	*/
								Copy_u8PinId -= 8 ; 
								
								/*check about Direaction Input or Output*/
								switch(Copy_u8Direction)
								{
									case OUTPUT		:
									/*to avoid SPEED_INPUT in output Mode*/
										if(Copy_u8Speed != SPEED_INPUT)
										{
											Local_enuState = ES_OK ;
											/*	output speed Seletion	*/
											switch(Copy_u8Speed)
											{
												case SPEED_10MHZ 	:	SET_BIT( GPIOA -> CRH , (Copy_u8PinId * 4) );	CLR_BIT( GPIOA -> CRH , ((Copy_u8PinId * 4)+1) );break;
												case SPEED_2MHZ		:	CLR_BIT( GPIOA -> CRH , (Copy_u8PinId * 4) );	SET_BIT( GPIOA -> CRH , ((Copy_u8PinId * 4)+1) );break;
												case SPEED_50MHZ 	:	SET_BIT( GPIOA -> CRH , (Copy_u8PinId * 4) );	SET_BIT( GPIOA -> CRH , ((Copy_u8PinId * 4)+1) );break;
												default				:	Local_enuState = ES_OUT_OF_RANGE ;
											}
											/*	output Mode Seletion	*/
											switch(Copy_u8Mode)
											{
												case OUTPUT_PUSHPULL 		:	CLR_BIT( GPIOA -> CRH , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOA -> CRH , ((Copy_u8PinId * 4)+3) );break;
												case OUTPUT_OPEN_DRAIN		:	SET_BIT( GPIOA -> CRH , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOA -> CRH , ((Copy_u8PinId * 4)+3) );break;
												case AF_OUTPUT_PUSHPULL 	:	CLR_BIT( GPIOA -> CRH , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOA -> CRH , ((Copy_u8PinId * 4)+3) );	CLR_BIT( GPIOA -> ODR , (Copy_u8PinId+8) );break;
												case AF_OUTPUT_OPEN_DRAIN 	:	SET_BIT( GPIOA -> CRH , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOA -> CRH , ((Copy_u8PinId * 4)+3) );	SET_BIT( GPIOA -> ODR , (Copy_u8PinId+8) );break;
												default						:	Local_enuState = ES_OUT_OF_RANGE ;
											}
											
										}
										/*SPEED_INPUT in the output Mode is wrong choice	*/
										else
										{
											Local_enuState = ES_NOK ;
										}			break;	/* End of OUTPUT case */
									
									case INPUT		:
									/*to avoid SPEED_OUTPUT in input Mode*/
										if(Copy_u8Speed == SPEED_INPUT)
										{
											Local_enuState = ES_OK ;
											/* SET INPUT mode */
											CLR_BIT( GPIOA -> CRL , ( Copy_u8PinId * 4) );
											CLR_BIT( GPIOA -> CRL , ((Copy_u8PinId * 4)+1) );
											/*	INPUT Mode Seletion	*/
											switch(Copy_u8Mode)
											{
												case INPUT_ANALOG 		:	CLR_BIT( GPIOA -> CRH , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOA -> CRH , ((Copy_u8PinId * 4)+3) );break;
												case INPUT_FLOATING		:	SET_BIT( GPIOA -> CRH , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOA -> CRH , ((Copy_u8PinId * 4)+3) );break;
												case INPUT_PULLDOWN 	:	CLR_BIT( GPIOA -> CRH , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOA -> CRH , ((Copy_u8PinId * 4)+3) );break;
												case INPUT_PULLUP	 	:	SET_BIT( GPIOA -> CRH , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOA -> CRH , ((Copy_u8PinId * 4)+3) );break;
												default					:	Local_enuState = ES_OUT_OF_RANGE ;
											}
										}
									break;	/* End of INPUT case */
									/*	if the direction is not input or output	*/
									default			:	Local_enuState = ES_OUT_OF_RANGE ;
								}
							}
							else
							{
								Error_enuStatus	Local_enuState = ES_OUT_OF_RANGE ;
							}
							break;
			/****************************************************************/
			/* End Of PORTA													*/				
			/****************************************************************/
			
			
			/*	Range check for PINS Of PORT LOW	*/				
			case PORTB  :	
							if(Copy_u8PinId < 8)
							{
								Local_enuState = ES_OK ;
								/*check about Direaction Input or Output*/
								switch(Copy_u8Direction)
								{
									case OUTPUT		:
									/*to avoid SPEED_INPUT in output Mode*/
										if(Copy_u8Speed != SPEED_INPUT)
										{
											Local_enuState = ES_OK ;
											/*	output speed Seletion	*/
											switch(Copy_u8Speed)
											{
												case SPEED_10MHZ 	:	SET_BIT( GPIOB -> CRL , (Copy_u8PinId * 4) );	CLR_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+1) );break;
												case SPEED_2MHZ		:	CLR_BIT( GPIOB -> CRL , (Copy_u8PinId * 4) );	SET_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+1) );break;
												case SPEED_50MHZ 	:	SET_BIT( GPIOB -> CRL , (Copy_u8PinId * 4) );	SET_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+1) );break;
												default				:	Local_enuState = ES_OUT_OF_RANGE ;
											}
											/*	output Mode Seletion	*/
											switch(Copy_u8Mode)
											{
												case OUTPUT_PUSHPULL 		:	CLR_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+3) );break;
												case OUTPUT_OPEN_DRAIN		:	SET_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+3) );break;
												case AF_OUTPUT_PUSHPULL 	:	CLR_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+3) );break;
												case AF_OUTPUT_OPEN_DRAIN 	:	SET_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+3) );break;
												default						:	Local_enuState = ES_OUT_OF_RANGE ;
											}
											
										}
										/*SPEED_INPUT in the output Mode is wrong choice	*/
										else
										{
											Local_enuState = ES_NOK ;
										}			break;	/* End of OUTPUT case */
									
									case INPUT		:
									/*to avoid SPEED_OUTPUT in input Mode*/
										if(Copy_u8Speed == SPEED_INPUT)
										{
											Local_enuState = ES_OK ;
											/* SET INPUT mode */
											CLR_BIT( GPIOB -> CRL , ( Copy_u8PinId * 4) );
											CLR_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+1) );
											/*	INPUT Mode Seletion	*/
											switch(Copy_u8Mode)
											{
												case INPUT_ANALOG 		:	CLR_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+3) );break;
												case INPUT_FLOATING		:	SET_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+3) );break;
												case INPUT_PULLDOWN 	:	CLR_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+3) );	CLR_BIT( GPIOB -> ODR , Copy_u8PinId  );break;
												case INPUT_PULLUP	 	:	SET_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+3) );	SET_BIT( GPIOB -> ODR , Copy_u8PinId  );break;
												default					:	Local_enuState = ES_OUT_OF_RANGE ;
											}
										}
									break;	/* End of INPUT case */
									/*	if the direction is not input or output	*/
									default			:	Local_enuState = ES_OUT_OF_RANGE ;
								}
							}/*	Range check for PINS Of PORT HIGH		*/
							else if(Copy_u8PinId < 16)
							{
								Local_enuState = ES_OK ;
								/*	modification of Pin Numer of HIGH port with bit number of GPIO_CRH Reg	*/
								Copy_u8PinId -= 8 ; 
								
								/*check about Direaction Input or Output*/
								switch(Copy_u8Direction)
								{
									case OUTPUT		:
									/*to avoid SPEED_INPUT in output Mode*/
										if(Copy_u8Speed != SPEED_INPUT)
										{
											Local_enuState = ES_OK ;
											/*	output speed Seletion	*/
											switch(Copy_u8Speed)
											{
												case SPEED_10MHZ 	:	SET_BIT( GPIOB -> CRH , (Copy_u8PinId * 4) );	CLR_BIT( GPIOB -> CRH , ((Copy_u8PinId * 4)+1) );break;
												case SPEED_2MHZ		:	CLR_BIT( GPIOB -> CRH , (Copy_u8PinId * 4) );	SET_BIT( GPIOB -> CRH , ((Copy_u8PinId * 4)+1) );break;
												case SPEED_50MHZ 	:	SET_BIT( GPIOB -> CRH , (Copy_u8PinId * 4) );	SET_BIT( GPIOB -> CRH , ((Copy_u8PinId * 4)+1) );break;
												default				:	Local_enuState = ES_OUT_OF_RANGE ;
											}
											/*	output Mode Seletion	*/
											switch(Copy_u8Mode)
											{
												case OUTPUT_PUSHPULL 		:	CLR_BIT( GPIOB -> CRH , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOB -> CRH , ((Copy_u8PinId * 4)+3) );break;
												case OUTPUT_OPEN_DRAIN		:	SET_BIT( GPIOB -> CRH , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOB -> CRH , ((Copy_u8PinId * 4)+3) );break;
												case AF_OUTPUT_PUSHPULL 	:	CLR_BIT( GPIOB -> CRH , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOB -> CRH , ((Copy_u8PinId * 4)+3) );	CLR_BIT( GPIOB -> ODR , (Copy_u8PinId+8) );break;
												case AF_OUTPUT_OPEN_DRAIN 	:	SET_BIT( GPIOB -> CRH , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOB -> CRH , ((Copy_u8PinId * 4)+3) );	SET_BIT( GPIOB -> ODR , (Copy_u8PinId+8) );break;
												default						:	Local_enuState = ES_OUT_OF_RANGE ;
											}
											
										}
										/*SPEED_INPUT in the output Mode is wrong choice	*/
										else
										{
											Local_enuState = ES_NOK ;
										}			break;	/* End of OUTPUT case */
									
									case INPUT		:
									/*to avoid SPEED_OUTPUT in input Mode*/
										if(Copy_u8Speed == SPEED_INPUT)
										{
											Local_enuState = ES_OK ;
											/* SET INPUT mode */
											CLR_BIT( GPIOB -> CRL , ( Copy_u8PinId * 4) );
											CLR_BIT( GPIOB -> CRL , ((Copy_u8PinId * 4)+1) );
											/*	INPUT Mode Seletion	*/
											switch(Copy_u8Mode)
											{
												case INPUT_ANALOG 		:	CLR_BIT( GPIOB -> CRH , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOB -> CRH , ((Copy_u8PinId * 4)+3) );break;
												case INPUT_FLOATING		:	SET_BIT( GPIOB -> CRH , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOB -> CRH , ((Copy_u8PinId * 4)+3) );break;
												case INPUT_PULLDOWN 	:	CLR_BIT( GPIOB -> CRH , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOB -> CRH , ((Copy_u8PinId * 4)+3) );break;
												case INPUT_PULLUP	 	:	SET_BIT( GPIOB -> CRH , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOB -> CRH , ((Copy_u8PinId * 4)+3) );break;
												default					:	Local_enuState = ES_OUT_OF_RANGE ;
											}
										}
									break;	/* End of INPUT case */
									/*	if the direction is not input or output	*/
									default			:	Local_enuState = ES_OUT_OF_RANGE ;
								}
							}
							else
							{
								Error_enuStatus	Local_enuState = ES_OUT_OF_RANGE ;
							}
							break;
			
			/****************************************************************/
			/* The End Of PORTB												*/				
			/****************************************************************/
			
			
								
			case PORTC  : 
							/*	Range check for PINS Of PORT LOW	*/
							if(Copy_u8PinId < 8)
							{
								Local_enuState = ES_OK ;
								/*check about Direaction Input or Output*/
								switch(Copy_u8Direction)
								{
									case OUTPUT		:
									/*to avoid SPEED_INPUT in output Mode*/
										if(Copy_u8Speed != SPEED_INPUT)
										{
											Local_enuState = ES_OK ;
											/*	output speed Seletion	*/
											switch(Copy_u8Speed)
											{
												case SPEED_10MHZ 	:	SET_BIT( GPIOC -> CRL , (Copy_u8PinId * 4) );	CLR_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+1) );break;
												case SPEED_2MHZ		:	CLR_BIT( GPIOC -> CRL , (Copy_u8PinId * 4) );	SET_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+1) );break;
												case SPEED_50MHZ 	:	SET_BIT( GPIOC -> CRL , (Copy_u8PinId * 4) );	SET_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+1) );break;
												default				:	Local_enuState = ES_OUT_OF_RANGE ;
											}
											/*	output Mode Seletion	*/
											switch(Copy_u8Mode)
											{
												case OUTPUT_PUSHPULL 		:	CLR_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+3) );break;
												case OUTPUT_OPEN_DRAIN		:	SET_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+3) );break;
												case AF_OUTPUT_PUSHPULL 	:	CLR_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+3) );break;
												case AF_OUTPUT_OPEN_DRAIN 	:	SET_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+3) );break;
												default						:	Local_enuState = ES_OUT_OF_RANGE ;
											}
											
										}
										/*SPEED_INPUT in the output Mode is wrong choice	*/
										else
										{
											Local_enuState = ES_NOK ;
										}			break;	/* End of OUTPUT case */
									
									case INPUT		:
									/*to avoid SPEED_OUTPUT in input Mode*/
										if(Copy_u8Speed == SPEED_INPUT)
										{
											Local_enuState = ES_OK ;
											/* SET INPUT mode */
											CLR_BIT( GPIOC -> CRL , ( Copy_u8PinId * 4) );
											CLR_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+1) );
											/*	INPUT Mode Seletion	*/
											switch(Copy_u8Mode)
											{
												case INPUT_ANALOG 		:	CLR_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+3) );break;
												case INPUT_FLOATING		:	SET_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+3) );break;
												case INPUT_PULLDOWN 	:	CLR_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+3) );	CLR_BIT( GPIOC -> ODR , Copy_u8PinId  );break;
												case INPUT_PULLUP	 	:	SET_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+3) );	SET_BIT( GPIOC -> ODR , Copy_u8PinId  );break;
												default					:	Local_enuState = ES_OUT_OF_RANGE ;
											}
										}
									break;	/* End of INPUT case */
									/*	if the direction is not input or output	*/
									default			:	Local_enuState = ES_OUT_OF_RANGE ;
								}
							}/*	Range check for PINS Of PORT HIGH		*/
							else if(Copy_u8PinId < 16)
							{
								Local_enuState = ES_OK ;
								/*	modification of Pin Numer of HIGH port with bit number of GPIO_CRH Reg	*/
								Copy_u8PinId -= 8 ; 
								
								/*check about Direaction Input or Output*/
								switch(Copy_u8Direction)
								{
									case OUTPUT		:
									/*to avoid SPEED_INPUT in output Mode*/
										if(Copy_u8Speed != SPEED_INPUT)
										{
											Local_enuState = ES_OK;
											/*	output speed Seletion	*/
											switch(Copy_u8Speed)
											{
												case SPEED_10MHZ 	:	SET_BIT( GPIOC -> CRH , (Copy_u8PinId * 4) );	CLR_BIT( GPIOC -> CRH , ((Copy_u8PinId * 4)+1) );break;
												case SPEED_2MHZ		:	CLR_BIT( GPIOC -> CRH , (Copy_u8PinId * 4) );	SET_BIT( GPIOC -> CRH , ((Copy_u8PinId * 4)+1) );break;
												case SPEED_50MHZ 	:	SET_BIT( GPIOC -> CRH , (Copy_u8PinId * 4) );	SET_BIT( GPIOC -> CRH , ((Copy_u8PinId * 4)+1) );break;
												default				:	Local_enuState = ES_OUT_OF_RANGE ;
											}
											/*	output Mode Seletion	*/
											switch(Copy_u8Mode)
											{
												case OUTPUT_PUSHPULL 		:	CLR_BIT( GPIOC -> CRH , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOC -> CRH , ((Copy_u8PinId * 4)+3) );break;
												case OUTPUT_OPEN_DRAIN		:	SET_BIT( GPIOC -> CRH , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOC -> CRH , ((Copy_u8PinId * 4)+3) );break;
												case AF_OUTPUT_PUSHPULL 	:	CLR_BIT( GPIOC -> CRH , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOC -> CRH , ((Copy_u8PinId * 4)+3) );	CLR_BIT( GPIOC -> ODR , (Copy_u8PinId+8) );break;
												case AF_OUTPUT_OPEN_DRAIN 	:	SET_BIT( GPIOC -> CRH , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOC -> CRH , ((Copy_u8PinId * 4)+3) );	SET_BIT( GPIOC -> ODR , (Copy_u8PinId+8) );break;
												default						:	Local_enuState = ES_OUT_OF_RANGE ;
											}
											
										}
										/*SPEED_INPUT in the output Mode is wrong choice	*/
										else
										{
											Local_enuState = ES_NOK ;
										}			break;	/* End of OUTPUT case */
									
									case INPUT		:
									/*to avoid SPEED_OUTPUT in input Mode*/
										if(Copy_u8Speed == SPEED_INPUT)
										{
											Local_enuState = ES_OK;
											/* SET INPUT mode */
											CLR_BIT( GPIOC -> CRL , ( Copy_u8PinId * 4) );
											CLR_BIT( GPIOC -> CRL , ((Copy_u8PinId * 4)+1) );
											/*	INPUT Mode Seletion	*/
											switch(Copy_u8Mode)
											{
												case INPUT_ANALOG 		:	CLR_BIT( GPIOC -> CRH , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOC -> CRH , ((Copy_u8PinId * 4)+3) );break;
												case INPUT_FLOATING		:	SET_BIT( GPIOC -> CRH , ((Copy_u8PinId * 4)+2) );	CLR_BIT( GPIOC -> CRH , ((Copy_u8PinId * 4)+3) );break;
												case INPUT_PULLDOWN 	:	CLR_BIT( GPIOC -> CRH , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOC -> CRH , ((Copy_u8PinId * 4)+3) );break;
												case INPUT_PULLUP	 	:	SET_BIT( GPIOC -> CRH , ((Copy_u8PinId * 4)+2) );	SET_BIT( GPIOC -> CRH , ((Copy_u8PinId * 4)+3) );break;
												default					:	Local_enuState = ES_OUT_OF_RANGE ;
											}
										}
									break;	/* End of INPUT case */
									/*	if the direction is not input or output	*/
									default			:	Local_enuState = ES_OUT_OF_RANGE ;
								}
							}
							else
							{
								Error_enuStatus Local_enuState = ES_OUT_OF_RANGE ;
							}
							break;
			/*	if not in Range A or B or CLR_BIT			*/				
			default		: Local_enuState = ES_OUT_OF_RANGE ;
			
		}
	
		return Local_enuState;
}

/************************************************/
/* THIS FUNCTION FOR SETTING PIN VALUE          */
/* INPUTS : 3 UNSIGHNED CHARACTERS              */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus GPIO_enuSetPinValue(u8 Copy_u8PortId ,u8 Copy_u8PinId ,u8 Copy_u8Value)
{
	Error_enuStatus Local_enuState = ES_NOK ;
	
	if(Copy_u8PinId < 16)
	{
		switch(Copy_u8PortId)
		{
			case PORTA	:	
							switch(Copy_u8Value)
							{
								case	HIGH	:	SET_BIT(GPIOA -> ODR , Copy_u8PinId);	Local_enuState  = ES_OK;break;
								case	LOW		:	CLR_BIT(GPIOA -> ODR , Copy_u8PinId);	Local_enuState  = ES_OK;break;
								default			:	Local_enuState = ES_OUT_OF_RANGE ;
							}
							break; /*	The End of PortA	*/
						
			case PORTB	:	
							switch(Copy_u8Value)
							{
								case	HIGH	:	SET_BIT(GPIOB -> ODR , Copy_u8PinId);	Local_enuState  = ES_OK;break;
								case	LOW		:	CLR_BIT(GPIOB -> ODR , Copy_u8PinId);	Local_enuState  = ES_OK;break;
								default			:	Local_enuState = ES_OUT_OF_RANGE ;
							}
							break; /*	The End of PortB	*/
				
			case PORTC	:	
							switch(Copy_u8Value)
							{
								case	HIGH	:	SET_BIT(GPIOC -> ODR , Copy_u8PinId);	Local_enuState = ES_OK;break;
								case	LOW		:	CLR_BIT(GPIOC -> ODR , Copy_u8PinId);	Local_enuState = ES_OK;break;
								default			:	Local_enuState = ES_OUT_OF_RANGE ;
							}
							break; /*	The End of PortA	*/
						
			default		:	Local_enuState = ES_OUT_OF_RANGE ;
		}
	}
	else
	{
		Local_enuState = ES_OUT_OF_RANGE ;
	}
	
	return Local_enuState;
}

/*************************************************/
/* THIS FUNCTION FOR GETTING PIN VALUE           */
/* INPUTS : 2 UNSIGHNED CHARACTERS AND POINTER TO*/
/*               UNSIGHNED CHARACTER             */
/* RETURN : ERROR STATE                          */
/*************************************************/
/*    PRECONDITION :                             */
/*                                               */
/*************************************************/

Error_enuStatus GPIO_enuGetPinValue(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 * Copy_Pu8Value )
{
    Error_enuStatus Local_enuState = ES_NOK;
	
	if(Copy_u8PinId < 16)
	{
			switch(Copy_u8PortId)
		{
			case PORTA 	:	*Copy_Pu8Value 	=	GET_BIT(GPIOA -> IDR , Copy_u8PinId);	Local_enuState = ES_OK;	break;
			case PORTB 	:	*Copy_Pu8Value 	=	GET_BIT(GPIOB -> IDR , Copy_u8PinId);	Local_enuState = ES_OK;	break;
			case PORTC 	:	*Copy_Pu8Value 	=	GET_BIT(GPIOC -> IDR , Copy_u8PinId);	Local_enuState = ES_OK;	break;
			default		:	Local_enuState = ES_OUT_OF_RANGE ;
		}
	}else
	{
		Local_enuState = ES_OUT_OF_RANGE ;
	}

	return Local_enuState;
}
