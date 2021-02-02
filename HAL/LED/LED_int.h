/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam       **/
/*****Date        : 24/07/2020                 **/
/*****Version     : 1.0  V                     **/
/*****Description : LED FUNCTION Prototypes    **/
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/

#ifndef   _LED_INT_H_
#define   _LED_INT_H_

/************************************************/
/*    THIS FUNCTION USED TO SET LED PIN         */
/*    INPUTS : UNSIGHNED INT, UNSIGHNED INT     */
/*    RETURN : VOID                             */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/


void                  LED_enumSetLedPin(u8 Copy_u8PortId ,u8 Copy_u8PinId);

/************************************************/
/*    THIS FUNCTION USED TO SET LED ON          */
/*    INPUTS : UNSIGHNED INT, UNSIGHNED INT     */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus        LED_enumSetLedOn(u8 Copy_u8PortId ,u8 Copy_u8PinId);

/************************************************/
/*    THIS FUNCTION USED TO SET LED OFF         */
/*    INPUTS : UNSIGHNED INT, UNSIGHNED INT     */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus        LED_enumSetLedOff(u8 Copy_u8PortId ,u8 Copy_u8PinId);

/************************************************/
/*    THIS FUNCTION USED TO SET LED TOGGLE      */
/*    INPUTS : UNSIGHNED INT, UNSIGHNED INT     */
/*    RETURN : ERROR STATUS                     */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus        LED_enumSetLedTog(u8 Copy_u8PortId ,u8 Copy_u8PinId);

#endif