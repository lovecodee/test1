#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int Index_KMP(char S[],char T[],int next[],int pos)
{
    int i=pos;
    int time=1;
    int j=0;
    while(S[i]!='\0'&&T[j]!='\0')
    {
        if(j==0||S[i]==T[j]){++i;++j;time++;}

        else{ j=next[j];time+=(j-next[j]);}//   �ƶ��ַ���
    }
        printf("KMP�㷨��Ҫ�ƶ��Ĵ���Ϊ��%d\n",time);
    if(T[j]=='\0')return i-strlen(T)+1;
    else
    {
        printf("ƥ��ʧ�ܣ�");
        return 0;
    }
}

//��ȡnext��ֵ
void get_next(char T[],int  next[])
{
    int i=1;
    next[0]=0;           //��ʼ��next��һ��ֵΪ0
    int j=0;
    int length3;
    length3=strlen(T);
    while(i<length3){
        if(j==0||T[i]==T[j])
        {
            ++i,++j;
            next[i]=j;
        }
        else
            j=next[j];
    }
}
//BF�㷨
int BF(char S[],char T[]){
	int index=0;                     //�������±�0��ʼ��һ��ƥ��
	int time=0;                      //��¼�Ƚϴ���
	int i=0,j=0;                     //���ñȽϵ���ʼ�±�
	int length=strlen(T);
	while((S[i]!='\0')&&(T[j]!='\0'))
    {
            time++;
		if(S[i]==T[j])
		{
			i++;j++;
		}else
		{
			index++;
			time+=j;
			i=index;j=0;
		}
    }
    printf("BF�㷨���ƶ�����Ϊ:%d\n",time);
    if(j==strlen(T))return (i-strlen(T)+1);
    else return 0;

}

int main(){
    char S[50];
    char T[50];
    int next[40];
    int po,position1,position2;
    printf("�����ַ���S1��\n");
    gets(S);
    printf("�����ַ���S2: \n");
    gets(T);
    printf("����������������ʼλ�ã�");
   scanf("%d",&po);
    get_next(T,next);
    position1 = Index_KMP(S,T,next,po);
    position2 = BF(S,T);
    if(position1==0)
    {
        printf("Ŀ�괮���������У�\n");
    }
    else{
        printf("KMP�㷨Ŀ�괮�������ж�Ӧ��λ��Ϊ��%d\n",position1);
    }
    if(position2==0)
    {
        printf("Ŀ�괮���������У�\n");
    }
    else{
        printf("BF�㷨Ŀ�괮�������ж�Ӧ��λ��Ϊ��%d\n",position2);
    }
    return 0;
}
