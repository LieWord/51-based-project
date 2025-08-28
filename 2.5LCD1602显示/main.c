#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
int a=0;

void main(){
	LCD_Init();
	LCD_ShowString(1,1,"Running time is:");
	LCD_ShowChar(2,9,'s');
	while(1){
		a++;
		Delay(1000);
		LCD_ShowNum(2,1,a,8);
	}
}