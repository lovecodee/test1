//字符串之暴力匹配算法（BF算法）

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//BF算法
int BF(char S[],char T[]){
	int index=0;                     //主串从下标0开始第一趟匹配
	int time=0;                      //记录比较次数
	int i=0,j=0;                     //设置比较的起始下标
	int length=strlen(T);
	while((S[i]!='\0')&&(T[j]!='\0'))//字符串结束标志为“\0” 
    {
            time++;
		if(S[i]==T[j])
		{
			i++;j++;                 //主串和目标串的位置均加1，然后继续比较 
		}else
		{
			index++;                 //主串起始位置后移 
			i=index;                  
			j=0;                     //重置目标串起始位置 
		}
    }
    printf("总比较次数为%d\n",time);
    if(j==strlen(T))return (i-strlen(T)+1);//字符数组默认下标是从0开始，位置=下标+1
    else return 0;

}

int main()
{
    char s1[100];
    char s2[80];
    int position;
    printf("请输入字符串S1:\n");
    gets(s1);
    printf("请输入目标串S2：\n");
    gets(s2);
    position = BF(s1,s2);
    if(position==0)
    {
        printf("目标串不在主串中！\n");
    }
    else{
        printf("目标串在主串中对应的位置为：\n");
        printf("%d\n",position);
    }
    return 0;
}
