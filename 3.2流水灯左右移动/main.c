#include <REGX52.H>
#include "Delay.h"
unsigned int Count=1;

void main(){
	P2=0xFE;
	while(1){
			if(P2==0xFE){
				P2=~(~P2<<1);
				Delay(200);
				Count=1;
			}
			if(P2==0x7F){
				P2=~(~P2>>1);
				Delay(200);
				Count=0;
			}
			if(Count==1){
				P2=~(~P2<<1);
				Delay(200);
			}
			if(Count==0){
				P2=~(~P2>>1);
				Delay(200);
			}	
	}
}