 /* ջΪһ���Ƚ�������������ͣ���������ջ�����в��� */


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
//��������
void InitStack(SqStack *S);      //��ʼ��˳��ջ
void Push(SqStack *S,int key);   //Ԫ����ջ
void Pop(SqStack *S,int key);    //Ԫ�س�ջ
void Gettop(SqStack *S);         //ȡջ��Ԫ��

int main()
{
    int total,key,i;
    SqStack *S;
    InitStack(S);
    printf("������Ԫ���ܸ�����\n");
    scanf("%d",&total);
    printf("������Ԫ�أ�\n");
    for(i=0;i<total;i++){
        scanf("%d",&key);             //��ȡԪ��
        Push(S,key);                  //ѹ��ջ��
    }
    if(i==total){
        printf("��ջ�ɹ���\n");
    }
    printf("��ջ���Ϊ��\n");
    while(S->top!=S->base)
    {
       Pop(S,key);
    }
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
void Pop(SqStack *S,int key){
    if(S->top==S->base)
        printf("ջ�գ�\n");
    else{
        key=*--S->top;        //ջ��ָ���1����ջ��Ԫ�ظ���key
        printf("��ջ�ɹ�,��ջԪ��Ϊ%d\n",key);
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






