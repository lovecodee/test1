/*ѭ������˳��洢��������*/
#include<stdio.h>
#define MAXQSIZE 100        //�������ܴﵽ����󳤶�
typedef struct{
int *base;    //�洢�ռ�Ļ���ַ
int front;    //ͷָ��
int  rear;    //βָ��
}SqQueue;
//��������
void InitQueue(SqQueue *Q); //���г�ʼ��
int QueueLength(SqQueue *Q); //����г���
void Enqueue(SqQueue *Q,int e);//���
void DeQueue(SqQueue *Q,int e);//����
int GetHead(SqQueue *Q);    //ȡѭ������ͷԪ��
//������
int main(){
    int i,total,key,length;
    SqQueue *Q;
    InitQueue(Q);
    printf("���������Ԫ��������\n");
    scanf("%d",&total);
    printf("������Ԫ�أ�\n");
    for(i=0;i<total;i++){
        scanf("%d",&key);
        Enqueue(Q,key);
    }
    if(i==total){
        printf("��ӳɹ���\n");
    }
    DeQueue(Q,key);
    length=QueueLength(Q);
    printf("���еĳ���Ϊ��%d\n",length);
    key=GetHead(Q);
    printf("��ͷԪ��Ϊ%d\n",key);
    return 0;
}
//��ʼ��
void InitQueue(SqQueue *Q)    //����һ���ն���Q
{
    Q->base=new int[MAXQSIZE];//Ϊ���з���һ���������ΪMAXQSIZE������ռ�
    if(!Q->base)
        printf("�ռ����ʧ�ܣ�\n");
    else{
        Q->front=Q->rear=0;
        printf("���г�ʼ���ɹ���\n");
    }
}

//����г���
int QueueLength(SqQueue *Q)    //����Q��Ԫ�ظ����������еĳ���
{
    return (Q->rear-Q->front+MAXQSIZE)%MAXQSIZE;
}
//���
void Enqueue(SqQueue *Q,int e) //����eΪQ���µĶ�βԪ��
{
    if((Q->rear+1)%MAXQSIZE==Q->front)
        printf("����������\n");
    else{
        Q->base[Q->rear]=e;
        Q->rear=(Q->rear+1)%MAXQSIZE;
    }
}
//����
void DeQueue(SqQueue *Q,int e)//ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
{
    if(Q->front==Q->rear)
        printf("�����ѿգ�\n");
    else{
        e=Q->base[Q->front];              //�����ͷԪ��
        Q->front=(Q->front+1)%MAXQSIZE;   //��ͷָ���1
        printf("Ԫ��%d���ӳɹ���\n",e);
    }
}

//ȡѭ�����е�ͷԪ��
int GetHead(SqQueue *Q)//����Q�Ķ�ͷԪ�أ����޸�ͷָ��
{
    if(Q->rear==Q->front)
        printf("�����ѿգ�\n");
    else{
        return Q->base[Q->front];//���ض�ͷԪ�ص�ֵ����ͷָ�벻��
    }
}
