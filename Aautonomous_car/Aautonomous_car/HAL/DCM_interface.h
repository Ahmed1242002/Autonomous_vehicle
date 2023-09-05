/*
 * DCM_interface.h
 *
 * Created: 4/29/2023 2:43:44 PM
 *  Author: AMIT
 */ 


#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

#define	RIGHT_MOTOR 0
#define	LEFT_MOTOR  1


void DCM_init  (void)	 ;
void RIGHT_DCM (void)    ;
void LEFT_DCM  (void)    ;
void POWER_ON  (void)    ;

void DCM_off(u8 MOTOR_POSITON) ;


#endif /* DCM_INTERFACE_H_ */