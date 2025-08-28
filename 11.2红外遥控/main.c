#include <REGX52.H>
#include "IR.h"
#include "MOTOR.h"
#include "Nixie.h"

unsigned char Address;
unsigned char Command;
unsigned char pare;

void main()
{
	Motor_Init();
	IR_Init();
	while(1)
	{
		if(IR_GetDataFlag() || IR_GetRepeatFlag())
		{
			Address=IR_GetAddress();
			Command=IR_GetCommand();
			if(Command==IR_VOL_MINUS)		
				{
					pare--;	
					Motor_SetSpeed(pare);		
				}
				if(Command==IR_VOL_ADD)			
				{
					pare++;
					Motor_SetSpeed(pare);					
				}
		}
		Nixie(1,pare);	
	}
}


