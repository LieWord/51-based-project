#include <REGX52.H>
#include "Delay.h"


unsigned char MatrixKey(){
	unsigned char MatrixNumber=0;
	
	P1=0xFF;
	P1_3=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);MatrixNumber=1;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);MatrixNumber=5;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);MatrixNumber=9;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);MatrixNumber=13;}
	
	P1=0xFF;
	P1_2=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);MatrixNumber=2;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);MatrixNumber=6;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);MatrixNumber=10;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);MatrixNumber=14;}
	
	P1=0xFF;
	P1_1=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);MatrixNumber=3;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);MatrixNumber=7;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);MatrixNumber=11;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);MatrixNumber=15;}

	P1=0xFF;
	P1_0=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);MatrixNumber=4;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);MatrixNumber=8;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);MatrixNumber=12;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);MatrixNumber=16;}

	return MatrixNumber;
}