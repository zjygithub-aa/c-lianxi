#include "head.h"
int main_a=100;//ȫ�ֱ���
static int main_b=200;//ȫ�ֱ���  ��������һ����̬��
void ceshi(void)
{
    printf("���Ժ���_main_b:%d\n",main_b);
}
int main(int argc, char const *argv[])
{
    printf("main_a:%d main_b:%d\n",main_a,main_b);
    funca();//��ǰ�������ʵ����a.c�ļ���
    ceshi();
  //  funcb();//������������������ ��Ϊ����һ����̬����  
   funca();
    funca();
    return 0;
}
