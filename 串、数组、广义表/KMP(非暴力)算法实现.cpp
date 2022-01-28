//字符串匹配算法之KMP算法
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

        else{ j=next[j];time+=(j-next[j]);}//   移动字符串
    }
        printf("KMP算法需要移动的次数为：%d\n",time);
    if(T[j]=='\0')return i-strlen(T)+1;
    else
    {
        printf("匹配失败！");
        return 0;
    }
}

//获取next的值
void get_next(char T[],int  next[])
{
    int i=1;
    next[0]=0;           //初始化next第一个值为0
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
    printf("输入字符串S1：\n");
    gets(S);
    printf("输入字符串S2: \n");
    gets(T);
   // printf("请输入主串检索开始位置：");
   //scanf("%d",&po);
    get_next(T,next);
    position = Index_KMP(S,T,next,po);
    printf("KMP算法匹配位置为：%d\n",position);
    return 0;
}
