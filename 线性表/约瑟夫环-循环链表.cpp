/*
有n个人围城一圈，按顺序编号，从第一个人开始报数，从1报到m，凡报到m的人退出圈子，
然后接着报数，问最后留下来的是原来的第几号的那位？

*/

//循环链表实现
//构造一个循环链表，链表节点的数据域存放人的编号，遍历整个链表，每次报到m的人退出，并释放该节点，直到链表只剩一个节点。
#include <stdio.h>
#include <malloc.h>

 /*构建结构体*/
 typedef struct Node{
     int Num;
     struct Node *next;
 }JoseNode, *PNode, *HNode;

 /**********初始化循环单链表*********/
 int JoseInit(HNode h)
 {
     if (!h)
     {
         printf("初始化链表错误！\n");
         return 0;
     }
     (h)->next = (h);//循环单链表
     return 1;

 }

 /*************单链表插入操作**********/
 int JoseInsert(JoseNode *h, int pos, int x)
 {
     PNode p=h,q;
     int i=1;
     if (pos == 1)/*尾插法*/
     {
         p->Num = x;
         p->next = p;
         return 1;
     }
     while(i<pos-1)//让p指向插入位置的前一个结点
     {
         p=p->next;
         i++;
     }
     q=(PNode)malloc(sizeof(JoseNode));//定义一个新的节点q
     q->Num=x;                          //初始化数据域
     q->next=p->next;                   //将q指向p所指结点的下一结点
     p->next=q;                         //将p指向q
     return 1;                          //格外要注意，必须要保证链不能断
 }

 /*遍历*/
 void TraverseList(HNode h, int M)              //h表示单链表，M指的是链表中的结点个数
 {
     int i = 0;
     PNode p = h;                               //定义一个指向结点的指针，来在结点中移动
     printf("参与的人的编号为：\n");
     while (i<M)
     {
         printf("%d\t", p->Num);
         p = p->next;
         i++;
     }
     printf("\n");
 }
 void TraverSeList(HNode h, int M)              //M为链表中节点总数
 {
     int i = 0,t=1;
     PNode p = h;
     printf("剩余人的编号为：\n");
     while (i<M)
     {
         printf("第%d个人：%d\n",t, p->Num);
         p = p->next;                           //指针移向下一个结点
         i++;
         t++;
     }
     printf("\n");
 }
 /**************出局函数****************/

 int JoseDelete(HNode h, int M, int k)
 {    int i;
     PNode p=h,q;                               //定义一个指向结点的指针，用来遍历链表
     while(M!=15)
     {
         for(i=1;(i+1)%k!=0;i++)                //如果（i+1）是k的倍数，就将指针p指向前一个结点
         {
             p=p->next;
         }
         q=p->next;                             //用指针q指向即将被删除的结点
         p->next=q->next;                       //将即将被删除结点的前一结点指向即将被删除的下一结点
         printf("出局的人为：%d号\n",q->Num);   //输出所删结点的值
         free(q);
         if(i==M)
		 {
         	i=1;
		 }

         p=p->next;
         M--;

     }
     //printf("***************获胜者为：%d号***************",p->Num);
     return 1;
 }


 /***************************************/
 int main()
 {
     int i;//计数器
     int N;//参与的人数
     int k;//报数密码
     printf("请输入参与人数：");
     scanf("%d",&N);
     printf("请输入出局密码：");
     scanf("%d",&k);

 /**************得到头结点****************/
     HNode h = ((HNode)malloc(sizeof(JoseNode)));

 /***************初始化单链表************/
     JoseInit(h);

 /******将编号插入到循环单链表中******/
     for (i = 1; i <=N; i++)
     {
         JoseInsert(h, i, i);
     }
 /**************遍历单链表***************/
     TraverseList(h,N);

 /***************出局函数************/

     JoseDelete(h, N, k);
    TraverSeList(h,15);


     printf("\n");
     printf("\n");
     return 0;
 }


