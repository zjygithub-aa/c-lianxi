/**
 * 1.常量指针
 *      const int *p;
 *      int const *p;
 *      本质上是一个指针，修饰的指针指向的内存的值为常量，  指针的指向可以修改，但是值不能修改
 * 2.指针常量
 *      int *const p;
 *      本质上是一个常量，修饰的指针为常量，指针所指向的内存的值可以修改，但不可以修改指向
 *   巧记：const在*号之前表示是一个常量指针，修饰的是值为常量 const在*后，表示是一个指针常量，修饰的是指针为常量
 * 3.字符串操作函数  strstr   strtok
 * 4. 主函数的参数
 *      int argc：用户终端传递过来的命令的条数
 *      char const *argv[]：是一个常量指针数组，用来接收终端输入的参数(命令）
 *      作用：为了方便用户与程序的一个交互
 * 5.万能指针
 *      void *类型指针 ，可以转换为任何类型
 *      - void *指针可以指向任意变量的内存空间
 * 6.内存布局
 *      栈区(地址向下增长): 局部变量、函数、返回值等
 *      堆区：  用户动态申请的内存
 *      全局区：data区：全局/静态变量已初始化    bss区：全局/静态变量未初始化的  
 *              字符常量区：字符串
 *      代码区：程序生成的二进制代码
 *   注意：地址编号大小  不等于  地址的高低  ，因为每个区域的编号是不一样
 * 7.动态分配  #include <stdlib.h>
 *      向堆区申请内存
 *      malloc：对内存中的数据不一定进行初始化赋值为0
 *      realloc：扩容
 *      calloc:对内存中的数据进行初始化赋值为0
 *      释放
 *       free
 *     内存管理
 *      memset
 *      memcpy
 *      memcmp
 * 7.函数指针数组
 *      数据类型 (*数组名[])(参数类型列表)；
 *      int (*f_pNum[3])(int ,int);
 *       本质上是一个数组，每一个元素都是一个函数指针里面存的是函数的地址
 *      主要用于状态机实现、命令处理器、回调函数表等


 *      
*/

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
//1.常量指针与指针常量
void pointer1(void);
//2.万能指针
void pointer2(void);
//3.函数指针数组
void pointer3(void);
int main(int argc, char const *argv[])
{

  
    // int i;
    // for(i=0;i<argc;i++)
    // {
    //     printf("%s\n",argv[i]);
    // }
   pointer3();
 
    return 0;
}

//1.常量指针与指针常量

void pointer1(void)
{
    int a=10,b=20;
    const int *p=&a;//定义一个常量指针p  p指向了a的地址
    int const *q=&a;
    p=&b;  //常量指针本质上是一个指针，修饰的是指着指向空间的值不能被修改  指着可以修改指向
   // *p=100;  不可以这么写
   q=&b;
  // *q=200;不可以这么写
    int * const k=&a; //指针常量不可以修改指向 可以修改值
   // k=&b;不可以这么写
    *k=200;
    printf("a:%d b:%d\n",a,b);
    //调用字符串操作函数  在字符串中查找子串
    char *findpos=strstr("Hello world hello","ello");//findpos接收 在字符串中找到第一次出现子串的地址
    printf("findpos:%p %p\n",findpos,"Hello world hello");
    printf("%s\n",findpos);//输出从起始位置 输出这一串字符

    //字符串分割
    char dest[100]={"this is my book,it is English-book"};
    char *delim={" ,-"};
    char *tokstr;//接收分割出来的字符串
    printf("字符串分割\n");
    tokstr=strtok(dest,delim);
   
    //如果想要继续往后进行分割  第一个参数只能传NULL  如果已经没有可以分割的 会返回一个NULL
    while (tokstr!=NULL)
    {
         printf("tokstr:%s\n",tokstr);
        tokstr=strtok(NULL,delim);
    }
    


}
//万能指针 与内存动态申请
void pointer2(void)
{
    //关于内存管理
   int s[5]={0};//16
    memset(s,0,sizeof(s));
   for(int i=0;i<5;i++)
   {
    printf("%d\t",s[i]);
   }
   printf("\n");
   int a[5]={10,20,30,147,5},b[8]={10,20,30,400,5,6,7,8};
   int cmp1=memcmp(a,b,sizeof(int)*5);
   printf("cmp1:%d\n",cmp1);
    while(1);
    // int a=10;
    // void *p;//定义一个万能类型指针
    // p=(void*)(&a);//将a的地址 强转转换为万能型 ，用p指向a的地址
    // *(int *)(p)=200;//通过万能指针p修改a的值 ，先将指针强转换为int类型 然后再去修改
    // printf("a=%d\n",a);
       int n;
   printf("请输入数字的个数\n");
    scanf("%d",&n);
   // int *arr=(int *)malloc(n*sizeof(int));//向堆区申请  n*4个字节 空间 用arr指向这段空间的首地址
   int *arr=(int *)calloc(n,sizeof(int));
    printf("遍历整个数组\n");
    for(int i=0;i<n;i++)
    {
       // printf("%d\t",*arr);
        //arr++;
        printf("%d\t",arr[i]);

    }
    printf("\n");
    //此时 可以将arr当作是一个数组名使用
    printf("请输入n个数据\n");
    int *t=arr;
    for(int i=0;i<n;i++)
    {
        scanf("%d",t);
        t++;
       // scanf("%d",&arr[i]);
    }
    printf("请输入需要扩容的数据个数\n");
    int m;
    scanf("%d",&m);
    arr=(int *)realloc(arr,sizeof(int)*(m+n));
      printf("请继续输入%d个数据\n",m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",arr+n+i);
    }
    printf("输入数据后 遍历整个数组\n");
    for(int i=0;i<m+n;i++)
    {
       // printf("%d\t",*arr);
        //arr++;
        printf("%d\t",arr[i]);

    }
    printf("\n");
    //memset  将某一段内存，清空 多大字节的 同一个数据
    // memset(arr,0,sizeof(int)*n);
    // printf("遍历整个数组\n");
    // for(int i=0;i<n;i++)
    // {
    //      // printf("%d\t",*arr);
    //     //arr++;
    //     printf("%d\t",arr[i]);
    // }
    //  printf("\n");
     //memcpy  内存的复制
     int num[10]={100,200,300,400,5,65,7,8,9,10};
  //   memcpy(arr,num,sizeof(int)*3+1);//400 
  memcpy(arr,num,sizeof(int)*3);
      printf("memcpy后遍历整个数组\n");
    for(int i=0;i<n;i++)
    {
         // printf("%d\t",*arr);
        //arr++;
        printf("%d\t",arr[i]);
    }
     printf("\n");
     //memcmp  内存比较
    int cmp= memcmp(arr,num,sizeof(int)*4);//相等  返回0   ，
    printf("cmp:%d\n",cmp);


    free(arr);//释放
}
int func1(int a,int b)
{return a+b;}
int func2(int a,int b)
{
    return a*b;
}
int func3(int a,int b)
{
    return a-b;
}
//3.函数指针数组
void pointer3(void)
{
    int (*f_pnum[3])(int,int)={func1,func2,func3};
    int i;
    for(i=0;i<3;i++)
    {
        int res=f_pnum[i](10,20);//函数指针数组  调用三个不同 的函数
        printf("res:%d\n",res);
    }
}