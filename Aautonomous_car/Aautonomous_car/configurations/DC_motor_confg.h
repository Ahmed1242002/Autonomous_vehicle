/*
 * DC_motor_confg.h
 *
 * Created: 7/14/2023 6:03:22 PM
 *  Author: Ahmed 
 */ 


#ifndef DC_MOTOR_CONFG_H_
#define DC_MOTOR_CONFG_H_

// motor positions
#define	RIGHT_MOTOR 0
#define	LEFT_MOTOR  1

// motors ports &	pins
#define ENABLE1_PORT	DIO_PORTD
#define ENABLE2_PORT	DIO_PORTD

#define ENABLE1_PIN 	DIO_PIN4
#define ENABLE2_PIN 	DIO_PIN7


#define H1_PORT			DIO_PORTC
#define H2_PORT			DIO_PORTC
#define H3_PORT			DIO_PORTC
#define H4_PORT			DIO_PORTC

#define H1_PIN			DIO_PIN3
#define H2_PIN			DIO_PIN4
#define H3_PIN			DIO_PIN5
#define H4_PIN			DIO_PIN6


#endif /* DC_MOTOR_CONFG_H_ */