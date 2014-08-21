#ifndef __LCD_H__
#define __LCD_H__
#include"define.h"
void delay(uint ms);
void write_com(uchar com);
void write_dat(uchar dat);
void write_sfm(uchar add,uchar dat);//4 7 10
void init();
#endif