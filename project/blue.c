#include<lpc21xx.h>
#define LED1 1<<10
void uart0_config(void);
volatile unsigned char d;
void uart0_isr(void) __irq
{	int temp;
	d=U0RBR;
	temp=U0IIR;
	VICVectAddr=0;

}
unsigned char uart0_rx(void)
{	
	while((U0LSR&1)==1);
	return U0RBR;
}
int main()
{   	IODIR0=LED1;
	uart0_config();
	
	VICIntSelect|=1<<6;
	VICVectCntl0=(0x20)|6;
	VICVectAddr0=(unsigned long)uart0_isr;
	U0IER=(1<<0)|(1<<1);
	VICIntEnable|=1<<6;
	while(1)
	{
	if(d=='l')
	IOCLR0=LED1;
	else if(d=='n')
	IOSET0=LED1;
	
	}

}

void uart0_config(void)
{
	PINSEL0=0x5;
	U0LCR=0x83;
	U0DLL=97;
	U0DLM=0;
	U0LCR=0x3;
}