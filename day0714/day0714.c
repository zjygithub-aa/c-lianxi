#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
#define length 100
int sum(int num1,int num2)
{
    return num1 + num2;


}
int max(int num1, int num2)
{
    if(num1 > num2)
    {
        return num1;
    }
    else
    {
        return num2;

    }
}
int  lifangti(int weight, int height)
{
    return length * weight * height;

}
void print()
{
    //可以优化成用数组放汉字，不过现在技术力不够，只有想法。GO TO
    printf("声 趁 以 借 围 瞒\n"
    "东 火 逸 刀 魏 天\n"
    "击 打 待 杀 救 过\n"
    "西 劫 劳 人 赵 海\n"
    );
}

void Screen_print(); //函数声明
int find_min();
int jiecheng();
float f_to_c();
int main()
{
    
    int num1,num2;
    printf("依次输入两个数字\n");
    scanf("%d %d",&num1,&num2);
    printf("sum = %d\n", sum(num1, num2));
    printf("max = %d\n", max(num1, num2));
    printf("立方体的体积为%d\n",lifangti(num1,num2));
    print();
    Screen_print(); //函数调用
    printf("%d\n", find_min());
    printf("%d\n",jiecheng());
    printf("%.2f\n",f_to_c());
    return 0;

}



void Screen_print()    //定义: 实现功能
{
    //菜单栏  实现的是菜单栏的编辑
    printf("--------------------------------------------------\n");
    printf("| 请输入你的家地址：                           |\n");
    printf("| 请输入你公司地址：                            |\n");
    printf("--------------------------------------------------\n");
    printf("\n");
    printf("你的家地址：");

    char addr[128] = "";
    char family[128] = "";
    scanf("%s", addr);
    printf("你的公司地址:");
    scanf("%s", family);
    printf("...存储中...\n");
    sleep(2);
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("| 你的家地址是：%s                             \n", addr);
    printf("| 你的公司地址是：%s                            \n", family);
    printf("--------------------------------------------------\n");
    printf("\n");
}
int  find_min()
{
    printf("输入3个数比较大小");
    int a,b,c;
    int temp;
    scanf("%d %d %d",&a,&b,&c);
    temp =a;
    if(b>temp&&c>temp)
    {
        return temp;
    }
    else
    {
        if(b>c) return c;
        else return b;

    }
    
}

int jiecheng()
{
    int ready,count;
    count =1;
    printf("输入起始值：\n");
    scanf("%d",&ready);
    for(int i =ready;i>0;i--)
    {
        count = i*count;
    }
    return count;
}

float f_to_c()
{
    float f,c;
    printf("输入华氏温度：\n");
    scanf("%f",&f);
    c =(f -32)*(float)5/9;
    return c;

}