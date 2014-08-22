#ifndef __LCD_H__
#define __LCD_H__
#include"define.h"
void delay(uint ms);
void write_com(uchar com);
void write_dat(uchar dat);
void write_time(uchar add,uchar dat,uchar mode);//4 7 10
void write_week(uchar dat);
void init();
#endif