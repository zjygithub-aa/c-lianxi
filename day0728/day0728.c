#include <stdio.h>

struct Student
{
    int num;
    char name[20];
    float score[5];
};
void add_stu(struct Student *stu);
void find_stu(int num, struct Student *stu);

int stu_number = 0;
int main()
{
    char ch;
    struct Student input[5], temp;

    while (1)
    {
        printf("--------学生管理系统------\n");
        printf("--------1、添加学生信息-----\n");
        printf("--------2、查询学生信息-----\n");
        printf("--------3、退出系统-------\n");
        printf("输入选项\n");
        ch = getchar();
        getchar();
        switch (ch)
        {
        case '1':
            add_stu(&temp);
            break;
        case '2':
            int id;
            printf("请输入要查询的学号: ");
            scanf("%d", &id);
            getchar(); // 处理输入缓冲区的换行符
            find_stu(id, input);
            break;
        case '3':
            return 0;
            break;
        default:
            printf("输入有误，请重新输入\n");
            break;
        }
    }
}

void add_stu(struct Student *stu)
{
    // 先将文件中的数据读出来
    int i = 0;
    stu_number = 0;                       // 当前学生人数 0个
    FILE *fp = fopen("student.txt", "r"); // 只读的方式打开
    if (!fp)
    {
        printf("Error\n");
        return;
    }
    while (1)
    {
        fscanf(fp, "%d %s %f %f %f %f %f",
               &(stu[stu_number].num), (stu[stu_number].name), &(stu[stu_number].score[0]),
               &(stu[stu_number].score[1]), &(stu[stu_number].score[2]), &(stu[stu_number].score[3]), &(stu[stu_number].score[4]));
        if (feof(fp))
        {
            break;
        }
        stu_number++;
    }

    fclose(fp);
    printf("学号 %d\n", 1 + stu_number);
    stu->num = 1 + stu_number;
    printf("姓名:");
    scanf("%s", stu->name);
    getchar();
    printf("请输入成绩\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%f", &stu->score[i]);
    }
    getchar();
    // 将数据写入文件中
    fp = fopen("student.txt", "a");
    if (!fp)
    {
        printf("文件打开失败\n");
        return;
    }
    fprintf(fp, "%d %s %f %f %f %f %f\n", stu->num, stu->name, stu->score[0], stu->score[1], stu->score[2], stu->score[3], stu->score[4]);
    fclose(fp);
    stu_number++;
}

void find_stu(int num, struct Student *stu)
{

    // 遍历输出
    // for (int i = 0; i < stu_number; i++)
    // {
    //     // printf("%d %s %f %f %f %f %f\n", (stu+i)->num,
    //     // (stu+i)->name,(stu+i)->score[0],(stu+i)->score[1],(stu+i)->score[2],(stu+i)->score[3],(stu+i)->score[4]);
    // }
    // 查询
    int i;
    stu_number = 0;                       // 当前学生人数 0个
    FILE *fp = fopen("student.txt", "r"); // 只读的方式打开
    if (!fp)
    {
        printf("Error\n");
        return;
    }
    while (1)
    {
        fscanf(fp, "%d %s %f %f %f %f %f",
               &(stu[stu_number].num), (stu[stu_number].name), &(stu[stu_number].score[0]),
               &(stu[stu_number].score[1]), &(stu[stu_number].score[2]), &(stu[stu_number].score[3]), &(stu[stu_number].score[4]));
        if (feof(fp))
        {
            break;
        }
        stu_number++;
    }

    fclose(fp);
    for ( i = 0; i < stu_number; i++)
    {
        if (num == (stu + i)->num) // 学号匹配
        {
            printf("%d %s %f %f %f %f %f\n", (stu + i)->num,
                   (stu + i)->name, (stu + i)->score[0], (stu + i)->score[1], (stu + i)->score[2], (stu + i)->score[3], (stu + i)->score[4]);
            break;
        }
    }
    if (i == stu_number)
    {
        printf("查无此人\n");
    }
}