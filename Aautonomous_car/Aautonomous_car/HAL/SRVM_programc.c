/*		TMR1_setCompareMatchValueA(375) ;

 * SRVM_programc.c
 *
 * Created: 4/29/2023 5:36:20 PM
 *  Author: AMIT
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "TMR1_interface.h"

/* HAL */
#include "SRVM_interface.h"




void SRVM_INIT(void)
{
	TMR1_init();
	TMR1_start();
}


void SRVM_START(u8 servoAngle)
{
	if (0 == servoAngle)
	{
		TMR1_setCompareMatchValueA(375);
	}
	else if (90 == servoAngle)
	{
	TMR1_setCompareMatchValueA(170);
	}
	else if (180 == servoAngle)
	{
		TMR1_setCompareMatchValueA(550);
	}
}