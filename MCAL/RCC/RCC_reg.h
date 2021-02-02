/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 09/05/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : RESET AND CLOCK CONTROL(RCC)*/
/*****                 REGISTERS                */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _RCC_REG_H_
#define   _RCC_REG_H_

typedef struct
{
	u32 volatile CR;
	u32 volatile CFGR;
	u32 volatile CIR;
	u32 volatile APB2RSTR;
	u32 volatile APB1RSTR;
	u32 volatile AHBENR;
	u32 volatile APB2ENR;
	u32 volatile APB1ENR;
	u32 volatile BDCR;
	u32 volatile CSR;	
}RCC_t;
 
#define     RCC         ((volatile RCC_t *)0x40021000) 

#endif
