/*
��n����Χ��һȦ����˳���ţ��ӵ�һ���˿�ʼ��������1����m��������m�����˳�Ȧ�ӣ�
Ȼ����ű��������������������ԭ���ĵڼ��ŵ���λ��

*/

//ѭ������ʵ��
//����һ��ѭ����������ڵ�����������˵ı�ţ�������������ÿ�α���m�����˳������ͷŸýڵ㣬ֱ������ֻʣһ���ڵ㡣
#include <stdio.h>
#include <malloc.h>

 /*�����ṹ��*/
 typedef struct Node{
     int Num;
     struct Node *next;
 }JoseNode, *PNode, *HNode;

 /**********��ʼ��ѭ��������*********/
 int JoseInit(HNode h)
 {
     if (!h)
     {
         printf("��ʼ���������\n");
         return 0;
     }
     (h)->next = (h);//ѭ��������
     return 1;

 }

 /*************������������**********/
 int JoseInsert(JoseNode *h, int pos, int x)
 {
     PNode p=h,q;
     int i=1;
     if (pos == 1)/*β�巨*/
     {
         p->Num = x;
         p->next = p;
         return 1;
     }
     while(i<pos-1)//��pָ�����λ�õ�ǰһ�����
     {
         p=p->next;
         i++;
     }
     q=(PNode)malloc(sizeof(JoseNode));//����һ���µĽڵ�q
     q->Num=x;                          //��ʼ��������
     q->next=p->next;                   //��qָ��p��ָ������һ���
     p->next=q;                         //��pָ��q
     return 1;                          //����Ҫע�⣬����Ҫ��֤�����ܶ�
 }

 /*����*/
 void TraverseList(HNode h, int M)              //h��ʾ������Mָ���������еĽ�����
 {
     int i = 0;
     PNode p = h;                               //����һ��ָ�����ָ�룬���ڽ�����ƶ�
     printf("������˵ı��Ϊ��\n");
     while (i<M)
     {
         printf("%d\t", p->Num);
         p = p->next;
         i++;
     }
     printf("\n");
 }
 void TraverSeList(HNode h, int M)              //MΪ�����нڵ�����
 {
     int i = 0,t=1;
     PNode p = h;
     printf("ʣ���˵ı��Ϊ��\n");
     while (i<M)
     {
         printf("��%d���ˣ�%d\n",t, p->Num);
         p = p->next;                           //ָ��������һ�����
         i++;
         t++;
     }
     printf("\n");
 }
 /**************���ֺ���****************/

 int JoseDelete(HNode h, int M, int k)
 {    int i;
     PNode p=h,q;                               //����һ��ָ�����ָ�룬������������
     while(M!=15)
     {
         for(i=1;(i+1)%k!=0;i++)                //�����i+1����k�ı������ͽ�ָ��pָ��ǰһ�����
         {
             p=p->next;
         }
         q=p->next;                             //��ָ��qָ�򼴽���ɾ���Ľ��
         p->next=q->next;                       //��������ɾ������ǰһ���ָ�򼴽���ɾ������һ���
         printf("���ֵ���Ϊ��%d��\n",q->Num);   //�����ɾ����ֵ
         free(q);
         if(i==M)
		 {
         	i=1;
		 }

         p=p->next;
         M--;

     }
     //printf("***************��ʤ��Ϊ��%d��***************",p->Num);
     return 1;
 }


 /***************************************/
 int main()
 {
     int i;//������
     int N;//���������
     int k;//��������
     printf("���������������");
     scanf("%d",&N);
     printf("������������룺");
     scanf("%d",&k);

 /**************�õ�ͷ���****************/
     HNode h = ((HNode)malloc(sizeof(JoseNode)));

 /***************��ʼ��������************/
     JoseInit(h);

 /******����Ų��뵽ѭ����������******/
     for (i = 1; i <=N; i++)
     {
         JoseInsert(h, i, i);
     }
 /**************����������***************/
     TraverseList(h,N);

 /***************���ֺ���************/

     JoseDelete(h, N, k);
    TraverSeList(h,15);


     printf("\n");
     printf("\n");
     return 0;
 }


