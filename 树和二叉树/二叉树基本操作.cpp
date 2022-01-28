/*二叉树遍历及相关基本操作    先序、中序、后序遍历使用递归实现，层次遍历使用队列实现 */

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define True 1
#define False 0
//测试数据:FCA##DB###EH##GM###

//树结点
typedef struct BiTNode{
    char data;                     //树结点数据域
    struct BiTNode *rchild,*lchild;//左右孩子指针
}BiTNode,*BiTree;

//队列结点
typedef struct QNode{
    BiTree data;                   //数据域
    struct QNode *next;            //指针域
}QNode,*QueuePtr;
typedef struct {
    QueuePtr front;                //队头指针
    QueuePtr rear;                 //队尾指针
}LinkQueue;

//函数声明
BiTree CreateBiTree();                 //二叉树的创建（先序遍历）
void Copy(BiTree T,BiTree NewT);       //二叉树的复制
int Depth(BiTree T);                   //计算二叉树的深度
int NodeCount(BiTree T);               //统计二叉树的结点总个数
void PreOrderTraverse(BiTree T);       //先序遍历二叉树
void InOrderTraverse(BiTree T);        //中序遍历二叉树
void BaOrderTraverse(BiTree T);        //后序遍历二叉树
void LevelTraverse(BiTree T);          //层次遍历二叉树（队列）
void Swap(BiTree T);                    //交换左右子树

LinkQueue *InitQueue();                 //队列的初始化
void EnQueue(LinkQueue *Q,BiTree T);    //入队
void DeQueue(LinkQueue *Q);             //出队
int Empty(LinkQueue *Q);                //判断队列是否为空
BiTree GetHead(LinkQueue *Q);            //获取队头元素

int main(){
    BiTree T;
    int total,depth;
    cout<<"请输入测试数据："<<endl; 
    T= CreateBiTree();
    cout<<"先序遍历结果为："<<endl;
    PreOrderTraverse(T);
    printf("\n");
    cout<<"中序遍历结果为："<<endl;
    InOrderTraverse(T);
    printf("\n");
    cout<<"后序遍历结果为："<<endl;
    BaOrderTraverse(T);
    printf("\n");
    cout<<"层次遍历结果为："<<endl;
    LevelTraverse(T);
    Swap(T);
    printf("\n交换左右子树后的后序遍历结果为：\n");
    BaOrderTraverse(T);
    total=NodeCount(T);
    printf("\n二叉树的结点总数为：%d\n",total);
    depth=Depth(T);
    printf("二叉树的深度为：%d\n",depth);
    return 0;
}

//二叉树的创建
BiTree CreateBiTree()//按照先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
{    BiTree T;
    char ch;
    cin>>ch;
    if(ch=='#')T=NULL;      //递归结束，建立树
    else{
      T = new BiTNode;       //生成根结点
      T->data=ch;             //根结点的数据域置为ch
      T->lchild=CreateBiTree();//递归创建左子树
      T->rchild=CreateBiTree();//递归创建右子树
    }
    return T;
}
//复制二叉树
void Copy(BiTree T,BiTree NewT)//复制一棵和T完全相同的二叉树
{
    if(T==NULL)
    {
        NewT=NULL;
        printf("T为空树！\n");
    }
    else{
        NewT=new BiTNode;
        NewT->data=T->data;             //复制根结点
        Copy(T->lchild,NewT->lchild);   //递归复制左子树
        Copy(T->rchild,NewT->rchild);   //递归复制右子树
    }
}
//计算二叉树的深度
int Depth(BiTree T){
    if(T==NULL) return 0;
    else{
        int m=Depth(T->lchild); //左子树深度
        int n=Depth(T->rchild); //右子树深度
        if(m>n)return (m+1);    //二叉树的深度为m与n的较大者加1
        else return (n+1);
    }
}

//统计二叉树结点个数
int NodeCount(BiTree T){
    if(T==NULL) return 0;
    else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}

//先序遍历二叉树
void PreOrderTraverse(BiTree T){
    if(T)
    {   printf("%c ",T->data);           //访问根结点
        PreOrderTraverse(T->lchild);   //先序遍历左子树
        PreOrderTraverse(T->rchild);   //先序遍历右子树
    }
}

//中序遍二叉树
void InOrderTraverse(BiTree T){
    if(T)
    {
        InOrderTraverse(T->lchild);//中序遍历左子树
         printf("%c ",T->data);     //访问根结点
        InOrderTraverse(T->rchild);//中序遍历右子树
    }

}


//后序遍历二叉树
void BaOrderTraverse(BiTree T){
    if(T){
        BaOrderTraverse(T->lchild); //后序遍历左子树
        BaOrderTraverse(T->rchild); //后序遍历右子树
        printf("%c ",T->data);       //访问根结点
    }
}

//层次遍历二叉树
void LevelTraverse(BiTree T){
    BiTree p;
    LinkQueue *Q;
    Q=InitQueue();
    if(!T)
    {
        printf("此二叉树为空树！\n");
    }
    else
    {
        EnQueue(Q,T);
    }
    while(!Empty(Q))
    {
        p=GetHead(Q);  //获取队头指针
        DeQueue(Q);    //删除队头元素
        printf("%c ",p->data);
        if(p->lchild)
        {
            EnQueue(Q,p->lchild);      //左孩子入队
        }
        if(p->rchild)
        {
           EnQueue(Q,p->rchild);      //右孩子入队
        }
    }
}
void Swap(BiTree T)     //交换左右子树
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
//队列的初始化
LinkQueue* InitQueue()
{
    LinkQueue *Q;
    Q->rear=Q->front=new QNode;           //生成新结点为头结点，队头和队尾指针指向此结点
    Q->front->next=NULL;        //头结点的指针域置空
    return Q;

}
//元素的入队
void EnQueue(LinkQueue *Q,BiTree T){
    QNode *p=new QNode;   //为入队元素分配结点空间，用指针p指向
    p->data=T;
    p->next=NULL;
    Q->rear->next=p;     //将新结点插到队尾
    Q->rear=p;
}

//元素的出队
void DeQueue(LinkQueue *Q){
    QNode *p;
    if(Q->front==Q->rear)
     printf("队列已空！\n");
     p=Q->front->next;        //p指向队头元素
    Q->front->next=p->next;  //修改头结点的指针域
    if(Q->rear==p)
     Q->rear=Q->front;
    delete p;
}
//判断队列是否空
int Empty(LinkQueue *Q){
    if(Q->front==Q->rear){
        return True;
    }
    else{
        return False;
    }
}
//获取队头元素
BiTree GetHead(LinkQueue *Q){
    if(Q->front==Q->rear){
        return NULL;
    }
    else{
        return Q->front->next->data;   //
    }
}
