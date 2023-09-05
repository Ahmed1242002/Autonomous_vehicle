/*
 * GI_program.c
 *
 * Created: 4/15/2023 3:34:53 PM
 *  Author: AMIT
 */ 
/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "GI_interface.h"


void GI_enable(void)
{
	SET_BIT(SREG,7);
}


void GI_disable(void)
{
	CLR_BIT(SREG,7);
}