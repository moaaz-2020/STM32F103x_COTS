/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam       **/
/*****Date        : 24/07/2020                 **/
/*****Version     : 1.0  V                     **/
/*****Description : ARM SEVEN SEGMENT          **/
/*****               CONFIGURATION             **/
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/


#ifndef  _SEVSEG_CONFIG_H
#define  _SEVSEG_CONFIG_H


/*************************************************/
/***SEVEN SEGMENT CONFIGURATION PORTS WITH PINS***/
/*************************************************/

#define A_PORT		PORTA
#define A_PIN		PIN0

#define B_PORT		PORTA
#define B_PIN		PIN1

#define C_PORT		PORTB
#define C_PIN		PIN1

#define D_PORT		PORTB
#define D_PIN		PIN3

#define E_PORT		PORTC
#define E_PIN		PIN14

#define F_PORT		PORTC
#define F_PIN		PIN15

#define G_PORT		PORTA
#define G_PIN		PIN11

#define DOT_PORT	PORTA
#define DOT_PIN		PIN12

#define CMN_PORT	PORTA
#define CMN_PIN		PIN15


/*************************************************/
/********SEVEN SEGMENT TYPES CONFIGURATION *******/
/*************************************************/

#define SEV_TYPE	CMN_ANODE


/*************************************************/
/*****SEVEN SEGMENT DOT STATUS CONFIGURATION *****/
/*************************************************/

#define DOT_STATUS	CONNECTED

#endif 