#include <REGX52.H>

void UART(){
	SCON=0x50;
	PCON=0x80;
	TMOD&=0x0F;
	TMOD|=0x20;
	TL1=0xF4;
	TH1=0xF4;
	//TF1=;
	TR1=1;
	ET1=0;
	EA=1;
	ES=1;
	//PT1=0;
}

void UART_SendByte(unsigned char Byte){
	SBUF=Byte;
	while(!TI);
	TI=0;
}

/*
void URAT_Routine() interrupt 4{
	
		if(RI==1){
			//P2=~SBUF;
			//UART_SendByte(SBUF);
			//Delay(1000);
			//P2=~P2;
			RI=0;
		}
}
*/