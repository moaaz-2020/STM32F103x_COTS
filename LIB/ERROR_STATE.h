/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam ********/
/*****Date        : 26/03/2020           ********/
/*****Version     : 1.0   V               ********/
/*****Description : ERROR STATE          ********/
/************************************************/


/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/

#ifndef _ERROR_STATE_H_
#define _ERROR_STATE_H_


/************************************************/
/******* FUNCTION TO REPRESENT ANY CASE WITH ****/
/***************** READABLE NAME ****************/
/************************************************/


typedef enum Error_enuStatus{
	ES_OK,
	ES_NOK,
	ES_OUT_OF_RANGE,
	ES_NULL_POINTER
}Error_enuStatus;


#endif
