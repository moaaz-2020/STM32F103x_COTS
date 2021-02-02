/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 11/11/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : DIRECT MEMORY ACCESS(DMA)   */
/*****                 CONFIGURATIONS           */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _DMA_CONFIG_H_
#define   _DMA_CONFIG_H_


#define   MEMORY_2_MEMORY_MODE                   ENABLE_MEM2MEM

#define   CHANNEL_PRIORITY_LEVEL                 VERY_HIGH

#define   MEMORY_SIZE                            _32_BIT

#define   PERIPHERAL_SIZE                        _32_BIT

#define   MEMORY_INCREMENT_MODE                  ENABLE_MINC

#define   PERIPHERAL_INCREMENT_MODE              ENABLE_PINC

#define   CIRCULAR_MODE                          DISABLE_CIRCULAR

#define   DATA_TRANSFER_DIRECTION                READ_FROM_PERIPHERAL

#define   TRANSFER_ERROR_INTERRUPT_ENABLE        DISABLE_TEIE

#define   HALF_TRANSFER_INTERRUPT_ENABLE         DISABLE_HTIE  

#define   TRANSFER_COMPLETE_INTERRUPT_ENABLE     ENABLE_TCIE

#define   CHANNEL_ENABLE                         DISABLE_CHANNEL

#endif	
