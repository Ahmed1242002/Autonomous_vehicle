/*
 * TMR0_interface.h
 *
 * Created: 4/15/2023 2:59:49 PM
 *  Author: AMIT
 */ 


#ifndef TMR0_INTERFACE_H_
#define TMR0_INTERFACE_H_



#define TMR0_NORMAL_MODE   0
#define TMR0_CTC_MODE      1
#define TMR0_FAST_PWM_MODE 2


void TMR0_init (void);
void TMR0_start(void);
void TMR0_setCompareMatchValue(u8 value);
void TMR0_Stop(void) ;
void TMR0_Clear(void) ;


#endif /* TMR0_INTERFACE_H_ */