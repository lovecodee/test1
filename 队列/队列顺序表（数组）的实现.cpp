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
//���еĳ�ʼ��
void QueueInitial(struct Queue* queue)
{
queue->front=0;
queue->rear=0;
}
//�ж϶����Ƿ�Ϊ��
void QueueEmpty(struct Queue*queue)
{
    if(queue->front==queue->rear){
        printf("����Ϊ��");
    }
    else{
        printf("����δ�գ�");
    }

}
//�ж϶����Ƿ�����
void QueueFull(struct Queue*queue){
if(queue->rear-queue->front==MAXSIZE)
{

    printf("����������");
}
else{
    printf("����δ����");
}


}


















