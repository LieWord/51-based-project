#include <REGX52.H>


void Delay(unsigned int t)		//@12.000MHz
{
	unsigned char i, j;
	for(t;t>0;t--)
	{
	i = 12;
	j = 169;
	do
	{
		while (--j);
	} while (--i);
	}

}

/*
void Delay(unsigned int xms)
{
unsigned int t ;
	while(xms--)
		for(t=0;t<12000;t++);
}
*/

void main()
{

	P2 = 0xFE;
	while(1)
	{
				Delay(10);
				if(!P3_0)
				{
						Delay(20);
						while(P3_0)
						{
								if(!P2_7)
									{
										P2 = 0xFE;
									}
								else
									{
										P2 = ~(~P2 << 1);
									}	
							break;	
						}
						while(!P3_0)
						{
							if(!P2_7)
							{
								P2 = 0xFE;
								Delay(20);
							}
							else
							{
								P2 = ~(~P2 << 1);
								Delay(20);
							}							
						}


				}
				if(!P3_1)
				{
					Delay(20);
					while(P3_1)
					{
						if(!P2_0)
						{
							P2=0x7F;
						}
						else
						{
							P2=~(~P2 >> 1);
						}
						break;
					}
					while(!P3_1)
					{
							if(!P2_0)
							{
								P2=0x7F;
								Delay(20);
							}
							else
							{
								P2=~(~P2 >> 1);
								Delay(20);
							}					
					}
					
				}
			
	}
}