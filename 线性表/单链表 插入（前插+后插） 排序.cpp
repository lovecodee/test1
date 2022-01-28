
/*
        Project: single linkeed list (���ݽṹ ������)
        Date:    2021-10-7 09:26:57
        Author:  Frank Wang
        InitList(LinkList &L) ������������L ���ܣ���ʼ�� ʱ�临�Ӷ� O(1)
        ListLength(LinkList L) ������������L ���ܣ���õ������� ʱ�临�Ӷ�O(n)
        ListInsert(LinkList &L,int i,ElemType e)
        ListDelete(LinkList &L,int i) ������������L��λ��i ���ܣ�ɾ��λ��iԪ�� ʱ�临�Ӷ�O(n)[�����˲���]
                                      ����֪pָ��ָ���ɾ�� �����O(1),��Ϊ�������̽�㽻��������Ȼ��ɾ����̽�㡣
                                      ���O(n),����ͷ����p֮ǰ�Ľ��,Ȼ��ɾ��p��ָ���
        LocateElem(LinkList L,ElemType e) ������������L��Ԫ��e ���ܣ����ҵ�һ������e��Ԫ�أ�����ָ�� ʱ�临�Ӷ�O(n)
    */
    #include<cstdio>
    #include<cstdlib>
    #include<cstring>
    #include<cmath>
    #include<iostream>
    using namespace std;
    #define Status int
    #define ElemType int
    //�����������ݽṹ
    typedef struct LNode
    {
        ElemType data;//������
        struct LNode *next;//ָ����
    }LNode,*LinkList;
    //**************************������������***************************//
    //��ʼ������
    Status InitList(LinkList &L)
    {
     L = new LNode;//����ͷ��� ����ɾ���Ȳ����Ͳ��طֵ�һ������������
     L->next = NULL;
     return 1;
    }
    void In_sert(LNode*p,LinkList &L,ElemType e);
    void Hin_sert(LNode*p,LinkList &L,ElemType e);
    //��ȡ�������� ͷ��������ݣ�����
    int ListLength(LinkList L)
    {
        LinkList p=L;int sum=0;
        while(p)
        {
         sum++;
         p=p->next;
        }
        return sum-1;//ȥ��ͷ���
    }
    //���ֲ��뷨��������
    bool ListInsert(LinkList &L,int i,ElemType e)
    {
        LNode* s;LinkList p=L;int j=0;
        while(p&&(j<i-1))//jָ��i-1λ�û���p�Ѿ������ʱ����
        {
         p=p->next;
         ++j;
        }
        if(!p||j>i-1)//i<1����i>ListLength(L)+1ʱ,����λ����Ч ������ListLength,���Ч��
        {
            printf("����λ�ô���); 
            return false;
        }
        else
        {
           In_sert(p,L,e);
        }
    }
    bool List_Insert(LinkList &L,int i,ElemType e)
    {
        LNode* s;LinkList p=L;int j=0;
        while(p&&(j<i))//jָ��i-1λ�û���p�Ѿ������ʱ����
        {
         p=p->next;
         ++j;
        }
        if(!p||j>i)//i<1����i>ListLength(L)+1ʱ,����λ����Ч ������ListLength,���Ч��
        {   printf("����λ�ô���);
            return false;
        }
        else
        {
           Hin_sert(p,L,e);
        }
    }
    //ɾ������ ɾ��λ��i�Ľ�� ��ɾ��i-1֮��Ľ��
    bool ListDelete(LinkList &L,int i)
    {
         LNode* s;LinkList p=L;int j=0;
        LinkList q;
        while(p&&(j<i-1))//jָ��i-1λ��
        {
         p=p->next;
         ++j;
        }
        if(!(p->next)||j>i-1)//i<1����i>ListLength(L)ʱ,ɾ��λ����Ч
        {
            printf("ɾ��λ����Ч������\n");
            return false;
        }
        q=p->next;
        p->next=q->next;
        free(q);//�ͷſռ�
        return true;
    }
    //���Һ��� ��ֵ���� ���ҵ�һ������e�Ľ�� �ɹ����ظý��ָ�룬���򷵻�NULL
    LNode *LocateElem(LinkList L,ElemType e)
    {
        LNode *p=L;
        while(p&&(p->data!=e))
        {
            p=p->next;
        }
        return p;
    }
    //**************************����ʵ�ֺ���**************************//
    //�����������
    void PrintList(LinkList L)
    {
        LinkList p=L->next;//����ͷ���
        if(ListLength(L))
        {
            printf("��ǰ����������Ԫ��:");
            while(p)
            {
                printf("%d ",p->data);
                p=p->next;
            }
            printf("\n");
        }
        else
        {
            printf("��ǰ�������ѿգ�\n");
        }
    }
    //���빦�ܺ��� ����ListInsert����
    void Insert(LinkList &L)
    {
      int place;ElemType e;bool flag;
      printf("������Ҫ�����λ��(��1��ʼ)��Ԫ��:\n");
      scanf("%d%d",&place,&e);
      flag=ListInsert(L,place,e);
      if(flag)
      {
        printf("����ɹ�������\n");
        PrintList(L);
      }
    }
    void Qinsert(LinkList &L)
    {
      int place;ElemType e;bool flag;
      printf("������Ҫ�����λ��(��1��ʼ)��Ԫ��:\n");
      scanf("%d%d",&place,&e);
      flag=List_Insert(L,place,e);
      if(flag)
      {
        printf("����ɹ�������\n");
        PrintList(L);
      }
    }
    //ɾ�����ܺ��� ����ListDeleteɾ��
    void Delete(LinkList L)
    {
      int place;bool flag;
      printf("������Ҫɾ����λ��(��1��ʼ):\n");
      scanf("%d",&place);
      flag=ListDelete(L,place);
      if(flag)
      {
        printf("ɾ���ɹ�������\n");
        PrintList(L);
      }
    }
    //���ҹ��ܺ��� ����LocateElem����
    void Search(LinkList L)
    {
      ElemType e;LNode *q;
      printf("������Ҫ���ҵ�ֵ:\n");
      scanf("%d",&e);
      q=LocateElem(L,e);
      if(q)
      {
        printf("�ҵ���Ԫ�أ�\n");
      }
      else
        printf("δ�ҵ���Ԫ�أ�\n");
    }
    //�˵�
    void menu()
    {
       printf("********1.���루ǰ��    2.ɾ��*********\n");
       printf("********3.����    4.���*********\n");
       printf("********5.�˳�     6.���루��  *********\n");
       printf("********7.����         ***************");
    }

	void Hin_sert(LNode*p,LinkList &L,ElemType e){
	   LNode*s;
		s=new LNode;
        s->data=e;
        s->next=p->next;
        p->next=s;
        printf("����ɹ�");
	}
	void In_sert(LNode*p,LinkList &L,ElemType e){
	   LNode*s;
		s=new LNode;
        s->data=e;
        s->next=p->next;
        p->next=s;
        printf("����ɹ�");
	}
void Listsorted(LinkList L);
    //������
    int main()
    {
     LinkList L;int choice;
     InitList(L);
     while(1)
     {
      menu();
      printf("������˵���ţ�\n");
      scanf("%d",&choice);
      if(choice==5) break;
      switch(choice)
      {
      case 1:Insert(L);break;
      case 2:Delete(L);break;
      case 3:Search(L);break;
      case 4:PrintList(L);break;
      case 6:Qinsert(L);break;
      case 7:Listsorted(L);break;
      default:printf("������󣡣���\n");
      }
     }
     return 0;
    }
    void Listsorted(LinkList L)
   {
   	LNode*p,*q;
   	ElemType e=NULL;
   	if(L->next==NULL)
   	{
   		printf("������Ϊ�������޷���������");
	}
   	else
	{
   	for(p=L->next;p!=NULL;p=p->next)
	   {

	   for(q=p->next;q!=NULL;q=q->next)
	   {
	   	if(p->data > q->data)
		   {
		   	e=p->data;
		   	p->data=q->data;
		   	q->data=e;
	       }
    	}
      }
      printf("����ɹ�\n");
      PrintList(L);
	}
   }
