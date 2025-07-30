#include <stdio.h>

void zhizhenshuzu();
void shuzuzhizhen();
void my_swap();
void yiwei_diff_erwei();
void callback(int x, int y, void (*func)(int, int));
void add(int a, int b);
void cut(int a, int b);
int main()
{
    // zhizhenshuzu();

    // shuzuzhizhen();

    // int a = 10, b = 20;
    // int *p = &a, *q = &b;
    // int **p1 = &p, **q1 = &q;
    // printf("ָ��pָ���ַ��%p ָ��qָ���ַ��%p\n", p, q);
    // my_swap(p1, q1);
    // printf("ָ��pָ���ַ��%p ָ��qָ���ַ��%p\n", p, q);
   
    // yiwei_diff_erwei();

    callback(10, 5, add);      // �ص� add
    callback(10, 5, cut); // �ص� cut
    return 0;
}

// ָ������
void zhizhenshuzu()
{
    int arr[2][3] = {1, 2, 3, 4, 5, 6};
    int *p[2];
    for (int i = 0; i < 2; ++i)
        p[i] = arr[i];

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j)
            printf("%d ", p[i][j]);
    printf("\n");
}
//����ָ��
void shuzuzhizhen()
{
    int arr[2][3] = {1, 2, 3, 4, 5, 6};
    int (*p)[3] = arr;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j)
            printf("%d ", *(*(p + i) + j));
    printf("\n");
}

void my_swap(int **p, int **q)
{
    int *t = *p;
    *p = *q;
    *q = t;
}

void yiwei_diff_erwei()
{
    int arr1[4] = {1, 2, 3, 4};
    int arr2[2][3] = {1, 2, 3, 4, 5, 6};
    printf("arr1        = %p\n", arr1);
    printf("&arr1       = %p\n", &arr1);
    printf("&arr1[0]    = %p\n", &arr1[0]);
    printf("arr2        = %p\n", arr2);
    printf("&arr2       = %p\n", &arr2);
    printf("&arr2[0]    = %p\n", &arr2[0]);
    printf("&arr2[0][0]    = %p\n", &arr2[0][0]);
}

void add(int a, int b)
{
    printf("�ӷ����: %d\n", a + b);
}

void cut(int a, int b)
{
    printf("�������: %d\n", a - b);
}

// ���պ���ָ����Ϊ�ص�
void callback(int x, int y, void (*func)(int, int))
{
    func(x, y);
}