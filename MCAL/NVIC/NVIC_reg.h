/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 31/08/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : NESTED VECTORED INTERRUPT   */
/*****              CONTROLLER(NVIC) REGISTER   */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _NVIC_REG_H_
#define   _NVIC_REG_H_

 
#define NVIC_BASE_ADDRESS   0xE000E100

/*Set Enable registers*/
#define NVIC_ISER0	*((volatile u32*)NVIC_BASE_ADDRESS)
#define NVIC_ISER1	*((volatile u32*)NVIC_BASE_ADDRESS+0x04)

/*Clear Enable registers*/
#define NVIC_ICER0	*((volatile u32*)(NVIC_BASE_ADDRESS+0x80))
#define NVIC_ICER1	*((volatile u32*)(NVIC_BASE_ADDRESS+0x84))

/*Set Pending flag registers*/
#define NVIC_ISPR0	*((volatile u32*)(NVIC_BASE_ADDRESS+0x100))
#define NVIC_ISPR1	*((volatile u32*)(NVIC_BASE_ADDRESS+0x104))

/*Clear Pending flag registers*/
#define NVIC_ICPR0	*((volatile u32*)(NVIC_BASE_ADDRESS+0x180))
#define NVIC_ICPR1	*((volatile u32*)(NVIC_BASE_ADDRESS+0x184))

/*Active bit register*/
#define NVIC_IABR0	*((volatile u32*)(NVIC_BASE_ADDRESS+0x200))
#define NVIC_IABR1	*((volatile u32*)(NVIC_BASE_ADDRESS+0x204))

/*Interrupt priority registers without Dereference*/
#define NVIC_IPR		((volatile u8*)(NVIC_BASE_ADDRESS+0x300))

#define SCB_BASE_ADDRESS		0xE000ED00

#define SCB_AIRCR	*((volatile u32*)(SCB_BASE_ADDRESS+0x0C))


#define NVIC_GROUP_4_SUB_0      0x05FA0300
#define NVIC_GROUP_3_SUB_1      0x05FA0400
#define NVIC_GROUP_2_SUB_2      0x05FA0500
#define NVIC_GROUP_1_SUB_3      0x05FA0600
#define NVIC_GROUP_0_SUB_4      0x05FA0700

#endif