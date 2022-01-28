/*循环队列顺序存储基本操作*/
#include<stdio.h>
#define MAXQSIZE 100        //队列所能达到的最大长度
typedef struct{
int *base;    //存储空间的基地址
int front;    //头指针
int  rear;    //尾指针
}SqQueue;
//函数声明
void InitQueue(SqQueue *Q); //队列初始化
int QueueLength(SqQueue *Q); //求队列长度
void Enqueue(SqQueue *Q,int e);//入队
void DeQueue(SqQueue *Q,int e);//出队
int GetHead(SqQueue *Q);    //取循环队列头元素
//主函数
int main(){
    int i,total,key,length;
    SqQueue *Q;
    InitQueue(Q);
    printf("请输入入队元素总数：\n");
    scanf("%d",&total);
    printf("请输入元素：\n");
    for(i=0;i<total;i++){
        scanf("%d",&key);
        Enqueue(Q,key);
    }
    if(i==total){
        printf("入队成功！\n");
    }
    DeQueue(Q,key);
    length=QueueLength(Q);
    printf("队列的长度为：%d\n",length);
    key=GetHead(Q);
    printf("队头元素为%d\n",key);
    return 0;
}
//初始化
void InitQueue(SqQueue *Q)    //构造一个空队列Q
{
    Q->base=new int[MAXQSIZE];//为队列分配一个最大容量为MAXQSIZE的数组空间
    if(!Q->base)
        printf("空间分配失败！\n");
    else{
        Q->front=Q->rear=0;
        printf("队列初始化成功！\n");
    }
}

//求队列长度
int QueueLength(SqQueue *Q)    //返回Q的元素个数，即队列的长度
{
    return (Q->rear-Q->front+MAXQSIZE)%MAXQSIZE;
}
//入队
void Enqueue(SqQueue *Q,int e) //插入e为Q的新的队尾元素
{
    if((Q->rear+1)%MAXQSIZE==Q->front)
        printf("队列已满！\n");
    else{
        Q->base[Q->rear]=e;
        Q->rear=(Q->rear+1)%MAXQSIZE;
    }
}
//出队
void DeQueue(SqQueue *Q,int e)//删除Q的队头元素，用e返回其值
{
    if(Q->front==Q->rear)
        printf("队列已空！\n");
    else{
        e=Q->base[Q->front];              //保存队头元素
        Q->front=(Q->front+1)%MAXQSIZE;   //队头指针加1
        printf("元素%d出队成功！\n",e);
    }
}

//取循环队列的头元素
int GetHead(SqQueue *Q)//返回Q的队头元素，不修改头指针
{
    if(Q->rear==Q->front)
        printf("队列已空！\n");
    else{
        return Q->base[Q->front];//返回队头元素的值，队头指针不变
    }
}
