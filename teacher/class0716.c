/*
1.for(i=0,j=10;i*2<j,j>5;i++,j--)//������������˵,����м���ʽ�ö��Ÿ�����ѭ�����������һ�����ʽΪ׼
2.�������
    ����������ڴ�����������ͬ���͵ı����ռ�
3.���鶨��
    ��������  ������[�������ʽ];//�������ʽ ��������ĳ���
    int  num[10];//����һ�����Դ洢10���������ݵ����飬�൱�ڶ�����10������  ÿ�������ֱ�Ϊ  ������[�±�]
4.Ԫ�ص�����
    ������[�±�]  �����������±��Ǵ�0��ʼ��
    int  num[10];///������num�в�����num[10]���Ԫ��
    һ��Ԫ�ؾ���һ������
5.�������������
    ��int num[10];����Ϊ��
    �����е�i��Ԫ�ؽ������� ��scanf("%d",&num[i]);
    �����е�i��Ԫ�ؽ������ ��pritnf("%d",num[i]);
6.����Ķ���ͳ�ʼ����ֵ    
    int num[10]={1,2,3,4,5,6,7,8,9,10};//���岢��ʼ����ֵ
    int num[10]={1,2};//����һ������  �� num[0]��ֵΪ1  num[1]��ֵΪ2 ������Ԫ��ֵĬ��Ϊ0 ,��ֵ���ݵĸ����������鳤��ʱ������Ԫ��ֵĬ��Ϊ0
    int num[10];//Ԫ�ص�ֵ�ǲ�ȷ����
    int num[10]={0};//�����������Ԫ�س�ʼ����ֵΪ0
    int num[]={1,2,3,4};//������ôд  �������������û�и��������С����������ʼ����ֵ������ĳ����ɳ�ʼ����ֵ�����ݵĸ�������
7.һ������£�������ĵط� �������ѭ���ǰ�ʹ�õ�
8.��һά����int num[10]��,�����������׵�ַ Ҳ����num�ȼ���&num[0] ��num+i�ȼ��� &num[i] ,*(num+i)����num[i]
9.��ַ��������
10.�ַ��������ַ���
    ���壺char  ������[���鳤��]��
    �ַ�������һ���ַ�����һ������ ����˫����������������  �ַ���Ĭ����'\0'��β
    ����͸�ֵ��
        char str[5]={'h','e','l','l','o'};
        char str[]={'h','e','l','l','o'};
        char str[] ={"hello"};
        char str[20]={"hello"};
    ��ʽռλ�� ��%c  �ַ�           %s���ַ��� ��ͨ���ַ����׵�ַ����'\0'������
    '\0'��ascii��ֵΪ0
11.�ַ��������������
    gets:�ַ������뺯��  ----ֻ��windows����ϵͳ������  ������ӵ���linux ��ֻ����fgets����gets
    fgets(s1,sizeof(s1),stdin);stdin:�������ļ�  �����ļ��ж�ȡsizeof(s1)-1���ֽ����ݵ� s1��,�Ὣ���ж���
    fgets��gets�����������л�ֹͣ��ֻ��fgets�Ὣ���ж���
    puts:�ַ����������  ���ʱ���Զ�����
12.�ַ�����Ȼ��һ�������������ַ������Ե���������ʹ��
13.�ַ�����������    Ҫ������ͷ�ļ�   #include <string.h>
    strlen:���ַ�������    �÷���int len =strlen(s1);
    strcat:�ַ�������      �÷���strcat(s1,s2);//ʵ�ֽ�s2������s1����
    strcpy:�ַ����ĸ���    �÷�:strcpy(s1,s2);//���ַ���s2������s1
    strcmp:�ַ����ıȽ�    һ���÷���if(strcmp(s1,s2)==0) {    }   //�ú��������Ƚ������ַ����Ƿ���ͬ�������ȷ���0.���s1>s2�������������s1<s2���ظ���
    sprintf:��ʽ��ת��Ϊ�ַ���   �÷���sprintf(s1,"��ʽ����",�������)��//printf������ʽ��������ݵ��ն�  ��sprintf��ʽ��������������ַ��ַ�����s1����
    sscanf:�ַ�����ʽ������ת��  �÷���sscanf(s1,"��ʽ����",��ַ����);//�����ո�/tab/�س�ֹͣ���룬��s1�и�ʽ���������ݴ��뵽��ַ���ж�Ӧ��������
*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
int main(int argc, char const *argv[])
{
    char s1[100]={'\0'},s2[100]={"wangwu 19 56.4"};
    char s3[100]={"name :zhaoliu age:22 weight:65.78"};
    char number[20]={"1234.5678"};//����һ�����ݷֳ��� �������ͱ���a��1234 b�д�5678
    int age;
    char name[20];
    float weight;
    printf("name :%s age:%d weight:%f\n","lisi",20,62.5);
    //sprintf����
    sprintf(s1,"name :%s age:%d weight:%f","lisi",20,62.5);//�����ݸ�ʽ��ת��Ϊһ���ַ���
    printf("%s\n",s1);
    scanf("%s%d%f",name,&age,&weight);
    printf("name :%s age:%d weight:%.2f\n",name,age,weight);
    //sscanf����
    sscanf(s2,"%s%d%f",name,&age,&weight);
    printf("name :%s age:%d weight:%.2f\n",name,age,weight);
    sscanf(s3,"name %s age:%d weight:%f",name,&age,&weight);
    printf("name :%s age:%d weight:%.2f\n",name,age,weight);
    int a,b;
    sscanf(number,"%4d.%d",&a,&b);
    printf("a=%d b=%d\n",a,b);

    return 0;
}

#if 0
//�ַ�����������
int main(int argc, char const *argv[])
{
    char s1[100]={"hello world"},buf[20]={" WORLDworld"};
    //�ַ�������
    int len=strlen(s1);
    printf("s1���ַ����ĳ���:%d\n",len);
    //�ַ�������
    printf("����ǰs1��%s\n",s1);
    strcat(s1,"HELLO");
     printf("���Ӻ�s1��%s\n",s1); 
     strcat(s1,buf);
     printf("2�����Ӻ�s1��%s\n",s1); 
  //  s1="world";  ������ֱ�Ӹ�ֵ
    strcpy(s1,"world");//�ַ�������
    printf("�����Ժ�s1:%s\n",s1);
    //�ַ����Ƚ�
    printf("�Ƚ�ǰ��s1:%s buf:%s\n",s1,buf);
   int cmp=strcmp(s1,buf);
   if(cmp>0)
   {
    printf("s1��\n");
   }
   else if(cmp<0)
   {
    printf("buf��\n");
   }
   else
   {
    printf("���\n");
   }
    return 0;
}


//Ҫ��Ӽ�������һ���ַ���ʵ���ַ����ķ����Ų�������������룺hello world�����ַ�����s1,ʵ�ַ����Ժ�s1�д����dlrow olleh
int main(int argc, char const *argv[])
{
    char s1[100]={'\0'};
    printf("������һ���ַ�\n");
    fgets(s1,sizeof(s1),stdin);//�Ӽ��� ����һ���ַ�  ���� s1
    //�ǵý�'\n'ȥ��
    int len=0;//���ַ����ĳ���
    while(s1[len])//��Ϊ�ַ�����ĩβ Ĭ����'\0'��β
   {    
     len++;
   }
    //��ǰ��õ�len����\n�Ǹ��ַ���   ����-1
    len--;//��ʱ��len���±��Ӧ���� '\n'��λ�� �������Ҫ������β������
    //��β�ַ�����
    int i=0,j=len-1;
    while(i<j)//ֻ��i<j�Ž���
    {
        char t=s1[i];
        s1[i]=s1[j];
        s1[j]=t;
        i++,j--;
    }
    printf("�����%s\n",s1);
    return 0;
}


int main(int argc, char const *argv[])
{
    char s1[50]={"hello world"};
    printf("s1:%s\n",s1);
    printf("%c\n",s1[3]);
    s1[3]='L';
      printf("%c\n",s1[3]);
      printf("s1:%s\n",s1);
      printf("%c\n","hello world"[6]);//�ַ���������Ե���һ���׵�ַȥ��
   // "hello world"[6]='W';//��һ������ �������ı��
    return 0;
}


//����һ���ַ��������д�дӢ���ַ��ĸ�����СдӢ���ַ�����  �����ַ��������Լ������ַ�����
int main(int argc, char const *argv[])
{
    
    char s1[50]={'\0'};//����һ���ַ�����
    int ENG=0,eng=0,num=0,other=0;
    printf("������һ���ַ�\n");
  // gets(s1);//���Ὣ���ж���
  //scanf("%s",s1);//Ϊʲô����ȡ��ַ�� ��Ϊ���������ǵ�ַ
  fgets(s1,sizeof(s1),stdin);//stdin:�������ļ�  �����ļ��ж�ȡsizeof(s1)-1���ֽ����ݵ� s1��,�Ὣ���ж���
    puts(s1);
 //   printf("s1:%s\nceshi",s1);
    for(int i=0;s1[i]!='\0';i++)//'\0'��ascii�����0
    {
  
        if(s1[i]>='A'&&s1[i]<='Z')
        {
            ENG++;
        }
        else if (s1[i]>='a'&&s1[i]<='z')
        {
           eng++;
        }
        else if (s1[i]>='0'&&s1[i]<='9')
        {
           num++;
        }
        else
        {
            other++;
        }  

    }
    printf("ENG:%d eng:%d num:%d other:%d\n",ENG,eng,num,other);
    return 0;
}


//�����ַ����Ļ���֪ʶ
int main(int argc, char const *argv[])
{
    char str[]={'h'};
    char s1[5]={'h','e','l','l'};
    char s2[]={"hello"};
    char s3[20]={'h','e','l','l','o'};//����ʵ�����ݸ����������鳤��ʱ������Ԫ��Ĭ��Ϊ0
    printf("str:%lu s1:%lu s2:%lu s3:%lu\n",sizeof(str),sizeof(s1),sizeof(s2),sizeof(s3));
    printf("str:%s s1:%s s2:%s s3:%s \n",str,s1,s2,s3);

    return 0;
}


//������ڴ� �Լ���С
int main(int argc, char const *argv[])
{
    int arr[]={1,2,3};
    for(int i=0;i<5;i++)
    {
        printf("&arr[%d],%p\n",i,&arr[i]);
        printf(" arr+%d :%p\n",i,arr+i);

    }
    printf("����Ĵ�СΪ%lu���ֽ�\n",sizeof(arr));
    for(int i=0;i<3;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    return 0;
}


//�ĸ��������ֵ  
int main(int argc, char const *argv[])
{
    // int a=12,b=43,c=4,d=32,max;
    // max=a>b?a:b;
    // max=max>c?max:c;
    // max=max>d?max:d;
    // printf("max:%d\n",max);
    int num[10]={0},max=0;//����һ�����鲢���дӳ�ʼ����ֵΪ0
    printf("������10������\n");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&num[i]);
    }
    printf("����Ԫ�أ�");
    for(int i=0;i<10;i++)
    {
        printf("%d\t",num[i]);
    }
    printf("\n");
    //�����ֵ
    max=num[0];//����0��Ԫ��Ϊ���ֵ
    for(int i=1;i<10;i++)
    {
        max=max>num[i]?max:num[i];//�õ�ǰ�����ֵ���������ÿһ��Ԫ��ȥ���бȽϣ�ÿһ�ζ���������ֵ
    }
    printf("max:%d\n",max);
    return 0;
}


//for���+ ���������
#define T(x,y) (x+y)
#include <stdio.h>
int main(int argc, char const *argv[])
{
//    int c=T(4,5)*(6,3,10);
//    printf("c=%d\n",c);
     int i,j;
     for(i=0,j=10;j>5,i*2<j;i++,j--)
    {
        printf("ok\n");
    }
     printf("i=%d ,=%d\n",i,j);
//i= ,j=     i= .j=
    return 0;
}
#endif
