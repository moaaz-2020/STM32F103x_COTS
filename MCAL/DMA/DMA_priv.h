/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 11/11/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : DIRECT MEMORY ACCESS (DMA)  */
/*****                 PRIVATE                  */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _DMA_PRIV_H_
#define   _DMA_PRIV_H_


#define    ENABLE_MEM2MEM        1
#define    DISABLE_MEM2MEM       2

#define    LOW                   3
#define    MEDIUM                4
#define    HIGH                  5
#define    VERY_HIGH             6

#define    _8_BIT                7
#define    _16_BIT               8
#define    _32_BIT               9
#define    RESERVED              10

#define    ENABLE_MINC           11
#define    DISABLE_MINC          12

#define    ENABLE_PINC           13
#define    DISABLE_PINC          14

#define    ENABLE_CIRCULAR       15
#define    DISABLE_CIRCULAR      16

#define    READ_FROM_MEMORY      17
#define    READ_FROM_PERIPHERAL  18

#define    ENABLE_TEIE           19
#define    DISABLE_TEIE          20

#define    ENABLE_HTIE           21
#define    DISABLE_HTIE          22

#define    ENABLE_TCIE           23
#define    DISABLE_TCIE          24

#define    ENABLE_CHANNEL        25
#define    DISABLE_CHANNEL       26

#endif