/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 31/08/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : NESTED VECTORED INTERRUPT   */
/*****   CONTROLLER(NVIC) FUNCTION PROTOTYPE    */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _NVIC_INT_H_
#define   _NVIC_INT_H_

/************************************************/
/* THIS FUNCTION FOR ENABLING INTERRUPT         */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : ERROR_STATE                         */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus NVIC_voidEnableInterrupt    (u8 Copy_u8IntNumber);

/************************************************/
/* THIS FUNCTION FOR DISABLING INTERRUPT        */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : ERROR_STATE                         */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus NVIC_voidDisableInterrupt   (u8 Copy_u8IntNumber);

/************************************************/
/* THIS FUNCTION FOR SETTING PENDING FLAG       */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : ERROR_STATE                         */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus NVIC_voidSetPendingFlag     (u8 Copy_u8IntNumber);

/************************************************/
/* THIS FUNCTION FOR CLEARING PENDING FLAG      */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : ERROR_STATE                         */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus NVIC_voidClearPendingFlag   (u8 Copy_u8IntNumber);

/************************************************/
/* THIS FUNCTION FOR GETTING ACTIVE FLAG        */
/* INPUTS : UNSIGHNED CHARACTER                 */
/* RETURN : UNSIGHNED CHARACTER                 */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

u8   NVIC_u8GetActiveFlag        (u8 Copy_u8IntNumber);

/*****************************************************/
/* THIS FUNCTION FOR SETTING PRIORITY                */
/* INPUTS : 2*UNSIGHNED CHARACTER & SIGHNED CHARACTER*/
/* RETURN : ERROR_STATE                              */
/*****************************************************/
/*    PRECONDITION :                                 */
/*                                                   */
/*****************************************************/

Error_enuStatus NVIC_voidSetPriority(s8 Copy_s8IntId , u8 Copy_u8GroupPriority ,u8 Copy_u8SubPriority );

#endif