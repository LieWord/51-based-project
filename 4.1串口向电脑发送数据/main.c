#include <REGX52.H>
#include "Delay.h"
#include "UART_Init.h"


unsigned char Sec;





void main(){
	UART();
	while(1){

	}
}

void URAT_Routine() interrupt 4{
	
		if(RI==1){
			P2=~SBUF;
			UART_SendByte(SBUF);
			//Delay(1000);
			//P2=~P2;
			RI=0;
		}
}