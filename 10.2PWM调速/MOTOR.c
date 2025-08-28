#include <REGX52.H>

sbit Motor=P1^0;
unsigned char Counter,Compare;


void Timer1_Init(void)
{
	TMOD &= 0x0F;	
	TMOD |= 0x10;
	TL1 = 0x9C;		
	TH1 = 0xFF;		
	TF1 = 0;		
	TR1 = 1;	
	ET1=1;
	EA=1;
	PT1=0;
}

void Motor_Init(void)
{
	Timer1_Init();
}

void Motor_SetSpeed(unsigned char Speed)
{
	Compare=Speed;
}

void Timer1_Routine() interrupt 3
{
	TL1 = 0x9C;	
	TH1 = 0xFF;		
	Counter++;
	Counter%=100;	
	if(Counter<Compare)	
	{
		Motor=1;	
	}
	else		
	{
		Motor=0;	
	}
}