/*ջ�ĵ���Ӧ��֮���ʽ��ֵ*/
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
//��������
void InitStack(SqStack *S);      //��ʼ��˳��ջ
void Push(SqStack *S,int key);   //Ԫ����ջ
void Pop(SqStack *S,int *key);    //Ԫ�س�ջ
void Gettop(SqStack *S);         //ȡջ��Ԫ��

int main()
{

        return 0;
}
//��ʼ��˳��ջ
void InitStack(SqStack *S){
    S->base = (int *)malloc(sizeof(int)*MAXSIZE);// Ϊ˳��ջ��̬����һ���������ΪMAXSIZE������ռ�
    if(!S->base)
        printf("��̬�����ڴ�ռ�ʧ�ܣ�\n");
    else{
        S->top=S->base;                           //top��ʼΪbase����ջ
        S->stacksize =MAXSIZE;
        printf("��ʼ���ɹ�\n");}
}

//Ԫ����ջ
void Push(SqStack *S,int key){
//����Ԫ��keyΪ�µ�ջ��Ԫ��
    if(S->top-S->base==S->stacksize)
        printf("ջ�Ѿ�����");
    else{
        *S->top++=key;
    }
}

//Ԫ�س�ջ
void Pop(SqStack *S,int *key){
    if(S->top==S->base)
        printf("ջ�գ�\n");
    else{
        *key=*--S->top;        //ջ��ָ���1����ջ��Ԫ�ظ���key
        printf("��ջ�ɹ�,��ջԪ��Ϊ%d\n",*key);
    }
}

//ȡջ��Ԫ��
void Gettop(SqStack *S){
//����S��ջ��Ԫ�أ����޸�ջ��ָ��
    if(S->top!=S->base)
    {
        printf("%d\t",*(S->top-1)); //����ջ��Ԫ�ص�ֵ
    }
}

char EvaluateExpression()//�������ʽ��ֵ����������㷨����OPTR��OPND�ֱ�Ϊ�����ջ�Ͳ�����ջ
{
    char ch;
    int
    InitStack(OPND);     //��ʼ��OPNDջ
    InitStack(OPTR);     //��ʼ��OPTRջ
    Push(OPTR,'#');      //�����ʽ��ʼ����#��ѹ��OPTRջ
    cin>>ch;
    while(ch!='#'||GetTop(OPTR)!='#'){
        if(!In(ch)){
            Push(OPND,ch);
            cin>>ch;
        }
        else{
            switch(Precede(GetTop(OPTR),ch)){
                case'<':{Push(OPTR,ch);                //��ǰ�ַ�chѹ��OPTRջ����ȡ��һ���ַ�
                          cin>>ch;
                          break;
                        }
                case'>':{ Pop(OPTR,theta);             //����ջ���������
                          Pop(OPND,b);Pop(OPND,a);      //����OPNDջ��������������
                          Push(OPND,Operate(a,theta,b));//��������ѹ��OPNDջ
                          break;
                         }
                case'=':{                              //OPTR��ջ��Ԫ���ǡ�������ch�ǡ�����
                          Pop(OPND,x);                  //����ջ��������
                          cin>>ch;                      //��ȡ��һ���ַ�ch
                          break;
                         }

            }
            return GetTop(OPND);                       //OPNDջ��Ԫ�ؼ�Ϊ���ʽ��ֵ���
        }
    }
}






































