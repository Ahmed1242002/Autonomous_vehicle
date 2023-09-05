/*
 * EXTI_interface.h
 *
 * Created: 4/8/2023 3:19:06 PM
 *  Author: AMIT
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


/* Macros For Interrupt Source */
#define EXTI_INT0                   0    // PORT_D PIN_2
#define EXTI_INT1                   1    // PORT_D PIN_3
#define EXTI_INT2                   2    // PORT_B PIN_2

/* Macros For Interrupt Trigger Edge */						
#define EXTI_RISING_EDGE            0
#define EXTI_FALLING_EDGE           1
#define EXTI_LOW_LEVEL              2
#define EXTI_ANY_LOGICAL_CHANGE     3

                    /*************** APIS PROTOTYPES ***************/
					
void EXTI_enable (u8 interruptSource, u8 interruptTriggerEdge);
void EXTI_disable(u8 interruptSource);

#endif /* EXTI_INTERFACE_H_ */