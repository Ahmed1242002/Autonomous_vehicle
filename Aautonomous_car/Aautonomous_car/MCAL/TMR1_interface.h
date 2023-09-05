/*
 * TMR1_interface.h
 *
 * Created: 4/29/2023 4:47:59 PM
 *  Author: AMIT
 */ 


#ifndef TMR1_INTERFACE_H_
#define TMR1_INTERFACE_H_


void TMR1_init                 (void);
void TMR1_start                (void);
void TMR1_setCompareMatchValueA(u16 value);


#endif /* TMR1_INTERFACE_H_ */