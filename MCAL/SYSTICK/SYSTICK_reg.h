/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 31/08/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : SYSTICK TIMER REGISTERS FOR */
/*****                 ARM MICROCONTROLLER      */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _SYSTICK_REG_H_
#define   _SYSTICK_REG_H_


typedef struct
{
	volatile u32 STK_CTRL  ;
	volatile u32 STK_LOAD  ;
	volatile u32 STK_VAL   ;
}STK_Type;

#define  STK		((volatile STK_Type*)0xE000E010)


#endif
