/* 15����ͽ��15 ���ǽ�ͽ��������գ����뽫һ�����Ͷ�뺣�У�������˲����������ѣ�
   ��������һ���취��30����Χ��һԲȦ���ӵ�һ���˿�ʼ���α�����ÿ�����ھŸ��˾ͽ��������
                     ���ѭ������ֱ������15����Ϊֹ������ŵ��˵���š�
*/
/*
��n����Χ��һȦ����˳���ţ��ӵ�һ���˿�ʼ��������1����m��������m�����˳�Ȧ�ӣ�
Ȼ����ű�����������������Ǽ�λ�Ƕ��٣�
*/
//����
//�ó���Ϊn������洢�˵ı�ţ��˳����˱����Ϊ0����15���˶��˳���ʣ�µ��Ǹ���Ų�Ϊ0���˾���Ҫ�ҵ��ˡ�

#include <stdio.h>
#include <malloc.h>
void left_num(int* a,int n,int m) {
    int out = 0,count = 0,i =0;    //outΪ��ȥ��������countΪ������iΪĿǰ�����ڼ�����
    int *p = a;
    int num = 0;
    for(num = 0;num < n;num++)
    {
        *(a+num) = num+1;
    }   //Ϊn���˱��1-n
    while (out != 15)
     {
        if (*(p+i) != 0)
        {
            count ++;   //������0�ű���+��
        }
        if (count%m==0 && *(p+i)!=0)
        {
            //printf("���ӵ����Ϊ��%d",*(p+i));
            *(p+i) = 0;
            count=0;
            out++;  //����m��ô����������out+1����������0��������0
            printf("%d\n",i+1);
        }
        i++;
        if (i == n)
        {
            i = 0;//����β��ͷ��ʼ
        }
    }
    //���ʣ�µ���
    for (num = 0; num < n; num++) {
        if (*(a+num) != 0)
        {
            printf("left num:%d\n",*(a+num));
        }
    }
}

int main()
{
    int m,n;
    int a[50] = {0};
    printf("Please input total num:");
    scanf("%d",&n);
    printf("Please input out num:");
    scanf("%d",&m);
    printf("leave sequence��\n");
    left_num(a,n,m);
    return 0;
}
