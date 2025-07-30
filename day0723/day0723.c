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
    char name[50]; // ����
    int age;       // ����
    double score;  // �ɼ�
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
    printf("����a��b,�Լ�+-*/ģʽ\n");
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
        printf("�ڴ����ʧ�ܣ�\n");
        return;
    }

    double avg = calculateAverage(arr, size);
    printf("ƽ��ֵΪ: %.2f\n", avg);

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
        printf("������� %d ������: ", i + 1);
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("�Ƿ����룡\n");
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
// ��ʼ������ѧ����Ϣ�����������ṹ�壩
void initStudent(Student *student)
{
    printf("����ѧ������\n");
    scanf("%s", student->name);
    printf("����ѧ������\n");
    scanf("%d", &student->age);
    printf("����ѧ���ɼ�\n");
    scanf("%lf", &student->score);
}

// ��������N��ѧ����Ϣ�����ṹ�����飩
void inputStudents(Student *students, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("����� %d ��ѧ����Ϣ\n", i + 1);
        initStudent(&students[i]);
    }
}

// ��ӡN��ѧ����Ϣ
void printStudents(const Student *students, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("������%s\t���䣺%d\t�ɼ���%.2f\n",
               students[i].name, students[i].age, students[i].score);
    }
}
