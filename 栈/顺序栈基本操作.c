 /* 栈为一种先进后出的数据类型，仅可以在栈顶进行操作 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
typedef struct
{
int *base;
int *top;
int stacksize;
}SqStack;
//函数声明
void InitStack(SqStack *S);      //初始化顺序栈
void Push(SqStack *S,int key);   //元素入栈
void Pop(SqStack *S,int key);    //元素出栈
void Gettop(SqStack *S);         //取栈顶元素

int main()
{
    int total,key,i;
    SqStack *S;
    InitStack(S);
    printf("请输入元素总个数：\n");
    scanf("%d",&total);
    printf("请输入元素：\n");
    for(i=0;i<total;i++){
        scanf("%d",&key);             //获取元素
        Push(S,key);                  //压入栈中
    }
    if(i==total){
        printf("入栈成功！\n");
    }
    printf("出栈结果为：\n");
    while(S->top!=S->base)
    {
       Pop(S,key);
    }
        return 0;
}
//初始化顺序栈
void InitStack(SqStack *S){
    S->base = (int *)malloc(sizeof(int)*MAXSIZE);// 为顺序栈动态分配一个最大容量为MAXSIZE的数组空间
    if(!S->base)
        printf("动态分配内存空间失败！\n");
    else{
        S->top=S->base;                           //top初始为base，空栈
        S->stacksize =MAXSIZE;
        printf("初始化成功\n");}
}

//元素入栈
void Push(SqStack *S,int key){
//插入元素key为新的栈顶元素
    if(S->top-S->base==S->stacksize)
        printf("栈已经满！");
    else{
        *S->top++=key;
    }
}

//元素出栈
void Pop(SqStack *S,int key){
    if(S->top==S->base)
        printf("栈空！\n");
    else{
        key=*--S->top;        //栈顶指针减1，将栈顶元素赋给key
        printf("出栈成功,出栈元素为%d\n",key);
    }
}

//取栈顶元素
void Gettop(SqStack *S){
//返回S的栈顶元素，不修改栈顶指针
    if(S->top!=S->base)
    {
        printf("%d\t",*(S->top-1)); //返回栈顶元素的值
    }
}






