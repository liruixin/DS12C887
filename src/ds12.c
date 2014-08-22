#include"ds12.h"
void write_ds(uchar add,uchar dat)
{
   dscs=0;
   dsas=1;
   dsds=1;
   dsrw=1;
   P0=add;
   dsas=0;
   dsrw=0;
   P0=dat;
   dsrw=1;
   dsas=1;
   dscs=1;
}
uchar read_ds(uchar add)
{
   uchar ds_data;
   dsas=1;
   dsds=1;
   dsrw=1;
   dscs=0;
   P0=add;
   dsas=0;
   dsds=0;
   P0=0xff;
   ds_data=P0;
   dsds=1;
   dsas=1;
   dscs=1;
   return ds_data;
}
void ds_fir_set()
{
   write_ds(0,50);  //sec
   write_ds(1,0);
   write_ds(2,59);//min
   write_ds(3,0);
   write_ds(4,17);//hour
   write_ds(5,0);
   write_ds(6,4);  //week
   write_ds(7,21); //day
   write_ds(8,8); //moth
   write_ds(9,14); //year
 //  write_ds(0x0a,0x20) ;first_time_only
 //  write_ds(0x0b,0x26); first_time_only
}