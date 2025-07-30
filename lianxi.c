#include <stdio.h>

void selectsort(int num[], int n);
void bullersort(int num[], int n);
void insertsort(int num[], int n);
void quicksort(int num[], int start, int end); 
int main()
{
    int input[10] = {12, 32, 423, 56, 2, 89, 54, 78, 90, 23};
    int input1[10] = {11,2,34,23,5, 78,9,55,99,6};
    selectsort(input, 10);
    printf("\n");
    bullersort(input, 10);
    printf("\n");
    insertsort(input, 10);
    printf("\n");
    quicksort(input1, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", input1[i]);
    }
}

void bullersort(int num[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (num[j] < num[j + 1])
            {
                temp = num[j + 1];
                num[j + 1] = num[j];
                num[j] = temp;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", num[i]);
    }
}

void selectsort(int num[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (num[j] < num[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            temp = num[i];
            num[i] = num[min];
            num[min] = temp;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", num[i]);
    }
}

void insertsort(int num[], int n)
{
    int temp;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j > 0; j--)
        {
            if (num[j] < num[j - 1])
            {
                temp = num[j];
                num[j] = num[j - 1];
                num[j - 1] = temp;
            }
            else
            {
                break;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", num[i]);
    }
}

void insertsort1(int num[],int n)
{

}

void quicksort(int num[], int start, int end)
{
    int i = start;
    int j = end;
    int key = num[start];
    while (i < j)
    {
        while (i < j && num[j] >= key)
        {
            j--;
        }
        num[i] = num[j];
        while (i < j && num[i] <= key)
        {
            i++;
        }
        num[j] = num[i];
    }
    num[i] = key;

    if (i - 1 > start)
    {
        quicksort(num, start, i - 1);
    }

    if (i + 1 < end)
    {
        quicksort(num, i + 1, end);
    }
}