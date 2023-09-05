/*
 * TMR2_Interface.h
 *
 *  Author: Ahmed Mahmoud
 */ 


#ifndef TMR2_INTERFACE_H_
#define TMR2_INTERFACE_H_

#define TMR2_NORMAL_MODE   0
#define TMR2_CTC_MODE      1
#define TMR2_FAST_PWM_MODE 2


void TMR2_init (void);
void TMR2_start(void);
void TMR2_setCompareMatchValue(u8 value);
void TMR2_STOP (void);
void TMR2_delay (u8 mile_sec) ;



#endif /* TMR2_INTERFACE_H_ */