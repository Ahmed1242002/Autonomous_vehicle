/*
 * CAR_Program.c
 *
 *  Author: Ahmed Mahmoud
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* HAL */
#include "SRVM_interface.h"
#include "Ultrasonic_Config.h"
#include "Ultrasonic_Interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include "DCM_interface.h"
#include "DC_motor_confg.h"

/* MCAL */
#include "DIO_interface.h"
#include "TMR1_interface.h"
#include "TMR0_config.h"
#include "TMR0_interface.h"
#include "EXTI_interface.h"
#include "GI_interface.h"
#include "TMR2_Interface.h"
#include "TMR2_Confg.h"






void CAR_INIT(void)
{
	Ultrasonic_Init() ;
	Ultrasonic_InterruptEnable() ;
	LCD_init()  ;
	
	SRVM_INIT() ;
}

void CarForward(void)
{
// Disable both motors (assuming enable1 and enable2 are connected to PortD Pin 4 and Pin 7)
DIO_setPinValue(ENABLE1_PORT, ENABLE1_PIN, DIO_PIN_HIGH);
DIO_setPinValue(ENABLE2_PORT, ENABLE2_PIN, DIO_PIN_HIGH);

// Set direction pins for both motors for backward motion
// Adjust the control pins based on your H-bridge configuration
DIO_setPinValue(H1_PORT, H1_PIN, DIO_PIN_LOW); // Control pin for right motor
DIO_setPinValue(H2_PORT, H2_PIN, DIO_PIN_HIGH);  // Control pin for right motor
DIO_setPinValue(H3_PORT, H3_PIN, DIO_PIN_HIGH);  // Control pin for left motor
DIO_setPinValue(H4_PORT, H4_PIN, DIO_PIN_LOW); // Control pin for left motor
}
void CarBackward(void) 
{
	POWER_ON() ;
}
void CarRight(void)
{
	RIGHT_DCM() ;
	
}
void CarLeft(void)
{
	LEFT_DCM()  ;

}

void CarStop(void)
{
	DCM_off(RIGHT_MOTOR) ;
	DCM_off(LEFT_MOTOR)  ;
}
