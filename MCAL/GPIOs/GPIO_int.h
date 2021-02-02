/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 22/07/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : GENERAL PURPOSE I/O REGISTER*/
/*****                 FUNCTION Prototypes      */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _GPIO_INT_H_
#define   _GPIO_INT_H_


#define		OUTPUT							1
#define		INPUT							3
/**************************************************************/
#define		HIGH							1
#define		LOW								0
/**************************************************************/
#define		OUTPUT_PUSHPULL					1
#define		OUTPUT_OPEN_DRAIN				3
#define		AF_OUTPUT_PUSHPULL				5
#define		AF_OUTPUT_OPEN_DRAIN			7
/**************************************************************/

#define		SPEED_INPUT						1
#define		SPEED_10MHZ						3
#define		SPEED_2MHZ						7
#define		SPEED_50MHZ						5

/*************************************************************/

#define		INPUT_ANALOG					13
#define		INPUT_FLOATING					14
#define		INPUT_PULLDOWN					15
#define		INPUT_PULLUP					16


/*************************************************************/

#define		PORTA							1
#define		PORTB							3
#define		PORTC							5


/*************************************************************/
#define		PIN0							0
#define		PIN1							1
#define		PIN2							2
#define		PIN3							3
#define		PIN4							4
#define		PIN5							5
#define		PIN6							6
#define		PIN7							7
#define		PIN8							8
#define		PIN9							9
#define		PIN10							10
#define		PIN11							11
#define		PIN12							12
#define		PIN13							13
#define		PIN14							14
#define		PIN15							15

/************************************************/
/* THIS FUNCTION FOR SETTING PIN MODE           */
/* INPUTS : 4 UNSIGHNED CHARACTERS              */
/* RETURN : ERROR STATE                         */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus GPIO_enuSetPinMode(u8 Copy_u8PortId ,u8 Copy_u8PinId ,u8 Copy_u8Direction ,u8 Copy_u8Mode ,u8 Copy_u8Speed);

/************************************************/
/* THIS FUNCTION FOR SETTING PIN VALUE          */
/* INPUTS : 3 UNSIGHNED CHARACTERS              */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus GPIO_enuSetPinValue(u8 Copy_u8PortId ,u8 Copy_u8PinId ,u8 Copy_u8Value);

/*************************************************/
/* THIS FUNCTION FOR GETTING PIN VALUE           */
/* INPUTS : 2 UNSIGHNED CHARACTERS AND POINTER TO*/
/*               UNSIGHNED CHARACTER             */
/* RETURN : ERROR STATE                          */
/*************************************************/
/*    PRECONDITION :                             */
/*                                               */
/*************************************************/

Error_enuStatus GPIO_enuGetPinValue(u8 Copy_u8PortId ,u8 Copy_u8PinId , u8 * Copy_Pu8Value );




#endif