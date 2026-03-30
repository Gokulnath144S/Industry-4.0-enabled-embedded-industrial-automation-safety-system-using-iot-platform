
#ifndef _DEFINES_H
#define led 1<<14
#define led1 1<<15
#define led2 1<<16
#define led3 1<<17
#define in1 1<<18
#define buzzer 1<<19
#define in2 1<<20
 void spiinit(void);
 unsigned char spidata(unsigned char d);
 float adc(unsigned char ch);

 #endif