#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef int ElmeType;
typedef struct Queue{
ElmeType data[MAXSIZE];
int *front;
int *rear;
};
//队列的初始化
void QueueInitial(struct Queue* queue)
{
queue->front=0;
queue->rear=0;
}
//判断队列是否为空
void QueueEmpty(struct Queue*queue)
{
    if(queue->front==queue->rear){
        printf("队列为空");
    }
    else{
        printf("队列未空！");
    }

}
//判断队列是否已满
void QueueFull(struct Queue*queue){
if(queue->rear-queue->front==MAXSIZE)
{

    printf("队列已满！");
}
else{
    printf("队列未满！");
}


}


















