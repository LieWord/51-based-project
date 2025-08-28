#include <REGX52.H>
#include <INTRINS.H>

void Delay1ms(unsigned int t)		//@12.000MHz
{
	unsigned char i, j;
while(t)
	{
		i = 12;
		j = 169;
		do
		{
			while (--j);
		} while (--i);
		t--;
	}

}


/*void main()
{
	while(1)
	{
	P2=0xFE;//1111 1110
	Delay1ms(50);
	P2=0xFD;//1111 1101
	Delay1ms(50);
	P2=0xFB;//1111 1011
	Delay1ms(50);
	P2=0xF7;//1111 0111
	Delay1ms(50);
	P2=0xEF;//1110 1111
	Delay1ms(50);
	P2=0xDF;//1101 1111
	Delay1ms(50);
	P2=0xBF;//1011 1111
	Delay1ms(50);
	P2=0x7F;//0111 1111
	Delay1ms(50);
	}
}*/


void 	LED()
{
	int i = 0;
	for(i=0;i<8;i++)
	{
	P2=~(0x01<<i);
	Delay1ms(25);
	}
}

void main()
{
while(1){
	LED();
}

}
