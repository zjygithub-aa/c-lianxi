/**
 * 8.�Զ�����������--�ṹ��
 *      a.�ṹ����������
 *          struct �ṹ�������� {  
 *          ��Ա�б�1;
 *          ��Ա�б�2;
 *            };
 *      b.�ṹ������Ķ��壺��������  ��������
 *      c.��Ա�����ã�������
 *           ������.��Ա
 *      d.�ṹ�������ʼ�� 1�����ճ�Ա˳����и�ֵ��2��ָ����Ա���и�ֵ
 *      e.�ṹ�����鶨��  �������� ������[���鳤��]
 *      f.�ṹ����Ϊ��������
 *      g.�ṹ��ָ��  
 *              ���p��һ��ָ����������ó�Ա ����*p��.��Ա 
 *       ->���ṹ��ָ���Ա���������              p->��Ա 
 *      h.�ṹ����ռ���ڴ��С  ������Ա���͵Ĵ�С�������� ���ڷ����ֽ�ʱ������ڴ����
 *          �ṹ��ָ��ռ���ڴ��С��8���ֽ� 
 * 9.typedef�ؼ��� 
 *      ����ȡ����
 * 10.�ṹ���ڳ�Ա������ṹ�����͵ı��������ǲ������Լ�������͵ı��������Ҫ�����Լ�������͵ĳ�Ա�Ļ��������Աֻ����ָ��  -->����
 * 

*/
#include<stdio.h>
typedef struct birth
{
    int year;
    int month;
    int day;
}birth,BIR;//birth ��һ���ṹ�������� ��typedef struct birth�ı���  BIRҲ�Ǳ���

//����һ���ṹ������
struct student
{
   char name[20];//����
   int age;//����
   float score;//�ɼ�
   char sex;//�Ա�  'w':Ů  'm':��
   birth  Birthday;//����������
}c;//c ��һ���ṹ�����͵ı���  �������Ҳ�ǿ��Խ��г�ʼ����ֵ��

//����һ���ṹ�����ͱ���  ����ʼ����ֵ
struct student a={"lili",18,98.5,'w',{2000,3,7}};
struct student b={.score=89.5,.age=20,.name="xiaowang",.sex='m'};
//  struct student *p_stu�ṹ������ָ��
void input_data(struct student *p_stu);
void output_data(struct student *p_stu);
//���ڽṹ���Ա��Ӧ��  ������.��Ա
void output(void)
{

    printf("name:%s age:%d score:%.2f sex:%c year %d month :%d day:%d \n",
    a.name,a.age,a.score,a.sex,a.Birthday.year,a.Birthday.month,a.Birthday.day);
    //��bͬѧ�����ս��и�ֵ
    b.Birthday.year=1998;
    b.Birthday.month=7;
    b.Birthday.day=18;
     printf("name:%s age:%d score:%.2f sex:%c year %d month :%d day:%d \n",
     b.name,b.age,b.score,b.sex,b.Birthday.year,b.Birthday.month,b.Birthday.day);
     printf("name:%s age:%d score:%.2f sex:%c year %d month :%d day:%d \n",
     c.name,c.age,c.score,c.sex,c.Birthday.year,c.Birthday.month,c.Birthday.day);
}
void input(void)
{
    printf("name:");
    scanf("%s",c.name);
    getchar();
    printf("age:");
    scanf("%d",&c.age);
     getchar();
    printf("score:");
    scanf("%f",&c.score);
     getchar();
    printf("sex:");
    scanf("%c",&c.sex);
     getchar();
    printf("year-motn-day:");
    scanf("%d-%d-%d",&c.Birthday.year,&c.Birthday.month,&c.Birthday.day);
}
struct teacher 
{
    char name[13];//13
    int age;//4
   float h;//4
   char sex;//1
   struct a
   {
    int kk;
    int ll;
   }t ;//�ڽṹ�������ڲ�����һ���ṹ�����Ͳ�����һ�������͵ı����������  �����������ֻ�ڱ�teacher�ṹ���ڿ���ʹ��
  // struct teacher tea;//!!!!  �ڱ��ṹ���� ��������ýṹ�����͵ĳ�Ա���� ���ǿ��Զ���ָ�����ͱ���
   struct teacher *next;
};
int main(int argc, char const *argv[])
{

    printf("struct teacher size:%lu\n",sizeof(struct teacher ));
    struct teacher k,*p_t;
    printf("&k:%p k.name:%p \n&k.age:%p\n&k.h:%p\n&k.sex:%p\n",&k,k.name,&k.age,&k.h,&k.sex);
    printf("�ṹ��struct teacher ָ���С��%lu\n",sizeof(p_t));
    //���������ǹ���  �ṹ�������ڴ��С�Լ��ṹ��ָ���С��
//----------------------------------------------------------------------
    // input();
    // output();
    //�ṹ������
    struct student stu_num[3];
    struct student *p=stu_num;//ָ��ָ��������׵�ַ
    input_data(p);//p  �� stu_num��һ����
    output_data(p);
    printf("�����ṹ������\n");
    for(int i=0;i<3;i++)
    {
         printf("name:%s age:%d\n",stu_num[i].name,stu_num[i].age);
    }
    return 0;
}

//  struct student *p_stu�ṹ������ָ��
void input_data(struct student *p_stu)
{
    for(int i=0;i<3;i++)
    {
        printf("name:");
      //  scanf("%s",(*p_stu).name);
       scanf("%s",p_stu->name);
        getchar();
        printf("age:");
        // scanf("%d",&(*p_stu).age);
        scanf("%d",&p_stu->age);
         getchar();
         p_stu++;
    }
   

}

void output_data(struct student *p_stu)
{
     for(int i=0;i<3;i++)
    {
        printf("name:");
      //  printf("%s\t",(*p_stu).name);
       printf("%s\t",p_stu->name);
        printf("age:");
     //   printf("%d\n",(*p_stu).age);
     printf("%d\n",p_stu->age);
         p_stu++;
    }
}
