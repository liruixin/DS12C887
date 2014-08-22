#include"lcd.h"
uchar code sha[]={" 2000-00-00-XXX "};
uchar code xia[]={"    00:00:00    "};
uchar code wek[8][4]={{"XXX "},{"Mon "},{"Tues"},
{"Wed "},{"Thur"},{"Fri "},{"Sat "},{"Sun "}};
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
   delay(2);
   en=1; delay(3);en=0;
}
void write_dat(uchar dat)//写数据
{
   rs=1;
   rw=0;
   LCD=dat;
   delay(2);
   en=1;delay(3);en=0;
}
void write_time(uchar add,uchar dat,uchar mode)//4,7,10
{
   uchar shi,ge;
   shi=dat/10;
   ge=dat%10;
   if(mode==1) //first raw
   write_com(0x80+add);
   else if(mode==2)		//second raw
   write_com(0x80+0x40+add);
   write_dat(48+shi);
   write_dat(48+ge);
}
void write_week(uchar dat)
{
  uchar i;
  write_com(0x80+12);
  for(i=0;i<4;i++)
  { 
     write_dat(wek[dat][i]);
  }
}
