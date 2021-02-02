/***************************************************/
/****AUTHOR      : Moaaz Rashad Sewilam            */
/****Date        : 11/11/2020                      */
/****Version     : 1.0  V                          */
/****Description : DIRECT MEMORY ACCESS (DMA)      */
/****                 IMPLEMENTATION               */
/***************************************************/


/***************************************************/
/**********  STANDARD LIB DIRECTIVES ***************/
/***************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"


/***************************************************/
/********** COMPONENTS DIRECTIVES    ***************/
/***************************************************/

#include "DMA_reg.h"
#include "DMA_int.h"
#include "DMA_Config.h"
#include "DMA_Priv.h"


/************************************************/
/* THIS FUNCTION FOR INITIALIZATION THE CHANNEL */
/*                 OF DMA                       */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void DMA_voidChannel1Init(void)
{
	#if  MEMORY_2_MEMORY_MODE  == ENABLE_MEM2MEM
	      SET_BIT(DMA->CHANNEL[0].CCR, 14);
	#elif  MEMORY_2_MEMORY_MODE  == DISABLE_MEM2MEM
	      CLR_BIT(DMA->CHANNEL[0].CCR, 14);
    #else
         #warning "The MEM2MEM mode is not choosen"
    #endif
    /**********************************/
    #if  CHANNEL_PRIORITY_LEVEL   ==  LOW
       	  CLR_BIT(DMA->CHANNEL[0].CCR, 13);
       	  CLR_BIT(DMA->CHANNEL[0].CCR, 12);	
    #elif  CHANNEL_PRIORITY_LEVEL   ==  MEDIUM
       	  CLR_BIT(DMA->CHANNEL[0].CCR, 13);
       	  SET_BIT(DMA->CHANNEL[0].CCR, 12);
    #elif  CHANNEL_PRIORITY_LEVEL   ==  HIGH
       	  SET_BIT(DMA->CHANNEL[0].CCR, 13);
       	  CLR_BIT(DMA->CHANNEL[0].CCR, 12);
    #elif  CHANNEL_PRIORITY_LEVEL   ==  VERY_HIGH
       	  SET_BIT(DMA->CHANNEL[0].CCR, 13);
       	  SET_BIT(DMA->CHANNEL[0].CCR, 12);
    #else 
         #warning "Channel Priority is not choosen"
	#endif 
    /**********************************/
    #if    MEMORY_SIZE   ==  _8_BIT
       	  CLR_BIT(DMA->CHANNEL[0].CCR, 11);
       	  CLR_BIT(DMA->CHANNEL[0].CCR, 10);	
    #elif  MEMORY_SIZE   ==  _16_BIT
       	  CLR_BIT(DMA->CHANNEL[0].CCR, 11);
       	  SET_BIT(DMA->CHANNEL[0].CCR, 10);
    #elif  MEMORY_SIZE   ==  _32_BIT
       	  SET_BIT(DMA->CHANNEL[0].CCR, 11);
       	  CLR_BIT(DMA->CHANNEL[0].CCR, 10);
    #elif  MEMORY_SIZE   ==  RESERVED
       	  SET_BIT(DMA->CHANNEL[0].CCR, 11);
       	  SET_BIT(DMA->CHANNEL[0].CCR, 10);
    #else 
         #warning "THIS MEMORY SIZE is not found"
	#endif 
    /**********************************/	
    #if    PERIPHERAL_SIZE   ==  _8_BIT
       	  CLR_BIT(DMA->CHANNEL[0].CCR, 9);
       	  CLR_BIT(DMA->CHANNEL[0].CCR, 8);	
    #elif  PERIPHERAL_SIZE   ==  _16_BIT
       	  CLR_BIT(DMA->CHANNEL[0].CCR, 9);
       	  SET_BIT(DMA->CHANNEL[0].CCR, 8);
    #elif  PERIPHERAL_SIZE   ==  _32_BIT
       	  SET_BIT(DMA->CHANNEL[0].CCR, 9);
       	  CLR_BIT(DMA->CHANNEL[0].CCR, 8);
    #elif  PERIPHERAL_SIZE   ==  RESERVED
       	  SET_BIT(DMA->CHANNEL[0].CCR, 9);
       	  SET_BIT(DMA->CHANNEL[0].CCR, 8);
    #else 
         #warning "THIS PERIPHERAL SIZE is not found"
	 
	#endif
    /**********************************/	
	#if  MEMORY_INCREMENT_MODE  == ENABLE_MINC
	      SET_BIT(DMA->CHANNEL[0].CCR, 7);
	#elif  MEMORY_INCREMENT_MODE  == DISABLE_MINC
	      CLR_BIT(DMA->CHANNEL[0].CCR, 7);
    #else
         #warning "The MEMORY INCREMENT mode is not selected"
    #endif
    /**********************************/
	#if  PERIPHERAL_INCREMENT_MODE  == ENABLE_PINC
	      SET_BIT(DMA->CHANNEL[0].CCR, 6);
	#elif  PERIPHERAL_INCREMENT_MODE  == DISABLE_PINC
	      CLR_BIT(DMA->CHANNEL[0].CCR, 6);
    #else
         #warning "The PERIPHERAL INCREMENT mode is not selected"
    #endif
    /**********************************/
	#if  CIRCULAR_MODE  == ENABLE_CIRCULAR
	      SET_BIT(DMA->CHANNEL[0].CCR, 5);
	#elif  CIRCULAR_MODE  == DISABLE_CIRCULAR
	      CLR_BIT(DMA->CHANNEL[0].CCR, 5);
    #else
         #warning "The CIRCULAR mode is not selected"
    #endif
    /**********************************/	
	#if  DATA_TRANSFER_DIRECTION  == READ_FROM_MEMORY
	      SET_BIT(DMA->CHANNEL[0].CCR, 4);
	#elif  DATA_TRANSFER_DIRECTION  == READ_FROM_PERIPHERAL
	      CLR_BIT(DMA->CHANNEL[0].CCR, 4);
    #else
         #error "DATA TRANSFER DIRECTION is not correct"
    #endif
    /**********************************/	
	#if  TRANSFER_ERROR_INTERRUPT_ENABLE  == ENABLE_TEIE
	      SET_BIT(DMA->CHANNEL[0].CCR, 3);
	#elif  TRANSFER_ERROR_INTERRUPT_ENABLE  == DISABLE_TEIE
	      CLR_BIT(DMA->CHANNEL[0].CCR, 3);
    #else
         #warning "The TRANSFER ERROR INTERRUPT ENABLE is not selected"
    #endif
    /**********************************/
	#if  HALF_TRANSFER_INTERRUPT_ENABLE  == ENABLE_HTIE
	      SET_BIT(DMA->CHANNEL[0].CCR, 2);
	#elif  HALF_TRANSFER_INTERRUPT_ENABLE  == DISABLE_HTIE
	      CLR_BIT(DMA->CHANNEL[0].CCR, 2);
    #else
         #warning "The HALF TRANSFER INTERRUPT ENABLE is not selected"
    #endif
    /**********************************/
	#if  TRANSFER_COMPLETE_INTERRUPT_ENABLE  == ENABLE_TCIE
	      SET_BIT(DMA->CHANNEL[0].CCR, 1);
	#elif  TRANSFER_COMPLETE_INTERRUPT_ENABLE  == DISABLE_TCIE
	      CLR_BIT(DMA->CHANNEL[0].CCR, 1);
    #else
         #warning "The TRANSFER COMPLETE INTERRUPT ENABLE is not selected"
    #endif
    /**********************************/
	#if  CHANNEL_ENABLE  == ENABLE_CHANNEL
	      SET_BIT(DMA->CHANNEL[0].CCR, 0);
	#elif  CHANNEL_ENABLE  == DISABLE_CHANNEL
	      CLR_BIT(DMA->CHANNEL[0].CCR, 0);
    #else
         #warning "The CHANNEL ENABLE is not selected"
    #endif
    /**********************************/	
}

/************************************************/
/* THIS FUNCTION FOR STARTING THE CHANNEL       */
/*                 OF DMA                       */
/* INPUTS : 2 * UNSIGNED INTEGERS POINTERS AND  */
/*                  UNSIGNED SHORT INTEGER      */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void DMA_voidStartChannel1(u32* Copy_pu32SourceAddress, u32* Copy_pu32DestinationAddress, u16 Copy_u16BlockLength)
{
	/*Make sure channel is disabled*/
	CLR_BIT(DMA->CHANNEL[0].CCR, 0);
	/*Load the addresses*/
	/* Because the data transfer from peripheral to memory, 
	so the peripheral express about source and memory express about destination */
	DMA->CHANNEL[0].CPAR = Copy_pu32SourceAddress;
	DMA->CHANNEL[0].CMAR = Copy_pu32DestinationAddress;
	
	/* Load the Block Length  */
	DMA->CHANNEL[0].CNDTR = Copy_u16BlockLength;
	
	/* Make the channel is enabled */
	SET_BIT(DMA->CHANNEL[0].CCR, 0);
	
}










