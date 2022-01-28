#include<stdio.h>
#include<iostream>
using namespace std;
typedef struct StackNode{
    int data;                 //������
    struct StackNode *next;   //ָ����
}StackNode,*LinkStack;
//��������
void InitStack(StackNode *S);     //��ջ�ĳ�ʼ��
void Push(StackNode *S,int key);  //��ջ����ջ
int  Pop(StackNode *S,int key);   //��ջ�ĳ�ջ
void Gettop(StackNode *S);        //ȡջ��Ԫ��

int main(){
int i,total,key,key1;
StackNode *S;
InitStack(S);
printf("������Ԫ���ܸ�����\n");
scanf("%d",&total);
printf("������Ԫ�أ�\n");
for( i=0;i<total;i++){
    scanf("%d",&key);
    Push(S,key);
}
if(i==total){
    printf("��ջ�ɹ���\n");
}
printf("%d",(S->data));
   key1 = Pop(S,key1);
printf("%d\n",key1);
return 0;
}

//��ջ�ĳ�ʼ��
void InitStack(StackNode *S){
//����һ����ջ
    S=NULL;
    printf("��ʼ���ɹ���\n");
}
//��ջ����ջ
void Push(StackNode *S,int key){
//��ջ������Ԫ��
    StackNode *p  = new StackNode; //��̬������ռ�
    if(!p){
        printf("�½������ʧ�ܣ�");
    }
    else{
        p->data= key;
        p->next=S;
        S=p;
}
}
//��ջ�ĳ�ջ
int Pop(StackNode *S,int key){
//ɾ��S�е�ջ��Ԫ�أ���key������ֵ
    StackNode *p;
    if(S==NULL)
        printf("ջ�ѿգ�\n");
    else{
        key=S->data;              //��ջ��Ԫ�ظ�ֵ��key
        p=S;                      //��p��ʱ����ջ���ռ䣬�ѱ��ͷ�
        S=S->next;                //�޸�ջ��ָ��
        delete p;                 //�ͷ�ԭջ��Ԫ�صĿռ�
       return key;
    }
}

//ȡջ��Ԫ��
void Gettop(StackNode *S){
//����S��ջ��ָ�룬���޸�ջ��ָ��
    if(S!=NULL){
        printf("ջ��Ԫ��Ϊ��%d",S->data);
    }
}





