#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void erwei_arr_create();

float score[5][4] =
    {
        {66, 66, 66, 66},
        {90, 90, 90, 90},
        {45, 45, 45, 45},
        {50, 50, 50, 50},
        {86, 86, 86, 86}

};

// stu_score_avg��ѧ�����пγ̵�ƽ����
// score_avg���ÿγ̵�ƽ����
float stu_score_avg[5] = {0}, score_avg[4] = {0};

float get_subcore_avg(int n);
float get_stuscore_avg(int n);
int get_2fail_stu(int n);
int well_stu(int n);
int jiecheng_digui(int n);
void boom();
int sumArray(int arr[][3], int rows);
void sumRowsCols(int arrp[][3], int rows, int rowSum[], int colSum[]);

// main()���
int main(int argc, char const *argv[])
{
    // printf("ѧ����ƽ���ɼ��ǣ�\n");
    // get_stuscore_avg(5);
    // printf("\n");
    // printf("�γ̵�ƽ���ɼ��ǣ�\n");
    // get_subcore_avg(4);
    // printf("\n");
    // get_2fail_stu(5);
    // printf("\n");
    // well_stu(5);
    // printf("%d\n",jiecheng_digui(5));
    // boom();

    int arr[][3] = {{1, 2, 3}, {4, 5, 6}};
    int rows = 2;
    int rowSum[2] = {0};
    int colSum[3] = {0};
    sumRowsCols(arr, rows, rowSum, colSum);

    // ���ÿ�е��ܺ�
    printf("ÿ�е��ܺ�: ");
    for (int i = 0; i < rows; i++)
    {
        printf("%d ", rowSum[i]);
    }
    printf("\n");

    // ���ÿ�е��ܺ�
    printf("ÿ�е��ܺ�: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", colSum[i]);
    }
    printf("\n");

    return 0;
    // printf("%d \n",sumArray(arr,2));
}

float get_stuscore_avg(int n)
{
    float avg = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            avg += score[i][j];
        }
        stu_score_avg[i] = avg / 4;
        printf("%.2f  ", stu_score_avg[i]);
        avg = 0;
    }
}

float get_subcore_avg(int n)
{
    float avg = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            avg += score[j][i];
        }
        score_avg[i] = avg / 5;
        printf("%.2f  ", score_avg[i]);
        avg = 0;
    }
}

int get_2fail_stu(int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (score[i][j] < 60)
                count++;
        }
        if (count >= 2)
            printf("��%d��ͬѧ��������û�м���\n", i + 1);
        count = 0;
    }
}

int well_stu(int n)
{

    for (int i = 0; i < n; i++)
    {
        if (stu_score_avg[i] >= 80)
            printf("��%d��ͬѧƽ������80����\n", i + 1);
    }
}

int jiecheng_digui(int n)
{
    int result = 1;
    if (n == 1)
        return result;

    result = n * jiecheng_digui(n - 1);
}

void boom()
{
    srand(time(NULL));
    int num = rand() % 100 + 1;
    int epoch = 10;
    int n = 0;
    int max = 100, min = 1;
    while (n != num && epoch != 0)
    {
        printf("��%d - %d֮�����\n", min, max);
        scanf("%d", &n);
        if (n > num)
        {
            printf("��������\n");
            epoch--;
        }
        else if (n < num)
        {
            printf("����С��\n");
            epoch--;
        }
        else
        {
            printf("BOOM!!!");
            exit(0);
        }
    }
    printf("����������,��ֵ��������ս����������");
}

int sumArray(int arr[][3], int rows)
{
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            count += arr[i][j];
        }
    }
    return count;
}

void sumRowsCols(int arrp[][3], int rows, int rowSum[], int colSum[])
{
    // ����ÿ�е��ܺ�
    for (int i = 0; i < rows; i++)
    {
        rowSum[i] = 0;
        for (int j = 0; j < 3; j++)
        {
            rowSum[i] += arrp[i][j];
        }
    }

    // ����ÿ�е��ܺ�
    for (int j = 0; j < 3; j++)
    {
        colSum[j] = 0;
        for (int i = 0; i < rows; i++)
        {
            colSum[j] += arrp[i][j];
        }
    }
}



// void erwei_arr_create()
// {
//     int num[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//             printf("%d ", num[i][j]);
//             printf("&num[%d][%d]: %p\t", i, j, &num[i][j]);
//         }
//         printf("\n");
//     }

//     // �����ʼ����ֵ�Ķ���
//     int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     printf("arr size: %lu\n", sizeof(arr));
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }

//     printf("-----------------\n");
//     int array[3][4] = {{1, 2}, {3, 4}, {5, 6, 7, 8}};
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//             printf("%d ", array[i][j]);
//         }
//         printf("\n");
//     }

// }