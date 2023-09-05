/*
 * Ultrasonic_Interface.h
 *
 * Created: 8/23/2023 6:48:58 PM
 *  Author: HP
 */ 


#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_

void Ultrasonic_Init(void) ; 
void Ultrasonic_PulsSend(void) ;
void Ultrasonic_StartMeasuring(void) ; 
u16  Ultrasonic_GetDistance(void) ;

void Ultrasonic_StopMeasruing (void) ;
void Ultrasonic_InterruptEnable (void) ;



#endif /* ULTRASONIC_INTERFACE_H_ */