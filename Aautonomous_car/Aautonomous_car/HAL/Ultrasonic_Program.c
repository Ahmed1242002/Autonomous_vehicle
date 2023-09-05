/*
 * Ultrasonic_Program.c
 *
 * Created: 8/23/2023 6:48:39 PM
 *  Author: Ahmed Mahmoud
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "TMR0_config.h"
#include "TMR0_interface.h"
#include "GI_interface.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"

/* HAL */
#include "Ultrasonic_Config.h"
#include "Ultrasonic_Interface.h"



void Ultrasonic_Init(void) 
{
	// set ultrasonic pins directions 
	DIO_setPinDeriction(Trigger_Port,Trigger_Pin,DIO_PIN_OUTPUT) ;
	DIO_setPinDeriction(Echo_Port,Echo_Pin,DIO_PIN_INPUT) ;
	
	//enable timer0 on prescaler 64
	TMR0_init();
}
void Ultrasonic_InterruptEnable (void)
{	
	//enable external interrupt
	EXTI_enable(EXTI_INT0,EXTI_ANY_LOGICAL_CHANGE) ;
	
	GI_enable();
}

void Ultrasonic_PulsSend(void) 
{
	// send trigger signal to enable sensor 
	DIO_setPinValue(Trigger_Port,Trigger_Pin,DIO_PIN_HIGH)	; 
	_delay_us(10) ; 
	DIO_setPinValue(Trigger_Port,Trigger_Pin,DIO_PIN_LOW)	;
}

void Ultrasonic_StartMeasuring(void)
{
	TMR0_start() ; 
}

u16  Ultrasonic_GetDistance(void)
{
	u16 distance  ;
	distance =( ( TCNT0 * 4 ) / 29.1 ) / 2 ; 
	
	return distance ;
}

void Ultrasonic_StopMeasruing (void)
{
	TMR0_Stop() ;
}