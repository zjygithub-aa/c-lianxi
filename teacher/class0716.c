/*
1.for(i=0,j=10;i*2<j,j>5;i++,j--)//对于这个语句来说,如果中间表达式用逗号隔开，循环条件以最后一个表达式为准
2.数组概念
    数组就是在内存中连续的相同类型的变量空间
3.数组定义
    数据类型  数组名[常量表达式];//常量表达式 就是数组的长度
    int  num[10];//定义一个可以存储10个整型数据的数组，相当于定义了10个变量  每个变量分别为  数组名[下标]
4.元素的引用
    数组名[下标]  ，在数组中下标是从0开始的
    int  num[10];///在数组num中不存在num[10]这个元素
    一个元素就是一个变量
5.数组的输入和输出
    以int num[10];数组为例
    对其中第i个元素进行输入 ：scanf("%d",&num[i]);
    对其中第i个元素进行输出 ：pritnf("%d",num[i]);
6.数组的定义和初始化赋值    
    int num[10]={1,2,3,4,5,6,7,8,9,10};//定义并初始化赋值
    int num[10]={1,2};//定义一个数组  给 num[0]赋值为1  num[1]赋值为2 ，其余元素值默认为0 ,赋值数据的个数不足数组长度时，后续元素值默认为0
    int num[10];//元素的值是不确定的
    int num[10]={0};//给数组的所有元素初始化赋值为0
    int num[]={1,2,3,4};//允许这么写  ，如果方括号内没有给定数组大小，数组必须初始化赋值，数组的长度由初始化赋值的数据的个数决定
7.一般情况下，有数组的地方 ，数组和循环是绑定使用的
8.在一维数组int num[10]中,数组名就是首地址 也就是num等价于&num[0] ，num+i等价于 &num[i] ,*(num+i)就是num[i]
9.地址是连续的
10.字符数组与字符串
    定义：char  数组名[数组长度]；
    字符串：是一串字符，是一个常量 ，用双引号引起来的内容  字符串默认以'\0'结尾
    定义和赋值：
        char str[5]={'h','e','l','l','o'};
        char str[]={'h','e','l','l','o'};
        char str[] ={"hello"};
        char str[20]={"hello"};
    格式占位符 ：%c  字符           %s：字符串 （通过字符串首地址，到'\0'结束）
    '\0'的ascii码值为0
11.字符串输入输出函数
    gets:字符串输入函数  ----只在windows操作系统下有用  如果链接的是linux 就只能用fgets代替gets
    fgets(s1,sizeof(s1),stdin);stdin:输入流文件  从流文件中读取sizeof(s1)-1个字节数据到 s1中,会将换行读入
    fgets和gets都是遇到换行会停止，只有fgets会将换行读入
    puts:字符串输出函数  输出时会自动换行
12.字符串虽然是一个常量，但是字符串可以当作数组名使用
13.字符串操作函数    要包含该头文件   #include <string.h>
    strlen:求字符串长度    用法：int len =strlen(s1);
    strcat:字符串连接      用法：strcat(s1,s2);//实现将s2连接在s1后面
    strcpy:字符串的复制    用法:strcpy(s1,s2);//将字符串s2拷贝给s1
    strcmp:字符串的比较    一般用法：if(strcmp(s1,s2)==0) {    }   //该函数用来比较两个字符串是否相同，如果相等返回0.如果s1>s2返回正数，如果s1<s2返回负数
    sprintf:格式化转换为字符串   用法：sprintf(s1,"格式控制",输出表列)；//printf函数格式化输出数据到终端  ，sprintf格式化将数据输出到字符字符数组s1里面
    sscanf:字符串格式化数据转换  用法：sscanf(s1,"格式控制",地址表列);//遇到空格/tab/回车停止读入，从s1中格式化读入数据存入到地址表列对应的数据中
*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
int main(int argc, char const *argv[])
{
    char s1[100]={'\0'},s2[100]={"wangwu 19 56.4"};
    char s3[100]={"name :zhaoliu age:22 weight:65.78"};
    char number[20]={"1234.5678"};//将这一串数据分出来 存入整型变量a存1234 b中存5678
    int age;
    char name[20];
    float weight;
    printf("name :%s age:%d weight:%f\n","lisi",20,62.5);
    //sprintf函数
    sprintf(s1,"name :%s age:%d weight:%f","lisi",20,62.5);//将数据格式化转换为一个字符串
    printf("%s\n",s1);
    scanf("%s%d%f",name,&age,&weight);
    printf("name :%s age:%d weight:%.2f\n",name,age,weight);
    //sscanf函数
    sscanf(s2,"%s%d%f",name,&age,&weight);
    printf("name :%s age:%d weight:%.2f\n",name,age,weight);
    sscanf(s3,"name %s age:%d weight:%f",name,&age,&weight);
    printf("name :%s age:%d weight:%.2f\n",name,age,weight);
    int a,b;
    sscanf(number,"%4d.%d",&a,&b);
    printf("a=%d b=%d\n",a,b);

    return 0;
}

#if 0
//字符串操作函数
int main(int argc, char const *argv[])
{
    char s1[100]={"hello world"},buf[20]={" WORLDworld"};
    //字符串长度
    int len=strlen(s1);
    printf("s1中字符串的长度:%d\n",len);
    //字符串连接
    printf("连接前s1：%s\n",s1);
    strcat(s1,"HELLO");
     printf("连接后s1：%s\n",s1); 
     strcat(s1,buf);
     printf("2次连接后s1：%s\n",s1); 
  //  s1="world";  不允许直接赋值
    strcpy(s1,"world");//字符串复制
    printf("复制以后s1:%s\n",s1);
    //字符串比较
    printf("比较前：s1:%s buf:%s\n",s1,buf);
   int cmp=strcmp(s1,buf);
   if(cmp>0)
   {
    printf("s1大\n");
   }
   else if(cmp<0)
   {
    printf("buf大\n");
   }
   else
   {
    printf("相等\n");
   }
    return 0;
}


//要求从键盘输入一串字符，实现字符串的反序存放并输出；例如输入：hello world存入字符数组s1,实现反序以后s1中存的是dlrow olleh
int main(int argc, char const *argv[])
{
    char s1[100]={'\0'};
    printf("请输入一串字符\n");
    fgets(s1,sizeof(s1),stdin);//从键盘 输入一串字符  存入 s1
    //记得将'\n'去掉
    int len=0;//求字符串的长度
    while(s1[len])//因为字符串的末尾 默认以'\0'结尾
   {    
     len++;
   }
    //当前求得的len涵盖\n那个字符的   所以-1
    len--;//此时第len个下标对应的是 '\n'的位置 所以如果要进行首尾交换，
    //首尾字符交换
    int i=0,j=len-1;
    while(i<j)//只有i<j才交换
    {
        char t=s1[i];
        s1[i]=s1[j];
        s1[j]=t;
        i++,j--;
    }
    printf("反序后：%s\n",s1);
    return 0;
}


int main(int argc, char const *argv[])
{
    char s1[50]={"hello world"};
    printf("s1:%s\n",s1);
    printf("%c\n",s1[3]);
    s1[3]='L';
      printf("%c\n",s1[3]);
      printf("s1:%s\n",s1);
      printf("%c\n","hello world"[6]);//字符串本身可以当作一个首地址去用
   // "hello world"[6]='W';//是一个常量 不允许被改变的
    return 0;
}


//输入一串字符，求其中大写英文字符的个数，小写英文字符个数  数字字符个数，以及其它字符个数
int main(int argc, char const *argv[])
{
    
    char s1[50]={'\0'};//定义一个字符数组
    int ENG=0,eng=0,num=0,other=0;
    printf("请输入一串字符\n");
  // gets(s1);//不会将换行读入
  //scanf("%s",s1);//为什么不用取地址？ 因为数组名就是地址
  fgets(s1,sizeof(s1),stdin);//stdin:输入流文件  从流文件中读取sizeof(s1)-1个字节数据到 s1中,会将换行读入
    puts(s1);
 //   printf("s1:%s\nceshi",s1);
    for(int i=0;s1[i]!='\0';i++)//'\0'的ascii码就是0
    {
  
        if(s1[i]>='A'&&s1[i]<='Z')
        {
            ENG++;
        }
        else if (s1[i]>='a'&&s1[i]<='z')
        {
           eng++;
        }
        else if (s1[i]>='0'&&s1[i]<='9')
        {
           num++;
        }
        else
        {
            other++;
        }  

    }
    printf("ENG:%d eng:%d num:%d other:%d\n",ENG,eng,num,other);
    return 0;
}


//关于字符串的基础知识
int main(int argc, char const *argv[])
{
    char str[]={'h'};
    char s1[5]={'h','e','l','l'};
    char s2[]={"hello"};
    char s3[20]={'h','e','l','l','o'};//数组实际数据个数不足数组长度时，后续元素默认为0
    printf("str:%lu s1:%lu s2:%lu s3:%lu\n",sizeof(str),sizeof(s1),sizeof(s2),sizeof(s3));
    printf("str:%s s1:%s s2:%s s3:%s \n",str,s1,s2,s3);

    return 0;
}


//数组的内存 以及大小
int main(int argc, char const *argv[])
{
    int arr[]={1,2,3};
    for(int i=0;i<5;i++)
    {
        printf("&arr[%d],%p\n",i,&arr[i]);
        printf(" arr+%d :%p\n",i,arr+i);

    }
    printf("数组的大小为%lu个字节\n",sizeof(arr));
    for(int i=0;i<3;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    return 0;
}


//四个数求最大值  
int main(int argc, char const *argv[])
{
    // int a=12,b=43,c=4,d=32,max;
    // max=a>b?a:b;
    // max=max>c?max:c;
    // max=max>d?max:d;
    // printf("max:%d\n",max);
    int num[10]={0},max=0;//定义一个数组并进行从初始化赋值为0
    printf("请输入10个整数\n");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&num[i]);
    }
    printf("数组元素：");
    for(int i=0;i<10;i++)
    {
        printf("%d\t",num[i]);
    }
    printf("\n");
    //求最大值
    max=num[0];//将第0个元素为最大值
    for(int i=1;i<10;i++)
    {
        max=max>num[i]?max:num[i];//拿当前的最大值依次与后续每一个元素去进行比较，每一次都会更新最大值
    }
    printf("max:%d\n",max);
    return 0;
}


//for语句+ 逗号运算符
#define T(x,y) (x+y)
#include <stdio.h>
int main(int argc, char const *argv[])
{
//    int c=T(4,5)*(6,3,10);
//    printf("c=%d\n",c);
     int i,j;
     for(i=0,j=10;j>5,i*2<j;i++,j--)
    {
        printf("ok\n");
    }
     printf("i=%d ,=%d\n",i,j);
//i= ,j=     i= .j=
    return 0;
}
#endif
