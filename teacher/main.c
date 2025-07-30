#include "head.h"
int main_a=100;//全局变量
static int main_b=200;//全局变量  但是它是一个静态的
void ceshi(void)
{
    printf("测试函数_main_b:%d\n",main_b);
}
int main(int argc, char const *argv[])
{
    printf("main_a:%d main_b:%d\n",main_a,main_b);
    funca();//当前这个函数实现在a.c文件中
    ceshi();
  //  funcb();//这个函数不能在这调用 因为它是一个静态函数  
   funca();
    funca();
    return 0;
}
