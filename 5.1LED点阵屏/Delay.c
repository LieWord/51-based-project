#include <REGX52.H>
#include <INTRINS.H>

void Delay(unsigned int xms)		//@12.000MHz
{
	while(xms){
		/*
		unsigned char i, j;
		i = 12;
		j = 169;
		do
		{
			while (--j);
		} while (--i);
		*/
		unsigned char i, j;

		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}


