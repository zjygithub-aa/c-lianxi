#include <stdio.h>

enum weekday
{
    MON = 1,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
} day;

union Data
{
    int i;
    float f;
    char str[4];
} data;

void test1();
void test2();
void test3();
void getWeekdayName(enum weekday day);
void getunion_ascii(union Data data);
int main()
{
    test3();
}

void test1()
{
    int input;
    printf("请输入一个整数（1~7）表示星期几：");
    scanf("%d", &input);

    if (input >= 1 && input <= 7)
    {
        day = (enum weekday)input;
        getWeekdayName(day);
    }
    else
    {
        printf("输入错误\n");
    }
}

void test2()
{
    
    int input1;
    float input2;

    printf("输入一个整数: ");
    scanf("%d", &input1);
    data.i = input1;  
    getunion_ascii(data);

    printf("输入一个浮点数: ");
    scanf("%f", &input2);
    data.f = input2;  
    getunion_ascii(data);


}

void test3()
{
    FILE *rfp, *wfp;
    int ch;  

    rfp = fopen("a.txt", "r");
    if (rfp == NULL)
    {
        printf("无法打开源文件\n");
        return;
    }

    wfp = fopen("w.txt", "w");
    if (wfp == NULL)
    {
        printf("无法创建目标文件\n");
        fclose(rfp);  
        return;
    }

    while ((ch = fgetc(rfp)) != EOF) 
    {
        fputc(ch, wfp);
    }

    fclose(rfp);
    fclose(wfp);
    printf("文件复制成功\n");

}


void getunion_ascii(union Data data)
{
    printf("data.i : %d\n", data.i);
    printf("data.f : %f\n", data.f);
    printf("data.str ASCII : ");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", (unsigned char)data.str[i]);
    }
    printf("\n");
}

void getWeekdayName(enum weekday day)
{
    switch (day)
    {
    case MON:
        printf("星期一\n");
        break;
    case TUE:
        printf("星期二\n");
        break;
    case WED:
        printf("星期三\n");
        break;
    case THU:
        printf("星期四\n");
        break;
    case FRI:
        printf("星期五\n");
        break;
    case SAT:
        printf("星期六\n");
        break;
    case SUN:
        printf("星期日\n");
        break;
    default:
        printf("输入错误\n");
    }
}