//�ַ���֮����ƥ���㷨��BF�㷨��

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//BF�㷨
int BF(char S[],char T[]){
	int index=0;                     //�������±�0��ʼ��һ��ƥ��
	int time=0;                      //��¼�Ƚϴ���
	int i=0,j=0;                     //���ñȽϵ���ʼ�±�
	int length=strlen(T);
	while((S[i]!='\0')&&(T[j]!='\0'))//�ַ���������־Ϊ��\0�� 
    {
            time++;
		if(S[i]==T[j])
		{
			i++;j++;                 //������Ŀ�괮��λ�þ���1��Ȼ������Ƚ� 
		}else
		{
			index++;                 //������ʼλ�ú��� 
			i=index;                  
			j=0;                     //����Ŀ�괮��ʼλ�� 
		}
    }
    printf("�ܱȽϴ���Ϊ%d\n",time);
    if(j==strlen(T))return (i-strlen(T)+1);//�ַ�����Ĭ���±��Ǵ�0��ʼ��λ��=�±�+1
    else return 0;

}

int main()
{
    char s1[100];
    char s2[80];
    int position;
    printf("�������ַ���S1:\n");
    gets(s1);
    printf("������Ŀ�괮S2��\n");
    gets(s2);
    position = BF(s1,s2);
    if(position==0)
    {
        printf("Ŀ�괮���������У�\n");
    }
    else{
        printf("Ŀ�괮�������ж�Ӧ��λ��Ϊ��\n");
        printf("%d\n",position);
    }
    return 0;
}
