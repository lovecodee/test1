/*   队列的链式存储结构 基本操作：初始化、入队、出队、取队头元素     */
#include<stdio.h>
//结点
typedef struct QNode{
    int data;           //数据域
    struct QNode *next;//指针域
}QNode,*QueuePtr;

typedef struct {
    QueuePtr front;//队头指针
    QueuePtr rear;//队尾指针
}LinkQueue;

//函数声明
void InitQueue(LinkQueue *Q);         //队列的初始化
void EnQueue(LinkQueue *Q,int key);   //入队
void DeQueue(LinkQueue *Q,int key);   //出队
void GetHead(LinkQueue *Q);           //取队头元素
//主函数
int main(){
    LinkQueue *Q;
    int total,i,key;
    InitQueue(Q);
    printf("请输入进队元素总数：\n");
    scanf("%d\n",&total);
    for (i=0;i<total;i++){
        scanf("%d",&key);
        EnQueue(Q,key);
    }
    if(i==total){
        printf("入队成功！\n");
    }
    while(Q)
    {
        DeQueue(Q,key);
    }
return 0;
}
//初始化
void InitQueue(LinkQueue *Q)//构造一个空队列Q
{
    Q->front=Q->rear=new QNode;//生成新结点作为头结点，队头和队尾指针指向此结点
    Q->front->next=NULL;      //头结点的指针
    printf("初始化成功！\n");
}

//入队
void EnQueue(LinkQueue *Q,int key)//插入元素key为Q的新的队尾元素
{
    QNode *p=new QNode;                 //为入队元素分配结点空间，用指针p指向
    p->data = key;                      //将新结点的数据域置为key
    p->next=NULL;                       //将新结点插入到队尾
    Q->rear->next=p;
    Q->rear=p;                          //修改队尾指针
}

//出队
void DeQueue(LinkQueue *Q,int key)//删除Q的队头元素，用key返回其值
{
    QNode *p;
    if(Q->front==Q->rear)
        printf("队列已空！\n");
    p=Q->front->next;                   //p指向队头元素
    key = p->data;                      //e用来保存队头元素的值
    Q->front->next=p->next;             //修改头结点的指针域
    if(Q->rear==p) Q->rear=Q->front;    //最后一个元素被删，队尾指针指向头结点
    delete p;                           //释放原队头元素空间
    printf("出队元素为%d\n",key);
}

//取队头元素
void GetHead(LinkQueue *Q)  //返回Q的队头元素，不修改队头指针
{
    if(Q->front!=Q->rear)
        printf("队列已空！\n");
    else{
        printf("队头元素为%d",Q->front->next->data);//Q->front初始指向头指针
    }
}

