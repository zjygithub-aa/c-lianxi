#include <stdio.h>

void count();
void year_diff();
int max();
void month_diff();
void jiecheng();
void zhishu_diff();
void chengfabiao();
void zhishu_find();
void dengyao_triangle();

// main入口
int main()
{
    // // count();
    // year_diff();
    // printf("最大值为%d \n", max());
    // month_diff();
    // jiecheng();
    // zhishu_diff();
    // chengfabiao();
    // zhishu_find();
    dengyao_triangle();
}
void count()
{
    int eng = 0, num = 0, space = 0, other = 0;
    while (1)
    {
        char ch = getchar();
        if (ch == '\n')
            break;
        if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
            eng++;
        else if (ch >= '0' && ch <= '9')
            num++;
        else if (ch == ' ')
            space++;
        else
            other++;
    }

    printf("英文字符的个数：%d ,数字字符个数：%d,空格字符个数：%d,其他字符个数: %d \n", eng, num, space, other);
}

void year_diff()
{
    int year;
    printf("输入年份\n");
    scanf("%d", &year);
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        printf("%d 年是闰年\n", year);
    else
        printf("%d 年是平年\n", year);
}
int max()
{
    int a, b, c, d;
    printf("输入4个数\n");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    // if (a > b && a > c && a >d)
    //     return a;
    // else if (b > c && b >d)
    //     return b;
    // else if (c > d)
    //     return c;
    // else
    //     return d;

    return (a > b && a > c && a > d) ? a : ((b > c && b > d) ? b : ((c > d) ? c : d));
}
void month_diff()
{
    int month;
    while (1)
    {
        printf("输入任一月份");
        scanf("%d", &month);
        switch (month)
        {
        case 1:
            printf("%d月有31天\n", month);
            break;
        case 2:
            printf("%d月有28天\n", month);
            break;
        case 3:
            printf("%d月有31天\n", month);
            break;
        case 4:
            printf("%d月有30天\n", month);
            break;
        case 5:
            printf("%d月有31天\n", month);
            break;
        case 6:
            printf("%d月有30天\n", month);
            break;
        case 7:
            printf("%d月有31天\n", month);
            break;
        case 8:
            printf("%d月有31天\n", month);
            break;
        case 9:
            printf("%d月有30天\n", month);
            break;
        case 10:
            printf("%d月有31天\n", month);
            break;
        case 11:
            printf("%d月有30天\n", month);
            break;
        case 12:
            printf("%d月有31天\n", month);
            break;
        default:
            printf("数据有误，请重新输入！");
            break;
        }
    }
}
void jiecheng()
{
    int input;
    int index;
    int result = 1;
    printf("输入\n");

    scanf("%d", &input);
    printf("选择方法\n");
    scanf("%d", &index);

    switch (index)
    {
    case 1:
        while (input > 0)
        {
            result *= input;
            input--;
        }
        printf("%d\n", result);
        break;
    case 2:

        do
        {
            result *= input;
            input--;
        } while (input > 0);
        printf("%d\n", result);
        break;

    case 3:
        for (int i = input; i > 0; i--)
        {
            result *= input;
            input--;
        }
        printf("%d\n", result);
        break;
    }
}
void zhishu_diff()
{
    int input;
    int flag = 0;
    printf("输入一个数\n");
    scanf("%d", &input);
    for (int i = 2; i <= input - 1; i++)
    {
        if (input % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0 && input != 1)
        printf("%d是质数", input);
    else
        printf("%d不是质数", input);
}

void chengfabiao()
{
    int i, j;
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d * %d = %d  ", j, i, i * j);
        }
        printf("\n");
    }
}

void zhishu_find()
{
    int input;
    int i, j;
    printf("给定范围：\n");
    scanf("%d", &input);
    for (i = 2; i <= input; i++)
    {
        int flag = 1;
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            printf("%d ", i);
        }
    }
}

void dengyao_triangle()
{
    int input;
    printf("输入三角形的高度");
    scanf("%d", &input);
    for (int i = 1; i <= input; i++)
    {
        for (int j = 1; j <= input - i; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            printf("*");
        }
        printf("\n");
    }
}