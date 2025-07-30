#ifndef _HEAD_H  //如果没有定义_HEAD_H
#define _HEAD_H //那就定义_HEAD_H

#include<stdio.h>
extern int main_a;//外部声明可以被声明多次，但是外部声明不能进行赋值，初始化赋值只能有一次
void ceshi(void);
void funca(void);
static void funcb(void);
#endif//结束定义