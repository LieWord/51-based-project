#include <REGX52.H>
#include "Timer0_Init.h"
#include "Delay.h"
#include "IndeKey.h"
#include "Nixie.h"

sbit MOTOR=P1^0;

unsigned char Counter,Compare;
unsigned char KeyNum,Speed;

//void Delay(unsigned int t){
//	while(t--);
//}

void main()
{
	Timer0_Init();
	Compare=5;
	while(1)
	{
		KeyNum=IndeKey();
		if(KeyNum==1)
		{
			Speed++;
			Speed%=4;
			if(Speed==0){Compare=0;}
			if(Speed==1){Compare=50;}
			if(Speed==2){Compare=75;}
			if(Speed==3){Compare=100;}
		}
		Nixie(1,Speed);
	}
}

void Timer0_Routine() interrupt 1
{
	TL0=0xA4;		
	TH0=0xFF;	
	Counter++;
	Counter%=100;
	if(Counter<Compare)
	{
		MOTOR=1;
	}
	else
	{
		MOTOR=0;
	}
}