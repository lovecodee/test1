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
//BF算法
int BF(char S[],char T[]){
	int index=0;                     //主串从下标0开始第一趟匹配
	int time=0;                      //记录比较次数
	int i=0,j=0;                     //设置比较的起始下标
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
    printf("BF算法总移动次数为:%d\n",time);
    if(j==strlen(T))return (i-strlen(T)+1);
    else return 0;

}

int main(){
    char S[50];
    char T[50];
    int next[40];
    int po,position1,position2;
    printf("输入字符串S1：\n");
    gets(S);
    printf("输入字符串S2: \n");
    gets(T);
    printf("请输入主串检索开始位置：");
   scanf("%d",&po);
    get_next(T,next);
    position1 = Index_KMP(S,T,next,po);
    position2 = BF(S,T);
    if(position1==0)
    {
        printf("目标串不在主串中！\n");
    }
    else{
        printf("KMP算法目标串在主串中对应的位置为：%d\n",position1);
    }
    if(position2==0)
    {
        printf("目标串不在主串中！\n");
    }
    else{
        printf("BF算法目标串在主串中对应的位置为：%d\n",position2);
    }
    return 0;
}
