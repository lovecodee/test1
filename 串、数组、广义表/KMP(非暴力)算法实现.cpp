//�ַ���ƥ���㷨֮KMP�㷨
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

int main(){
    char S[50];
    char T[50];
    int next[40];
    int po,position;
    printf("�����ַ���S1��\n");
    gets(S);
    printf("�����ַ���S2: \n");
    gets(T);
   // printf("����������������ʼλ�ã�");
   //scanf("%d",&po);
    get_next(T,next);
    position = Index_KMP(S,T,next,po);
    printf("KMP�㷨ƥ��λ��Ϊ��%d\n",position);
    return 0;
}
