#include"define.h"
#include"lcd.h"
#include"ds12.h"
#include"key.h"
uint flag_ds=0;
uint miao,fen,shi;
uint day,week,moth,year;
void main()
{
    
    init();
//	ds_fir_set();
    while(1)
  {    	
      if(flag_ds==0)
	  {
		miao=read_ds(0);
		fen=read_ds(2);
		shi=read_ds(4);
		week=read_ds(6);
		day=read_ds(7);
		moth=read_ds(8);
		year=read_ds(9);
		write_time(10,miao,2);
		write_time(7,fen,2);
		write_time(4,shi,2);
		write_week(week);
		write_time(9,day,1);
	    write_time(6,moth,1);
		write_time(3,year,1);
	  }
	  keyscan();
  } 
}
