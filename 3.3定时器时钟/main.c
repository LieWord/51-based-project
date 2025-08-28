#include <REGX52.H>
#include <INTRINS.H> 
#include "Delay.h"
#include "MatrixKey.h"
#include "IndeKey.h"
#include "LCD1602.h"
#include "Timer0_Init.h"

unsigned char Sec=51;
unsigned char Min=59;
unsigned char Hour=13;


/*//1ºÁÃë¼ÆÊ±Æ÷
void Timer0_Init(){
	TMOD &= 0xF0;		
	TMOD |= 0x01;		
	TL0 = 0x18;		
	TH0 = 0xFC;		
	TF0 = 0;		
	TR0 = 1;		
	
	ET0=1;
	EA=1;
	PT0=0;
}*/


void main(){
	Timer0_Init();
	LCD_Init();
	LCD_ShowString(1,1,"Clock:");
	while(1){
		/*KeyNum=IndeKey();
		if(KeyNum){
			if(KeyNum==1){LEDMode=1;}
			if(KeyNum==2){LEDMode=2;}
		}
	*/
		LCD_ShowNum(2,7,Sec,2);
		LCD_ShowNum(2,4,Min,2);
		LCD_ShowNum(2,1,Hour,2);
		LCD_ShowChar(2,3,':');
		LCD_ShowChar(2,6,':');


	}	
}

void Timer0_Routine() interrupt 1{
	static unsigned int T0Count;
	TL0 = 0x18;		
	TH0 = 0xFC;		
	T0Count++;
	if(T0Count>=1000){
		T0Count=0;
		/*if(LEDMode==1)P2=_crol_(P2,1);
		if(LEDMode==2)P2=_cror_(P2,1);*/
		Sec++;
		if(Sec>=60){Sec=0;Min++;}
		if(Min>=60){Min=0;Hour++;}

	}
}