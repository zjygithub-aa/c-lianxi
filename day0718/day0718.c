#include <stdio.h>
#include <string.h>
#define N 5
#define IGNORE_SPACE 1

void vote(void);
int sum_all_elements(int arr[3][4]);
void str_cat(char *dest, const char *src);

//���������
int main()
{
    // #if defined N
    // printf("�궨���Ѿ�����\n");
    // #endif
    // #if N
    // printf("��\n");
    // #endif
    // #undef N
    // printf("�궨���Ѿ�ʧЧ\n");
    // #ifdef N
    // printf("û��ʧЧ\n");
    // #endif
    // #ifndef  N
    // printf("���ʧЧ��\n");
    // #endif

    //     vote();
    //     return 0;
//      int arr[3][4] ={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
//    printf("��ά��������Ԫ�صĺ�:%d\n",sum_all_elements(arr));

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

    // ƴ�� src �� dest
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

    *dest = '\0'; // ������

}









void vote(void)
{
    // char student[N][20]={"zhangsan","lisi","wangwu","zhaoiu","lili"};
    char student[N][20] = {"\0"};
    int NuM[N] = {0};  // ͳ�Ƶ�Ʊ
    char name[20];     // ����ͶƱ
    int curnum = 0, j; // ��ǰ��Χ����
    for (int i = 0; i < N; i++)
    {
        printf("��ͶƱ:");
        gets_s(name,sizeof(name)); // ��Ϊfgets�Ὣ���ж��룬���ַ������д���
        // ��ͶƱ�����������������Χ����ȥ���бȽ�
        for (j = 0; j < curnum; j++) // �ڵ�ǰ��Χ��������ȥ����
        {
            if (strcmp(name, student[j]) == 0) // ƥ����
            {
                NuM[j]++; // �ҵ��� Ʊ��+1���Ͳ���������
                break;
            }
        }
        if (j == curnum) // ����Χ������û���ҵ������
        {
            // ��ô�����˼�����Χ���� ����Ʊ��+1 ��Χ����+1
            strcpy(student[j], name);
            NuM[j]++;
            curnum++;
        }
    }
    // ͶƱ������ �������ͳ�Ƶ�Ʊ���
    for (int i = 0; i < curnum; i++)
    {
        printf("%s ��Ʊ��Ϊ: %d\n", student[i], NuM[i]);
    }
}