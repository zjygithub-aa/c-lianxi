/**
 * 1.ָ��������
 *   p++; ++p;*p++;*(p++); (*p)++;++*p;*++p
 *   ����� p+1  q+1  p<q  q-p ����Щ����ĵ�ǰ��  �� ָ��ָ���ͬһ������
 * 2.ָ������
 *  ��������һ�����飬��һ��������ָ������飻Ҳ����˵ÿһ��Ԫ�ض��൱��һ��ָ�������ÿһ��Ԫ�ش�Ķ��ǵ�ַ
 *  ���壺 �������� * ������[����];
 *          int *p_num[4];//������һ�����飬��������p_num���� p_num+i����&p_num[i] ��ô*(p_num+i)����p_num[i]
 *      �ڶ���һ������ʱ������������û��д�����С��һ���ǵó�ʼ����ֵ
 *  һ���϶�ά�������ʹ��p_num[i]
 * 3.����ָ��
 *      ��������һ��ָ�룬��һ����ָ�룬����ָ���n��Ԫ�ص�һά����
 *     ���壺int (*p_num)[4];//��ʾ����ָ��һ����4��Ԫ�ص�һά����
 *      һ���϶�ά�������ʹ��p_num[i]
 * 4.����ָ��
 *      ָ��ָ���ָ��
 *     ���壺�������� **������;
 *      �༶ָ��
 * 5.������ָ��
 *      ��һά������ int arr[10];    ������arr����һ���׵�ַ
 *          arr����һ�����������൱��ָ����Ԫ�صĵ�ַ��ָ��  ���� int *����,����Ϊ4���ֽ�
 *          &arr:����ĵ�ַ ��ʽת��Ϊ���������ָ��  ����Ϊ  int (*)[10] ������Ϊ4*10���ֽ�
 *          &arr[0]:��Ԫ�صĵ�ַ������Ϊ4
 *      �ڶ�ά���� int arr[3][4];   arr ��&arr ��&arr[0] �� &arr[0][0]��ֵ��һ����
 *          arr����һ������������ʽת��Ϊָ���������е�ָ�룬����Ϊ int (*)[4],����Ϊ 4*4���ֽ�
 *          &arr:������ĵ�ַ ������Ϊ int (*)[3][4] ���һ����ά����ָ�루һά����ָ�����ָ��һ�У���ά����ָ��ָ��������ά���飩��
 * ����Ϊ 3*4*4���ֽ�
 *          &arr[0]:���еĵ�ַ��&num[0] ��ָ����һ�е�ָ�룬����Ϊ int (*)[4]���� num ��������ͬ��
 *          &arr[0][0]:��Ԫ�صĵ�ַ ������Ϊ4
 * 6.ָ����ռ�ռ��ֽڴ�С
 *      ��������������Ͷ��仯�������ɴ������������������� �������32λ��ָ��Ĵ�СΪ4���ֽڣ����64λ�ľ���8���ֽ�
 * 7.����ָ��  ��  ָ�뺯��
 *      ָ�뺯������������һ������������ֵ����Ϊָ��ĺ���  ����֮ǰд��mystrcat \mystrcpy���� 
 *      ����ָ�룺��������һ��ָ�� ����һ����������ָ������ָ��
 *      ����ָ�붨�壺  ����ֵ����  (*ָ�������)(�β������б�)��
 *              ������int (*p_f)(int ,char);//����ָ��  ������ָ��һ������ֵ����Ϊint ���βηֱ�Ϊint �� char���ͱ����ĺ���
 *      ʹ�ú���ָ��ʱһ��Ҫע�⣬�β��б�����Ҫһ�£�����ҲҪһһ��Ӧ
 * 8. �ص�����
 *    ����ʵ�ַ� ��������øú��������ɽӿ��ṩ�������øú������ͳ�Ϊ�ص�������
*/

#include<stdio.h>
void pointer1(void);
//ָ������
void pointer2(void);
//����ָ��
void pointer3(void);
//����ָ��
void pointer4(void);
//ָ��߼�
void pointer5(void);
//ָ��ռ��С
 void pointer6(void);
 //����ָ��
  void pointer7(void);
  //�ص�����
    void pointer8(void);
//������ָ��
void test(void)
{
    int (*p)[4];//һά����ָ�� ����ָ�� ָ��һ����4��Ԫ�ص�һά����  ������ ����һ��ָ��
    int arr[4];//arr ��һ�������� Ҳ����Ԫ�صĵ�ַ&arr[0],����Ϊint*
    //&arr����һ������ĵ�ַ ���е�ַ������ int (*)[]�����ִ�� &arr+1  ,��ʵ�Ǽ�һ��ά�ȵĴ�С ����1�У�
    p=&arr;
    printf("&arr:%p &arr+1:%p\n",arr,&arr+1);
    int num[3][4];//��ά����  num�൱�����еĵ�ַ &num[0]  ,��num[0]������һ��һά�������� ������ num��һ��int (*)[]����
    //&num :����һ����ά����ĵ�ַ ������ int (*)[][]���� ��ά����ָ�룬һ��ζ�ſ�������ָ����ά���� 
    printf("num:%p &num+1:%p\n",num,&num+1);//+1���Ǽ�һ��ά��
}
int main(int argc, char const *argv[])
{
    //����ָ��
    //pointer4();
   // pointer5();
   // pointer7();
   pointer8();
    return 0;
}
void pointer1(void)
{
    int num[10]={11,22,33,44,5,6,7,8,9,10};
    int *p=num;
    int c=*p++;//�ȼ��� c=*p  ;p=p+1;
    printf("c:%d ,*p:%d\n",c,*p);
    int d=*++p;//�ȼ��� p=p+1; d=*p
    printf("d:%d *p:%d\n",d,*p);
    int e=(*p)++;//�ȼ��� e=*p ;*p=*p+1;
    printf("e:%d *p:%d\n",e,*p);
    int f=*(p++);//�ȼ��� f=*p  ;p=p+1;    *p++�ȼ��� *(p++)
    printf("f:%d  *p:%d\n",f,*p);
    int g=++*p;//�ȼ���*p=*p+1;g=*p;  pû�и�ָ�� ���� ֵ+1
    printf("g:%d *p:%d\n",g,*p);
}
//ָ������

//ͨ��ָ������ ���ʶ�ά���� �������Ԫ�ص�ֵ �����ά��������Ԫ�صĺ�
int getsum(int *q_num[4])
{
    int sum=0;
    //��ʱq_num���Ե��� arr��ʹ��
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<2;j++)
        {
           // printf("%d\t",q_num[i][j]);
            // printf("%d\t",(*(q_num+i))[j]);//�ȼ��� arr[i][j] ,*(arr+i):�е��׵�ַ ����*(arr+i)+j����&arr[i][j]
             printf("%d\t",*(*(q_num+i)+j));
             sum+=*(*(q_num+i)+j);
        }
        printf("\n");
    }
    return sum;

}
void pointer2(void)
{
    int a=10,b=20,c=30,d=40;
    int *p_num[4]={&a,&b,&c,&d};//ָ������
    //����ָ�������е�����
    for(int i=0;i<4;i++)
    {
        printf("%p\t",p_num[i]);
    }
    printf("\n");
    printf("%p\t%p\t%p\t%p\n",&a,&b,&c,&d);

    //���ָ�������� Ԫ����ָ��Ŀռ� �����ֵ  
    for(int i=0;i<4;i++)
    {
      //  printf("%d\t",*p_num[i]);
        printf("%d\t",*(*(p_num+i)));
    }
    printf("\n");
    int arr[4][2]={1,2,   3,4,  5,6,   7,8};//��ά���� ������4��һά���� arr[i]

    //�ֱ���q_num��ÿһ��Ԫ��ָ���ά��ÿһ�е��׵�ַ
    for(int i=0;i<4;i++)
    {
        p_num[i]=arr[i];
    }
 
  int s= getsum(p_num);
    printf("s:%d\n",s);

}

//3.����ָ��
void pointer3(void)
{
    int num[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    int arr[4]={11,22,33,44};
    int (*p)[4];//����ָ��
    p=&arr;//pָ��arr�����׵�ַ
    printf("arr:%d  &arr:%d\n",arr,&arr);
    printf("%d\n",*p);
    //ͨ������ָ�����һά����arr��Ԫ�ص�ֵ  *pҲ��&arr[0]  ���� *p+i ���� &arr[i]  ��ô *(*p+i)����arr[i]
    for(int i=0;i<4;i++)
    {
      //  printf("%p\t",&arr[i]);
       // printf("%p\t",*p+i);
       printf("%d\t",*(*p+i));
    }
    printf("\n");
    //�ڶ�ά������  num��һ�������� �����е��е�ַ
    printf("num:%p &num:%p  &num[0]:%p  &num[0][0]:%p\n",num,&num,&num[0],&num[0][0]);
    int *x=(int*)((&num)+1);
    printf("x:%p\n",x);
    //p=&num[0];//�ڶ�ά�����п��Խ�num[0]������һ��һά�����������  ����num����&num[0]
    p=num;//pָ�� num[0]��  ��ʱ p���Ե��� num��ʹ��
    p++;//�ƶ���һ����
    printf("p:%p\n",p);
    p=num;//������pָ��num������
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
          //  printf("%d\t",p[i][j]);//������ָ��p������������ʹ��
          //p���� num  ,��num+i����&num[i]����p+i ����num[i]������һ��һά����Ļ�num[i]+j����&num[i][j]
          //��ô*(num+i)+j����&num[i][j]  ��ô *(*(num+i)+j)���� num[i][j]
        
          printf("%d\t",*(*(p+i)+j));
        }
        printf("\n");
    }
    //ͨ��p++�ķ�ʽ�����ά�����и�Ԫ�ص�ֵ
    p=num;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
          printf("%d\t",*(*p+j));
        }
        printf("\n");
        p++;
    }



}
//�ú��� �ڲ�������p��q��ָ�� ����ʵ����˵  ָ��ָ���ǲ��ύ����
void swap1(int *p,int *q)
{
    int *t;
    printf("swap1��������ǰ p:%p  q:%p\n",p,q);
    t=p;
    p=q;
    q=t;
    printf("swap1���������� p:%p  q:%p\n",p,q);
}
//swap2����  ������������ָ���ָ��
void swap2(int **k,int **l)
{
    int *t;
    t=*k;
    *k=*l;
    *l=t;
}
void swap3(int **k,int **l)
{
    int t;
    t=**k;
    **k=**l;
    **l=t;
}
//����ָ��
void pointer4(void)
{
    // int a=10;
    // int *p=&a;
    // int **q=&p;
    // int ***k=&q;
    // printf("&a:%p  p:%p\n",&a,p);//p�����a�ĵ�ַ
    // printf("&p:%p q:%p\n",&p,q);//q�����p�ĵ�ַ  *q�����a�ĵ�ַ  **q��ľ���a��ֵ
    // printf("&q:%p k:%p\n",&q,k);//k�����q�ĵ�ַ *k��ľ���p�ĵ�ַ **k��ľ���a�ĵ�ַ  ***k�����a��ֵ
    // printf("a:%d  *p:%d\n",a,*p);
    // printf("**q:%d  ***k:%d\n",**q,***k);
    int a=10,b=20;
    int *p=&a,*q=&b;
    printf("&a:%p &b:%p  p:%p  q:%p\n",&a,&b,p,q);
    swap1(p,q);
    printf("&a:%p &b:%p  p:%p  q:%p\n",&a,&b,p,q);
    swap2(&p,&q);
    printf("&a:%p &b:%p  p:%p  q:%p\n",&a,&b,p,q);
    swap3(&p,&q);
    printf("&a:%p &b:%p  p:%p  q:%p\n",&a,&b,p,q);
    printf("a=%d b=%d\n",a,b);
}

//ָ��߼�
void pointer5(void)
{
    int arr[10];//��һά������arr��һ�������� �൱��һ��ָ����Ԫ��(arr[0])��ַ��ָ�� ����Ϊint *,����Ϊ4���ֽ�
    int *p;
    p=arr;
    printf("arr:%p  &arr:%p  &arr[0]:%p\n",arr,&arr,&arr[0]);//��Ȼ��ֵ��һ���� �������岻һ��
    //&arr:��һ��һά����ĵ�ַ ����ʽת��Ϊ����ָ�� ���� int (* )[]���� ������Ϊ4*10���ֽ�
    int *q=(int *)((&arr)+1);
    printf("q:%p\n",q);
    q=(int *)(&arr[0]+1);
     printf("q:%p\n",q);
    int num[3][4];
    int *k=(int *)(num+1);//num�൱����һ������ָ�� ָ���˶�ά�������еĵ�ַ ����Ϊ16
    printf("num:%p k:%p\n",num,k);
    k=(int *)(&num+1);
    printf("k:%p\n",k);
    k=(int *)(&num[0]+1);
       printf("k:%p\n",k);
    k=(int *)(&num[0][0]+1);
       printf("k:%p\n",k);
}
//ָ��ռ��С
 void pointer6(void)
 {
    int a=10;
    int *p=&a;
    char str[100]={"hello"},*q=str;
    double score=100.87,*k=&score;
    printf("p-size:%lu q-size:%lu k-size:%lu\n",sizeof(p),sizeof(q),sizeof(k));

 }

char* my_strcat(char* dest,  char* src)
{
    char *t=dest;//ָ��Ŀ���ַ������׵�ַ
   
    //ͨ��ָ�����t�ҵ���һ���ַ�����ĩβ   ָ��ָ���һ���ַ�����ĩβ
    while(*t)
    {
        t++;
    }//��ʱt�Ѿ�ָ��'\0'
    //����
    while (*src)
    {
        *t=*src;
      
        t++,src++;
    }
    
    *t='\0';
   

    return dest;//����Ŀ���ַ������׵�ַ
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
    *s1='\0';
    return t;
    
}
int getsum(int a,int b)
{
    return a+b;
}
 //����ָ��
 void pointer7(void)
 {
    //����һ������ָ��
    char * (*f_p)(char *,char *);
  //  f_p=getsum;//��������ôʹ��  ������  һ��Ҫ���������ͺ�����һһ��Ӧ
    //ʹ�ú���ָ��
    f_p=my_strcat;//��f_p��ָ��my_strcat���� �����������Ǻ������׵�ַ
    //ͨ������ָ��������my_strcat����
    char s1[20]={"hello"},s2[10]={" world!"};
   // char *p=my_strcat(s1,s2);
   char *p=f_p(s1,s2);
    printf("p:%s  s1:%s\n",p,s1);
    //ͨ��ָ���޸�ָ�� f_pָ��mystrcpy����
    f_p=mystrcpy;
    //ͨ������ָ�������ú���   ����2
    printf("s1:%s s2:%s\n",s1,s2);
    p=(*f_p)(s1,s2);
    printf("p:%s  s1:%s\n",p,s1);
 }

//char * (*f_p)(char *,char *) ��һ���βΣ�����ָ����ζ��ֻ�ܽ���һ��������
void callback(char * (*f_p)(char *,char *),char *s1,char *s2)
{
    f_p(s1,s2);
}
 //�ص�����  
void pointer8(void)
{
    char s1[20]={"hello"},s2[10]={" world!"};
    printf("callback before s1:%s s2:%s\n",s1,s2);
    callback(mystrcpy,s1,s2);//����
    printf("callback after s1:%s s2:%s\n",s1,s2);
    printf("callback before s1:%s s2:%s\n",s1,s2);
    callback(my_strcat,s1,s2);//����
    printf("callback after s1:%s s2:%s\n",s1,s2);
}