#include <stdio.h>
#include <string.h>

int my_strlen(const char *p);
char my_strcat(char *dest, const char *source);
void swap_if_greater(int *a, int *b);
int sum(int *arr, int size);
int main()
{
    char arr[50] = {"hello"};
    char add[10] = {"world"};
    // printf("%d\n", strlen(arr));
    // printf("%d\n", my_strlen(arr));
    // printf("%s\n", strcat(arr, add));
    my_strcat(arr, add);
    puts(arr);
    // int a =10,b =20;
    // swap_if_greater(&a,&b);
    // printf("%d %d\n",a,b);
    // int arr[5] = {1, 2, 3, 4, 5};
    // int *num = arr;
    // sum(arr, 5);
}

char my_strcat(char *dest, const char *source)
{
    while (*dest)
    {
        dest++;
    }
    while (*source)
    {
         *dest = *source;
        dest++;
        source++;  
        
       
    }
   
}

int my_strlen(const char *p)
{
    int count = 0;
    while (*p)
    {
        p++;
        count++;
    }
    return count;
}

int sum(int *arr, int size)
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        result += *arr;
        arr++;
    }
    printf("%d", result);
}

void swap_if_greater(int *a, int *b)
{
    int t = *a;
    if (*a > *b)
    {
        *a = *b;
        *b = t;
    }
}
