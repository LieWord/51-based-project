#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "DS18B20.h"
#include "AT2402.h"
#include "I2C.h"
#include "Timer0_Init.h"
#include "IndeKey.h"
#include "Buzzer.h"

float T,TShow;
char TLow,THigh;
unsigned KeyNum;
unsigned char WarnFlag=0;

void main(){
	THigh=AT24C02_ReadByte(0);
	TLow=AT24C02_ReadByte(1);
	if(THigh>125 || TLow<-55 || TLow>=THigh){TLow=-5;THigh=20;}
	Timer0_Init();
	DS18B20_ConvertT();
	Delay(1000);
	LCD_Init();
	LCD_ShowString(1,1,"T:");
	LCD_ShowString(2,1,"TH:");
	LCD_ShowString(2,9,"TL:");
	//LCD_ShowString(1,1,"Temperature:");
	while(1){
		KeyNum=IndeKey();
		/*温度读取及显示*/
		DS18B20_ConvertT();
		T=DS18B20_ReadT();
		if(T<0){
			LCD_ShowChar(1,3,'-');
			TShow=-T;
		}
		else{
			LCD_ShowChar(1,3,'+');
			TShow=T;
		}
			
		LCD_ShowNum(1,4,TShow,3);
		LCD_ShowChar(1,7,'.');
		LCD_ShowNum(1,8,(unsigned long)(TShow*100)%100,2);
		/*阈值判断及显示*/
		LCD_ShowSignedNum(2,4,THigh,3);
		LCD_ShowSignedNum(2,12,TLow,3);
		if(KeyNum){
			switch(KeyNum){
				case 1:THigh++;Buzzer_tms(100);if(THigh>125)THigh=125;break;
				case 2:THigh--;Buzzer_tms(100);if(THigh<=TLow)THigh++;break;
				case 3:TLow++;Buzzer_tms(100);if(TLow>=THigh)TLow--;break;
				case 4:TLow--;Buzzer_tms(100);if(TLow<-55)TLow=-55;break;
				default:break;
				AT24C02_WriteByte(0,THigh);
				Delay(8);
				AT24C02_WriteByte(1,TLow);				
			}
			if(T>THigh){
				LCD_ShowString(1,13,"OV:H");
				WarnFlag=1;
			}			
			else if(T<TLow){
				LCD_ShowString(1,13,"OV:L");				
				WarnFlag=1;
			}
			else{
				LCD_ShowString(1,13,"    ");	
				WarnFlag=0;						
			}
		}
	}
}



void Timer0_Routine() interrupt 1{
	static unsigned int T0Count1,T0Count2,T0Count3;
	TL0=0x18;
	TH0=0xFC;
	T0Count1++;
	if(T0Count1>=20){
		T0Count1=0;
		Key_Loop();
	}	
	T0Count2++;	
	//T0Count2++;
	//if(T0Count2>=2){
	//	T0Count2=0;
	//	Nixie_Loop();
	//}	
	//T0Count3++;
	//if(T0Count3>=10){
	//	T0Count3=0;
	//	Sec_Loop();
	//}
}