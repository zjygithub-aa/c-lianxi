#include<stdio.h>
#include <sys/stat.h>
void file_opre1(void)
{
    FILE *fp=fopen("a.txt","a+");//可读可写方式打开
    if(!fp)
    {
        printf("文件打开失败\n");
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
//文件状态
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
 //   printf("文件大小：%lu\t 文件最后修改时间 %lld \n",st.st_size,st.st_mtime);
    rename("a.txt","a_2.txt");//重命名
    FILE *fp=fopen("a.txt","r");//只读方式
    if(!fp){printf("文件打开失败 改名成功\n");return 0;}
    fclose(fp);
    remove("a_2.txt");
  FILE *fp=fopen("a_2.txt","r");
    if(!fp){printf("文件打开失败 文件已删除\n");return 0;}
    return 0;
}
#endif
//声明一个结构体类型
typedef struct student
{
    int num;
    char name[20];
    float score[5];
}STU;
#define N 5  //宏定义  
int curmannum=0;//当前学生人数  是一个全局变量
void input(STU *s);
void find(int NUM ,STU *P_ARR);
void read_file(STU *P_ARR);//读文件信息

/**做一个简单学生成绩管理系统  ：1.录入成绩  2.通过学号查询成绩 3.退出*/
void menu(void)
{
    char *m[]={"1.录入信息","2.查询信息","3.退出系统"};
    printf("----------------------------------------\n");
    for(int i=0;i<3;i++)
    {
        printf("%s\n",m[i]);
    }
    printf("数据信息：%3d / %3d\n",curmannum,N);
    printf("----------------------------------------\n");

}

int main(int argc, char const *argv[])
{
    char ch;
    STU arr[N],temp;
    read_file(arr);//先读文件中数据
    while(1)
    {
        menu();
        ch=getchar();
        getchar();//将回车读走
        switch (ch)
        {
            case '1':
                input(&temp);
                break;
            case '2':
            if(curmannum==0)
            {
                printf("系统中没有信息\n");
                break;
            }
        int n;
            printf("请输入学号");
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
    printf("学号：%d\n",10001+curmannum);
    s->num=10001+curmannum;//保存学号
    printf("姓名：");
    scanf("%s",s->name);
    getchar();
    printf("请输入成绩\n");
    for(int i=0;i<5;i++)
    {
        scanf("%f",&s->score[i]);
    }
    getchar();
    //将数据存入文件中
    FILE *fp=fopen("student.txt","a");
    if(!fp){printf("文件打开失败\n");return ;}
    fprintf(fp,"%d %s %f %f %f %f %f\n",s->num,s->name,s->score[0],s->score[1],s->score[2],s->score[3],s->score[4]);
    fclose(fp);
    curmannum++;//当前人数+1
}
void read_file(STU *P_ARR)
{
    curmannum=0;//当前学生人数 0个
    FILE *fp=fopen("student.txt","r");//只读的方式打开
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
       //遍历输出
    // for(int i=0;i<curmannum;i++)
    // {
    //     printf("%d %s %f %f %f %f %f\n",(P_ARR+i)->num,
    //     (P_ARR+i)->name,(P_ARR+i)->score[0],(P_ARR+i)->score[1],(P_ARR+i)->score[2],(P_ARR+i)->score[3],(P_ARR+i)->score[4]);
    // }
}
void find(int NUM ,STU *P_ARR)
{
//读一次文件
    read_file(P_ARR);
    int i=0;
    //查询
     for( i=0;i<curmannum;i++)
    {
        if(NUM==(P_ARR+i)->num)//学号匹配
        {
              printf("%d %s %f %f %f %f %f\n",(P_ARR+i)->num,
         (P_ARR+i)->name,(P_ARR+i)->score[0],(P_ARR+i)->score[1],(P_ARR+i)->score[2],(P_ARR+i)->score[3],(P_ARR+i)->score[4]);
         break;
        }
    }
    if(i==curmannum)
    {
        printf("查无此人\n");
    }
}