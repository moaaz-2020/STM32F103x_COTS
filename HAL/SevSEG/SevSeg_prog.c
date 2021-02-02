/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam       **/
/*****Date        : 24/07/2020                 **/
/*****Version     : 1.0  V                     **/
/*****Description :  FUNCTION IMPLEMENTATION   **/
/*****               FOR SEVEN SEGMENT         **/
/************************************************/

/************************************************/
/**********  STANDARD LIB DIRECTIVES ************/
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"


/************************************************/
/********** COMPONENTS DIRECTIVES    ************/
/************************************************/
#include "GPIO_int.h"
#include "GPIO_reg.h"

#include "SevSeg_config.h"
#include "SevSeg_priv.h"
#include "SevSeg_int.h"




/************************************************/
/********** FUNCTION IMPLEMENTATION  ************/
/************************************************/

/************************************************/
/* THIS FUNCTION FOR INITIALIZATION TO SEV.SEG  */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void SevSeg_vidInit(void)
{
	GPIO_enuSetPinMode( A_PORT , A_PIN , OUTPUT , OUTPUT_PUSHPULL , SPEED_10MHZ);
	GPIO_enuSetPinMode( B_PORT , B_PIN , OUTPUT , OUTPUT_PUSHPULL , SPEED_10MHZ);
	GPIO_enuSetPinMode( C_PORT , C_PIN , OUTPUT , OUTPUT_PUSHPULL , SPEED_10MHZ);
	GPIO_enuSetPinMode( D_PORT , D_PIN , OUTPUT , OUTPUT_PUSHPULL , SPEED_10MHZ);
	GPIO_enuSetPinMode( E_PORT , E_PIN , OUTPUT , OUTPUT_PUSHPULL , SPEED_10MHZ);
	GPIO_enuSetPinMode( F_PORT , F_PIN , OUTPUT , OUTPUT_PUSHPULL , SPEED_10MHZ);
	GPIO_enuSetPinMode( G_PORT , G_PIN , OUTPUT , OUTPUT_PUSHPULL , SPEED_10MHZ);
	GPIO_enuSetPinMode( DOT_PORT , DOT_PIN , OUTPUT , OUTPUT_PUSHPULL , SPEED_10MHZ);
	GPIO_enuSetPinMode( CMN_PORT , CMN_PIN , OUTPUT , OUTPUT_PUSHPULL , SPEED_10MHZ);
}


/************************************************/
/* THIS FUNCTION TO DISPLAY NUMBER OF SEV. SEG. */
/* INPUTS : UNSIGHNED INTEGER                   */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void SevSeg_vidDisplayNumber(u8 Copy_u8Number)
{
	#if SEV_TYPE == CMN_CATHODE
		GPIO_enuSetPinValue(A_PORT,A_PIN,(SevSeg_Au8NumOfSevSeg[Copy_u8Number]      & 0x01) );
		GPIO_enuSetPinValue(B_PORT,B_PIN,((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>1) & 0x01) );
		GPIO_enuSetPinValue(C_PORT,C_PIN,((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>2) & 0x01) );
		GPIO_enuSetPinValue(D_PORT,D_PIN,((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>3) & 0x01) );
		GPIO_enuSetPinValue(E_PORT,E_PIN,((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>4) & 0x01) );
		GPIO_enuSetPinValue(F_PORT,F_PIN,((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>5) & 0x01) );
		GPIO_enuSetPinValue(G_PORT,G_PIN,((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>6) & 0x01) );

	#elif SEV_TYPE == CMN_ANODE
		GPIO_enuSetPinValue(A_PORT,A_PIN,!((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>0) & 0x01) );
		GPIO_enuSetPinValue(B_PORT,B_PIN,!((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>1) & 0x01) );
		GPIO_enuSetPinValue(C_PORT,C_PIN,!((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>2) & 0x01) );
		GPIO_enuSetPinValue(D_PORT,D_PIN,!((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>3) & 0x01) );
		GPIO_enuSetPinValue(E_PORT,E_PIN,!((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>4) & 0x01) );
		GPIO_enuSetPinValue(F_PORT,F_PIN,!((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>5) & 0x01) );
		GPIO_enuSetPinValue(G_PORT,G_PIN,!((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>6) & 0x01) );

	#else
		#error "Wrong Type"
	#endif

	#if (SEV_TYPE == CMN_CATHODE && DOT_STATUS == CONNECTED)
		GPIO_enuSetPinValue(DOT_PORT,DOT_PIN,CONNECTED);

	#elif (SEV_TYPE == CMN_ANODE && DOT_STATUS == CONNECTED)
		GPIO_enuSetPinValue(DOT_PORT,DOT_PIN, CONNECTED);
	#else
		#warning "DOT is not Connected"
	#endif
}

/************************************************/
/* FUNCTION TO SET THE COMMON PIN OF SEV. SEG. */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void SevSeg_vidSetCommonPin(void)
{
	#if (SEV_TYPE == CMN_CATHODE )
		GPIO_enuSetPinValue(CMN_PORT,CMN_PIN,0);
	#elif (SEV_TYPE == CMN_ANODE )
		GPIO_enuSetPinValue(CMN_PORT,CMN_PIN,1);
	#else
		#error "wrong Type"
	#endif
}

/************************************************/
/* FUNCTION TO STOP THE COMMON PIN OF SEV. SEG.*/
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void SevSeg_vidStopCommonPin(void)
{
	#if (SEV_TYPE == CMN_CATHODE )
		GPIO_enuSetPinValue(CMN_PORT,CMN_PIN,1);
	#elif (SEV_TYPE == CMN_ANODE )
		GPIO_enuSetPinValue(CMN_PORT,CMN_PIN,0);
	#else
		#error "wrong Type"
	#endif
}

/************************************************/
/* FUNCTION TO STOP THE  SEVEVEN SEGMENT.       */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void SevSeg_vidStopSevSeg(u8 Copy_u8Number)
{
    #if SEV_TYPE == CMN_ANODE
		GPIO_enuSetPinValue(A_PORT,A_PIN,(SevSeg_Au8NumOfSevSeg[Copy_u8Number]      & 0x01) );
		GPIO_enuSetPinValue(B_PORT,B_PIN,((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>1) & 0x01) );
		GPIO_enuSetPinValue(C_PORT,C_PIN,((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>2) & 0x01) );
		GPIO_enuSetPinValue(D_PORT,D_PIN,((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>3) & 0x01) );
		GPIO_enuSetPinValue(E_PORT,E_PIN,((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>4) & 0x01) );
		GPIO_enuSetPinValue(F_PORT,F_PIN,((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>5) & 0x01) );
		GPIO_enuSetPinValue(G_PORT,G_PIN,((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>6) & 0x01) );

	#elif SEV_TYPE == CMN_CATHODE
		GPIO_enuSetPinValue(A_PORT,A_PIN,!((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>0) & 0x01) );
		GPIO_enuSetPinValue(B_PORT,B_PIN,!((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>1) & 0x01) );
		GPIO_enuSetPinValue(C_PORT,C_PIN,!((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>2) & 0x01) );
		GPIO_enuSetPinValue(D_PORT,D_PIN,!((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>3) & 0x01) );
		GPIO_enuSetPinValue(E_PORT,E_PIN,!((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>4) & 0x01) );
		GPIO_enuSetPinValue(F_PORT,F_PIN,!((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>5) & 0x01) );
		GPIO_enuSetPinValue(G_PORT,G_PIN,!((SevSeg_Au8NumOfSevSeg[Copy_u8Number]>>6) & 0x01) );

	#else
		#error "Wrong Type"
	#endif

	#if (SEV_TYPE == CMN_ANODE && DOT_STATUS == CONNECTED)
		GPIO_enuSetPinValue(DOT_PORT,DOT_PIN,CONNECTED);

	#elif (SEV_TYPE == CMN_CATHODE && DOT_STATUS == CONNECTED)
		GPIO_enuSetPinValue(DOT_PORT,DOT_PIN,! CONNECTED);
	#else
		#warning "DOT is not Connected"
	#endif
}