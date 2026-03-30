#define LED 0xf<<8
#define RS 1<<12
#define E 1<<13
void LCD_INIT(void);
void LCD_CMD(unsigned char);
void LCD_DATA(unsigned char);
void delay(int );
void LCD_STRING(unsigned char *s);
void LCD_INT(int n);
void LCD_float(float f);


void LCD_INIT(void)
{IODIR0|=LED|RS|E;
LCD_CMD(0x01);
LCD_CMD(0x02);
LCD_CMD(0x0c);
LCD_CMD(0x28);


}
void LCD_CMD(unsigned char cmd)
{IOCLR0=LED;
IOSET0=((cmd>>4)&0x0f)<<8;
IOCLR0=RS;
IOSET0=E;
delay(2);
IOCLR0=E;

IOCLR0=LED;
IOSET0=(cmd&0x0f)<<8;
IOCLR0=RS;
IOSET0=E;
delay(2);
IOCLR0=E;
}
void LCD_DATA(unsigned char d)
{IOCLR0=LED;
IOSET0=((d>>4)&0x0f)<<8;
IOSET0=RS;
IOSET0=E;
delay(2);
IOCLR0=E;

IOCLR0=LED;
IOSET0=(d&0x0f)<<8;
IOSET0=RS;
IOSET0=E;
delay(2);
IOCLR0=E;
}

void delay(int s)
{T0PR=15000-1;
T0TCR=0x01;
 while(T0TC<s);
T0TCR=0x03;
T0TCR=0x00;
}
void LCD_STRING(unsigned char *s)
{ int count=0;
  while(*s)
   {	
   		LCD_DATA(*s++);
   		count++;
		if(count==16)
	       LCD_CMD(0xc0);
}}	  

void LCD_INT(int n)
{	unsigned char a[5];
	signed char i=0;
	if(n==0)
	{	
		LCD_DATA('0');
	}
	else
	{   if(n<0)
	      {	  	
		LCD_DATA('-');
		n=-n;
	      }
            
	  while(n>0)
	      {	 	
	  		a[i++]=n%10;
			n=n/10;
	  	}
     }
	 for(--i;i>=0;i--)
	  LCD_DATA(a[i]+48);
}

void LCD_float(float f)
{	int s;
 	int x;
	x=f;
	LCD_INT(x);
	LCD_DATA('.');
	s=(f-x)*10;
	LCD_INT(s);
	}

