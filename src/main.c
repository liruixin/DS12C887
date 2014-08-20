#include<reg52.h>
#define LCD P0
#define uchar unsigned char 
#define uint unsigned int
sbit dula=P2^6;
sbit wela=P2^7;
sbit en=P3^4;
sbit rs=P3^5;
sbit rw=P3^6;
uchar code table[]={"1234567890"};
void delay(uint ms);
void write_com(uchar com);
void write_dat(uchar dat);
uchar read_dat();
void init();
void main()
{
    uchar i,temp=0;
    init();
    while(1)
  {
     for(i=0;i<10;i++)
	 {
	    write_dat(table[i]);
	 }
	 while(1);
  } 
}
void delay(uint ms)
{
   uint x,y;
   for(x=ms;x>0;x--)
      for(y=123;y>0;y--);
}
void write_com(uchar com)
{
   rs=0;
   rw=0;
   LCD=com;
   delay(3);
   en=1; delay(3);en=0;
}
void write_dat(uchar dat)
{
   rs=1;
   rw=0;
   LCD=dat;
   delay(3);
   en=1;delay(3);en=0;
}
void init()
{
   dula=0;wela=0;en=0;
   write_com(0x38);
   write_com(0x0f);
   write_com(0x06);
   write_com(0x80);
}
