#include <REGX52.H>
unsigned char Tamp;

unsigned char IndeKey(){
	unsigned char T_Tamp=Tamp; 
	Tamp=0;
	return T_Tamp;
}



unsigned char Key_Gate(){
	unsigned char IndeKeyNumber=0;
	
	if(P3_1==0){IndeKeyNumber=1;}
	if(P3_0==0){IndeKeyNumber=2;}
	if(P3_2==0){IndeKeyNumber=3;}
	if(P3_3==0){IndeKeyNumber=4;}

	return IndeKeyNumber;
}

void Key_Loop(){
	static unsigned char NowStata,LastStata;
	LastStata=NowStata;
	NowStata=Key_Gate();
	if(NowStata==0 && LastStata==1){
		Tamp=1;
	}	
	if(NowStata==0 && LastStata==2){
		Tamp=2;
	}	
	if(NowStata==0 && LastStata==3){
		Tamp=3;
	}	
	if(NowStata==0 && LastStata==4){
		Tamp=4;
	}
	
}