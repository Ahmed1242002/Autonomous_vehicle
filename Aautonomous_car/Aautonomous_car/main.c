/*
 * AUTO_CAR.c
 *
 * Author : Ahmed Mahmoud
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
#include "CAR_Interface.h"
#include "DCM_interface.h"
#include "DC_motor_confg.h"

/* MCAL */
#include "DIO_interface.h"
#include "TMR1_interface.h"
#include "TMR0_config.h"
#include "TMR0_interface.h"
#include "EXTI_interface.h"
#include "GI_interface.h"
#include "TMR2_Confg.h"
#include "TMR2_Interface.h"



// variables for check distance
u16  RightSide= 0 ; /* first check if distance less than 10cm */
u16  LeftSide= 0 ; /* check the distance on right side */



// variables for ultrasonic 
u8 SensorInWork = 0 ;
u16 Distance_CM = 0 ;
u8 ovf_counter = 0 ;

int main(void)
{
	// Initialize all car component 
	CAR_INIT() ;
	DCM_init() ; 
   CarForward() ;
	TMR2_init();
   SRVM_START(0);
    while (1) 
    {
		// send trigger signal 
		Ultrasonic_PulsSend() ; 
		if (Distance_CM < 20 && Distance_CM > 2)
		{	
		CarStop() ;
		_delay_ms(1000) ;
		SRVM_START(90) ;
		_delay_ms(1000) ;
		// get distance from ultrasonic
		Ultrasonic_PulsSend();
		RightSide = Distance_CM ;
		_delay_ms(1000) ;
		
		SRVM_START(180) ;
		_delay_ms(1000) ;
		Ultrasonic_PulsSend();
		LeftSide = Distance_CM ;
		_delay_ms(1000) ;
	
		
		if (LeftSide > RightSide)
		{
			CarRight() ;
			_delay_ms(3000) ;
			CarStop() ;
			CarForward() ;
			SRVM_START(0) ;
			RightSide = 0 ;
			LeftSide = 0 ;
			LCD_clear() ;
		      LCD_sendChar('R') ;    LCD_sendChar('i') ;    LCD_sendChar('g') ;     LCD_sendChar('h') ;	    LCD_sendChar('t') ;
			
		}	 if (LeftSide < RightSide)
		{
			CarLeft() ;
			LCD_clear() ;
		      LCD_sendChar('L') ;    LCD_sendChar('e') ;    LCD_sendChar('f') ;     LCD_sendChar('t') ;	   
			_delay_ms(3000) ;
			CarStop() ;
			CarForward() ;
			SRVM_START(0) ;
			RightSide = 0 ;
			LeftSide = 0 ;
		}
		
		
 }
			 
			
		}
}
    



// Timer0 OVF interrupt
void __vector_11(void) __attribute__ ((signal));
void __vector_11(void)
{
	ovf_counter ++ ;
}

// external interrupt for ultrasonic sensor
void __vector_1(void) __attribute__ ((signal));
void __vector_1(void)
{
	if ( 0 == SensorInWork )
	{
		Ultrasonic_StartMeasuring() ;
		SensorInWork = 1 ;
	} else if ( 1 == SensorInWork )
	{
		TMR0_Stop() ;
		Distance_CM = Ultrasonic_GetDistance() + (ovf_counter * 13) ;
		ovf_counter = 0 ;
		TMR0_Clear() ;
		SensorInWork = 0 ;
		
		LCD_clear() ;
		// save the distance on the LCD
		LCD_clear() ;
		
		LCD_sendChar('D') ;	LCD_sendChar('i') ;	LCD_sendChar('s') ;	LCD_sendChar('t') ;	LCD_sendChar('a')  ;
		LCD_sendChar('n') ; LCD_sendChar('c') ;LCD_sendChar('e') ;	LCD_sendChar(' ') ;  LCD_sendChar('C') ;
		LCD_sendChar('M') ; LCD_sendChar(' ') ;
		
		LCD_writeNumber(Distance_CM) ;
		//delay for measuring
		_delay_ms(200) ;
	}
	
}


