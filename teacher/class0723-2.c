/**
 * 8.自定义数据类型--结构体
 *      a.结构体类型声明
 *          struct 结构体类型名 {  
 *          成员列表1;
 *          成员列表2;
 *            };
 *      b.结构体变量的定义：数据类型  变量名；
 *      c.成员的引用：打点调用
 *           变量名.成员
 *      d.结构体变量初始化 1）按照成员顺序进行赋值，2）指定成员进行赋值
 *      e.结构体数组定义  数据类型 数组名[数组长度]
 *      f.结构体作为函数参数
 *      g.结构体指针  
 *              如果p是一个指针变量，引用成员 ：（*p）.成员 
 *       ->：结构体指针成员访问运算符              p->成员 
 *      h.结构体所占用内存大小  是最大成员类型的大小的整数倍 ，在分配字节时会进行内存对齐
 *          结构体指针占用内存大小：8个字节 
 * 9.typedef关键字 
 *      进行取别名
 * 10.结构体内成员允许定义结构体类型的变量，但是不能是自己这个类型的变量，如果要定义自己这个类型的成员的话，这个成员只能是指针  -->链表
 * 

*/
#include<stdio.h>
typedef struct birth
{
    int year;
    int month;
    int day;
}birth,BIR;//birth 是一个结构体类型名 是typedef struct birth的别名  BIR也是别名

//声明一个结构体类型
struct student
{
   char name[20];//姓名
   int age;//年龄
   float score;//成绩
   char sex;//性别  'w':女  'm':男
   birth  Birthday;//出生年月日
}c;//c 是一个结构体类型的变量  这个变量也是可以进行初始化赋值的

//定义一个结构体类型变量  并初始化赋值
struct student a={"lili",18,98.5,'w',{2000,3,7}};
struct student b={.score=89.5,.age=20,.name="xiaowang",.sex='m'};
//  struct student *p_stu结构体类型指针
void input_data(struct student *p_stu);
void output_data(struct student *p_stu);
//对于结构体成员的应用  变量名.成员
void output(void)
{

    printf("name:%s age:%d score:%.2f sex:%c year %d month :%d day:%d \n",
    a.name,a.age,a.score,a.sex,a.Birthday.year,a.Birthday.month,a.Birthday.day);
    //对b同学的生日进行赋值
    b.Birthday.year=1998;
    b.Birthday.month=7;
    b.Birthday.day=18;
     printf("name:%s age:%d score:%.2f sex:%c year %d month :%d day:%d \n",
     b.name,b.age,b.score,b.sex,b.Birthday.year,b.Birthday.month,b.Birthday.day);
     printf("name:%s age:%d score:%.2f sex:%c year %d month :%d day:%d \n",
     c.name,c.age,c.score,c.sex,c.Birthday.year,c.Birthday.month,c.Birthday.day);
}
void input(void)
{
    printf("name:");
    scanf("%s",c.name);
    getchar();
    printf("age:");
    scanf("%d",&c.age);
     getchar();
    printf("score:");
    scanf("%f",&c.score);
     getchar();
    printf("sex:");
    scanf("%c",&c.sex);
     getchar();
    printf("year-motn-day:");
    scanf("%d-%d-%d",&c.Birthday.year,&c.Birthday.month,&c.Birthday.day);
}
struct teacher 
{
    char name[13];//13
    int age;//4
   float h;//4
   char sex;//1
   struct a
   {
    int kk;
    int ll;
   }t ;//在结构体类型内部声明一个结构体类型并定义一个该类型的变量是允许的  但是这个类型只在本teacher结构体内可以使用
  // struct teacher tea;//!!!!  在本结构体类 不允许定义该结构体类型的成员变量 但是可以定义指针类型变量
   struct teacher *next;
};
int main(int argc, char const *argv[])
{

    printf("struct teacher size:%lu\n",sizeof(struct teacher ));
    struct teacher k,*p_t;
    printf("&k:%p k.name:%p \n&k.age:%p\n&k.h:%p\n&k.sex:%p\n",&k,k.name,&k.age,&k.h,&k.sex);
    printf("结构体struct teacher 指针大小：%lu\n",sizeof(p_t));
    //以上内容是关于  结构体类型内存大小以及结构体指针大小的
//----------------------------------------------------------------------
    // input();
    // output();
    //结构体数组
    struct student stu_num[3];
    struct student *p=stu_num;//指针指向数组的首地址
    input_data(p);//p  和 stu_num是一样的
    output_data(p);
    printf("遍历结构体数组\n");
    for(int i=0;i<3;i++)
    {
         printf("name:%s age:%d\n",stu_num[i].name,stu_num[i].age);
    }
    return 0;
}

//  struct student *p_stu结构体类型指针
void input_data(struct student *p_stu)
{
    for(int i=0;i<3;i++)
    {
        printf("name:");
      //  scanf("%s",(*p_stu).name);
       scanf("%s",p_stu->name);
        getchar();
        printf("age:");
        // scanf("%d",&(*p_stu).age);
        scanf("%d",&p_stu->age);
         getchar();
         p_stu++;
    }
   

}

void output_data(struct student *p_stu)
{
     for(int i=0;i<3;i++)
    {
        printf("name:");
      //  printf("%s\t",(*p_stu).name);
       printf("%s\t",p_stu->name);
        printf("age:");
     //   printf("%d\n",(*p_stu).age);
     printf("%d\n",p_stu->age);
         p_stu++;
    }
}
