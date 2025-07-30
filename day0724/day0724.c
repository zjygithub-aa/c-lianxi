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
    printf("������һ��������1~7����ʾ���ڼ���");
    scanf("%d", &input);

    if (input >= 1 && input <= 7)
    {
        day = (enum weekday)input;
        getWeekdayName(day);
    }
    else
    {
        printf("�������\n");
    }
}

void test2()
{
    
    int input1;
    float input2;

    printf("����һ������: ");
    scanf("%d", &input1);
    data.i = input1;  
    getunion_ascii(data);

    printf("����һ��������: ");
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
        printf("�޷���Դ�ļ�\n");
        return;
    }

    wfp = fopen("w.txt", "w");
    if (wfp == NULL)
    {
        printf("�޷�����Ŀ���ļ�\n");
        fclose(rfp);  
        return;
    }

    while ((ch = fgetc(rfp)) != EOF) 
    {
        fputc(ch, wfp);
    }

    fclose(rfp);
    fclose(wfp);
    printf("�ļ����Ƴɹ�\n");

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
        printf("����һ\n");
        break;
    case TUE:
        printf("���ڶ�\n");
        break;
    case WED:
        printf("������\n");
        break;
    case THU:
        printf("������\n");
        break;
    case FRI:
        printf("������\n");
        break;
    case SAT:
        printf("������\n");
        break;
    case SUN:
        printf("������\n");
        break;
    default:
        printf("�������\n");
    }
}