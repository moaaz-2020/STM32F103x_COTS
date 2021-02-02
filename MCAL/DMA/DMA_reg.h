/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 11/11/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : DIRECT MEMORY ACCESS (DMA)  */
/*****                 REGISTERS                */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _DMA_REG_H_
#define   _DMA_REG_H_

typedef struct
{
	 volatile u32 CCR;
	 volatile u32 CNDTR;
	 volatile u32 CPAR;
	 volatile u32 CMAR;
	 volatile u32 RESERVED;	 
}DMA_CHANNEL;

typedef struct
{
	 volatile u32 ISR;
	 volatile u32 IFCR;
	 DMA_CHANNEL CHANNEL[7];
}DMA_t;
 
#define     DMA         ((volatile DMA_t *)0x40020000) 

#endif
