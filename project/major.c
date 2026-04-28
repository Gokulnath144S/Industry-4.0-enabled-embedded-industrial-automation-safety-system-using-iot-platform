#include<lpc21xx.h>
#include"defines.h"
#include "lcdheader.h"

volatile int flag =0;
volatile unsigned char ch=0;
void uartinit(void);
unsigned char uartrx(void);
void timerinit(void);
void delays(int s)
{
T0PR=15000000-1;
T0TCR=0x01;
 while(T0TC<s);
T0TCR=0x03;
T0TCR=0x00;
}

void uart_isr(void) __irq
{
 	int temp;
	temp=U0IIR&0x0e;
	if(temp==0x04)
			 ch=U0RBR;
	  
	  VICVectAddr=0;
}
void timer_isr(void) __irq
{	 
	  flag=1;
	 T1IR=0x1;
//	 if(flag==0)
//	{
//	IOCLR0=led5;

//	}
	 VICVectAddr=0;

}
int main()
{	
	float f,temp;
	IODIR0|=led|led1|led2|led3|in1|in2|buzzer;
	IOSET0|=led|led1|led2|led3|in2|in1|buzzer;
	LCD_INIT();
	//LCD_DATA('a');
	LCD_STRING("INDUSTRIAL AUTOMATION 4.0 USING IOT CLOUD");
	//for(i=0;i<120000;i++)
	//for(j=0;j<200;j++);
	delay(3000);
	LCD_CMD(0x01);
 	uartinit();
	timerinit();
//	enableIRQ();
	spiinit();

	while(1)
	{	
	 if(flag==1)
		{	flag=0;
			//IOCLR0=led5;
			//LCD_CMD(0x01);
			LCD_CMD(0xc0);
			LCD_STRING("temp monitor"); 
 			f=adc(1);
				temp=f/0.01;

			LCD_CMD(0xcf);
			LCD_float(temp);
								
		  	if(temp<30.0f)
				{IOSET0=buzzer;
			
				}
			else
				IOCLR0=buzzer;
				}
		
	LCD_CMD(0x80);
	LCD_STRING("uart:");
		//ch=uartrx();
	LCD_DATA(ch);
	 switch(ch)
	 {	case 'c':IOCLR0=led;
			 	break;
	  	
	  	case 'd':IOSET0=led;
				break;
		 case 'a':IOCLR0=led1;
			break;
		case 'b':IOSET0=led1;
				break;
		case 'e':IOCLR0=led2;
				break;
		case 'f':IOSET0=led2;
				break; 
		case 'g':IOCLR0=led3;
				break;
		case 'h':IOSET0=led3;
				break;
	  }
	  

	}

}

 void timerinit(void)
 {
  	T1MR0=15000000-1;
	T1MCR=0x03;
	VICIntSelect&=~(1<<5);
	VICVectCntl1=(0x20)|5;
	
	VICVectAddr1=(unsigned long)timer_isr;
	VICIntEnable|=1<<5;
		T1TCR=0x1;
 }

void uartinit(void)
{
 	PINSEL0|=0x5;
	U0LCR=0x83;
	U0DLL=97;
	U0DLM=0;
	U0LCR=0x3;
   VICIntSelect&=~(1<<6);
   VICVectCntl0=(0x20)|6;
   VICVectAddr0=(unsigned long)uart_isr;
   U0IER=1<<0;
   VICIntEnable|=1<<6;

}
unsigned char uartrx(void)
{
 while((U0LSR&1)==0);
 return U0RBR;

}

