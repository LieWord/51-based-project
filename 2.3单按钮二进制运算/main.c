#include <REGX52.H>

void Delay(unsigned int xms)		//@12.000MHz
{
	
	while(xms)
	{
		unsigned char i, j;

		i = 12;
		j = 169;
		do
		{
			while (--j);
		} while (--i);	
	xms--;
	}

}

void main(){
	unsigned char t=0;
	while(1){
		if(!P3_1){
			Delay(20);
			while(!P3_1);
			t++;
			P2=~t;
		}
	}
}