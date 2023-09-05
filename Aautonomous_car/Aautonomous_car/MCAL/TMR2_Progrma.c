/*
 * TMR2_Progrma.c
 *
 *  Author: Ahmed Mahmoud
 */ 

#define F_CPU 16000000UL

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "TMR2_Confg.h"
#include "TMR2_Interface.h"

void TMR2_init (void)
{
	#if TMR2_MODE == TMR2_NORMAL_MODE
	// Select Mode = Normal Mode
	CLR_BIT(TCCR2,3) ;
	CLR_BIT(TCCR2,4) ;

	// Init Timer With Preload Value
	TCNT2 = TMR2_PRELOAD_VALUE ;
	
	// Enable OVF Interrupt
	SET_BIT(TIMSK,6) ;
	
	#elif TMR2_MODE == TMR2_CTC_MODE
	 
	 //Select CTC Mode
	 CLR_BIT(TCCR2,3) ;
	 SET_BIT(TCCR2,4) ;

	// Enable CTC Interrupt
	SET_BIT(TIMSK,7) ;

	#elif TMR2_MODE == TMR2_FAST_PWM_MODE
	// Select Mode = Fast PWM Mode
	SET_BIT(TCCR2,3) ;
	SET_BIT(TCCR2,4) ;
	
	// Select Non Inverting Mode
	CLR_BIT(TCCR2,4);
	SET_BIT(TCCR2,5);	
	
	 //Set OC0 pin as O/P pin
	SET_BIT(DDRD,7) ;
	#endif
}
void TMR2_start(void)
{
	CLR_BIT(TCCR2,0) ;
	CLR_BIT(TCCR2,1) ;
	SET_BIT(TCCR2,2) ;

}
void TMR2_setCompareMatchValue(u8 value)
{
	OCR2 = value ;
}

void TMR2_STOP (void) 
{
	CLR_BIT(TCCR2,0) ;
	CLR_BIT(TCCR2,1) ;
	CLR_BIT(TCCR2,2) ;	
}

