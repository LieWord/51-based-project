#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password;
unsigned int Count;
unsigned int RealPassword = 1234;

void main(){
	LCD_Init();	
	while(1){
		LCD_ShowString(1,1,"Password:");
		KeyNum=MatrixKey();
		if(KeyNum){
			if(KeyNum<=10){
				if(Count<4){
					Password*=10;
					Password+=KeyNum%10;
					Delay(20);
					Count++;				
					}
				LCD_ShowNum(2,1,Password,4);		
			}
			if(KeyNum==11){
				if(Password == RealPassword){
					LCD_ShowString(1,10,"CORRECT");
					Password=0;
					Count=0;
				}
				else{
					LCD_ShowString(1,10,"WRONG  ");					
					Password=0;
					Count=0;				
				}
				LCD_ShowNum(2,1,Password,4);						
			}
			if(KeyNum==12){
				Password=0;
				Count=0; 
				LCD_ShowNum(2,1,Password,4);						
			}

		}
	}
}
