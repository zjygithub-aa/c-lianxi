#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
#define length 100
int sum(int num1,int num2)
{
    return num1 + num2;


}
int max(int num1, int num2)
{
    if(num1 > num2)
    {
        return num1;
    }
    else
    {
        return num2;

    }
}
int  lifangti(int weight, int height)
{
    return length * weight * height;

}
void print()
{
    //�����Ż���������ź��֣��������ڼ�����������ֻ���뷨��GO TO
    printf("�� �� �� �� Χ ��\n"
    "�� �� �� �� κ ��\n"
    "�� �� �� ɱ �� ��\n"
    "�� �� �� �� �� ��\n"
    );
}

void Screen_print(); //��������
int find_min();
int jiecheng();
float f_to_c();
int main()
{
    
    int num1,num2;
    printf("����������������\n");
    scanf("%d %d",&num1,&num2);
    printf("sum = %d\n", sum(num1, num2));
    printf("max = %d\n", max(num1, num2));
    printf("����������Ϊ%d\n",lifangti(num1,num2));
    print();
    Screen_print(); //��������
    printf("%d\n", find_min());
    printf("%d\n",jiecheng());
    printf("%.2f\n",f_to_c());
    return 0;

}



void Screen_print()    //����: ʵ�ֹ���
{
    //�˵���  ʵ�ֵ��ǲ˵����ı༭
    printf("--------------------------------------------------\n");
    printf("| ��������ļҵ�ַ��                           |\n");
    printf("| �������㹫˾��ַ��                            |\n");
    printf("--------------------------------------------------\n");
    printf("\n");
    printf("��ļҵ�ַ��");

    char addr[128] = "";
    char family[128] = "";
    scanf("%s", addr);
    printf("��Ĺ�˾��ַ:");
    scanf("%s", family);
    printf("...�洢��...\n");
    sleep(2);
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("| ��ļҵ�ַ�ǣ�%s                             \n", addr);
    printf("| ��Ĺ�˾��ַ�ǣ�%s                            \n", family);
    printf("--------------------------------------------------\n");
    printf("\n");
}
int  find_min()
{
    printf("����3�����Ƚϴ�С");
    int a,b,c;
    int temp;
    scanf("%d %d %d",&a,&b,&c);
    temp =a;
    if(b>temp&&c>temp)
    {
        return temp;
    }
    else
    {
        if(b>c) return c;
        else return b;

    }
    
}

int jiecheng()
{
    int ready,count;
    count =1;
    printf("������ʼֵ��\n");
    scanf("%d",&ready);
    for(int i =ready;i>0;i--)
    {
        count = i*count;
    }
    return count;
}

float f_to_c()
{
    float f,c;
    printf("���뻪���¶ȣ�\n");
    scanf("%f",&f);
    c =(f -32)*(float)5/9;
    return c;

}