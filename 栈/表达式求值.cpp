/*栈的典型应用之表达式求值*/
#include<stdio.h>
#include<iostream>
#include<string.h>
#define MAXSIZE 100
using namespace std:
typedef struct
{
int *base;
int *top;
int stacksize;
}SqStack;
//函数声明
void InitStack(SqStack *S);      //初始化顺序栈
void Push(SqStack *S,int key);   //元素入栈
void Pop(SqStack *S,int *key);    //元素出栈
void Gettop(SqStack *S);         //取栈顶元素

int main()
{

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
void Pop(SqStack *S,int *key){
    if(S->top==S->base)
        printf("栈空！\n");
    else{
        *key=*--S->top;        //栈顶指针减1，将栈顶元素赋给key
        printf("出栈成功,出栈元素为%d\n",*key);
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

char EvaluateExpression()//算术表达式求值的算符优先算法，设OPTR和OPND分别为运算符栈和操作数栈
{
    char ch;
    int
    InitStack(OPND);     //初始化OPND栈
    InitStack(OPTR);     //初始化OPTR栈
    Push(OPTR,'#');      //将表达式起始符“#”压入OPTR栈
    cin>>ch;
    while(ch!='#'||GetTop(OPTR)!='#'){
        if(!In(ch)){
            Push(OPND,ch);
            cin>>ch;
        }
        else{
            switch(Precede(GetTop(OPTR),ch)){
                case'<':{Push(OPTR,ch);                //当前字符ch压入OPTR栈，读取下一个字符
                          cin>>ch;
                          break;
                        }
                case'>':{ Pop(OPTR,theta);             //弹出栈顶的运算符
                          Pop(OPND,b);Pop(OPND,a);      //弹出OPND栈顶的两个操作数
                          Push(OPND,Operate(a,theta,b));//将运算结果压入OPND栈
                          break;
                         }
                case'=':{                              //OPTR的栈顶元素是‘（’且ch是‘）’
                          Pop(OPND,x);                  //弹出栈顶‘（’
                          cin>>ch;                      //读取下一个字符ch
                          break;
                         }

            }
            return GetTop(OPND);                       //OPND栈顶元素即为表达式求值结果
        }
    }
}






































