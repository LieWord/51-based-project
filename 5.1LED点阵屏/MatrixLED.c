#include <REGX52.H>
#include <Delay.h>
#include <MatrixLED.h>
#define MATRIX_LED P0
sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SER=P3^4;

void __74HC595_WriteByte(unsigned char Byte){
	unsigned char i;
	for(i=0;i<8;i++){
		SER=Byte&(0x80>>i);
		SCK=1;
		SCK=0;
	}
	RCK=1;
	RCK=0;
}

void MatrixLED_Init(){
	SCK=0;
	RCK=0;
}

void MatrixLED(unsigned char Column,Date){
	__74HC595_WriteByte(Date);
	MATRIX_LED=~(0x80>>Column);
	Delay(1);
	MATRIX_LED=0xFF;
}

