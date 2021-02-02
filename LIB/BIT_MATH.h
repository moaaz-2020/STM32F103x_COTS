/************************************************/
/*****AUTHOR      : Moaaz Rashad Sewilam ********/
/*****Date        : 26/03/2020           ********/
/*****Version     : 1.0   V              ********/
/*****Description : BIT MATH             ********/
/************************************************/


/************************************************/
/*****gaurd of file will call one time in .c*****/
/************************************************/

#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_


/*************************************************/
/**** THIS FILE TO SET OR CLEARING OR TOGLING ****/
/**** OR GETTING OR ASSIGNING VALUE **************/
/*************************************************/      

#define SET_BIT(REG,INDEX)         REG|=(1<<INDEX) 
#define CLR_BIT(REG,INDEX)         REG&=(~(1<<INDEX))
#define TOG_BIT(REG,INDEX)         REG^=(1<<INDEX)
#define GET_BIT(REG,INDEX)         ((REG>>INDEX)&1)
#define ASSIGN_BIT(REG,INDEX,VAL)  REG=((REG&(~(1<<INDEX)))|(VAL<<INDEX))

#endif