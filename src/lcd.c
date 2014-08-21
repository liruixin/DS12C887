#include"lcd.h"
uchar code sha[]={"2014-7-07-Monday"};
uchar code xia[]={"    12:23:45    "};
void delay(uint ms)//延时
{
   uint x,y;
   for(x=ms;x>0;x--)
      for(y=123;y>0;y--);
}
void init()			 //初始化
{
   uchar i;
   dula=0;wela=0;en=0;
   write_com(0x38);
   write_com(0x0c);
   write_com(0x06);
   write_com(0x80);

   for(i=0;i<16;i++)
	 {
	    write_dat(sha[i]);
	 }
	 write_com(0x80+0x40);
	 for(i=0;i<16;i++)
	 {
	    write_dat(xia[i]);
	 }
}
void write_com(uchar com)//写命令
{
   rs=0;
   rw=0;
   LCD=com;
   delay(3);
   en=1; delay(3);en=0;
}
void write_dat(uchar dat)//写数据
{
   rs=1;
   rw=0;
   LCD=dat;
   delay(3);
   en=1;delay(3);en=0;
}
void write_sfm(uchar add,uchar dat)//4,7,10
{
   uchar shi,ge;
   shi=dat/10;
   ge=dat%10;
   write_com(0x80+0x40+add);
   write_dat(48+shi);
   write_dat(48+ge);
}
