#include <REGX52.H>
#include "Delay.h"

unsigned char IndeKey(){
	unsigned char IndeKeyNumber=0;
	if(P3_1==0){Delay(20);while(P3_1==0);Delay(20);IndeKeyNumber=1;}
	if(P3_0==0){Delay(20);while(P3_0==0);Delay(20);IndeKeyNumber=2;}
	if(P3_2==0){Delay(20);while(P3_2==0);Delay(20);IndeKeyNumber=3;}
	if(P3_3==0){Delay(20);while(P3_3==0);Delay(20);IndeKeyNumber=4;}

	return IndeKeyNumber;
}