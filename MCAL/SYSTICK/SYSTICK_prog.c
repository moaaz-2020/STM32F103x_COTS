/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 31/08/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : SYSTICK TIMER FUNCTION      */
/*****  IMPLEMENTATION FOR ARM MICROCONTROLLER  */
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


#include "SYSTICK_int.h"
#include "SYSTICK_priv.h"
#include "SYSTICK_config.h"
#include "SYSTICK_reg.h"

/* Define Callback Global Variable */
static void(*STK_CallBack)(void);

/* Define Variable for interval mode */
static u8 STK_u8ModeOfInterval;


/************************************************/
/* THIS FUNCTION FOR INITIALIZATION SYSTICK     */
/* INPUTS : VOID                                */
/* RETURN : ERROR_STATE                         */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

Error_enuStatus STK_voidInit(void)
{
	    Error_enuStatus  Local_enuError = ES_NOK;
	
	#if MSTK_CLK_SRC == STK_SRC_AHB
	    Local_enuError = ES_OK;
    /* Disable STK - Disable STK Interrupt - Set clock source AHB */
	    STK -> STK_CTRL = 0x00000004;
    #else
		Local_enuError = ES_OK;
    /* Disable STK - Disable STK Interrupt - Set clock source AHB/8 */
	    STK -> STK_CTRL = 0;
	
    #endif
	
	return Local_enuError;
}

/************************************************/
/* THIS FUNCTION FOR DELAY BY SYSTICK           */
/* INPUTS : UNSIGHNED INTEGER                   */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void STK_voidSetBusyWait(u32 Copy_u32Ticks)
{
		/* Load ticks to load register */
	STK -> STK_LOAD = Copy_u32Ticks;
	
	/* Start Timer */
	SET_BIT(STK->STK_CTRL, 0);
	
	/* Wait till flag is raised */
	while( (GET_BIT(STK->STK_CTRL,16)) == 0);
	
	/* Stop Timer */
	SET_BIT(STK->STK_CTRL, 0);
	STK -> STK_LOAD = 0;
	STK -> STK_VAL  = 0;
}

/************************************************/
/* THIS FUNCTION FOR SETTING SINGLE INTERVAL    */
/* INPUTS : UNSIGHNED INTEGER & POINTER TO      */
/*    FUNCTION TAKE VOID and RETURN VOID        */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void STK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
	/* Load ticks to load register */
	STK -> STK_LOAD = Copy_u32Ticks;
	
	/* Start Timer */
	SET_BIT(STK->STK_CTRL, 0);
	
	/* Save CallBack */
	STK_CallBack = Copy_ptr;
	
	/* Set Mode to Single */
	STK_u8ModeOfInterval = STK_SINGLE_INTERVAL;
	
	/* Enable STK Interrupt */
	SET_BIT(STK->STK_CTRL, 1);
}

/************************************************/
/* THIS FUNCTION FOR SETTING PERIODIC INTERVAL  */
/* INPUTS : UNSIGHNED INTEGER & POINTER TO      */
/*    FUNCTION TAKE VOID and RETURN VOID        */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void STK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
	/* Load ticks to load register */
	STK -> STK_LOAD = Copy_u32Ticks;
	
	/* Start Timer */
	SET_BIT(STK->STK_CTRL, 0);
	
	/* Save CallBack */
	STK_CallBack = Copy_ptr;
	
	/* Set Mode to Single */
	STK_u8ModeOfInterval = STK_PERIOD_INTERVAL;
	
	/* Enable STK Interrupt */
	SET_BIT(STK->STK_CTRL, 1);
}

/************************************************/
/* THIS FUNCTION FOR STOP INTERVAL              */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void STK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(STK->STK_CTRL, 1);
	
	/* Stop Timer */
	SET_BIT(STK->STK_CTRL, 0);
	STK -> STK_LOAD = 0;
	STK -> STK_VAL  = 0;
}

/************************************************/
/* THIS FUNCTION FOR GETTING ELAPSED TIME       */
/* INPUTS : VOID                                */
/* RETURN : UNSIGHNED INTEGER                   */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

u32  STK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	
	Local_u32ElapsedTime = STK->STK_LOAD  -  STK->STK_VAL ;
	
	return Local_u32ElapsedTime;
}

/************************************************/
/* THIS FUNCTION FOR GETTING REMAINING TIME     */
/* INPUTS : VOID                                */
/* RETURN : UNSIGHNED INTEGER                   */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

u32  STK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainTime;
	
	Local_u32RemainTime = MSTK -> VAL ;
	
	return Local_u32RemainTime;
}



void SysTick_Handler (void)
{
		u8 Local_u8Temporary;
	
	if (STK_u8ModeOfInterval == STK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(STK->STK_CTRL, 1);
	
		/* Stop Timer */
		SET_BIT(STK->STK_CTRL, 0);
		STK -> STK_LOAD = 0;
		STK -> STK_VAL  = 0;
	}
	
	/* Callback notification */
	STK_CallBack();
	
	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(STK->STK_CTRL,16);
}