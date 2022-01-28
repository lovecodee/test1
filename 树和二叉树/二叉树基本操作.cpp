/*��������������ػ�������    �������򡢺������ʹ�õݹ�ʵ�֣���α���ʹ�ö���ʵ�� */

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define True 1
#define False 0
//��������:FCA##DB###EH##GM###

//�����
typedef struct BiTNode{
    char data;                     //�����������
    struct BiTNode *rchild,*lchild;//���Һ���ָ��
}BiTNode,*BiTree;

//���н��
typedef struct QNode{
    BiTree data;                   //������
    struct QNode *next;            //ָ����
}QNode,*QueuePtr;
typedef struct {
    QueuePtr front;                //��ͷָ��
    QueuePtr rear;                 //��βָ��
}LinkQueue;

//��������
BiTree CreateBiTree();                 //�������Ĵ��������������
void Copy(BiTree T,BiTree NewT);       //�������ĸ���
int Depth(BiTree T);                   //��������������
int NodeCount(BiTree T);               //ͳ�ƶ������Ľ���ܸ���
void PreOrderTraverse(BiTree T);       //�������������
void InOrderTraverse(BiTree T);        //�������������
void BaOrderTraverse(BiTree T);        //�������������
void LevelTraverse(BiTree T);          //��α��������������У�
void Swap(BiTree T);                    //������������

LinkQueue *InitQueue();                 //���еĳ�ʼ��
void EnQueue(LinkQueue *Q,BiTree T);    //���
void DeQueue(LinkQueue *Q);             //����
int Empty(LinkQueue *Q);                //�ж϶����Ƿ�Ϊ��
BiTree GetHead(LinkQueue *Q);            //��ȡ��ͷԪ��

int main(){
    BiTree T;
    int total,depth;
    cout<<"������������ݣ�"<<endl; 
    T= CreateBiTree();
    cout<<"����������Ϊ��"<<endl;
    PreOrderTraverse(T);
    printf("\n");
    cout<<"����������Ϊ��"<<endl;
    InOrderTraverse(T);
    printf("\n");
    cout<<"����������Ϊ��"<<endl;
    BaOrderTraverse(T);
    printf("\n");
    cout<<"��α������Ϊ��"<<endl;
    LevelTraverse(T);
    Swap(T);
    printf("\n��������������ĺ���������Ϊ��\n");
    BaOrderTraverse(T);
    total=NodeCount(T);
    printf("\n�������Ľ������Ϊ��%d\n",total);
    depth=Depth(T);
    printf("�����������Ϊ��%d\n",depth);
    return 0;
}

//�������Ĵ���
BiTree CreateBiTree()//���������������������н���ֵ��һ���ַ������������������ʾ�Ķ�����T
{    BiTree T;
    char ch;
    cin>>ch;
    if(ch=='#')T=NULL;      //�ݹ������������
    else{
      T = new BiTNode;       //���ɸ����
      T->data=ch;             //��������������Ϊch
      T->lchild=CreateBiTree();//�ݹ鴴��������
      T->rchild=CreateBiTree();//�ݹ鴴��������
    }
    return T;
}
//���ƶ�����
void Copy(BiTree T,BiTree NewT)//����һ�ú�T��ȫ��ͬ�Ķ�����
{
    if(T==NULL)
    {
        NewT=NULL;
        printf("TΪ������\n");
    }
    else{
        NewT=new BiTNode;
        NewT->data=T->data;             //���Ƹ����
        Copy(T->lchild,NewT->lchild);   //�ݹ鸴��������
        Copy(T->rchild,NewT->rchild);   //�ݹ鸴��������
    }
}
//��������������
int Depth(BiTree T){
    if(T==NULL) return 0;
    else{
        int m=Depth(T->lchild); //���������
        int n=Depth(T->rchild); //���������
        if(m>n)return (m+1);    //�����������Ϊm��n�Ľϴ��߼�1
        else return (n+1);
    }
}

//ͳ�ƶ�����������
int NodeCount(BiTree T){
    if(T==NULL) return 0;
    else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}

//�������������
void PreOrderTraverse(BiTree T){
    if(T)
    {   printf("%c ",T->data);           //���ʸ����
        PreOrderTraverse(T->lchild);   //�������������
        PreOrderTraverse(T->rchild);   //�������������
    }
}

//����������
void InOrderTraverse(BiTree T){
    if(T)
    {
        InOrderTraverse(T->lchild);//�������������
         printf("%c ",T->data);     //���ʸ����
        InOrderTraverse(T->rchild);//�������������
    }

}


//�������������
void BaOrderTraverse(BiTree T){
    if(T){
        BaOrderTraverse(T->lchild); //�������������
        BaOrderTraverse(T->rchild); //�������������
        printf("%c ",T->data);       //���ʸ����
    }
}

//��α���������
void LevelTraverse(BiTree T){
    BiTree p;
    LinkQueue *Q;
    Q=InitQueue();
    if(!T)
    {
        printf("�˶�����Ϊ������\n");
    }
    else
    {
        EnQueue(Q,T);
    }
    while(!Empty(Q))
    {
        p=GetHead(Q);  //��ȡ��ͷָ��
        DeQueue(Q);    //ɾ����ͷԪ��
        printf("%c ",p->data);
        if(p->lchild)
        {
            EnQueue(Q,p->lchild);      //�������
        }
        if(p->rchild)
        {
           EnQueue(Q,p->rchild);      //�Һ������
        }
    }
}
void Swap(BiTree T)     //������������
{
	BiTree p;
	if (T) 
	{
		Swap(T->rchild);
		Swap(T->lchild);
		p = T->rchild;
		T->rchild = T->lchild;
		T->lchild = p;
	}
}
//���еĳ�ʼ��
LinkQueue* InitQueue()
{
    LinkQueue *Q;
    Q->rear=Q->front=new QNode;           //�����½��Ϊͷ��㣬��ͷ�Ͷ�βָ��ָ��˽��
    Q->front->next=NULL;        //ͷ����ָ�����ÿ�
    return Q;

}
//Ԫ�ص����
void EnQueue(LinkQueue *Q,BiTree T){
    QNode *p=new QNode;   //Ϊ���Ԫ�ط�����ռ䣬��ָ��pָ��
    p->data=T;
    p->next=NULL;
    Q->rear->next=p;     //���½��嵽��β
    Q->rear=p;
}

//Ԫ�صĳ���
void DeQueue(LinkQueue *Q){
    QNode *p;
    if(Q->front==Q->rear)
     printf("�����ѿգ�\n");
     p=Q->front->next;        //pָ���ͷԪ��
    Q->front->next=p->next;  //�޸�ͷ����ָ����
    if(Q->rear==p)
     Q->rear=Q->front;
    delete p;
}
//�ж϶����Ƿ��
int Empty(LinkQueue *Q){
    if(Q->front==Q->rear){
        return True;
    }
    else{
        return False;
    }
}
//��ȡ��ͷԪ��
BiTree GetHead(LinkQueue *Q){
    if(Q->front==Q->rear){
        return NULL;
    }
    else{
        return Q->front->next->data;   //
    }
}
