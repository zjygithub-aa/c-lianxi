/*
1.scanf���� �����س�/�ո�/tabֹͣ��ȡ�������س�����
2.�ַ���д��������
    getchar:��ȡһ���ַ�   �����س����������������Զ��߻س�
    putchar:���һ���ַ�
3.ASCII��ֵ
    �ַ��ڼ���������� ASCII����ʽ�洢
    'A' =  65
    'a' =  97
    ' ' =  32
    ���ڵ��ַ�������asciiֵΪ1 
4.�����
    �򵥼�һ�����ȼ� ����>���������>��ϵ�����>&&>||>��ֵ�����
    �߼��� ������Ŀ�����   a=3,��ô!a����0  �����a=0,��ô!a����1    ����0���棬0����0
    ����������� + ��-��*��/��%��  λ�����  ��<<  ��>>�� |��&��^��~  ��
    ��ϵ�������>��<��==��!= ��>=  ��<= ��
    �߼��� &&��  �������ʽͬʱΪ����Ϊ��
    �߼��� || �� �������ʽһ��Ϊ����Ϊ��
    ��ֵ������� =��+= ��-= ��/=  ��*=  ��%=  ��<<=��
5.while(1){}��ѭ��   break����1������ѭ��
6.c����������ƽṹ��
    ˳��ṹ--ѡ��ṹ--ѭ���ṹ
    ˳��ṹ��C����ִ�а���˳��ִ�У���������
7.ѡ��ṹ
    1)if ���
        a.if����ʹ��  ��������ʽΪ�棬��ִ�л������ڵ����
            if(���ʽ)
            {
                ���
            }
        b.����֧ if-else  ������ʽΪ�棬��ִ�л������ڵ����1������ִ��else�����ڵ����2
             if(���ʽ)
            {
                ���1
            }
            else
            {
                ���2
            }
        c.���֧ if-else if --else if ...else 
         ������ʽ1Ϊ�棬��ִ�л������ڵ����1,��������жϺ������ʽ�Ƿ�Ϊ�棬Ϊ����ִ�ж�Ӧ����䣬������еı��ʽ����Ϊ����ִ��else�ڵ�����
            if(���ʽ1)
            {
                ���1
            }
            else if(���ʽ2)
            {
                ���2
            }
            else
            {
                ���n
            }
        d.ifǶ��
            if()
            {
                if()
                {

                }
            }
    2��switch-case
        switch(���ʽ)//����  �ַ���  ö������
        {
            case �������ʽ1:  
                ���1��  
                break;
              case �������ʽ2:  
                ���2��  
                break;
                ...
            default :
                ���n;
            break;
        }
        break����2������switch���   
        �����дbreak���᣿
    3����Ŀ�����  �� ��:��      
         ���ʽ1 �����ʽ2�����ʽ3
         ������ʽ1Ϊ�棬��ִ�б��ʽ2������ִ�б��ʽ3
8.ѭ���ṹ
    ѭ�����ظ���ȥ��ĳһ������
    1��while���
        ���ʽΪ�棬��ִ��ѭ���壬�������ѭ��
        ѭ����ʼֵ���ʽ��
        while(���ʽ)
        {
            ѭ���壻
        ѭ���������ʽ��
        }
    2��do-while
    do-while�����������ִ��һ��ѭ���壬��ȥ�жϱ��ʽ�Ƿ�Ϊ�棬 ������ʽΪ�棬��ִ��ѭ���壬�������ѭ��
        ѭ����ʼֵ���ʽ1
        do
        {
            ѭ���壻
            ѭ���������ʽ��
        }while(���ʽ);
    3)for���
     ������ʽΪ�棬��ִ��ѭ���壬�������ѭ��
        for(ѭ����ʼֵ���ʽ1;ѭ���������ʽ2;ѭ���������ʽ3)   //ע�� ��forԲ�����ڣ����ʽ���Բ�д�����������ֺűز�����
        {
            ѭ���壻
        }
        for(;;){}  ���ǵȼ��� while(1){};
    !!!  ��������ǿ����໥ת����
    4)ѭ������Ƕ��
        for(;;)
        {
            for(;;)
            {
                while()
                {
                    ...
                }
            }
        }
    5��goto��� ������̭�� ��������ʹ��
        ��ǩ��
            ѭ���壻
        goto ��ǩ��
    6��break�ؼ���   
        ����ѭ��
    7��continue�ؼ���
        ��ֹ����ѭ��������ִ����һ��ѭ��
9.���ͳ���
    010���˽���10
    0x10:ʮ������10
    
*/
#include <stdio.h>
#include <math.h>
//λ�����  �Զ�������˵
int main(int argc, char const *argv[])
{
    char c=011;//�˽��� 11 ---��ʮ���� ��9  ---��0000 1001�������ƣ�
    printf("c=%o %d %x\n",c,c,c);
    // &  ��λ��  ����ͬλ��ͬʱΪ1��Ϊ1������Ϊ0
    c &=5;//0000 1001 & 0000 0101 ===0
    printf("c&=5:%d\n",c);
    // |  ��λ��  ����ͬλ����1��Ϊ1������Ϊ0
    c=17;//0001 0001
    c|=9;//0001 0001 | 0000 1001 =0001 1001
    printf("17|=9:%d\n",c);
    // ^  ��λ��� ����ͬλ����ͬ��Ϊ0����ͬ��Ϊ1int
    c=17;//0001 0001
    c^=9;//0001 0001 ^ 0000 1001 =0001 1000
    printf("17^=9:%d\n",c);
    // ~  ��λȡ�� �����е�λ�ϵ���ȡ��
    c=17;//0001 0001
    c=~c;//1110 1110(����)-->1001 0001 +1=1001 0010(ԭ�� -18)
     printf("~17=%d\n",c);
    // <<  ����  
    c=17;  //0001 0001
    c<<=3; //1000 1000 (����)-->1111 0111+1=1111 1000(ԭ��)=-��32+64+16+8��
     printf("c<<=3:%d\n",c);
    // >>  ����
    c>>=5;//1000 1000 >>5 =1000 0100                                                                   
     printf("c>>=5:%d\n",c);
    return 0;
}

#if 0
//continue  break  goto���
int main(int argc, char const *argv[])
{
    int i=1;
    for(i=1;i<=10;i++)
    {
         
        if(i%2==0)
        {
         break;// ����ѭ��  continue;//��ֹ����ѭ��  ����ִ����һ��ѭ��
        }
        printf("i=%d\n",i);
    }
    //goto���
    i=1;
    end:
        printf("goto ������\n");
        i++;
        if(i<10)
   goto end;    
    return 0;
}


//ѭ��Ƕ��
/*
��ӡһ��*��ֱ��������
*
**
***
****
*****
ֱ�������ξžų˷���  i:��   j:��
j   *  i = j*i 
 1  * 1  = 1
 1  * 2  = 2   2  *  2  =  4

*/
int main(int argc, char const *argv[])
{
    int i,j;
    for(j=1;j<=5;j++) //��ѭ��
    {     
        //��ӡ*�ŵĸ���  ��=�кţ�
       for(i=1;i<=j;i++)//��ѭ��
        {
            printf("%4c",'*');
        }
        printf("\n");
    }
    return 0;
}


//����һ���� ���жϸ����Ƿ�Ϊ����(����1����Ȼ��) ��ֻ��1�ͱ�������������
int main(int argc, char const *argv[])
{
    unsigned int num;//�޷�������
    do{
    printf("������һ������1������\n");
    scanf("%u",&num);//2
    }while(num<=1);
   
    int i=2,flag=0;//flag ������1˵���������������
    // for(i=2;i<num;i++)
    // {
    //     if(num%i==0)//�ܹ�������������
    //     {
    //         flag=1;
    //         break;//����ѭ��
    //     }
    // }
    //��һ���Ż�
    for(i=2;i<=sqrt(num);i++)
    {
        if(num%i==0)//�ܹ�������������
        {
             flag=1;
             break;
        }
    }
    if(flag==1)
    {
        printf("%u��������\n",num);
    }
    else
     printf("%u������\n",num);
    return 0;
}


//ʵ����5�Ľ׳�
int main(int argc, char const *argv[])
{
    int  t=1,i=2;//t:������  i������
    while(i<=5)
    {
        t=t*i;
        i++;
    }
    printf("t:%d\n",t);
    return 0;
}


//ͨ������ѭ�����  ʵ�����1-10
int main(int argc, char const *argv[])
{
    //while���
    int i;//ѭ������
    printf("while��䣺");
    i=1;
    while(i<=10)
    {
        printf("%d\t",i);
        i++;
    }
    printf("\n");
    printf("do-while��䣺");
    i=1;
    do
    {
        printf("%d\t",i);
        i++;
    }while(i<=10);
    printf("\n");
     printf("for��䣺");
     for(i=1;i<=10;i++)
     {
        printf("%d\t",i);
     }
     printf("\n");
    return 0;
}


//ѭ��
int main(int argc, char const *argv[])
{
    int month;
   for(;month<1||month>12;)
    {  
         printf("�����������·�\n");
        scanf("%d",&month);
    }//��������ݲ��� �ͼ���ѭ������
        switch (month)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
             printf("31��\n");
            break;
            case 2:
                printf("28��\n");
                break;
            case 4:
            case 6:
            case 9:
            case 11:
              printf("30��\n");
                break;
            default:
             printf("��������\n");
            break;
        }
    return 0;
}

//���������·�  ������µ����� ����ƽ������ 2��28�죩
int main(int argc, char const *argv[])
{
    int month;
    printf("�����������·�\n");
        scanf("%d",&month);
        switch (month)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
             printf("31��\n");
            break;
            case 2:
                printf("28��\n");
                break;
            case 4:
            case 6:
            case 9:
            case 11:
              printf("30��\n");
                break;
            default:
             printf("��������\n");
            break;
        }
    return 0;
}


//���������·� ��������·� ��������4  �������

int main(int argc, char const *argv[])
{
    int month;
    while(1)
    {
        printf("�����������·�\n");
        scanf("%d",&month);
    switch (month)
    {
     case 1:
        printf("һ��\n");
        break;
    case 2:
        printf("����\n");
        break;
     case 3:
        printf("����\n");
        // break;
      case 4:
        printf("����\n");
        break;
      case 5:
        printf("����\n");
        break;
      case 6:
        printf("����\n");
        break;
      case 7:
        printf("����\n");
        break;
      case 8:
        printf("����\n");
        break;
      case 9:
        printf("����\n");
        break;
      case 10:
        printf("ʮ��\n");
        break;
      case 11:
        printf("ʮһ��\n");
        break;
      case 12:
        printf("ʮ����\n");
        break;    
      default:
        printf("��������\n");
        break;
    }

    }
    
    return 0;
}

//Ҫ������ if���  �Լ���Ŀ�����  �����������е����ֵ
int main(int argc, char const *argv[])
{
  int a,b,c,max;
  printf("��������������\n");
  scanf("%d%d%d",&a,&b,&c);
//   max=(a>b)?a:b;
//   max=(max>c)?max:b;
    // if(a>b)max=a;else max=b;
    // if(max<c)max=c;

// max=(a>b)?(a>c?a:c):(b>c?b:c);
    if(a>b)
    {
       if(a>c)
       {
        max=a;
       } 
       else
       max=c;
    }
    else
    {
        if(b>c)
        max=b;
        else 
        max=c;
        
    }
  printf("max:%d\n",max);
    return 0;
}

//if��� +������
int main(int argc, char const *argv[])
{
    int a=10;
    // if(!a)//�ж�!a�Ƿ�Ϊ��  �ȼ���   a==0
    // {
    //     printf("$$$\n");
    // }
    // else
    // {
    //     printf("***\n");
    // }
    // if(a=0)//�Ƚ�0��ֵ��a  Ȼ�ж�a�Ƿ�Ϊ��
    // {
    //     printf("$$$\n");
    // }
    // else
    // {
    //     printf("***\n");
    // }
    // if(a==0)//a�Ƿ����0
    // {
    //     printf("$$$\n");
    // }
    // else
    // {
    //     printf("***\n");
    // }
    int c=0,d=0;
    if((c=3)||(d=4))
//  if((c=3)&&(d=4))
//  if((c=0)||(d=4))
//  if((c=0)&&(d=4))
    {
        printf("yes\n");
    }
    //c :?  d  :?
    printf("c=%d d=%d\n",c,d);
    return 0;
}


//if���   + ��Ŀ�����
//������������  �����ֵ 
//Ҫ������ if���  �Լ���Ŀ�����  �����������е����ֵ
int main(int argc, char const *argv[])
{
    int a,b ,max;
    printf("��������������:\n");
    scanf("%d%d",&a,&b);
    //if���
    // if(a>b)
    // {
    //     max=a;
    // }
    // else
    // {
    //     max=b;
    // }
    //��Ŀ�����
    max=(a>b)?a:b;
    printf("max:%d\n",max);

    return 0;
}


//ģ���� + if���
//������� ���жϸ����Ƿ�Ϊ����  ������ܹ���4�������Ҳ��ܱ�100��������������ܱ�400������
int main(int argc, char const *argv[])
{
    int year;//���
    printf("��������ݣ�1970--2030�꣩:");
    scanf("%d",&year);
    //�ж����
    if(year%4==0 && year%100!=0 || year%400==0)//��д������ ��Ĭ��ֻ��Ͻһ�����
     {  
         printf("%d��������\n",year);   
    }
    else
    {
     printf("%d����ƽ��\n",year);
    }

    return 0;
}


//����һ���ַ�����Ӣ����ĸ����  �Լ�  �����ַ����� �Լ��ո�ĸ��� �������ַ�����
int main(int argc, char const *argv[])
{
    char ch;
 
    int eng=0,num=0,blank=0,other=0;

    while (1)
    {     
        ch=getchar();//����  ��һ���ַ�
       
        if(ch=='\n')//�س���'\r'�� (���� '\n')
        {
            break;
        }
        //Ӣ���ַ�
        if(ch>='A'&&ch<='Z' || ch>='a'&&ch<='z')
        {
            eng=eng+1;
        }
        else if(ch>='0'&&ch<='9')
        {
            num++;//�ȼ��� num=num+1  ����
        }
        else if(ch ==' ')
        {
            blank++;
        }
        else 
        {

           other++;
        }
        
    }
    printf("Ӣ���ַ�������%d  �����ַ�������%d  �ո��ַ�������%d  �����ַ�������%d\n",eng,num,blank,other);
    
    // char ch;//����һ���ַ����ͱ���
    // ch=getchar();
    // printf("���ַ�Ϊ:");
    // putchar(ch);
    // printf("ascii:%d\n",ch);
    //  ch=getchar();//���س�������
    // printf("���ַ�Ϊ:");
    // putchar(ch);
    //  printf("ascii:%d\n",ch);
    return 0;
}

#endif