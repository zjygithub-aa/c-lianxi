/**
 * 1.指针与数组
 *   p++; ++p;*p++;*(p++); (*p)++;++*p;*++p
 *   如果有 p+1  q+1  p<q  q-p 等这些运算的的前提  是 指针指向的同一个数组
 * 2.指针数组
 *  本质上是一个数组，是一个用来存指针的数组；也就是说每一个元素都相当于一个指针变量，每一个元素存的都是地址
 *  定义： 数据类型 * 数组名[常量];
 *          int *p_num[4];//本质上一个数组，对于数组p_num而言 p_num+i就是&p_num[i] 那么*(p_num+i)就是p_num[i]
 *      在定义一个数组时，若方括号内没有写数组大小，一定记得初始化赋值
 *  一般结合二维数组进行使用p_num[i]
 * 3.数组指针
 *      本质上是一个指针，是一个行指针，用来指向带n个元素的一维数组
 *     定义：int (*p_num)[4];//表示可以指向一个含4个元素的一维数组
 *      一般结合二维数组进行使用p_num[i]
 * 4.二级指针
 *      指向指针的指针
 *     定义：数据类型 **变量名;
 *      多级指针
 * 5.数组与指针
 *      在一维数组中 int arr[10];    数组名arr就是一个首地址
 *          arr：是一个数组名，相当于指向首元素的地址的指针  类型 int *类型,步长为4个字节
 *          &arr:数组的地址 隐式转换为数组的首行指针  类型为  int (*)[10] ，步长为4*10个字节
 *          &arr[0]:首元素的地址，步长为4
 *      在二维数中 int arr[3][4];   arr 与&arr 与&arr[0] 与 &arr[0][0]的值是一样的
 *          arr：是一个数组名，隐式转换为指向数组首行的指针，类型为 int (*)[4],步长为 4*4个字节
 *          &arr:是数组的地址 ，类型为 int (*)[3][4] 变成一个二维数组指针（一维数组指针可以指向一行，二维数组指针指向整个二维数组），
 * 步长为 3*4*4个字节
 *          &arr[0]:首行的地址，&num[0] 是指向这一行的指针，类型为 int (*)[4]，与 num 的类型相同。
 *          &arr[0][0]:首元素的地址 ，步长为4
 * 6.指针所占空间字节大小
 *      不会根据数据类型而变化，而是由处理器（环境）来决定 ，如果是32位的指针的大小为4个字节，如果64位的就是8个字节
 * 7.函数指针  与  指针函数
 *      指针函数：本质上是一个函数，返回值类型为指针的函数  例如之前写的mystrcat \mystrcpy函数 
 *      函数指针：本质上是一个指针 ，是一个可以用来指向函数的指针
 *      函数指针定义：  返回值类型  (*指针变量名)(形参类型列表)；
 *              举例：int (*p_f)(int ,char);//函数指针  它可以指向一个返回值类型为int ，形参分别为int 和 char类型变量的函数
 *      使用函数指针时一定要注意，形参列表数量要一致，类型也要一一对应
 * 8. 回调函数
 *    函数实现方 不方便调用该函数，而由接口提供方来调用该函数，就称为回调函数。
*/

#include<stdio.h>
void pointer1(void);
//指针数组
void pointer2(void);
//数组指针
void pointer3(void);
//二级指针
void pointer4(void);
//指针高级
void pointer5(void);
//指针空间大小
 void pointer6(void);
 //函数指针
  void pointer7(void);
  //回调函数
    void pointer8(void);
//数组与指针
void test(void)
{
    int (*p)[4];//一维数组指针 ：行指针 指向一个含4个元素的一维数组  本质上 就是一个指针
    int arr[4];//arr 是一个数组名 也是首元素的地址&arr[0],类型为int*
    //&arr就是一个数组的地址 （行地址）类型 int (*)[]，如果执行 &arr+1  ,其实是加一个维度的大小 （加1行）
    p=&arr;
    printf("&arr:%p &arr+1:%p\n",arr,&arr+1);
    int num[3][4];//二维数组  num相当于首行的地址 &num[0]  ,将num[0]看作是一个一维数组名字 ，所以 num是一个int (*)[]类型
    //&num :就是一个二维数组的地址 ，类型 int (*)[][]类型 二维数组指针，一意味着可以用来指向三维数组 
    printf("num:%p &num+1:%p\n",num,&num+1);//+1就是加一个维度
}
int main(int argc, char const *argv[])
{
    //二级指针
    //pointer4();
   // pointer5();
   // pointer7();
   pointer8();
    return 0;
}
void pointer1(void)
{
    int num[10]={11,22,33,44,5,6,7,8,9,10};
    int *p=num;
    int c=*p++;//等价于 c=*p  ;p=p+1;
    printf("c:%d ,*p:%d\n",c,*p);
    int d=*++p;//等价于 p=p+1; d=*p
    printf("d:%d *p:%d\n",d,*p);
    int e=(*p)++;//等价于 e=*p ;*p=*p+1;
    printf("e:%d *p:%d\n",e,*p);
    int f=*(p++);//等价于 f=*p  ;p=p+1;    *p++等价于 *(p++)
    printf("f:%d  *p:%d\n",f,*p);
    int g=++*p;//等价于*p=*p+1;g=*p;  p没有改指向 而是 值+1
    printf("g:%d *p:%d\n",g,*p);
}
//指针数组

//通过指针数组 访问二维数组 输出所有元素的值 并求二维数组所有元素的和
int getsum(int *q_num[4])
{
    int sum=0;
    //此时q_num可以当作 arr来使用
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<2;j++)
        {
           // printf("%d\t",q_num[i][j]);
            // printf("%d\t",(*(q_num+i))[j]);//等价于 arr[i][j] ,*(arr+i):行的首地址 所有*(arr+i)+j就是&arr[i][j]
             printf("%d\t",*(*(q_num+i)+j));
             sum+=*(*(q_num+i)+j);
        }
        printf("\n");
    }
    return sum;

}
void pointer2(void)
{
    int a=10,b=20,c=30,d=40;
    int *p_num[4]={&a,&b,&c,&d};//指针数组
    //遍历指针数组中的数据
    for(int i=0;i<4;i++)
    {
        printf("%p\t",p_num[i]);
    }
    printf("\n");
    printf("%p\t%p\t%p\t%p\n",&a,&b,&c,&d);

    //输出指针数组中 元素所指向的空间 里面的值  
    for(int i=0;i<4;i++)
    {
      //  printf("%d\t",*p_num[i]);
        printf("%d\t",*(*(p_num+i)));
    }
    printf("\n");
    int arr[4][2]={1,2,   3,4,  5,6,   7,8};//二维数组 看作是4个一维数组 arr[i]

    //分别用q_num的每一个元素指向二维的每一行的首地址
    for(int i=0;i<4;i++)
    {
        p_num[i]=arr[i];
    }
 
  int s= getsum(p_num);
    printf("s:%d\n",s);

}

//3.数组指针
void pointer3(void)
{
    int num[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    int arr[4]={11,22,33,44};
    int (*p)[4];//数组指针
    p=&arr;//p指向arr的行首地址
    printf("arr:%d  &arr:%d\n",arr,&arr);
    printf("%d\n",*p);
    //通过数组指针输出一维数组arr的元素的值  *p也是&arr[0]  所以 *p+i 就是 &arr[i]  那么 *(*p+i)就是arr[i]
    for(int i=0;i<4;i++)
    {
      //  printf("%p\t",&arr[i]);
       // printf("%p\t",*p+i);
       printf("%d\t",*(*p+i));
    }
    printf("\n");
    //在二维数组中  num是一个数组名 是首行的行地址
    printf("num:%p &num:%p  &num[0]:%p  &num[0][0]:%p\n",num,&num,&num[0],&num[0][0]);
    int *x=(int*)((&num)+1);
    printf("x:%p\n",x);
    //p=&num[0];//在二维数组中可以将num[0]看作是一个一维数组的数组名  ，而num就是&num[0]
    p=num;//p指向 num[0]行  此时 p可以当作 num来使用
    p++;//移动了一整行
    printf("p:%p\n",p);
    p=num;//重新让p指向num的首行
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
          //  printf("%d\t",p[i][j]);//把数组指针p当作数组名来使用
          //p就是 num  ,而num+i就是&num[i]就是p+i ，把num[i]看作是一个一维数组的话num[i]+j就是&num[i][j]
          //那么*(num+i)+j就是&num[i][j]  那么 *(*(num+i)+j)才是 num[i][j]
        
          printf("%d\t",*(*(p+i)+j));
        }
        printf("\n");
    }
    //通过p++的方式输出二维数组中个元素的值
    p=num;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
          printf("%d\t",*(*p+j));
        }
        printf("\n");
        p++;
    }



}
//该函数 内部交换了p和q的指向 而对实参来说  指针指向是不会交换的
void swap1(int *p,int *q)
{
    int *t;
    printf("swap1函数交换前 p:%p  q:%p\n",p,q);
    t=p;
    p=q;
    q=t;
    printf("swap1函数交换后 p:%p  q:%p\n",p,q);
}
//swap2函数  交换的是两个指针的指向
void swap2(int **k,int **l)
{
    int *t;
    t=*k;
    *k=*l;
    *l=t;
}
void swap3(int **k,int **l)
{
    int t;
    t=**k;
    **k=**l;
    **l=t;
}
//二级指针
void pointer4(void)
{
    // int a=10;
    // int *p=&a;
    // int **q=&p;
    // int ***k=&q;
    // printf("&a:%p  p:%p\n",&a,p);//p存的是a的地址
    // printf("&p:%p q:%p\n",&p,q);//q存的是p的地址  *q存的是a的地址  **q存的就是a的值
    // printf("&q:%p k:%p\n",&q,k);//k存的是q的地址 *k存的就是p的地址 **k村的就是a的地址  ***k存的是a的值
    // printf("a:%d  *p:%d\n",a,*p);
    // printf("**q:%d  ***k:%d\n",**q,***k);
    int a=10,b=20;
    int *p=&a,*q=&b;
    printf("&a:%p &b:%p  p:%p  q:%p\n",&a,&b,p,q);
    swap1(p,q);
    printf("&a:%p &b:%p  p:%p  q:%p\n",&a,&b,p,q);
    swap2(&p,&q);
    printf("&a:%p &b:%p  p:%p  q:%p\n",&a,&b,p,q);
    swap3(&p,&q);
    printf("&a:%p &b:%p  p:%p  q:%p\n",&a,&b,p,q);
    printf("a=%d b=%d\n",a,b);
}

//指针高级
void pointer5(void)
{
    int arr[10];//在一维数组中arr是一个数组名 相当于一个指向首元素(arr[0])地址的指针 类型为int *,步长为4个字节
    int *p;
    p=arr;
    printf("arr:%p  &arr:%p  &arr[0]:%p\n",arr,&arr,&arr[0]);//虽然数值是一样的 但是意义不一样
    //&arr:是一个一维数组的地址 ，隐式转换为数组指针 类型 int (* )[]类型 ，步长为4*10个字节
    int *q=(int *)((&arr)+1);
    printf("q:%p\n",q);
    q=(int *)(&arr[0]+1);
     printf("q:%p\n",q);
    int num[3][4];
    int *k=(int *)(num+1);//num相当于是一个数组指针 指向了二维数组首行的地址 步长为16
    printf("num:%p k:%p\n",num,k);
    k=(int *)(&num+1);
    printf("k:%p\n",k);
    k=(int *)(&num[0]+1);
       printf("k:%p\n",k);
    k=(int *)(&num[0][0]+1);
       printf("k:%p\n",k);
}
//指针空间大小
 void pointer6(void)
 {
    int a=10;
    int *p=&a;
    char str[100]={"hello"},*q=str;
    double score=100.87,*k=&score;
    printf("p-size:%lu q-size:%lu k-size:%lu\n",sizeof(p),sizeof(q),sizeof(k));

 }

char* my_strcat(char* dest,  char* src)
{
    char *t=dest;//指向目标字符串的首地址
   
    //通过指针变量t找到第一个字符串的末尾   指针指向第一个字符串的末尾
    while(*t)
    {
        t++;
    }//此时t已经指向'\0'
    //连接
    while (*src)
    {
        *t=*src;
      
        t++,src++;
    }
    
    *t='\0';
   

    return dest;//返回目标字符串的首地址
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
    *s1='\0';
    return t;
    
}
int getsum(int a,int b)
{
    return a+b;
}
 //函数指针
 void pointer7(void)
 {
    //定义一个函数指针
    char * (*f_p)(char *,char *);
  //  f_p=getsum;//不可以这么使用  ！！！  一定要参数的类型和数量一一对应
    //使用函数指针
    f_p=my_strcat;//用f_p来指向my_strcat函数 ，函数名就是函数的首地址
    //通过函数指针来调用my_strcat函数
    char s1[20]={"hello"},s2[10]={" world!"};
   // char *p=my_strcat(s1,s2);
   char *p=f_p(s1,s2);
    printf("p:%s  s1:%s\n",p,s1);
    //通过指针修改指向 f_p指向mystrcpy函数
    f_p=mystrcpy;
    //通过函数指针来调用函数   方法2
    printf("s1:%s s2:%s\n",s1,s2);
    p=(*f_p)(s1,s2);
    printf("p:%s  s1:%s\n",p,s1);
 }

//char * (*f_p)(char *,char *) 是一个形参，函数指针意味着只能接收一个函数名
void callback(char * (*f_p)(char *,char *),char *s1,char *s2)
{
    f_p(s1,s2);
}
 //回调函数  
void pointer8(void)
{
    char s1[20]={"hello"},s2[10]={" world!"};
    printf("callback before s1:%s s2:%s\n",s1,s2);
    callback(mystrcpy,s1,s2);//复制
    printf("callback after s1:%s s2:%s\n",s1,s2);
    printf("callback before s1:%s s2:%s\n",s1,s2);
    callback(my_strcat,s1,s2);//连接
    printf("callback after s1:%s s2:%s\n",s1,s2);
}