#include"define.h"
#include"lcd.h"
#include"ds12.h"
void main()
{
    uchar miao=13;
    init();
	ds_fir_set();
    while(1)
  {
     	write_sfm(10,miao);
		miao=read_ds(0);
  } 
}
