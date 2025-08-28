#ifndef __TIMER0_INIT_H__
#define __TIMER0_INIT_H__

void Timer0_Init();
void Timer0_SetCounter(unsigned int Value);
unsigned int Timer0_GetCounter();
void Timer0_Run(unsigned char Flag);

#endif