/*
 * EXTI_program.c
 *
 * Created: 4/8/2023 3:18:56 PM
 *  Author: AMIT
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "EXTI_interface.h"


void EXTI_enable(u8 interruptSource, u8 interruptTriggerEdge)
{
	switch(interruptSource)
	{
		case EXTI_INT0:
		if(EXTI_RISING_EDGE == interruptTriggerEdge)
		{
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
		}
		else if(EXTI_FALLING_EDGE == interruptTriggerEdge)
		{
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
		}
		else if(EXTI_LOW_LEVEL == interruptTriggerEdge)
		{
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
		}
		else if(EXTI_ANY_LOGICAL_CHANGE == interruptTriggerEdge)
		{
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
		}
		
		CLR_BIT(DDRD,2); // INT0 PIN >> I/P
		SET_BIT(GICR,6); //enable INT0
		break;
		
		case EXTI_INT1:
		if(EXTI_RISING_EDGE == interruptTriggerEdge)
		{
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
		}
		else if(EXTI_FALLING_EDGE == interruptTriggerEdge)
		{
			CLR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
		}
		else if(EXTI_LOW_LEVEL == interruptTriggerEdge)
		{
			CLR_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
		}
		else if(EXTI_ANY_LOGICAL_CHANGE == interruptTriggerEdge)
		{
			SET_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
		}
		
		CLR_BIT(DDRD,3); // INT1 PIN >> I/P
		SET_BIT(GICR,7); //enable INT1
		break;
		
		case EXTI_INT2:
		if(EXTI_RISING_EDGE == interruptTriggerEdge)
		{
			SET_BIT(MCUCSR,6);
		}
		else if(EXTI_FALLING_EDGE == interruptTriggerEdge)
		{
			CLR_BIT(MCUCSR,6);
		}
		
		CLR_BIT(DDRB,2); // INT2 PIN >> I/P
		SET_BIT(GICR,5); //enable INT2
		break;
	}
}


void EXTI_disable(u8 interruptSource)
{
	switch(interruptSource)
	{
		case EXTI_INT0:
		CLR_BIT(GICR,6);
		break;
		
		case EXTI_INT1:
		CLR_BIT(GICR,7);
		break;
		
		case EXTI_INT2:
		CLR_BIT(GICR,5);
		break;
	}
}