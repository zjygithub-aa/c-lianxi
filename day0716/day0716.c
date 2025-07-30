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

// main入口
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
    printf("输入字符串\n");
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
    printf("大写英文%d 小写英文%d 数字字符%d 其他字符%d \n", Eng, eng, num, other);
}

void arr_panduan()
{
    int input[10] = {0};
    printf("输入数据\n");
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
    printf("输入初始字符串\n");
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
    printf("s1字符串的长度：%d\n", len);
    printf("连接前s1:%s\n", s1);
    strcat(s1, "HELLO");
    printf("连接后s1:%s\n", s1);
    strcat(s1, buf);
    printf("第二次连接后s1:%s\n", s1);
    strcpy(s1, "world");
    printf("复制以后s1:%s\n", s1);
    printf("比较前:s1:%s buf:%s\n", s1, buf);
    int cmp = strcmp(s1, buf);
    if (cmp > 0)
        printf("s1大\n");
    else if (cmp < 0)
        printf("buf大\n");
    else
        printf("相等");
    return 0;
}
char str_output()
{
    char s1[100] = {'\0'}, s2[100] = {"wangwu 19 56.4"};
    char s3[100] = {"name: zhaoliu age:22 weight:65.78"};
    char number[20] = {"1234.5678"}; // 将这一串数据分出来 存入整型变量a存1234 b中存5678
    int age;
    char name[20];
    float weight;

    printf("name :%s age:%d weight:%f\n", "lisi", 20, 62.5);

    // sprintf函数
    sprintf(s1, "name :%s age:%d weight:%f", "lisi", 20, 62.5); // 将数据格式化转换为一个字符串
    printf("%s\n", s1);
    scanf("%s%d%f", name, &age, &weight);
    printf("name :%s age:%d weight:%.2f\n", name, age, weight);

    // sscanf函数
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
    printf("输入预期长度\n");
    scanf("%d", &length);
    getchar();
    printf("请输入字符串：\n");
    fgets(input, sizeof(input), stdin);

    if (strlen(input) - 1 == length && strlen(input) <= 20)
    {
        printf("实际长度符合预期\n");
    }
    else
    {
        printf("输入有误");
    }
}

void jiou_diff()
{
    int arr[10];

    printf("请输入10个整数：\n");
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

    
    printf("处理后的数组为：\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}