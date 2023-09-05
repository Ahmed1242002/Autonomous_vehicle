/*
 * DCM_program.c
 *
 * Created: 4/29/2023 2:43:35 PM
 *  Author: AMIT
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"


/* HAL */
#include "DCM_interface.h"
#include "DC_motor_confg.h"


void DCM_init     (void)
{
	/* Replace with your application code */
	DIO_setPinDeriction(ENABLE1_PORT,ENABLE1_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDeriction(ENABLE2_PORT,ENABLE2_PIN,DIO_PIN_OUTPUT);
	
	DIO_setPinDeriction(H1_PORT,H1_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDeriction(H2_PORT,H2_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDeriction(H3_PORT,H3_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDeriction(H4_PORT,H4_PIN,DIO_PIN_OUTPUT);
}



void DCM_off      (u8 MOTOR_POSITON)
{
	switch (MOTOR_POSITON)
	{
		case 0 : 
	DIO_setPinValue(ENABLE1_PORT,ENABLE1_PIN,DIO_PIN_LOW);
		break; 
		
		case 1 :
		
	DIO_setPinValue(ENABLE2_PORT,ENABLE2_PIN,DIO_PIN_LOW);


	}
}

void RIGHT_DCM (void) 
{
	DIO_setPinValue(ENABLE2_PORT,ENABLE2_PIN,DIO_PIN_HIGH)  ;
	
	DIO_setPinValue(H3_PORT,H3_PIN,DIO_PIN_LOW)	  ;
	DIO_setPinValue(H4_PORT,H4_PIN,DIO_PIN_HIGH)  ;
	
	
	
}
void LEFT_DCM (void) 
{
	DIO_setPinValue(ENABLE1_PORT,ENABLE1_PIN,DIO_PIN_HIGH) ;
	
	DIO_setPinValue(H2_PORT,H2_PIN,DIO_PIN_LOW)  ;
	
	DIO_setPinValue(H1_PORT,H1_PIN,DIO_PIN_HIGH) ;
}

void POWER_ON (void) 
{
	LEFT_DCM() ;
	RIGHT_DCM() ;
}