/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 11/11/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : DIRECT MEMORY ACCESS(DMA)   */
/*****                 FUNCTION Prototypes      */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _DMA_INT_H_
#define   _DMA_INT_H_


/************************************************/
/* THIS FUNCTION FOR INITIALIZATION THE CHANNEL */
/*                 OF DMA                       */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void DMA_voidChannel1Init(void);

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

void DMA_voidStartChannel1(u32* Copy_pu32SourceAddress, u32* Copy_pu32DestinationAddress, u16 Copy_u16BlockLength);

#endif