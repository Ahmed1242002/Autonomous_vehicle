/*
 * TMR0_program.c
 *
 * Created: 4/15/2023 2:59:41 PM
 *  Author: AMIT
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "TMR0_interface.h"
#include "TMR0_config.h"


void TMR0_init(void)
{
#if TMR0_MODE == TMR0_NORMAL_MODE
	// Select Mode = Normal Mode
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	
	// Init Timer With Preload Value
	TCNT0 = TMR0_PRELOAD_VALUE;
	
	// Enable OVF Interrupt
		SET_BIT(TIMSK,0);
	
#elif TMR0_MODE == TMR0_CTC_MODE
    // Select Mode = CTC Mode
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

	// Enable CTC Interrupt
	SET_BIT(TIMSK,1);
	
#elif TMR0_MODE == TMR0_FAST_PWM_MODE
	// Select Mode = Fast PWM Mode
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	
	// Select Non Inverting Mode
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	
	SET_BIT(DDRB,3); //Set OC0 pin as O/P pin
#endif
}


void TMR0_start(void)
{
	// Select Prescaler Value = 64
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);

}

void TMR0_setCompareMatchValue(u8 value)
{
	OCR0 = value;
}


void TMR0_Stop(void)
{
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}

void TMR0_Clear(void) 
{
	TCNT0 = 0 ;
}


