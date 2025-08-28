#include <REGX52.H>
#include "IndeKey.h"
#include "Delay.h"
#include "Nixie.h"
#include "Buzzer.h"
#include "MatrixKey.h"
#include "Timer0_Init.h"
#define SPEED 250
unsigned char KeyNum,FreqSelet=0,MSelet=0;
unsigned int i,m;
unsigned int Freq[]={
	0,
	63628,63731,63835,63928,64021,64185,64260,64331,64400,64463,64528,
	64580,64633,64684,64777,64820,64860,64898,64934,64968,65000,65035,
	65058,65085,65110,65134,65157,65178,65198,65217,65235,65268,65283,
};
unsigned char Mus[]={
13,4,
13,4,
20,4,
20,4,
22,4,
22,4,
20,4+4,
0,4,
18,4,
18,4,
17,4,
17,4,
15,4,
15,4,
13,4+4,
0xFF
};




void main(){
	Timer0_Init();
	while(1){
		if(Mus[MSelet]!=0xFF){
			FreqSelet=Mus[MSelet];
			MSelet++;
			Delay(SPEED/4*Mus[MSelet]);
			MSelet++;		
			TR0=0;
			Delay(5);
			TR0=1;	
		}
		else{
					TR0=0;

		}
	}
}

void Timer0_Routine() interrupt 1{
	if(Freq[FreqSelet]){
	TL0=Freq[FreqSelet]%256;
	TH0=Freq[FreqSelet]/256;
	Buzzer=!Buzzer;	
	}

}