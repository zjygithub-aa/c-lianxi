/**
 * 1.自定义数据类型--共用体（联合体）
 *  用体变量的地址和它的各成员的地址都是同一地址，内存大小是最大成员的大小
 *  特点：修改其中某一个成员的值，其余的值也会有影响
 *  声明共用体类型
 *         union 类型名 
 *            {
 *              成员列表1；
 *              成员列表1；
 *              }；
 *      成员引用：打点调用     变量名.成员
 * 2.自定义数据类型--枚举类型
 *    枚举：将变量的值一一列举出来，变量的值只限于列举出来的值的范围内，实际是一个常量，
 *     enum 枚举类型
 *      {
 *          枚举值1，
 *          枚举值2,
 *      };
 *      在枚举值表中应列出所有可用值，也称为枚举元素。
 *      枚举值是常量，不能在程序中用赋值语句再对它赋值。
 *      枚举元素本身由系统定义了一个表示序号的数值从 0 开始顺序定义为 0，1，2
 *      在声明枚举类型时，对其中某一枚举值赋值的话，后续的枚举值是就该枚举值+1
 * 3.文件操作
 *      文件分类：
 *          文本文件（t）  二进制文件(b)
 *      文件指针定义：  FILE *fp;
 *      文件的打开和关闭：
 *              打开：fp=fopen("文件路径"，"打开方式")；
 *          文件路径可以是相对路径也可以是绝对路径
 *                  如果文件打开失败  fp接收到的为NULL,否则不为NULL
 *              关闭：fclose(fp);
 *      打开方式： 读 和 写 可读可写 追加写
 *              r(t/b):以只读的方式打开文件，如果文件不存在则打开失败
 *              w     :以只写的方式打开文件，如果文件不存在则新建文件，文件存在则刷新写入内容
 *              r+    :以可读可写的方式打开文件，如果文件不存在打开失败
 *              w+    :以可读可写的方式打开文件，如果文件不存在则新建文件，文件存在则刷新写入内容
 *              a     :以追加写的方式打开文件，文件不存在会新建文件，文件存在不会刷新，追加在文件末尾写
 *              a+    :以追加可读可写的方式打开文件
 *     文件读写操作函数：
 *       分类                读                  写
 *       字符读写          fgetc               fputc
 *     文件读写位置移动
 *          rewind(fp);//将文件读写位置移动文件的首位置
 *          fseek(fp,len,pos);从pos的位置移动len个字节
 *          len<0:往左移动   len>0：往右移动
 *          pos可选参数有三种：SEEK_SET(0):文件首位置  SEEK_CUR(1):文件当前位置 SEEK_END(2):文件末尾位置
 *    文件末尾：结束符  :EOF
 *          文件末尾函数   feof(fp);  如果该函数返回为真就表示读到了文件末尾，否则返回假
 *      
*/
#include<stdio.h>
void file1_ope(void);
void file2_ope(void);
//文件操作
int main(int argc, char const *argv[])
{
    file2_ope();
    return 0;
}
void file1_ope(void)
{
    //定义一个文件指针
    FILE *fp;
    //打开一个文件  
  //  fp=fopen("a.txt","r");//以只读的方式打开文件文件不存在则打开失败
 //   fp=fopen("a.txt","w");//以只写的方式打开文件,
  //   fp=fopen("a.txt","w+");//以可读可写的方式打开文件 内容会刷新
   // fp=fopen("a.txt","r+");//以可读可写的方式打开文件文件不存在则打开失败
  //   fp=fopen("a2.txt","a");//不能读文件 只能在文件末尾写  ，文件不存在就新建，存在就打开文件
   fp=fopen("a2.txt","a+");//可读可写  文件不存在就新建，存在就打开文件
    if(NULL==fp)//fp==NULL
    {
        printf("文件打开失败\n");
        return;
    }
    printf("文件打开成功\n");

    //通过字符写函数向文件写入内容
    fputc('a',fp);
    fputc('b',fp);
     //通过文件读写位置移动 移动文件首位置
    rewind(fp);
   // fseek(fp,2,SEEK_SET);//从文件首位置移动2个字节
   //通过字符读函数来读取文件中字符
    char ch=fgetc(fp);
    printf("ch:%c\n",ch);
    ch=fgetc(fp);
    printf("ch:%c\n",ch);
    //关闭文件
    fclose(fp);
}
void file2_ope(void)
{
    char ch;
    FILE *fp=fopen("a2.txt","r");
    if(!fp)
    {
        printf("文件打开失败\n");
        return;
    }
    while(1)
    {
        ch=fgetc(fp);

       // if(ch==EOF)
       if(feof(fp))
        {
            break;
        }
         putchar(ch);
    }
    fclose(fp);
}


void union_test(void);//共用体
//学生和老师的管理列表
void stu_tea_manager_list(void);
 #if 0
//枚举类型
enum week
{
    sun = 2, mon, tue, wed, thu, fri, sat
};
enum bool
{
flase, true
};

//声明一个联合体类型
int main(int argc, char const *argv[])
{
   //stu_tea_manager_list();
  
  
   enum week a, b,c;
    a = sun;
    b = mon;
    c = tue;
    printf("%d,%d,%d\n", a, b, c);
    enum bool flag;
    flag = true;
    if (flag == 1)
    {
    printf("flag 为真\n");
    }

    return 0;
}
#endif


//声明一个共用体类型
typedef union data
{
  unsigned  char a;
  unsigned  short b;
  unsigned  int c;
}data;
void union_test(void)
{
     printf("共用体类型所占字节大小为：%lu\n",sizeof(union data));
    //定义一个共用体类型变量
    data k;
    k.a=0x11;
    printf("a:%x b:%x c:%x\n",k.a,k.b,k.c);
    k.c=0x11223344;
    printf("a:%x b:%x c:%x\n",k.a,k.b,k.c);
    k.a=0x00;
    printf("a:%x b:%x c:%x\n",k.a,k.b,k.c);
    printf("地址编号：&k:%p &k.a:%p &k.b:%p &k.c%p\n",&k,&k.a,&k.b,&k.c);
}
//共用体
union  Categ                         
{
 int classs;     //班级  
char position[10]; //职务 
}; 
//结构体类型
struct   p                      
{ 
    int num;  
   char name[10]; 
   char sex; 
   char job;//'s':学生 ‘t’:老师
   union  Categ  category ;
}person[2];//已经定义了一个数组

void input(void)
{
    for(int i=0;i<2;i++)
    { person[i].num=i+1;//序号
        printf("姓名");
        scanf("%s",person[i].name);
        getchar();
        printf("性别");
        scanf("%c",&person[i].sex);
        getchar();
        printf("职业");
          scanf("%c",&person[i].job);
        getchar();
        if(person[i].job=='s'||person[i].job=='S')
        {
            printf("班级");
            scanf("%d",&person[i].category.classs);
            getchar();
        }
        else{
            printf("职务");
            scanf("%s",person[i].category.position);
            getchar();
        }
       
    }
}
void output(void)
{
      for(int i=0;i<2;i++)
    {
       printf("序号%d\t",person[i].num);
        printf("姓名");
        printf("%s\t",person[i].name);
       
        printf("性别");
        printf("%c\t",person[i].sex);
       
        printf("职业");
          printf("%c\t",person[i].job);
       
        if(person[i].job=='s'||person[i].job=='S')
        {
            printf("班级");
            printf("%d\n",person[i].category.classs);
           
        }
        else
        {
                printf("职务 ");
                printf("%s\n",person[i].category.position);     
        }
       
    }
}
//学生和老师的管理列表
void stu_tea_manager_list(void)
{
    input();
    output();
}
#if 0
//枚举类型  +函数指针 +结构体 实现状态机
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 状态枚举
typedef enum {
    RED,
    GREEN,
    YELLOW
} TrafficLightState;
// 事件枚举
typedef enum {
    TIMEOUT
} Event;
// 状态机结构体
typedef struct TrafficLight {
    TrafficLightState currentState;
    void (*onRed)(Event event, struct TrafficLight *tl);
    void (*onGreen)(Event event, struct TrafficLight *tl);
    void (*onYellow)(Event event, struct TrafficLight *tl);
} TrafficLight;
// 红灯状态处理函数    //事件       
void redStateHandler(Event event, TrafficLight *tl) {
    if (event == TIMEOUT) {
        printf("Red light timeout, switch to green light\n");
        tl->currentState = GREEN;//将状态变化为绿灯
    }
}
// 绿灯状态处理函数
void greenStateHandler(Event event, TrafficLight *tl) {
    if (event == TIMEOUT) {
        printf("Green light timeout, switch to yellow light\n");
        tl->currentState = YELLOW;
    }
}
// 黄灯状态处理函数
void yellowStateHandler(Event event, TrafficLight *tl) {
    if (event == TIMEOUT) {
        printf("Yellow light timeout, switch to red light\n");
        tl->currentState = RED;
    }
}
// 初始化状态机
void initTrafficLight(TrafficLight *tl) {
    tl->currentState = RED;//红灯
    tl->onRed = redStateHandler;//函数指针指向了某个函数
    tl->onGreen = greenStateHandler;//函数指针指向了某个函数
    tl->onYellow = yellowStateHandler;//函数指针指向了某个函数
}
// 处理事件
void handleEvent(TrafficLight *tl, Event event) {
    switch (tl->currentState) //灯的状态
    {
        case RED:
            tl->onRed(event, tl);
            break;
        case GREEN:
            tl->onGreen(event, tl);
            break;
        case YELLOW:
            tl->onYellow(event, tl);
            break;
        default:
            break;
    }
}
int main() {
    TrafficLight tl;//交通灯  灯的状态，另外三个函数指针表示的是 根据灯的状态来决定使用哪个函数
    initTrafficLight(&tl);//初始化交通灯的状态 以及初始化函数指针的指向
    handleEvent(&tl, TIMEOUT);//处理事件
    handleEvent(&tl, TIMEOUT);
    handleEvent(&tl, TIMEOUT);
    for(int i=10;i>=0;i--)
    {
        printf("%d\n",i);
        _sleep(1000);
        handleEvent(&tl, i);
    }

    return 0;
}
#endif