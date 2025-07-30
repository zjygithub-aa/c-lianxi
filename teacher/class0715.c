/*
1.scanf函数 遇到回车/空格/tab停止读取，遇到回车结束
2.字符读写操作函数
    getchar:读取一个字符   遇到回车结束，但是它可以读走回车
    putchar:输出一个字符
3.ASCII码值
    字符在计算机中是以 ASCII码形式存储
    'A' =  65
    'a' =  97
    ' ' =  32
    相邻的字符，相差的ascii值为1 
4.运算符
    简单记一下优先级 ：！>算术运算符>关系运算符>&&>||>赋值运算符
    逻辑非 ！：单目运算符   a=3,那么!a就是0  ，如果a=0,那么!a就是1    ，非0即真，0就是0
    算术运算符： + 、-、*、/、%、  位运算符  ：<<  、>>、 |、&、^、~  等
    关系运算符：>、<、==、!= 、>=  、<= 等
    逻辑与 &&：  两个表达式同时为真则为真
    逻辑或 || ： 两个表达式一个为真则为真
    赋值运算符： =、+= 、-= 、/=  、*=  、%=  、<<=等
5.while(1){}死循环   break作用1：结束循环
6.c语言三大控制结构：
    顺序结构--选择结构--循环结构
    顺序结构：C语言执行按照顺序执行，从上至下
7.选择结构
    1)if 语句
        a.if单独使用  ，如果表达式为真，则执行花括号内的语句
            if(表达式)
            {
                语句
            }
        b.两分支 if-else  如果表达式为真，则执行花括号内的语句1，否则执行else括号内的语句2
             if(表达式)
            {
                语句1
            }
            else
            {
                语句2
            }
        c.多分支 if-else if --else if ...else 
         如果表达式1为真，则执行花括号内的语句1,否则继续判断后续表达式是否为真，为真则执行对应的语句，如果所有的表达式都不为真则执行else内的内容
            if(表达式1)
            {
                语句1
            }
            else if(表达式2)
            {
                语句2
            }
            else
            {
                语句n
            }
        d.if嵌套
            if()
            {
                if()
                {

                }
            }
    2）switch-case
        switch(表达式)//整型  字符型  枚举类型
        {
            case 常量表达式1:  
                语句1；  
                break;
              case 常量表达式2:  
                语句2；  
                break;
                ...
            default :
                语句n;
            break;
        }
        break作用2：结束switch语句   
        如果不写break？会？
    3）三目运算符  （ ？:）      
         表达式1 ？表达式2：表达式3
         如果表达式1为真，则执行表达式2，否则执行表达式3
8.循环结构
    循环：重复的去做某一件事情
    1）while语句
        表达式为真，就执行循环体，否则结束循环
        循环初始值表达式；
        while(表达式)
        {
            循环体；
        循环调整表达式；
        }
    2）do-while
    do-while语句先无条件执行一次循环体，再去判断表达式是否为真， 如果表达式为真，就执行循环体，否则结束循环
        循环初始值表达式1
        do
        {
            循环体；
            循环调整表达式；
        }while(表达式);
    3)for语句
     如果表达式为真，就执行循环体，否则结束循环
        for(循环初始值表达式1;循环条件表达式2;循环调整表达式3)   //注意 ：for圆括号内，表达式可以不写，但是两个分号必不可少
        {
            循环体；
        }
        for(;;){}  就是等价于 while(1){};
    !!!  三种语句是可以相互转换的
    4)循环允许嵌套
        for(;;)
        {
            for(;;)
            {
                while()
                {
                    ...
                }
            }
        }
    5）goto语句 基本淘汰了 。不建议使用
        标签：
            循环体；
        goto 标签；
    6）break关键字   
        结束循环
    7）continue关键字
        终止本次循环，继续执行下一次循环
9.整型常量
    010：八进制10
    0x10:十六进制10
    
*/
#include <stdio.h>
#include <math.h>
//位运算符  对二进制来说
int main(int argc, char const *argv[])
{
    char c=011;//八进制 11 ---》十进制 ：9  ---》0000 1001（二进制）
    printf("c=%o %d %x\n",c,c,c);
    // &  按位与  ：相同位上同时为1则为1，否则为0
    c &=5;//0000 1001 & 0000 0101 ===0
    printf("c&=5:%d\n",c);
    // |  按位或  ：相同位上有1则为1，否则为0
    c=17;//0001 0001
    c|=9;//0001 0001 | 0000 1001 =0001 1001
    printf("17|=9:%d\n",c);
    // ^  按位异或 ：相同位上相同则为0，不同则为1int
    c=17;//0001 0001
    c^=9;//0001 0001 ^ 0000 1001 =0001 1000
    printf("17^=9:%d\n",c);
    // ~  按位取反 ：所有的位上的数取反
    c=17;//0001 0001
    c=~c;//1110 1110(补码)-->1001 0001 +1=1001 0010(原码 -18)
     printf("~17=%d\n",c);
    // <<  左移  
    c=17;  //0001 0001
    c<<=3; //1000 1000 (补码)-->1111 0111+1=1111 1000(原码)=-（32+64+16+8）
     printf("c<<=3:%d\n",c);
    // >>  右移
    c>>=5;//1000 1000 >>5 =1000 0100                                                                   
     printf("c>>=5:%d\n",c);
    return 0;
}

#if 0
//continue  break  goto语句
int main(int argc, char const *argv[])
{
    int i=1;
    for(i=1;i<=10;i++)
    {
         
        if(i%2==0)
        {
         break;// 结束循环  continue;//终止本次循环  继续执行下一次循环
        }
        printf("i=%d\n",i);
    }
    //goto语句
    i=1;
    end:
        printf("goto 语句测试\n");
        i++;
        if(i<10)
   goto end;    
    return 0;
}


//循环嵌套
/*
打印一个*号直角三角形
*
**
***
****
*****
直角三角形九九乘法表  i:行   j:列
j   *  i = j*i 
 1  * 1  = 1
 1  * 2  = 2   2  *  2  =  4

*/
int main(int argc, char const *argv[])
{
    int i,j;
    for(j=1;j<=5;j++) //行循环
    {     
        //打印*号的个数  （=行号）
       for(i=1;i<=j;i++)//列循环
        {
            printf("%4c",'*');
        }
        printf("\n");
    }
    return 0;
}


//输入一个数 ，判断概述是否为质数(大于1的自然数) （只有1和本身两个因数）
int main(int argc, char const *argv[])
{
    unsigned int num;//无符号整型
    do{
    printf("请输入一个大于1的正数\n");
    scanf("%u",&num);//2
    }while(num<=1);
   
    int i=2,flag=0;//flag 如果变成1说明这个数不是质数
    // for(i=2;i<num;i++)
    // {
    //     if(num%i==0)//能够被其他数整除
    //     {
    //         flag=1;
    //         break;//结束循环
    //     }
    // }
    //进一步优化
    for(i=2;i<=sqrt(num);i++)
    {
        if(num%i==0)//能够被其他数整除
        {
             flag=1;
             break;
        }
    }
    if(flag==1)
    {
        printf("%u不是质数\n",num);
    }
    else
     printf("%u是质数\n",num);
    return 0;
}


//实现求5的阶乘
int main(int argc, char const *argv[])
{
    int  t=1,i=2;//t:被乘数  i：乘数
    while(i<=5)
    {
        t=t*i;
        i++;
    }
    printf("t:%d\n",t);
    return 0;
}


//通过三种循环语句  实现输出1-10
int main(int argc, char const *argv[])
{
    //while语句
    int i;//循环变量
    printf("while语句：");
    i=1;
    while(i<=10)
    {
        printf("%d\t",i);
        i++;
    }
    printf("\n");
    printf("do-while语句：");
    i=1;
    do
    {
        printf("%d\t",i);
        i++;
    }while(i<=10);
    printf("\n");
     printf("for语句：");
     for(i=1;i<=10;i++)
     {
        printf("%d\t",i);
     }
     printf("\n");
    return 0;
}


//循环
int main(int argc, char const *argv[])
{
    int month;
   for(;month<1||month>12;)
    {  
         printf("请输入数字月份\n");
        scanf("%d",&month);
    }//输入的数据不对 就继续循环输入
        switch (month)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
             printf("31天\n");
            break;
            case 2:
                printf("28天\n");
                break;
            case 4:
            case 6:
            case 9:
            case 11:
              printf("30天\n");
                break;
            default:
             printf("数据有误\n");
            break;
        }
    return 0;
}

//输入数字月份  输出该月的天数 （按平年来算 2月28天）
int main(int argc, char const *argv[])
{
    int month;
    printf("请输入数字月份\n");
        scanf("%d",&month);
        switch (month)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
             printf("31天\n");
            break;
            case 2:
                printf("28天\n");
                break;
            case 4:
            case 6:
            case 9:
            case 11:
              printf("30天\n");
                break;
            default:
             printf("数据有误\n");
            break;
        }
    return 0;
}


//输入数字月份 输出中文月份 例如输入4  输出四月

int main(int argc, char const *argv[])
{
    int month;
    while(1)
    {
        printf("请输入数字月份\n");
        scanf("%d",&month);
    switch (month)
    {
     case 1:
        printf("一月\n");
        break;
    case 2:
        printf("二月\n");
        break;
     case 3:
        printf("三月\n");
        // break;
      case 4:
        printf("四月\n");
        break;
      case 5:
        printf("五月\n");
        break;
      case 6:
        printf("六月\n");
        break;
      case 7:
        printf("七月\n");
        break;
      case 8:
        printf("八月\n");
        break;
      case 9:
        printf("九月\n");
        break;
      case 10:
        printf("十月\n");
        break;
      case 11:
        printf("十一月\n");
        break;
      case 12:
        printf("十二月\n");
        break;    
      default:
        printf("数据有误\n");
        break;
    }

    }
    
    return 0;
}

//要求大家用 if语句  以及三目运算符  求三个整数中的最大值
int main(int argc, char const *argv[])
{
  int a,b,c,max;
  printf("请输入三个整数\n");
  scanf("%d%d%d",&a,&b,&c);
//   max=(a>b)?a:b;
//   max=(max>c)?max:b;
    // if(a>b)max=a;else max=b;
    // if(max<c)max=c;

// max=(a>b)?(a>c?a:c):(b>c?b:c);
    if(a>b)
    {
       if(a>c)
       {
        max=a;
       } 
       else
       max=c;
    }
    else
    {
        if(b>c)
        max=b;
        else 
        max=c;
        
    }
  printf("max:%d\n",max);
    return 0;
}

//if语句 +笔试题
int main(int argc, char const *argv[])
{
    int a=10;
    // if(!a)//判断!a是否为真  等价于   a==0
    // {
    //     printf("$$$\n");
    // }
    // else
    // {
    //     printf("***\n");
    // }
    // if(a=0)//先将0赋值给a  然判断a是否为真
    // {
    //     printf("$$$\n");
    // }
    // else
    // {
    //     printf("***\n");
    // }
    // if(a==0)//a是否等于0
    // {
    //     printf("$$$\n");
    // }
    // else
    // {
    //     printf("***\n");
    // }
    int c=0,d=0;
    if((c=3)||(d=4))
//  if((c=3)&&(d=4))
//  if((c=0)||(d=4))
//  if((c=0)&&(d=4))
    {
        printf("yes\n");
    }
    //c :?  d  :?
    printf("c=%d d=%d\n",c,d);
    return 0;
}


//if语句   + 三目运算符
//输入两个整数  求最大值 
//要求大家用 if语句  以及三目运算符  求三个整数中的最大值
int main(int argc, char const *argv[])
{
    int a,b ,max;
    printf("请输入两个整数:\n");
    scanf("%d%d",&a,&b);
    //if语句
    // if(a>b)
    // {
    //     max=a;
    // }
    // else
    // {
    //     max=b;
    // }
    //三目运算符
    max=(a>b)?a:b;
    printf("max:%d\n",max);

    return 0;
}


//模运算 + if语句
//输入年份 ，判断该年是否为闰年  （年份能够被4整除并且不能被100整除，或者年份能被400整除）
int main(int argc, char const *argv[])
{
    int year;//年份
    printf("请输入年份（1970--2030年）:");
    scanf("%d",&year);
    //判断年份
    if(year%4==0 && year%100!=0 || year%400==0)//不写花括号 ，默认只管辖一条语句
     {  
         printf("%d年是闰年\n",year);   
    }
    else
    {
     printf("%d年是平年\n",year);
    }

    return 0;
}


//输入一串字符，求英文字母个数  以及  数字字符个数 以及空格的个数 和其它字符个数
int main(int argc, char const *argv[])
{
    char ch;
 
    int eng=0,num=0,blank=0,other=0;

    while (1)
    {     
        ch=getchar();//输入  读一个字符
       
        if(ch=='\n')//回车（'\r'） (换行 '\n')
        {
            break;
        }
        //英文字符
        if(ch>='A'&&ch<='Z' || ch>='a'&&ch<='z')
        {
            eng=eng+1;
        }
        else if(ch>='0'&&ch<='9')
        {
            num++;//等价于 num=num+1  自增
        }
        else if(ch ==' ')
        {
            blank++;
        }
        else 
        {

           other++;
        }
        
    }
    printf("英文字符个数：%d  数字字符个数：%d  空格字符个数：%d  其它字符个数：%d\n",eng,num,blank,other);
    
    // char ch;//定义一个字符类型变量
    // ch=getchar();
    // printf("该字符为:");
    // putchar(ch);
    // printf("ascii:%d\n",ch);
    //  ch=getchar();//将回车读走了
    // printf("该字符为:");
    // putchar(ch);
    //  printf("ascii:%d\n",ch);
    return 0;
}

#endif