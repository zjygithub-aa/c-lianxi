#include<stdio.h>
#include <sys/stat.h>
void file_opre1(void)
{
    FILE *fp=fopen("a.txt","a+");//�ɶ���д��ʽ��
    if(!fp)
    {
        printf("�ļ���ʧ��\n");
        return;
    }
    fputs("hello\nworld\n",fp);
    rewind(fp);
    char str[100];
    fgets(str,sizeof(str),fp);
    int len=0;
    while (str[len])
    {
        if(str[len]=='\n')
        {
            if(str[len-1]=='\r')
            {
                printf("windows file\n");
            }
            else
            {
                printf("linux file\n");
            }
        }
        len++;
    }
    fclose(fp);
}
//�ļ�״̬
void sta(char const  *file,struct stat *t)
{
    stat(file,t);
}
#if 0
int main(int argc, char const *argv[])
{
  // file_opre1();
   struct stat st;
   if(argc<2)
   {
    return 0;
   }
  //  sta(argv[1],&st);
 //   printf("�ļ���С��%lu\t �ļ�����޸�ʱ�� %lld \n",st.st_size,st.st_mtime);
    rename("a.txt","a_2.txt");//������
    FILE *fp=fopen("a.txt","r");//ֻ����ʽ
    if(!fp){printf("�ļ���ʧ�� �����ɹ�\n");return 0;}
    fclose(fp);
    remove("a_2.txt");
  FILE *fp=fopen("a_2.txt","r");
    if(!fp){printf("�ļ���ʧ�� �ļ���ɾ��\n");return 0;}
    return 0;
}
#endif
//����һ���ṹ������
typedef struct student
{
    int num;
    char name[20];
    float score[5];
}STU;
#define N 5  //�궨��  
int curmannum=0;//��ǰѧ������  ��һ��ȫ�ֱ���
void input(STU *s);
void find(int NUM ,STU *P_ARR);
void read_file(STU *P_ARR);//���ļ���Ϣ

/**��һ����ѧ���ɼ�����ϵͳ  ��1.¼��ɼ�  2.ͨ��ѧ�Ų�ѯ�ɼ� 3.�˳�*/
void menu(void)
{
    char *m[]={"1.¼����Ϣ","2.��ѯ��Ϣ","3.�˳�ϵͳ"};
    printf("----------------------------------------\n");
    for(int i=0;i<3;i++)
    {
        printf("%s\n",m[i]);
    }
    printf("������Ϣ��%3d / %3d\n",curmannum,N);
    printf("----------------------------------------\n");

}

int main(int argc, char const *argv[])
{
    char ch;
    STU arr[N],temp;
    read_file(arr);//�ȶ��ļ�������
    while(1)
    {
        menu();
        ch=getchar();
        getchar();//���س�����
        switch (ch)
        {
            case '1':
                input(&temp);
                break;
            case '2':
            if(curmannum==0)
            {
                printf("ϵͳ��û����Ϣ\n");
                break;
            }
        int n;
            printf("������ѧ��");
            scanf("%d",&n);
            getchar();
            find(n,arr);
             break;
         case '3':
        return 0;
             break;
        default:
            break;
        }
    }
}
void input(STU *s)
{
    printf("ѧ�ţ�%d\n",10001+curmannum);
    s->num=10001+curmannum;//����ѧ��
    printf("������");
    scanf("%s",s->name);
    getchar();
    printf("������ɼ�\n");
    for(int i=0;i<5;i++)
    {
        scanf("%f",&s->score[i]);
    }
    getchar();
    //�����ݴ����ļ���
    FILE *fp=fopen("student.txt","a");
    if(!fp){printf("�ļ���ʧ��\n");return ;}
    fprintf(fp,"%d %s %f %f %f %f %f\n",s->num,s->name,s->score[0],s->score[1],s->score[2],s->score[3],s->score[4]);
    fclose(fp);
    curmannum++;//��ǰ����+1
}
void read_file(STU *P_ARR)
{
    curmannum=0;//��ǰѧ������ 0��
    FILE *fp=fopen("student.txt","r");//ֻ���ķ�ʽ��
    if(!fp){printf("error\n");return;}
    while (1)
    {
        fscanf(fp,"%d %s %f %f %f %f %f",
        &(P_ARR+curmannum)->num,(P_ARR+curmannum)->name,&(P_ARR+curmannum)->score[0],
        &(P_ARR+curmannum)->score[1],&(P_ARR+curmannum)->score[2],&(P_ARR+curmannum)->score[3],&(P_ARR+curmannum)->score[4]);
        if(feof(fp))
        {
            break;
        }
       curmannum++;
    }
    
    fclose(fp);
       //�������
    // for(int i=0;i<curmannum;i++)
    // {
    //     printf("%d %s %f %f %f %f %f\n",(P_ARR+i)->num,
    //     (P_ARR+i)->name,(P_ARR+i)->score[0],(P_ARR+i)->score[1],(P_ARR+i)->score[2],(P_ARR+i)->score[3],(P_ARR+i)->score[4]);
    // }
}
void find(int NUM ,STU *P_ARR)
{
//��һ���ļ�
    read_file(P_ARR);
    int i=0;
    //��ѯ
     for( i=0;i<curmannum;i++)
    {
        if(NUM==(P_ARR+i)->num)//ѧ��ƥ��
        {
              printf("%d %s %f %f %f %f %f\n",(P_ARR+i)->num,
         (P_ARR+i)->name,(P_ARR+i)->score[0],(P_ARR+i)->score[1],(P_ARR+i)->score[2],(P_ARR+i)->score[3],(P_ARR+i)->score[4]);
         break;
        }
    }
    if(i==curmannum)
    {
        printf("���޴���\n");
    }
}