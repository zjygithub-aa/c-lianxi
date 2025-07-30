#include <stdio.h>
#include <string.h>
#define N 5
#define IGNORE_SPACE 1

void vote(void);
int sum_all_elements(int arr[3][4]);
void str_cat(char *dest, const char *src);

//主函数入口
int main()
{
    // #if defined N
    // printf("宏定义已经定义\n");
    // #endif
    // #if N
    // printf("真\n");
    // #endif
    // #undef N
    // printf("宏定义已经失效\n");
    // #ifdef N
    // printf("没有失效\n");
    // #endif
    // #ifndef  N
    // printf("真的失效了\n");
    // #endif

    //     vote();
    //     return 0;
//      int arr[3][4] ={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
//    printf("二维数组所有元素的和:%d\n",sum_all_elements(arr));

    char dest[100] = "Hello";
    const char *src = " World!";

    str_cat(dest, src);
    printf("%s\n", dest);

    return 0;
}

int sum_all_elements(int arr[3][4])
{
    int result =0;
    for(int i =0;i<3;i++)
    {
        for(int j =0 ; j<4;j++)
        {
            result +=arr[i][j];
        }
    }
    return result;
}

void str_cat(char *dest, const char *src)
{
     while (*dest) {
        dest++;
    }

    // 拼接 src 到 dest
    while (*src) {
#ifdef IGNORE_SPACE
        if (*src != ' ') {
            *dest++ = *src;
        }
#else
        *dest++ = *src;
#endif
        src++;
    }

    *dest = '\0'; // 结束符

}









void vote(void)
{
    // char student[N][20]={"zhangsan","lisi","wangwu","zhaoiu","lili"};
    char student[N][20] = {"\0"};
    int NuM[N] = {0};  // 统计得票
    char name[20];     // 用来投票
    int curnum = 0, j; // 当前入围人数
    for (int i = 0; i < N; i++)
    {
        printf("请投票:");
        gets_s(name,sizeof(name)); // 因为fgets会将换行读入，对字符串进行处理
        // 拿投票输入得名字与所有入围名单去进行比较
        for (j = 0; j < curnum; j++) // 在当前入围得名单中去查找
        {
            if (strcmp(name, student[j]) == 0) // 匹配上
            {
                NuM[j]++; // 找到了 票数+1，就不继续找了
                break;
            }
        }
        if (j == curnum) // 在入围名单中没有找到这个人
        {
            // 那么将该人加入入围名单 并且票数+1 入围人数+1
            strcpy(student[j], name);
            NuM[j]++;
            curnum++;
        }
    }
    // 投票结束后 输出以下统计得票情况
    for (int i = 0; i < curnum; i++)
    {
        printf("%s 得票数为: %d\n", student[i], NuM[i]);
    }
}