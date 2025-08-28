#include <REGX52.H>

void Timer1_Init(){//100us
	TMOD&=0x0F;
	TMOD|=0x10;
	TL1=0xA4;		
	TH1=0xFF;	
	TF1=0;
	TR1=1;
	ET1=1;
	EA=1;
	PT1=0;
}


/*
void Timer1_Routine() interrupt 3{
	static unsigned int T1Count;
	TL1=0xA4;		
	TH1=0xFF;	
	T1Count++;
	if(T1Count>=1000){
		T1Count=0;
	}
}
*/