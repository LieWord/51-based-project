#include <REGX52.H>

void Timer1_Init(){
	SCON=0x40;
	PCON=0x80;
	TMOD&=0x0F;
	TMOD|=0x20;
	TL1=0xF4;
	TH1=0xF4;
	//TF1=;
	TR1=1;
	ET1=0;
	//EA=1;
	//PT1=0;
}