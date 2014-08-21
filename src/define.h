#ifndef __DEFINE_H__
#define __DEFINE_H__
#include<reg52.h>
#define LCD P0
#define uchar unsigned char 
#define uint unsigned int
sbit dula=P2^6;
sbit wela=P2^7;
sbit en=P3^4;
sbit rs=P3^5;
sbit rw=P3^6;
sbit dscs=P1^4;
sbit dsas=P1^5;
sbit dsrw=P1^6;
sbit dsds=P1^7;
#endif