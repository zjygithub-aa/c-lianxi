#include <stdio.h>
#include <stdlib.h>
#define N 5

void test1();
void test2();
void test3();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double calculateAverage(int *arr, int size);
int *createArray(int size);
void freeArray(int *arr);

typedef struct
{
    char name[50]; // 姓名
    int age;       // 年龄
    double score;  // 成绩
} Student;
void initStudent(Student *student);
void inputStudents(Student *students, int n);
void printStudents(const Student *students, int n);

int main()
{
    // test1();
    //  test2();
    test3();
}

double add(double a, double b)
{
    return a + b;
}
double subtract(double a, double b)
{
    return a - b;
}
double multiply(double a, double b)
{
    return a * b;
}
double divide(double a, double b)
{
    return a / b;
}

void test1()
{
    double (*calculate[4])(double, double) = {add, subtract, multiply, divide};
    double a, b;
    char input;
    printf("输入a和b,以及+-*/模式\n");
    scanf("%lf %lf %c", &a, &b, &input);
    switch (input)
    {
    case '+':
        printf("%.2lf", calculate[0](a, b));
        break;
    case '-':
        printf("%.2lf", calculate[1](a, b));
        break;
    case '*':
        printf("%.2lf", calculate[2](a, b));
        break;
    case '/':
        printf("%.2lf", calculate[3](a, b));
        break;
    }
}

void test2()
{
    int size = 5;
    int *arr = createArray(size);
    if (arr == NULL)
    {
        printf("内存分配失败！\n");
        return;
    }

    double avg = calculateAverage(arr, size);
    printf("平均值为: %.2f\n", avg);

    freeArray(arr);
}

int *createArray(int size)
{
    int *arr = (int *)malloc(sizeof(int) * size);
    if (arr == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < size; i++)
    {
        printf("请输入第 %d 个整数: ", i + 1);
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("非法输入！\n");
            free(arr);
            return NULL;
        }
    }
    return arr;
}

double calculateAverage(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return (double)sum / size;
}
void freeArray(int *arr)
{
    free(arr);
}

void test3()
{
    Student students[N];
    inputStudents(students, N);
    printStudents(students, N);
}
// 初始化单个学生信息（从输入填充结构体）
void initStudent(Student *student)
{
    printf("输入学生姓名\n");
    scanf("%s", student->name);
    printf("输入学生年龄\n");
    scanf("%d", &student->age);
    printf("输入学生成绩\n");
    scanf("%lf", &student->score);
}

// 批量输入N名学生信息（填充结构体数组）
void inputStudents(Student *students, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("输入第 %d 个学生信息\n", i + 1);
        initStudent(&students[i]);
    }
}

// 打印N名学生信息
void printStudents(const Student *students, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("姓名：%s\t年龄：%d\t成绩：%.2f\n",
               students[i].name, students[i].age, students[i].score);
    }
}
