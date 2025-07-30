#include <stdio.h>
#include <string.h>

void str_diff();
void arr_panduan();
void engarr_exchange();
char str_function();
char str_output();
void numarr_exchange();
void str_length();
void jiou_diff();

// main���
int main()
{
    // str_diff();
    // engarr_exchange();
    // str_function();
    // str_output();
    // numarr_exchange();
    // str_length();
    jiou_diff();
}

void str_diff()
{
    char str[100] = {'\0'};
    int Eng = 0, eng = 0, num = 0, other = 0;
    printf("�����ַ���\n");
    fgets(str, sizeof(str), stdin);
    puts(str);
    for (int i = 0; i < strlen(str); i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z'))
            Eng++;
        else if ((str[i] >= 'a' && str[i] <= 'z'))
        {
            eng++;
        }
        else if ((str[i] >= '0' && str[i] <= '9'))
            num++;
        else
            other++;
    }
    printf("��дӢ��%d СдӢ��%d �����ַ�%d �����ַ�%d \n", Eng, eng, num, other);
}

void arr_panduan()
{
    int input[10] = {0};
    printf("��������\n");
    for (int i = 0; i < sizeof(input) / sizeof(input[0]); i++)
    {
        scanf("%d", &input[i]);
    }
    int max = input[0];
    int min = input[0];
    for (int i = 1; i < sizeof(input) / sizeof(input[0]); i++)
    {
        max = max > input[i] ? max : input[i];
        min = min < input[i] ? min : input[i];
    }
    printf("max:%d min%d", max, min);
}

void engarr_exchange()
{
    printf("�����ʼ�ַ���\n");
    char input[100] = {'\0'};
    int len = 0;

    fgets(input, sizeof(input), stdin);
    while (input[len])
        len++;

    len--;
    int i = 0, j = len - 1;
    while (i < j)
    {
        char temp = input[j];
        input[j] = input[i];
        input[i] = temp;
        i++;
        j--;
    }
    puts(input);
}

char str_function()
{
    char s1[100] = {"hello world"}, buf[20] = {" WORLDworld"};

    int len = strlen(s1);
    printf("s1�ַ����ĳ��ȣ�%d\n", len);
    printf("����ǰs1:%s\n", s1);
    strcat(s1, "HELLO");
    printf("���Ӻ�s1:%s\n", s1);
    strcat(s1, buf);
    printf("�ڶ������Ӻ�s1:%s\n", s1);
    strcpy(s1, "world");
    printf("�����Ժ�s1:%s\n", s1);
    printf("�Ƚ�ǰ:s1:%s buf:%s\n", s1, buf);
    int cmp = strcmp(s1, buf);
    if (cmp > 0)
        printf("s1��\n");
    else if (cmp < 0)
        printf("buf��\n");
    else
        printf("���");
    return 0;
}
char str_output()
{
    char s1[100] = {'\0'}, s2[100] = {"wangwu 19 56.4"};
    char s3[100] = {"name: zhaoliu age:22 weight:65.78"};
    char number[20] = {"1234.5678"}; // ����һ�����ݷֳ��� �������ͱ���a��1234 b�д�5678
    int age;
    char name[20];
    float weight;

    printf("name :%s age:%d weight:%f\n", "lisi", 20, 62.5);

    // sprintf����
    sprintf(s1, "name :%s age:%d weight:%f", "lisi", 20, 62.5); // �����ݸ�ʽ��ת��Ϊһ���ַ���
    printf("%s\n", s1);
    scanf("%s%d%f", name, &age, &weight);
    printf("name :%s age:%d weight:%.2f\n", name, age, weight);

    // sscanf����
    sscanf(s2, "%s%d%f", name, &age, &weight);
    printf("name :%s age:%d weight:%.2f\n", name, age, weight);
    sscanf(s3, "name: %s age:%d weight:%f", name, &age, &weight);
    printf("name: %s age:%d weight:%.2f\n", name, age, weight);
    int a, b;
    sscanf(number, "%d.%d", &a, &b);
    printf("a=%d b=%d\n", a, b);

    return 0;
}
void numarr_exchange()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i, j;
    i = 0;
    j = sizeof(arr) / sizeof(arr[0]) - 1;
    while (j > i)
    {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        i++;
        j--;
    }
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
}

void str_length()
{
    int length;
    char input[20] = {'\0'};
    printf("����Ԥ�ڳ���\n");
    scanf("%d", &length);
    getchar();
    printf("�������ַ�����\n");
    fgets(input, sizeof(input), stdin);

    if (strlen(input) - 1 == length && strlen(input) <= 20)
    {
        printf("ʵ�ʳ��ȷ���Ԥ��\n");
    }
    else
    {
        printf("��������");
    }
}

void jiou_diff()
{
    int arr[10];

    printf("������10��������\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]); 
    }

   
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] % 2 != 0)
        {
            arr[i] = 0;
        }
    }

    
    printf("����������Ϊ��\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}