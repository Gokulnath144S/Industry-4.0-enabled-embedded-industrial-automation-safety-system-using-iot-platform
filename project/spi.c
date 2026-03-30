#include<lpc21xx.h>
#include"defines.h"

void spiinit(void)
{
 	PINSEL0|=0x1500;
	S0SPCCR=150;
	S0SPCR=(1<<5)|0x00;
	S0SPSR=1<<7;
	IODIR0|=1<<7;
	IOSET0|=1<<7;

}

unsigned char spidata(unsigned char d)
{
 	unsigned char stat;
	stat=S0SPSR;
	S0SPDR=d;
	while(((S0SPSR>>7)&1)==0);
	return S0SPDR;

}

float adc(unsigned char ch)
{
 	unsigned char hbyte,lbyte;
	unsigned int val;
	float f;
	IOCLR0|=1<<7;
	 spidata(0x06);
	 hbyte=spidata(ch<<6);
	 lbyte=spidata(0x00);
	 IOSET0|=1<<7;
	   val=((hbyte&0x0f)<<8)|lbyte;
	   f=val*3.3/4096;
	   return f;

}
