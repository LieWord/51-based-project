#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "IndeKey.h"
#include "Timer0_Init.h"
#include "Delay.h"

unsigned char KeyNum,mode,sele,TSFF;

void TimeShow(){
		DS1302_ReadTime();
		LCD_ShowNum(1,1,DS1302_Time[0],2);
		LCD_ShowNum(1,4,DS1302_Time[1],2);
		LCD_ShowNum(1,7,DS1302_Time[2],2);
		LCD_ShowNum(2,1,DS1302_Time[3],2);
		LCD_ShowNum(2,4,DS1302_Time[4],2);
		LCD_ShowNum(2,7,DS1302_Time[5],2);
}

void TimeSet(){
	if(KeyNum==2){
		sele++;
		sele%=6;
	}
	//…Ë÷√º”
	if(KeyNum==3){
		DS1302_Time[sele]++;
		if(DS1302_Time[0]>99){DS1302_Time[0]=0;}
		if(DS1302_Time[1]>12){DS1302_Time[1]=1;}
		if(DS1302_Time[1]==1 || DS1302_Time[1]==3 || DS1302_Time[1]==5 || DS1302_Time[1]==7 || DS1302_Time[1]==8 || DS1302_Time[1]==10 || DS1302_Time[1]==12){
		   	if(DS1302_Time[2]>31){DS1302_Time[2]=1;}
		}
		else if(DS1302_Time[1]==4 || DS1302_Time[1]==6 || DS1302_Time[1]==9 || DS1302_Time[1]==11){
			if(DS1302_Time[2]>30){DS1302_Time[2]=1;}
		}
		else if(DS1302_Time[1]==2){
			if(DS1302_Time[0]%4==0){
				if(DS1302_Time[2]>29){DS1302_Time[2]=1;}
			}
			else{
				if(DS1302_Time[2]>28){DS1302_Time[2]=1;}
			}
		}
		if(DS1302_Time[3]>23){DS1302_Time[3]=0;}
		if(DS1302_Time[4]>59){DS1302_Time[4]=0;}
		if(DS1302_Time[5]>59){DS1302_Time[5]=0;}
	}
	//…Ë÷√ºı
	if(KeyNum==4){
		DS1302_Time[sele]--;
		if(DS1302_Time[0]<0){DS1302_Time[0]=99;}
		if(DS1302_Time[1]<1){DS1302_Time[1]=12;}
		if(DS1302_Time[1]==1 || DS1302_Time[1]==3 || DS1302_Time[1]==5 || DS1302_Time[1]==7 || DS1302_Time[1]==8 || DS1302_Time[1]==10 || DS1302_Time[1]==12){
		   	if(DS1302_Time[2]<1){DS1302_Time[2]=31;}
		}
		else if(DS1302_Time[1]==4 || DS1302_Time[1]==6 || DS1302_Time[1]==9 || DS1302_Time[1]==11){
			if(DS1302_Time[2]<1){DS1302_Time[2]=30;}
		}
		else if(DS1302_Time[1]==2){
			if(DS1302_Time[0]%4==0){
				if(DS1302_Time[2]<1){DS1302_Time[2]=29;}
			}
			else{
				if(DS1302_Time[2]<1){DS1302_Time[2]=28;}
			}
		}
		if(DS1302_Time[3]<0){DS1302_Time[3]=23;}
		if(DS1302_Time[4]<0){DS1302_Time[4]=59;}
		if(DS1302_Time[5]<0){DS1302_Time[5]=59;}
	}
	if(sele==0 && TSFF==1){LCD_ShowString(1,1,"  ");}
	else{LCD_ShowNum(1,1,DS1302_Time[0],2);}
	if(sele==1 && TSFF==1){LCD_ShowString(1,4,"  ");}
	else{LCD_ShowNum(1,4,DS1302_Time[1],2);}
	if(sele==2 && TSFF==1){LCD_ShowString(1,7,"  ");}
	else{LCD_ShowNum(1,7,DS1302_Time[2],2);}
	if(sele==3 && TSFF==1){LCD_ShowString(2,1,"  ");}
	else{LCD_ShowNum(2,1,DS1302_Time[3],2);}
	if(sele==4 && TSFF==1){LCD_ShowString(2,4,"  ");}
	else{LCD_ShowNum(2,4,DS1302_Time[4],2);}
	if(sele==5 && TSFF==1){LCD_ShowString(2,7,"  ");}
	else{LCD_ShowNum(2,7,DS1302_Time[5],2);}
	/*
	LCD_ShowNum(1,4,DS1302_Time[1],2);
	LCD_ShowNum(1,7,DS1302_Time[2],2);
	LCD_ShowNum(2,1,DS1302_Time[3],2);
	LCD_ShowNum(2,4,DS1302_Time[4],2);
	LCD_ShowNum(2,7,DS1302_Time[5],2);
	*/
}

void main(){
	LCD_Init();
	DS1302_Init();
	Timer0_Init();
	LCD_ShowString(1,1,"  -  -  ");
	LCD_ShowString(2,1,"  :  :  ");
	DS1302_SetTime();
	
	while(1){
		KeyNum=IndeKey();
		if(KeyNum==1){
			if(mode==1){mode=0;DS1302_SetTime();}
			else if(mode==0){mode=1;}
		}	
		switch(mode){
			case 0:TimeShow();break;
			case 1:TimeSet();break;		
		}
	}
}

void Timer0_Routine() interrupt 1{
	static unsigned int T0Count;
	TL0=0x18;
	TH0=0xFC;
	T0Count++;
	if(T0Count>=500){
		T0Count=0;
		TSFF=!TSFF;
	}
}