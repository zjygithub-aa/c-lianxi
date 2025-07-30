/**
 * 指针
 * 1.概念：
 *      指针就是地址，地址就是指针（通常的说法）----》类型有要求的
 * 2.指针变量的定义
 *      数据类型   * 指针变量名；
 *      举例：int *p;  //当前这一行里面   符号* 是一个指针说明符，说明p是一个指针类型的变量 
 *      同类型的指针指向相同类型的数据的地址
 *      举例：int a=10;int *P=&a;//p指向了a的地址  或者说 P里面存的是a的地址
 *      注意：int a=10,*p;  *p=&a;//这么写是错误的  如果在定义的时候没有初始化指向  后续只能写作  p=&a;
 *            int *p=0x1000;//是错误的  ！！！！
 *            int *p=(int *)(0x1000);//可以这么写但不要轻易这么写  因为对这一个数据编号是不确定的 除非知道该编号对应地址
 * 
 * 3.   指针变量的应用
 *          若有：int a=10;int *P=&a;
 *          *p:在这里 符号*  是一个取值运算符（指针运算符） 访问的是P所指向 那段空间的值（a）
 *          *P=100;//等价于  a=100;
 *             
 * 4.指针作为函数的参数
 * 5.野指针  没有指向的指针，     是一个很危险的指针 ，如果对该指针进行操作会非常危险
 * 6.空指针  指针变量指向为NULL  就是空指针 ，目的为了防止野指针   int *p=NULL;
 * 7.指针与一维数组
 *          int num[5]={10,20,30,40,50};
 *          int *p=num;//为什么 这里不是  &num    因为数组名就是首地址（&num[0]）   等价于 p指向 num[0]的地址
 *         指针变量允许 做加减运算的 若执行p++;  表示p=p+1,此时p将指向 下一个元素的地址 
 *          在指针运算中 p++.移动的字节数与 当前指针变量的数据类型有关 ，如果是char类型，则执行p++时，移动的是一个字节，如果是int类型则是移动4个字节
 *      在一维数组中  num+i  就是  &num[i]  若有p指向num,p+i就是 &num[i]  ,*(p+i)就是  num[i] ,*(num+i)就是num[i]  但要注意的是p可以执行p++的操作 而num不可以
 *      理清楚  ：p++;++p; *++p; ++*p; *p++;(*p)++;  
 * 8.指针与字符数组以及字符串(常量)
 *          
*/
#include<stdio.h>
#include <string.h>
//1.指针与变量、
void pointer1(void);
void swap1(int c,int d);
void swap2(int *c,int *d);
void swap3(int *c,int *d);
void swap4(int *c,int *d);
//2.指针与数组
void pointer2(void);
void change_num(int *p);//通过指针修改数组的数据
void fanxu_num(int *p,int len);//通过指针的方式 实现数组的反序
//关于数据存储  小端存储
void memory(void);
//3.指针与字符串
void pointer3(void);
int main(int argc, char const *argv[])
{
//    pointer1();//指针与变量
    //pointer2();//指针与数组
 //memory();
 pointer3();//指针与字符串
    
    return 0;
}

//1.指针与变量、
void pointer1(void)
{
    int a=10,b=20;//  a b两个存整数的整型变量
    int *p=&a,*q=&b;// p 1两个存整型变量的地址 的变量
    printf("p:%p &a:%p\n q:%p &b:%p\n",p,&a,q,&b);
    printf("*p:%d a:%d  *q:%d  b:%d\n",*p,a,*q,b);
     swap1(a,b);
     printf("swap1：*p:%d a:%d  *q:%d  b:%d\n",*p,a,*q,b);
     swap2(&a,&b);//如果传的是p 和 q呢 ？？是否可以修改 a b的值  可以   因为 p q的值 就是 &a &b
     printf("swap2：*p:%d a:%d  *q:%d  b:%d\n",*p,a,*q,b);
    // swap3(&a,&b);
    swap3(p,q);//指针作为函数的参数 进行传递
    printf("p:%p 1:%p\n",p,q);
      printf("swap3：*p:%d a:%d  *q:%d  b:%d\n",*p,a,*q,b);
    swap4(&a,&b);
    printf("swap4：*p:%d a:%d  *q:%d  b:%d\n",*p,a,*q,b);
    
}

//c  d 进行值传递  只是 实参值拷贝版 修改  c  d的值 不会影响实参
//该函数 修改的是 c d的值 改的是函数
void swap1(int c,int d)
{
    int t=c;
    c=d;
    d=t;
}
// c 指向了 实参a的地址 d指向了实参b的地址  修改 *c  *d 实际修改的是 实参a  b
//该函数 修改的函数外 传过来的  a b的值
void swap2(int *c,int *d)  //形参是一个指针类型
{
    int t=*c;
    *c=*d;
    *d=t;
}
//c指向 实参a的地址 d指向了实参b的地址   该程序修改的是c  d的指向
//该函数 修改的函数内部  c  d的指向 
void swap3(int *c,int *d)
{
    int *t=c;
    c=d;
    d=t;
}
//该函数  有问题  不论t是空指针 还是野指针 都不允许这么操作
void swap4(int *c,int *d)
{
    printf("1");
    int *t;//=NULL; 
      printf("2");
    *t=*c;//非法操作  t是一个野指针
      printf("3");
    *c=*d;
      printf("4");
    *d=*t;
      printf("5");
}

//2.指针与数组
void pointer2(void)
{
    int num[5]={10,20,30,40,50};
    change_num(num);//修改数组中的值
     printf("反序前数组num的值\n");
    for(int i=0;i<5;i++)
    {
        printf("%d -",num[i]);
    }
    printf("\n");
    fanxu_num(num,5);
    printf("反序后数组num的值\n");
    for(int i=0;i<5;i++)
    {
        printf("%d -",num[i]);
    }
    printf("\n");

}
//通过指针修改数组的数据
void change_num(int *p)//int p[]
{
    //实际上 这里的p也可以当作数组名来使用
    int i;
    // for(i=0;i<5;i++)
    // {
    //     printf("%d\t",p[i]);
    // }
    // printf("\n");
    // p[3]=100;//通过p来修改 数组内的值
    //*p就是 num[0]
    // *p++;//先进行 p++,然后执行*p  执行完以后 此时p指向num[1]
    // *p=200;
    // *++p;//执行完以后 此时p指向num[2]
    // *p=300;
    // *(p++);//执行完以后 此时p指向num[3] 
    // *p=400;
    // (*p)++;//执行完以后 此时p指向num[3]  *p的值+1
    // ++(*p);
    printf("通过*p来修改num数组中的数值\n");
    int *q=p;
    for(q=p;q<p+5;q++)
    {
        *q*=10;
    }

}
//通过指针的方式 实现数组的反序
void fanxu_num(int *p,int len)
{
    int *q=p+len-1;//q指向 数组最后一个元素所在地址
    for(;p<q;p++,q--)//移动的是指针
    {
        int t=*p;
        *p=*q;
        *q=t;
    }
}

//关于数据存储  小端存储
void memory(void)
{
    int num=0x01020304;
    char *p=(char *)(&num);//将num的地址类型 强制转换为 char* 类型
    for(int i=0;i<4;i++)
    {
        printf("%p:%x\t",p,*p);
        p++;
    }
}

//指针与字符串
void pointer3(void)
{
    //自定义一个字符串复制的函数 (指针方式)
    char *mystrcpy(char *s1,char *s2);
    int mystrcmp(char *s1,char *s2);
    char s1[10]={"hello"};
    char *p="hello";//p 指向了字符串常量"hello"的首地址
    printf("p[3]:%c\n",p[3]);
   // p[3]='L';    //不可以指向该语句  因为 hello是一个常量 ，常量是不允许修改的
    printf("p:%s\n",p);
    //s1="world";  不可以这么写  因为在C语言中 字符数组不允许进行字符串赋值 ，除非使用strcpy函数
    p="world";//p 更改了指向  指向了 "world"的首地址
    //测试以下 strcpy函数 返回的指针
    p=strcpy(s1,"abcd");
    printf("p:%p  s1:%p\n",p,s1);
    char *q=mystrcpy(s1,"abcd");
    printf("q:%p  s1:%p\n",q,s1);
    printf("s1:%s  p:%s  q:%s\n",s1,p,q);
    int n=strcmp("HELLO",s1);
    int m=mystrcmp("HELLO",s1);
    printf("m:%d  n:%d\n",m,n);
}

//自定义一个字符串复制的函数 (指针方式)
char *mystrcpy(char *s1,char *s2)
{
    char *t=s1;//保存住 s1里面所存的地址
    while (*s2)//不为'\0'  一直循环 将s2的各个字符 复制给 s1
    {
        *s1=*s2;
        s1++;
        s2++;
    }
    return t;
    
}
//自定义字符串比较函数  比的是ascii码值  如果相对应的位置的ascii不相等则结束比较
int mystrcmp(char *s1,char *s2)
{
    while(*s1==*s2 && *s1!='\0' && *s2!='\0')//如果 相同的序列号对应的字符相等并且两个指针所指向的元素值不为'\0' 则继续循环 往后判断
    {
        s1++;
        s2++;
    }
  //   return *s1-*s2;//如果相等  此时 *s1和*s2都为'\0'  
    if(*s1==*s2)
    return 0;
    else if(*s1>*s2)
    return 1;
    else 
     return -1;
}