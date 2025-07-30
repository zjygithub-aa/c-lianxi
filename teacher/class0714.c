/*
c语言的特征  ：
C语言有32个关键字 34种运算符
1.main函数  是C语言的入口  
2.在一个工程下 ：有且仅有一个主函数
3.一个c程序由一个或者多个源文件组成
4.一个源文件由函数组成
5.函数由  函数首部（函数返回值 函数名  参数列表）  和 函数体（{}括起来的内容）  组成
6.每一条语句都是以分号（;）结尾的你  多条语句可以写在一行，一条语句也可以分为多好编写（注意中间不能是打断字符串 “”）
7.printf函数   ：输出函数 ，双引号里面的内容原样输出
8.基本数据类型：整型   字符型  实型（单精度实型  双精度实型）
    类型    关键字       所占空间字节大小      格式占位符
   整型     int               4                    %d(十进制)  %o(八进制)  %x(十六进制) %p(地址十六进制) %u(无符号)
   短整型  short/short int    2                    %hd
   长整型  long/long int      4                    %ld
 长长整型  long long          8                    %lld

    字符型  char             1                    %c

   单精度实型  float         4                    %f
   双精度实型 double         8                    %lf

sizeof运算符：求数据类型/变量 所占用空间字节大小

整型：整数    实型：实数（小数）    字符型：字符
所占字节大小决定 它的取值范围    ：有无符号
9.变量：可以被改变的量
    变量的定义：数据类型  变量名 ；
    变量名的命名规则： 符合标识符的命名规则，并且不能与关键字重名
    标识符命名规则：由数字 字母 下划线组成，不能以数字开头
    举例：int  a; char b; float cl; double _3;
10.有无符号:指的是有没有负号 ，有符号，数据最高位作为符号位（1:负数，0:正数）
    有符号：signed
    无符号：unsigned
字符型变量可以用来存整数吗？      可以！
    signed char ：取值范围：  -128  ~127  (-2^7 ~ 2^7-1)
    unsigned char：取值范围   0   ~  255  (0 ~2^8-1)
    signed int :取值范围     -2^31~2^31-1   unsigned int 取值范围 ：0 ~2^32-1
11.数据在计算机中的存储方式:以补码的方式进行存储
    小端存储：数据的低位存储在地址的低字节
    大端存储：数据的高位存储在地址的低字节
12.printf函数  printf("格式控制"，输出表列)； //格式化输出函数
    scanf函数  scanf("格式控制"，地址表列)；  //格式化输入函数
    格式占位符：printf("%d,%c,%f",10,'a',12.345);//输出表列中的数据要与格式控制中的格式占位符一一对应
         %%:%     
         \n：换行   \t：制表符（tab)  \b：回删   \010:八进制10  \xa3:十六进制a3
    scanf 函数 遇到空格/tab/回车停止读取，遇到回车结束,如果格式控制中有格式要求，数据一定要严格按照要求输入，否则数据有误
    一定不要在格式控制中加  '\n'
13.常量：不可以被改变的量
    整型常量  ：123，0，-789
    字符常量： 'a','1','?','\n','\t','\010' ,
    字符串常量： "a","hello"
    实型常量：  1.234 , -4.567  , 1.2e5或1.2E5 (科学计数 表示1.2乘以10的5次方 e的前面必须有数字，e的后面只能是整数)
    符号常量：  #define  N 10  (宏定义 ：N代替了10)
    const修饰常量：const int a=10;//修饰a为只读，不能被修改
14.输出格式控制
    %m.nf  : 
    m：表示输出占用的域宽 （占用字符宽度）  m>0:数据右对齐  m<0：数据左对齐   m<实际数据长度按照实际输出输出
    n: 表示输出的小数位数
15.实型精度
    float  精度保留到第7位（含整数位+小数位）
    double 精度保留到第16位（含整数位+小数位）
16.数据类型转换
    隐式转换
    float a=10/3： 两个整型的数据进行运算，结果为整型；
    float c=10/3.0; 两个数据进行运算，其中一个为实型，结果就隐式转换为实型
    强制转换
        （强转类型）（强转的表达式）
     double e=(double)10/3;//将10 强制转换为实型
    double f=(double)(10/3);//将10/3的结果为3  强转转换为实型
*/
#include <stdio.h> //预处理指令  #号开头--预处理指令  stdio.h:标准的输入输出的头文件
//在C语言中是没有提供输入输出函数的   
//注释：// ：单行注释    /**/块注释

int main(int argc, char const *argv[])
{
    //实型精度
    float a=10/3;//将结果3 自动转换为实型  
    double b=10/3;
    float c=10/3.0;
    double d=10.0/3;
    double e=(double)10/3;//将10 强制转换为实型
    double f=(double)(10/3);//将10/3的结果为3  强转转换为实型
    printf("a=%10.8f b=%10.8lf\n",a,b);
    printf("c=%10.8f d=%10.8lf\n",c,d);
    printf("c=%10.16f d=%10.16lf\n",c,d);
    c=100/3.0;d=100/3.0;
    printf("c=%10.16f d=%10.16lf\n",c,d);
    printf("100/3.0=%10.16f 100/3.0=%10.16lf\n",100/3.0,100/3.0);
    printf("e=%lf f=%lf\n",e,f);
    return 0;
}

#if 0
//输入两个整数，求两个整数的和
//输入圆的半径，求圆的面积 
//输入底圆的半径和圆柱体的高，求圆柱体的体积 （v=s圆*h）和面积 (s=2*s圆+PI*2*r*h)
#define PI 3.14
int main(int argc, char const *argv[])
{   
    int a=0,b=0,c=0;//定义了三个整型变量，并初始化赋值为0    同类型的变量允许写在一起的 ，用逗号隔开
    printf("请输入两个整数：(用逗号隔开)");
    scanf("a=%d,b=%d",&a,&b);//scanf 函数 遇到空格/tab/回车停止读取，遇到回车结束
    c=a+b;
    printf("c=%d\n",c);
    //定义变量
    float r,s;
    printf("请输入圆的半径");
    scanf("%f",&r);
    s=PI*r*r;
    printf("s=%f\n",PI*r*r);
 
    return 0;
}



//sizeof运算符
int main(int argc, char const *argv[])
{
    printf("int   类型所占字节大小：%lu\n",sizeof(int));
    printf("short 类型所占字节大小：%lu\n",sizeof(short));
    printf("long  类型所占字节大小：%lu\n",sizeof(long));
    printf("long long 类型所占字节大小：%lu\n",sizeof(long long));
    printf("char  类型所占字节大小：%lu\n",sizeof(char));
    printf("float 类型所占字节大小：%lu\n",sizeof(float));
    printf("double类型所占字节大小：%lu\n",sizeof(double));
    return 0;
}

#define N 10
#define T(x,y) x+y  //只是起文本替换的作用 
int main(int argc, char const *argv[])
{
    //常量
    printf("N=%d\n",N);
   const int a=N+10;
    printf("a=%d\n",a);
    //a=100;  //报错
   // N=100;   //报错
    int b=T(3,4);
    printf("b=%d\n",b);
    int c=T(3,4)*T(2,3);//相当于 3+4*2+3=3+8+3=14
    printf("c=%d\n",c);
    printf("%o %x\n",'\010','\xa3');
    return 0;
}


//求两个整数的和    getsum就是一个自定义函数
int getsum(int a,int b)
{
    return a+b;
}
int main(int argc, char const *argv[])
{
    printf("hello   world\n"); //\n:换行符
    int c;
    c=getsum(1,2);//函数的调用
    printf("c=%d\n",c);//0000 0000 
    char a=127;//0111 1111+1==>1000 0000(补码) 1111 1111+1=>1 0000 0000  （一个字节）约定好 1000 0000作为-128的补码
    a=a+1;//把a+1的值重新赋值给a  一个等号表示赋值，右边的给左边
    printf("a=%d  %x\n",a,a);//%x  自动提升为4个字节（-128补码）
    // 0x f    f    f    f    f    f    8   0
    //    1111 1111 1111 1111 1111 1111 1000 0000 (补码)
    //    1000 0000 0000 0000 0000 0000 0111 1111 +1  ==》-128（原码）
    unsigned char b=255;
    b=b+1;
    printf("b=%d %x\n",b,b);
    //数据的存储 属于 小端还是大端
    int e=0x01020304;//4个字节 
    char *p=(char*)(&e);//强制类型转换
    int i;
    for(i=0;i<4;i++)
    {
        printf("%p %d\n",p,*p);
        p++;
    }
    return 0;
}
#endif
