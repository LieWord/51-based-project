#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"

void main(){
	LCD_Init();
	LCD_ShowChar(2,5,'A');
	LCD_ShowString(1,3,"Holle");
	LCD_ShowNum(1,9,66,3);
	LCD_ShowSignedNum(1,13,-86,2);
	LCD_ShowHexNum(2,1,0xA5,2);
	LCD_ShowBinNum(2,7,0xA5,8);
	LCD_ShowChar(2,4,0xDF);
	LCD_ShowString(1,16,"Holle");
	while(1){
		LCD_WriteCommand(0x18);
		Delay(50);
	}
}