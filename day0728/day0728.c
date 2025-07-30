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
        printf("--------ѧ������ϵͳ------\n");
        printf("--------1�����ѧ����Ϣ-----\n");
        printf("--------2����ѯѧ����Ϣ-----\n");
        printf("--------3���˳�ϵͳ-------\n");
        printf("����ѡ��\n");
        ch = getchar();
        getchar();
        switch (ch)
        {
        case '1':
            add_stu(&temp);
            break;
        case '2':
            int id;
            printf("������Ҫ��ѯ��ѧ��: ");
            scanf("%d", &id);
            getchar(); // �������뻺�����Ļ��з�
            find_stu(id, input);
            break;
        case '3':
            return 0;
            break;
        default:
            printf("������������������\n");
            break;
        }
    }
}

void add_stu(struct Student *stu)
{
    // �Ƚ��ļ��е����ݶ�����
    int i = 0;
    stu_number = 0;                       // ��ǰѧ������ 0��
    FILE *fp = fopen("student.txt", "r"); // ֻ���ķ�ʽ��
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
    printf("ѧ�� %d\n", 1 + stu_number);
    stu->num = 1 + stu_number;
    printf("����:");
    scanf("%s", stu->name);
    getchar();
    printf("������ɼ�\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%f", &stu->score[i]);
    }
    getchar();
    // ������д���ļ���
    fp = fopen("student.txt", "a");
    if (!fp)
    {
        printf("�ļ���ʧ��\n");
        return;
    }
    fprintf(fp, "%d %s %f %f %f %f %f\n", stu->num, stu->name, stu->score[0], stu->score[1], stu->score[2], stu->score[3], stu->score[4]);
    fclose(fp);
    stu_number++;
}

void find_stu(int num, struct Student *stu)
{

    // �������
    // for (int i = 0; i < stu_number; i++)
    // {
    //     // printf("%d %s %f %f %f %f %f\n", (stu+i)->num,
    //     // (stu+i)->name,(stu+i)->score[0],(stu+i)->score[1],(stu+i)->score[2],(stu+i)->score[3],(stu+i)->score[4]);
    // }
    // ��ѯ
    int i;
    stu_number = 0;                       // ��ǰѧ������ 0��
    FILE *fp = fopen("student.txt", "r"); // ֻ���ķ�ʽ��
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
        if (num == (stu + i)->num) // ѧ��ƥ��
        {
            printf("%d %s %f %f %f %f %f\n", (stu + i)->num,
                   (stu + i)->name, (stu + i)->score[0], (stu + i)->score[1], (stu + i)->score[2], (stu + i)->score[3], (stu + i)->score[4]);
            break;
        }
    }
    if (i == stu_number)
    {
        printf("���޴���\n");
    }
}