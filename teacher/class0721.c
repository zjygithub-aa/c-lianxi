/**
 * ָ��
 * 1.���
 *      ָ����ǵ�ַ����ַ����ָ�루ͨ����˵����----��������Ҫ���
 * 2.ָ������Ķ���
 *      ��������   * ָ���������
 *      ������int *p;  //��ǰ��һ������   ����* ��һ��ָ��˵������˵��p��һ��ָ�����͵ı��� 
 *      ͬ���͵�ָ��ָ����ͬ���͵����ݵĵ�ַ
 *      ������int a=10;int *P=&a;//pָ����a�ĵ�ַ  ����˵ P��������a�ĵ�ַ
 *      ע�⣺int a=10,*p;  *p=&a;//��ôд�Ǵ����  ����ڶ����ʱ��û�г�ʼ��ָ��  ����ֻ��д��  p=&a;
 *            int *p=0x1000;//�Ǵ����  ��������
 *            int *p=(int *)(0x1000);//������ôд����Ҫ������ôд  ��Ϊ����һ�����ݱ���ǲ�ȷ���� ����֪���ñ�Ŷ�Ӧ��ַ
 * 
 * 3.   ָ�������Ӧ��
 *          ���У�int a=10;int *P=&a;
 *          *p:������ ����*  ��һ��ȡֵ�������ָ��������� ���ʵ���P��ָ�� �Ƕοռ��ֵ��a��
 *          *P=100;//�ȼ���  a=100;
 *             
 * 4.ָ����Ϊ�����Ĳ���
 * 5.Ұָ��  û��ָ���ָ�룬     ��һ����Σ�յ�ָ�� ������Ը�ָ����в�����ǳ�Σ��
 * 6.��ָ��  ָ�����ָ��ΪNULL  ���ǿ�ָ�� ��Ŀ��Ϊ�˷�ֹҰָ��   int *p=NULL;
 * 7.ָ����һά����
 *          int num[5]={10,20,30,40,50};
 *          int *p=num;//Ϊʲô ���ﲻ��  &num    ��Ϊ�����������׵�ַ��&num[0]��   �ȼ��� pָ�� num[0]�ĵ�ַ
 *         ָ��������� ���Ӽ������ ��ִ��p++;  ��ʾp=p+1,��ʱp��ָ�� ��һ��Ԫ�صĵ�ַ 
 *          ��ָ�������� p++.�ƶ����ֽ����� ��ǰָ����������������й� �������char���ͣ���ִ��p++ʱ���ƶ�����һ���ֽڣ������int���������ƶ�4���ֽ�
 *      ��һά������  num+i  ����  &num[i]  ����pָ��num,p+i���� &num[i]  ,*(p+i)����  num[i] ,*(num+i)����num[i]  ��Ҫע�����p����ִ��p++�Ĳ��� ��num������
 *      �����  ��p++;++p; *++p; ++*p; *p++;(*p)++;  
 * 8.ָ�����ַ������Լ��ַ���(����)
 *          
*/
#include<stdio.h>
#include <string.h>
//1.ָ���������
void pointer1(void);
void swap1(int c,int d);
void swap2(int *c,int *d);
void swap3(int *c,int *d);
void swap4(int *c,int *d);
//2.ָ��������
void pointer2(void);
void change_num(int *p);//ͨ��ָ���޸����������
void fanxu_num(int *p,int len);//ͨ��ָ��ķ�ʽ ʵ������ķ���
//�������ݴ洢  С�˴洢
void memory(void);
//3.ָ�����ַ���
void pointer3(void);
int main(int argc, char const *argv[])
{
//    pointer1();//ָ�������
    //pointer2();//ָ��������
 //memory();
 pointer3();//ָ�����ַ���
    
    return 0;
}

//1.ָ���������
void pointer1(void)
{
    int a=10,b=20;//  a b���������������ͱ���
    int *p=&a,*q=&b;// p 1���������ͱ����ĵ�ַ �ı���
    printf("p:%p &a:%p\n q:%p &b:%p\n",p,&a,q,&b);
    printf("*p:%d a:%d  *q:%d  b:%d\n",*p,a,*q,b);
     swap1(a,b);
     printf("swap1��*p:%d a:%d  *q:%d  b:%d\n",*p,a,*q,b);
     swap2(&a,&b);//���������p �� q�� �����Ƿ�����޸� a b��ֵ  ����   ��Ϊ p q��ֵ ���� &a &b
     printf("swap2��*p:%d a:%d  *q:%d  b:%d\n",*p,a,*q,b);
    // swap3(&a,&b);
    swap3(p,q);//ָ����Ϊ�����Ĳ��� ���д���
    printf("p:%p 1:%p\n",p,q);
      printf("swap3��*p:%d a:%d  *q:%d  b:%d\n",*p,a,*q,b);
    swap4(&a,&b);
    printf("swap4��*p:%d a:%d  *q:%d  b:%d\n",*p,a,*q,b);
    
}

//c  d ����ֵ����  ֻ�� ʵ��ֵ������ �޸�  c  d��ֵ ����Ӱ��ʵ��
//�ú��� �޸ĵ��� c d��ֵ �ĵ��Ǻ���
void swap1(int c,int d)
{
    int t=c;
    c=d;
    d=t;
}
// c ָ���� ʵ��a�ĵ�ַ dָ����ʵ��b�ĵ�ַ  �޸� *c  *d ʵ���޸ĵ��� ʵ��a  b
//�ú��� �޸ĵĺ����� ��������  a b��ֵ
void swap2(int *c,int *d)  //�β���һ��ָ������
{
    int t=*c;
    *c=*d;
    *d=t;
}
//cָ�� ʵ��a�ĵ�ַ dָ����ʵ��b�ĵ�ַ   �ó����޸ĵ���c  d��ָ��
//�ú��� �޸ĵĺ����ڲ�  c  d��ָ�� 
void swap3(int *c,int *d)
{
    int *t=c;
    c=d;
    d=t;
}
//�ú���  ������  ����t�ǿ�ָ�� ����Ұָ�� ����������ô����
void swap4(int *c,int *d)
{
    printf("1");
    int *t;//=NULL; 
      printf("2");
    *t=*c;//�Ƿ�����  t��һ��Ұָ��
      printf("3");
    *c=*d;
      printf("4");
    *d=*t;
      printf("5");
}

//2.ָ��������
void pointer2(void)
{
    int num[5]={10,20,30,40,50};
    change_num(num);//�޸������е�ֵ
     printf("����ǰ����num��ֵ\n");
    for(int i=0;i<5;i++)
    {
        printf("%d -",num[i]);
    }
    printf("\n");
    fanxu_num(num,5);
    printf("���������num��ֵ\n");
    for(int i=0;i<5;i++)
    {
        printf("%d -",num[i]);
    }
    printf("\n");

}
//ͨ��ָ���޸����������
void change_num(int *p)//int p[]
{
    //ʵ���� �����pҲ���Ե�����������ʹ��
    int i;
    // for(i=0;i<5;i++)
    // {
    //     printf("%d\t",p[i]);
    // }
    // printf("\n");
    // p[3]=100;//ͨ��p���޸� �����ڵ�ֵ
    //*p���� num[0]
    // *p++;//�Ƚ��� p++,Ȼ��ִ��*p  ִ�����Ժ� ��ʱpָ��num[1]
    // *p=200;
    // *++p;//ִ�����Ժ� ��ʱpָ��num[2]
    // *p=300;
    // *(p++);//ִ�����Ժ� ��ʱpָ��num[3] 
    // *p=400;
    // (*p)++;//ִ�����Ժ� ��ʱpָ��num[3]  *p��ֵ+1
    // ++(*p);
    printf("ͨ��*p���޸�num�����е���ֵ\n");
    int *q=p;
    for(q=p;q<p+5;q++)
    {
        *q*=10;
    }

}
//ͨ��ָ��ķ�ʽ ʵ������ķ���
void fanxu_num(int *p,int len)
{
    int *q=p+len-1;//qָ�� �������һ��Ԫ�����ڵ�ַ
    for(;p<q;p++,q--)//�ƶ�����ָ��
    {
        int t=*p;
        *p=*q;
        *q=t;
    }
}

//�������ݴ洢  С�˴洢
void memory(void)
{
    int num=0x01020304;
    char *p=(char *)(&num);//��num�ĵ�ַ���� ǿ��ת��Ϊ char* ����
    for(int i=0;i<4;i++)
    {
        printf("%p:%x\t",p,*p);
        p++;
    }
}

//ָ�����ַ���
void pointer3(void)
{
    //�Զ���һ���ַ������Ƶĺ��� (ָ�뷽ʽ)
    char *mystrcpy(char *s1,char *s2);
    int mystrcmp(char *s1,char *s2);
    char s1[10]={"hello"};
    char *p="hello";//p ָ�����ַ�������"hello"���׵�ַ
    printf("p[3]:%c\n",p[3]);
   // p[3]='L';    //������ָ������  ��Ϊ hello��һ������ �������ǲ������޸ĵ�
    printf("p:%s\n",p);
    //s1="world";  ��������ôд  ��Ϊ��C������ �ַ����鲻��������ַ�����ֵ ������ʹ��strcpy����
    p="world";//p ������ָ��  ָ���� "world"���׵�ַ
    //�������� strcpy���� ���ص�ָ��
    p=strcpy(s1,"abcd");
    printf("p:%p  s1:%p\n",p,s1);
    char *q=mystrcpy(s1,"abcd");
    printf("q:%p  s1:%p\n",q,s1);
    printf("s1:%s  p:%s  q:%s\n",s1,p,q);
    int n=strcmp("HELLO",s1);
    int m=mystrcmp("HELLO",s1);
    printf("m:%d  n:%d\n",m,n);
}

//�Զ���һ���ַ������Ƶĺ��� (ָ�뷽ʽ)
char *mystrcpy(char *s1,char *s2)
{
    char *t=s1;//����ס s1��������ĵ�ַ
    while (*s2)//��Ϊ'\0'  һֱѭ�� ��s2�ĸ����ַ� ���Ƹ� s1
    {
        *s1=*s2;
        s1++;
        s2++;
    }
    return t;
    
}
//�Զ����ַ����ȽϺ���  �ȵ���ascii��ֵ  ������Ӧ��λ�õ�ascii�����������Ƚ�
int mystrcmp(char *s1,char *s2)
{
    while(*s1==*s2 && *s1!='\0' && *s2!='\0')//��� ��ͬ�����кŶ�Ӧ���ַ���Ȳ�������ָ����ָ���Ԫ��ֵ��Ϊ'\0' �����ѭ�� �����ж�
    {
        s1++;
        s2++;
    }
  //   return *s1-*s2;//������  ��ʱ *s1��*s2��Ϊ'\0'  
    if(*s1==*s2)
    return 0;
    else if(*s1>*s2)
    return 1;
    else 
     return -1;
}