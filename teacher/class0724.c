/**
 * 1.�Զ�����������--�����壨�����壩
 *  ��������ĵ�ַ�����ĸ���Ա�ĵ�ַ����ͬһ��ַ���ڴ��С������Ա�Ĵ�С
 *  �ص㣺�޸�����ĳһ����Ա��ֵ�������ֵҲ����Ӱ��
 *  ��������������
 *         union ������ 
 *            {
 *              ��Ա�б�1��
 *              ��Ա�б�1��
 *              }��
 *      ��Ա���ã�������     ������.��Ա
 * 2.�Զ�����������--ö������
 *    ö�٣���������ֵһһ�оٳ�����������ֵֻ�����оٳ�����ֵ�ķ�Χ�ڣ�ʵ����һ��������
 *     enum ö������
 *      {
 *          ö��ֵ1��
 *          ö��ֵ2,
 *      };
 *      ��ö��ֵ����Ӧ�г����п���ֵ��Ҳ��Ϊö��Ԫ�ء�
 *      ö��ֵ�ǳ����������ڳ������ø�ֵ����ٶ�����ֵ��
 *      ö��Ԫ�ر�����ϵͳ������һ����ʾ��ŵ���ֵ�� 0 ��ʼ˳����Ϊ 0��1��2
 *      ������ö������ʱ��������ĳһö��ֵ��ֵ�Ļ���������ö��ֵ�Ǿ͸�ö��ֵ+1
 * 3.�ļ�����
 *      �ļ����ࣺ
 *          �ı��ļ���t��  �������ļ�(b)
 *      �ļ�ָ�붨�壺  FILE *fp;
 *      �ļ��Ĵ򿪺͹رգ�
 *              �򿪣�fp=fopen("�ļ�·��"��"�򿪷�ʽ")��
 *          �ļ�·�����������·��Ҳ�����Ǿ���·��
 *                  ����ļ���ʧ��  fp���յ���ΪNULL,����ΪNULL
 *              �رգ�fclose(fp);
 *      �򿪷�ʽ�� �� �� д �ɶ���д ׷��д
 *              r(t/b):��ֻ���ķ�ʽ���ļ�������ļ����������ʧ��
 *              w     :��ֻд�ķ�ʽ���ļ�������ļ����������½��ļ����ļ�������ˢ��д������
 *              r+    :�Կɶ���д�ķ�ʽ���ļ�������ļ������ڴ�ʧ��
 *              w+    :�Կɶ���д�ķ�ʽ���ļ�������ļ����������½��ļ����ļ�������ˢ��д������
 *              a     :��׷��д�ķ�ʽ���ļ����ļ������ڻ��½��ļ����ļ����ڲ���ˢ�£�׷�����ļ�ĩβд
 *              a+    :��׷�ӿɶ���д�ķ�ʽ���ļ�
 *     �ļ���д����������
 *       ����                ��                  д
 *       �ַ���д          fgetc               fputc
 *     �ļ���дλ���ƶ�
 *          rewind(fp);//���ļ���дλ���ƶ��ļ�����λ��
 *          fseek(fp,len,pos);��pos��λ���ƶ�len���ֽ�
 *          len<0:�����ƶ�   len>0�������ƶ�
 *          pos��ѡ���������֣�SEEK_SET(0):�ļ���λ��  SEEK_CUR(1):�ļ���ǰλ�� SEEK_END(2):�ļ�ĩβλ��
 *    �ļ�ĩβ��������  :EOF
 *          �ļ�ĩβ����   feof(fp);  ����ú�������Ϊ��ͱ�ʾ�������ļ�ĩβ�����򷵻ؼ�
 *      
*/
#include<stdio.h>
void file1_ope(void);
void file2_ope(void);
//�ļ�����
int main(int argc, char const *argv[])
{
    file2_ope();
    return 0;
}
void file1_ope(void)
{
    //����һ���ļ�ָ��
    FILE *fp;
    //��һ���ļ�  
  //  fp=fopen("a.txt","r");//��ֻ���ķ�ʽ���ļ��ļ����������ʧ��
 //   fp=fopen("a.txt","w");//��ֻд�ķ�ʽ���ļ�,
  //   fp=fopen("a.txt","w+");//�Կɶ���д�ķ�ʽ���ļ� ���ݻ�ˢ��
   // fp=fopen("a.txt","r+");//�Կɶ���д�ķ�ʽ���ļ��ļ����������ʧ��
  //   fp=fopen("a2.txt","a");//���ܶ��ļ� ֻ�����ļ�ĩβд  ���ļ������ھ��½������ھʹ��ļ�
   fp=fopen("a2.txt","a+");//�ɶ���д  �ļ������ھ��½������ھʹ��ļ�
    if(NULL==fp)//fp==NULL
    {
        printf("�ļ���ʧ��\n");
        return;
    }
    printf("�ļ��򿪳ɹ�\n");

    //ͨ���ַ�д�������ļ�д������
    fputc('a',fp);
    fputc('b',fp);
     //ͨ���ļ���дλ���ƶ� �ƶ��ļ���λ��
    rewind(fp);
   // fseek(fp,2,SEEK_SET);//���ļ���λ���ƶ�2���ֽ�
   //ͨ���ַ�����������ȡ�ļ����ַ�
    char ch=fgetc(fp);
    printf("ch:%c\n",ch);
    ch=fgetc(fp);
    printf("ch:%c\n",ch);
    //�ر��ļ�
    fclose(fp);
}
void file2_ope(void)
{
    char ch;
    FILE *fp=fopen("a2.txt","r");
    if(!fp)
    {
        printf("�ļ���ʧ��\n");
        return;
    }
    while(1)
    {
        ch=fgetc(fp);

       // if(ch==EOF)
       if(feof(fp))
        {
            break;
        }
         putchar(ch);
    }
    fclose(fp);
}


void union_test(void);//������
//ѧ������ʦ�Ĺ����б�
void stu_tea_manager_list(void);
 #if 0
//ö������
enum week
{
    sun = 2, mon, tue, wed, thu, fri, sat
};
enum bool
{
flase, true
};

//����һ������������
int main(int argc, char const *argv[])
{
   //stu_tea_manager_list();
  
  
   enum week a, b,c;
    a = sun;
    b = mon;
    c = tue;
    printf("%d,%d,%d\n", a, b, c);
    enum bool flag;
    flag = true;
    if (flag == 1)
    {
    printf("flag Ϊ��\n");
    }

    return 0;
}
#endif


//����һ������������
typedef union data
{
  unsigned  char a;
  unsigned  short b;
  unsigned  int c;
}data;
void union_test(void)
{
     printf("������������ռ�ֽڴ�СΪ��%lu\n",sizeof(union data));
    //����һ�����������ͱ���
    data k;
    k.a=0x11;
    printf("a:%x b:%x c:%x\n",k.a,k.b,k.c);
    k.c=0x11223344;
    printf("a:%x b:%x c:%x\n",k.a,k.b,k.c);
    k.a=0x00;
    printf("a:%x b:%x c:%x\n",k.a,k.b,k.c);
    printf("��ַ��ţ�&k:%p &k.a:%p &k.b:%p &k.c%p\n",&k,&k.a,&k.b,&k.c);
}
//������
union  Categ                         
{
 int classs;     //�༶  
char position[10]; //ְ�� 
}; 
//�ṹ������
struct   p                      
{ 
    int num;  
   char name[10]; 
   char sex; 
   char job;//'s':ѧ�� ��t��:��ʦ
   union  Categ  category ;
}person[2];//�Ѿ�������һ������

void input(void)
{
    for(int i=0;i<2;i++)
    { person[i].num=i+1;//���
        printf("����");
        scanf("%s",person[i].name);
        getchar();
        printf("�Ա�");
        scanf("%c",&person[i].sex);
        getchar();
        printf("ְҵ");
          scanf("%c",&person[i].job);
        getchar();
        if(person[i].job=='s'||person[i].job=='S')
        {
            printf("�༶");
            scanf("%d",&person[i].category.classs);
            getchar();
        }
        else{
            printf("ְ��");
            scanf("%s",person[i].category.position);
            getchar();
        }
       
    }
}
void output(void)
{
      for(int i=0;i<2;i++)
    {
       printf("���%d\t",person[i].num);
        printf("����");
        printf("%s\t",person[i].name);
       
        printf("�Ա�");
        printf("%c\t",person[i].sex);
       
        printf("ְҵ");
          printf("%c\t",person[i].job);
       
        if(person[i].job=='s'||person[i].job=='S')
        {
            printf("�༶");
            printf("%d\n",person[i].category.classs);
           
        }
        else
        {
                printf("ְ�� ");
                printf("%s\n",person[i].category.position);     
        }
       
    }
}
//ѧ������ʦ�Ĺ����б�
void stu_tea_manager_list(void)
{
    input();
    output();
}
#if 0
//ö������  +����ָ�� +�ṹ�� ʵ��״̬��
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// ״̬ö��
typedef enum {
    RED,
    GREEN,
    YELLOW
} TrafficLightState;
// �¼�ö��
typedef enum {
    TIMEOUT
} Event;
// ״̬���ṹ��
typedef struct TrafficLight {
    TrafficLightState currentState;
    void (*onRed)(Event event, struct TrafficLight *tl);
    void (*onGreen)(Event event, struct TrafficLight *tl);
    void (*onYellow)(Event event, struct TrafficLight *tl);
} TrafficLight;
// ���״̬������    //�¼�       
void redStateHandler(Event event, TrafficLight *tl) {
    if (event == TIMEOUT) {
        printf("Red light timeout, switch to green light\n");
        tl->currentState = GREEN;//��״̬�仯Ϊ�̵�
    }
}
// �̵�״̬������
void greenStateHandler(Event event, TrafficLight *tl) {
    if (event == TIMEOUT) {
        printf("Green light timeout, switch to yellow light\n");
        tl->currentState = YELLOW;
    }
}
// �Ƶ�״̬������
void yellowStateHandler(Event event, TrafficLight *tl) {
    if (event == TIMEOUT) {
        printf("Yellow light timeout, switch to red light\n");
        tl->currentState = RED;
    }
}
// ��ʼ��״̬��
void initTrafficLight(TrafficLight *tl) {
    tl->currentState = RED;//���
    tl->onRed = redStateHandler;//����ָ��ָ����ĳ������
    tl->onGreen = greenStateHandler;//����ָ��ָ����ĳ������
    tl->onYellow = yellowStateHandler;//����ָ��ָ����ĳ������
}
// �����¼�
void handleEvent(TrafficLight *tl, Event event) {
    switch (tl->currentState) //�Ƶ�״̬
    {
        case RED:
            tl->onRed(event, tl);
            break;
        case GREEN:
            tl->onGreen(event, tl);
            break;
        case YELLOW:
            tl->onYellow(event, tl);
            break;
        default:
            break;
    }
}
int main() {
    TrafficLight tl;//��ͨ��  �Ƶ�״̬��������������ָ���ʾ���� ���ݵƵ�״̬������ʹ���ĸ�����
    initTrafficLight(&tl);//��ʼ����ͨ�Ƶ�״̬ �Լ���ʼ������ָ���ָ��
    handleEvent(&tl, TIMEOUT);//�����¼�
    handleEvent(&tl, TIMEOUT);
    handleEvent(&tl, TIMEOUT);
    for(int i=10;i>=0;i--)
    {
        printf("%d\n",i);
        _sleep(1000);
        handleEvent(&tl, i);
    }

    return 0;
}
#endif