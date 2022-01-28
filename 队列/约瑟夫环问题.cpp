/* 15个教徒和15 个非教徒在深海上遇险，必须将一半的人投入海中，其余的人才能幸免于难，
   于是想了一个办法：30个人围成一圆圈，从第一个人开始依次报数，每数到第九个人就将他扔入大海
                     如此循环进行直到仅余15个人为止。求活着的人的序号。
*/
/*
有n个人围城一圈，按顺序编号，从第一个人开始报数，从1报到m，凡报到m的人退出圈子，
然后接着报数，问最后留下来那几位是多少？
*/
//数组
//用长度为n的数组存储人的编号，退出的人编号置为0，当15个人都退出后，剩下的那个编号不为0的人就是要找的人。

#include <stdio.h>
#include <malloc.h>
void left_num(int* a,int n,int m) {
    int out = 0,count = 0,i =0;    //out为出去的人数，count为报数，i为目前报到第几个人
    int *p = a;
    int num = 0;
    for(num = 0;num < n;num++)
    {
        *(a+num) = num+1;
    }   //为n个人编号1-n
    while (out != 15)
     {
        if (*(p+i) != 0)
        {
            count ++;   //不等于0才报数+！
        }
        if (count%m==0 && *(p+i)!=0)
        {
            //printf("出队的序号为：%d",*(p+i));
            *(p+i) = 0;
            count=0;
            out++;  //报道m那么，出列人数out+1，且内容置0，报数置0
            printf("%d\n",i+1);
        }
        i++;
        if (i == n)
        {
            i = 0;//到队尾重头开始
        }
    }
    //输出剩下的人
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
    printf("leave sequence：\n");
    left_num(a,n,m);
    return 0;
}
