/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 09/05/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : GENERAL PURPOSE I/O REGISTER*/
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef _GPIO_REG_H_
#define _GPIO_REG_H_

typedef struct
{
	 volatile u32 CRL;
	 volatile u32 CRH;
	 volatile u32 IDR;
	 volatile u32 ODR;
	 volatile u32 BSRR;
	 volatile u32 BRR;
	 volatile u32 LCKR;
}GPIO_t;

#define GPIOA	((volatile GPIO_t*)0x40010800)
#define GPIOB	((volatile GPIO_t*)0x40010C00)
#define GPIOC	((volatile GPIO_t*)0x40011000)


#endif
