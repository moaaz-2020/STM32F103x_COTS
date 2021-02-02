/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 31/08/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : SYSTICK TIMER FUNCTIONS FOR */
/*****                 ARM MICROCONTROLLER      */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _SYSTICK_INT_H_
#define   _SYSTICK_INT_H_


/************************************************/
/* THIS FUNCTION FOR INITIALIZATION SYSTICK     */
/* INPUTS : VOID                                */
/* RETURN : ERROR_STATE                         */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus STK_voidInit(void);

/************************************************/
/* THIS FUNCTION FOR DELAY BY SYSTICK           */
/* INPUTS : UNSIGHNED INTEGER                   */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void STK_voidSetBusyWait(u32 Copy_u32Ticks);

/************************************************/
/* THIS FUNCTION FOR SETTING SINGLE INTERVAL    */
/* INPUTS : UNSIGHNED INTEGER & POINTER TO      */
/*    FUNCTION TAKE VOID and RETURN VOID        */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void STK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void));

/************************************************/
/* THIS FUNCTION FOR SETTING PERIODIC INTERVAL  */
/* INPUTS : UNSIGHNED INTEGER & POINTER TO      */
/*    FUNCTION TAKE VOID and RETURN VOID        */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void STK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void));

/************************************************/
/* THIS FUNCTION FOR STOP INTERVAL              */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void STK_voidStopInterval(void);

/************************************************/
/* THIS FUNCTION FOR GETTING ELAPSED TIME       */
/* INPUTS : VOID                                */
/* RETURN : UNSIGHNED INTEGER                   */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

u32  STK_u32GetElapsedTime(void);

/************************************************/
/* THIS FUNCTION FOR GETTING REMAINING TIME     */
/* INPUTS : VOID                                */
/* RETURN : UNSIGHNED INTEGER                   */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

u32  STK_u32GetRemainingTime(void);

#endif