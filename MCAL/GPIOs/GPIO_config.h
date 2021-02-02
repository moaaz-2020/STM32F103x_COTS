/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam        */
/*****Date        : 22/07/2020                  */
/*****Version     : 1.0  V                      */
/*****Description : GENERAL PURPOSE I/O REGISTER*/
/*****                       CONFIGURATIONS     */
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/



#ifndef   _GPIO_CONFIG_H_
#define   _GPIO_CONFIG_H_


/******************************************************************/
/********													*******
			OUTPUT_10MHZ_PUSHPULL			
			OUTPUT_2MHZ_PUSHPULL			
			OUTPUT_50MHZ_PUSHPULL			
			OUTPUT_10MHZ_OPEN_DRAIN			
			OUTPUT_2MHZ_OPEN_DRAIN			
			OUTPUT_50MHZ_OPEN_DRAIN			
			AF_OUTPUT_10MHZ_PUSHPULL		
			AF_OUTPUT_2MHZ_PUSHPULL			
			AF_OUTPUT_50MHZ_PUSHPULL		
			AF_OUTPUT_10MHZ_OPEN_DRAIN		
			AF_OUTPUT_2MHZ_OPEN_DRAIN		
			AF_OUTPUT_50MHZ_OPEN_DRAIN		
			INPUT_ANALOG					
			INPUT_FLOATING					
			INPUT_PULLDOWN					
			INPUT_PULLUP					
/*****************************************************************/
#define		DIRECTION_MODE			OUTPUT_10MHZ_PUSHPULL

#endif