/*   ���е���ʽ�洢�ṹ ������������ʼ������ӡ����ӡ�ȡ��ͷԪ��     */
#include<stdio.h>
//���
typedef struct QNode{
    int data;           //������
    struct QNode *next;//ָ����
}QNode,*QueuePtr;

typedef struct {
    QueuePtr front;//��ͷָ��
    QueuePtr rear;//��βָ��
}LinkQueue;

//��������
void InitQueue(LinkQueue *Q);         //���еĳ�ʼ��
void EnQueue(LinkQueue *Q,int key);   //���
void DeQueue(LinkQueue *Q,int key);   //����
void GetHead(LinkQueue *Q);           //ȡ��ͷԪ��
//������
int main(){
    LinkQueue *Q;
    int total,i,key;
    InitQueue(Q);
    printf("���������Ԫ��������\n");
    scanf("%d\n",&total);
    for (i=0;i<total;i++){
        scanf("%d",&key);
        EnQueue(Q,key);
    }
    if(i==total){
        printf("��ӳɹ���\n");
    }
    while(Q)
    {
        DeQueue(Q,key);
    }
return 0;
}
//��ʼ��
void InitQueue(LinkQueue *Q)//����һ���ն���Q
{
    Q->front=Q->rear=new QNode;//�����½����Ϊͷ��㣬��ͷ�Ͷ�βָ��ָ��˽��
    Q->front->next=NULL;      //ͷ����ָ��
    printf("��ʼ���ɹ���\n");
}

//���
void EnQueue(LinkQueue *Q,int key)//����Ԫ��keyΪQ���µĶ�βԪ��
{
    QNode *p=new QNode;                 //Ϊ���Ԫ�ط�����ռ䣬��ָ��pָ��
    p->data = key;                      //���½�����������Ϊkey
    p->next=NULL;                       //���½����뵽��β
    Q->rear->next=p;
    Q->rear=p;                          //�޸Ķ�βָ��
}

//����
void DeQueue(LinkQueue *Q,int key)//ɾ��Q�Ķ�ͷԪ�أ���key������ֵ
{
    QNode *p;
    if(Q->front==Q->rear)
        printf("�����ѿգ�\n");
    p=Q->front->next;                   //pָ���ͷԪ��
    key = p->data;                      //e���������ͷԪ�ص�ֵ
    Q->front->next=p->next;             //�޸�ͷ����ָ����
    if(Q->rear==p) Q->rear=Q->front;    //���һ��Ԫ�ر�ɾ����βָ��ָ��ͷ���
    delete p;                           //�ͷ�ԭ��ͷԪ�ؿռ�
    printf("����Ԫ��Ϊ%d\n",key);
}

//ȡ��ͷԪ��
void GetHead(LinkQueue *Q)  //����Q�Ķ�ͷԪ�أ����޸Ķ�ͷָ��
{
    if(Q->front!=Q->rear)
        printf("�����ѿգ�\n");
    else{
        printf("��ͷԪ��Ϊ%d",Q->front->next->data);//Q->front��ʼָ��ͷָ��
    }
}

