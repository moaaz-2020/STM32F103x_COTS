/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam       **/
/*****Date        : 30/03/2020                 **/
/*****Version     : 1.0  V                     **/
/*****Description : SEVEN SEGMENT FUNCTION     **/
/*****                Prototypes               **/
/************************************************/

/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/

#ifndef   _SEVSEG_INT_H_
#define   _SEVSEG_INT_H_

/************************************************/
/* THIS FUNCTION FOR INITIALIZATION TO SEV.SEG  */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void SevSeg_vidInit(void);

/************************************************/
/* THIS FUNCTION TO DISPLAY NUMBER OF SEV. SEG. */
/* INPUTS : UNSIGHNED INTEGER                   */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void SevSeg_vidDisplayNumber(u8 Copy_u8Number);

/************************************************/
/* FUNCTION TO SET THE COMMON PIN OF SEV. SEG. */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void SevSeg_vidSetCommonPin(void);

/************************************************/
/* FUNCTION TO STOP THE COMMON PIN OF SEV. SEG.*/
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void SevSeg_vidStopCommonPin(void);

/************************************************/
/* FUNCTION TO STOP THE  SEVEVEN SEGMENT.       */
/* INPUTS : VOID                                */
/* RETURN : VOID                                */
/************************************************/
/*    PRECONDITION :                            */
/*                                              */
/************************************************/

void SevSeg_voidStopSevSeg(void);




#endif