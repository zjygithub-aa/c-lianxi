/**
 * 1.����ָ��
 *      const int *p;
 *      int const *p;
 *      ��������һ��ָ�룬���ε�ָ��ָ����ڴ��ֵΪ������  ָ���ָ������޸ģ�����ֵ�����޸�
 * 2.ָ�볣��
 *      int *const p;
 *      ��������һ�����������ε�ָ��Ϊ������ָ����ָ����ڴ��ֵ�����޸ģ����������޸�ָ��
 *   �ɼǣ�const��*��֮ǰ��ʾ��һ������ָ�룬���ε���ֵΪ���� const��*�󣬱�ʾ��һ��ָ�볣�������ε���ָ��Ϊ����
 * 3.�ַ�����������  strstr   strtok
 * 4. �������Ĳ���
 *      int argc���û��ն˴��ݹ��������������
 *      char const *argv[]����һ������ָ�����飬���������ն�����Ĳ���(���
 *      ���ã�Ϊ�˷����û�������һ������
 * 5.����ָ��
 *      void *����ָ�� ������ת��Ϊ�κ�����
 *      - void *ָ�����ָ������������ڴ�ռ�
 * 6.�ڴ沼��
 *      ջ��(��ַ��������): �ֲ�����������������ֵ��
 *      ������  �û���̬������ڴ�
 *      ȫ������data����ȫ��/��̬�����ѳ�ʼ��    bss����ȫ��/��̬����δ��ʼ����  
 *              �ַ����������ַ���
 *      ���������������ɵĶ����ƴ���
 *   ע�⣺��ַ��Ŵ�С  ������  ��ַ�ĸߵ�  ����Ϊÿ������ı���ǲ�һ��
 * 7.��̬����  #include <stdlib.h>
 *      ����������ڴ�
 *      malloc�����ڴ��е����ݲ�һ�����г�ʼ����ֵΪ0
 *      realloc������
 *      calloc:���ڴ��е����ݽ��г�ʼ����ֵΪ0
 *      �ͷ�
 *       free
 *     �ڴ����
 *      memset
 *      memcpy
 *      memcmp
 * 7.����ָ������
 *      �������� (*������[])(���������б�)��
 *      int (*f_pNum[3])(int ,int);
 *       ��������һ�����飬ÿһ��Ԫ�ض���һ������ָ���������Ǻ����ĵ�ַ
 *      ��Ҫ����״̬��ʵ�֡�����������ص��������


 *      
*/

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
//1.����ָ����ָ�볣��
void pointer1(void);
//2.����ָ��
void pointer2(void);
//3.����ָ������
void pointer3(void);
int main(int argc, char const *argv[])
{

  
    // int i;
    // for(i=0;i<argc;i++)
    // {
    //     printf("%s\n",argv[i]);
    // }
   pointer3();
 
    return 0;
}

//1.����ָ����ָ�볣��

void pointer1(void)
{
    int a=10,b=20;
    const int *p=&a;//����һ������ָ��p  pָ����a�ĵ�ַ
    int const *q=&a;
    p=&b;  //����ָ�뱾������һ��ָ�룬���ε���ָ��ָ��ռ��ֵ���ܱ��޸�  ָ�ſ����޸�ָ��
   // *p=100;  ��������ôд
   q=&b;
  // *q=200;��������ôд
    int * const k=&a; //ָ�볣���������޸�ָ�� �����޸�ֵ
   // k=&b;��������ôд
    *k=200;
    printf("a:%d b:%d\n",a,b);
    //�����ַ�����������  ���ַ����в����Ӵ�
    char *findpos=strstr("Hello world hello","ello");//findpos���� ���ַ������ҵ���һ�γ����Ӵ��ĵ�ַ
    printf("findpos:%p %p\n",findpos,"Hello world hello");
    printf("%s\n",findpos);//�������ʼλ�� �����һ���ַ�

    //�ַ����ָ�
    char dest[100]={"this is my book,it is English-book"};
    char *delim={" ,-"};
    char *tokstr;//���շָ�������ַ���
    printf("�ַ����ָ�\n");
    tokstr=strtok(dest,delim);
   
    //�����Ҫ����������зָ�  ��һ������ֻ�ܴ�NULL  ����Ѿ�û�п��Էָ�� �᷵��һ��NULL
    while (tokstr!=NULL)
    {
         printf("tokstr:%s\n",tokstr);
        tokstr=strtok(NULL,delim);
    }
    


}
//����ָ�� ���ڴ涯̬����
void pointer2(void)
{
    //�����ڴ����
   int s[5]={0};//16
    memset(s,0,sizeof(s));
   for(int i=0;i<5;i++)
   {
    printf("%d\t",s[i]);
   }
   printf("\n");
   int a[5]={10,20,30,147,5},b[8]={10,20,30,400,5,6,7,8};
   int cmp1=memcmp(a,b,sizeof(int)*5);
   printf("cmp1:%d\n",cmp1);
    while(1);
    // int a=10;
    // void *p;//����һ����������ָ��
    // p=(void*)(&a);//��a�ĵ�ַ ǿתת��Ϊ������ ����pָ��a�ĵ�ַ
    // *(int *)(p)=200;//ͨ������ָ��p�޸�a��ֵ ���Ƚ�ָ��ǿת��Ϊint���� Ȼ����ȥ�޸�
    // printf("a=%d\n",a);
       int n;
   printf("���������ֵĸ���\n");
    scanf("%d",&n);
   // int *arr=(int *)malloc(n*sizeof(int));//���������  n*4���ֽ� �ռ� ��arrָ����οռ���׵�ַ
   int *arr=(int *)calloc(n,sizeof(int));
    printf("������������\n");
    for(int i=0;i<n;i++)
    {
       // printf("%d\t",*arr);
        //arr++;
        printf("%d\t",arr[i]);

    }
    printf("\n");
    //��ʱ ���Խ�arr������һ��������ʹ��
    printf("������n������\n");
    int *t=arr;
    for(int i=0;i<n;i++)
    {
        scanf("%d",t);
        t++;
       // scanf("%d",&arr[i]);
    }
    printf("��������Ҫ���ݵ����ݸ���\n");
    int m;
    scanf("%d",&m);
    arr=(int *)realloc(arr,sizeof(int)*(m+n));
      printf("���������%d������\n",m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",arr+n+i);
    }
    printf("�������ݺ� ������������\n");
    for(int i=0;i<m+n;i++)
    {
       // printf("%d\t",*arr);
        //arr++;
        printf("%d\t",arr[i]);

    }
    printf("\n");
    //memset  ��ĳһ���ڴ棬��� ����ֽڵ� ͬһ������
    // memset(arr,0,sizeof(int)*n);
    // printf("������������\n");
    // for(int i=0;i<n;i++)
    // {
    //      // printf("%d\t",*arr);
    //     //arr++;
    //     printf("%d\t",arr[i]);
    // }
    //  printf("\n");
     //memcpy  �ڴ�ĸ���
     int num[10]={100,200,300,400,5,65,7,8,9,10};
  //   memcpy(arr,num,sizeof(int)*3+1);//400 
  memcpy(arr,num,sizeof(int)*3);
      printf("memcpy�������������\n");
    for(int i=0;i<n;i++)
    {
         // printf("%d\t",*arr);
        //arr++;
        printf("%d\t",arr[i]);
    }
     printf("\n");
     //memcmp  �ڴ�Ƚ�
    int cmp= memcmp(arr,num,sizeof(int)*4);//���  ����0   ��
    printf("cmp:%d\n",cmp);


    free(arr);//�ͷ�
}
int func1(int a,int b)
{return a+b;}
int func2(int a,int b)
{
    return a*b;
}
int func3(int a,int b)
{
    return a-b;
}
//3.����ָ������
void pointer3(void)
{
    int (*f_pnum[3])(int,int)={func1,func2,func3};
    int i;
    for(i=0;i<3;i++)
    {
        int res=f_pnum[i](10,20);//����ָ������  ����������ͬ �ĺ���
        printf("res:%d\n",res);
    }
}