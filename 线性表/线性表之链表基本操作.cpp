/*���Ա�֮��ʽ�洢�ṹ��������  */

#include <stdio.h>
#include <stdlib.h>
typedef struct LNode{
    int data;                //������
    struct LNode *next;      //ָ����
}LNode,*LinkList;
//��������
void Menu();                                   //�����˵�
int* SetArray(int *S,int total);               //��ʼ������
LNode* InitList(LNode *L);                      //��ʼ��������
void CreateList(LNode *L,int *S,int total);    //����������
int LengthList(LNode *L);                      //���Ա�ĳ���
void DispList(LNode *L);                       //����������
void AddList(LNode *L,int key);                //��ӹؼ���
void DeleteList(LNode *L);                     //ɾ���ؼ���
void SearchList(LNode *L);                     //���ҹؼ���
void ModifyList(LNode *L);                     //�޸Ĺؼ���
void SortedList(LNode *L);                     //�ؼ�������
int main()
{   int *S;
    int choice;
    int total;
    int key;
    printf("*******���ݵĳ�ʼ��*******\n");
    printf("������Ԫ���ܸ�����\n");
    scanf("%d",&total);
    S = SetArray(S,total);
    LinkList L;
    Menu();
while(1){
	printf("��������Ĳ���ѡ��\n");
	scanf("%d",&choice);
	switch(choice){
        case 1:{L=InitList(L);
	            CreateList(L,S,total);}break;
        case 2:{printf("������Ҫ��ӵĹؼ��֣�\n");
                scanf("%d",&key);
                AddList(L,key);}break;
        case 3:{DeleteList(L);}break;
        case 4:{SearchList(L);}break;
        case 5:{ModifyList(L);}break;
        case 6:{SortedList(L);}break;
        case 7:{printf("�������Ϊ��\n");
                DispList(L); } break;
        case 8:{Menu();}       break;
        default:printf("��ӭʹ�ã�");break;
	}
 }
}

void Menu(){
printf("\t******************************************************\n");
printf("\t**             ���Ա�֮��ʽ�洢��������             **\n");
printf("\t**                    1.��ʼ��                      **\n");
printf("\t**                    2.��ӹؼ���                  **\n");
printf("\t**                    3.ɾ���ؼ���                  **\n");
printf("\t**                    4.���ҹؼ���                  **\n");
printf("\t**                    5.�޸Ĺؼ���                  **\n");
printf("\t**                    6.�ؼ�������                  **\n");
printf("\t**                    7.�����ؼ���                  **\n");
printf("\t**                    8.��ʾ���˵�                    **\n");
printf("\t******************************************************\n");
}

//��ʼ��������
LNode* InitList(LNode *L)
{
	L = (LNode *)malloc(sizeof(LNode));
	L->next = NULL;
	printf("�������ѳ�ʼ��!\n");
	return L;
}
void CreateList(LNode *L,int *S,int total)//����������
{
	LNode* p=L;
    int i;
    LNode *s;//����һ���½��
    //����㸳ֵ�ؼ��ּ���Ϣ
    for(i=0;i<total;i++)
	{
        s = (LNode *)malloc(sizeof(LNode));//�����½��
        s->data=S[i];
		//���½�����ν��뵥����
		s->next = NULL;
		p->next = s;
		p = p->next;
	}
	printf("���������ɹ�!\n");
}

//����������
void DispList(LNode *L)
{
	LNode * q = L->next;
	printf("�ؼ�����ϢΪ��\n");
	while(q!=NULL)
	{
		printf("%d ", q->data);//�ؼ�����Ϣ
        q=q->next;
	}
	printf("\n\n");
}
int* SetArray(int *S,int total)
{
    int i;
    S = (int*)malloc(sizeof(int)*total); //��̬�����ڴ�ռ�
    printf("������Ԫ�أ�\n");
    for( i=0;i<total;i++)
    {
        scanf("%d",(S+i));
    }
    if(i==total){
        printf("���ݴ洢�ɹ���\n");
    }
    return S;
}

//��ӹؼ���
void AddList(LNode *L,int key)
{
    LNode *s = (LNode *)malloc(sizeof(LNode));//�����½��
    if(s)
    {
        s->data=key;
        s->next=L->next;   //ͷ�巨
        L->next=s;
        printf("��ӹؼ��ֳɹ���\n");
     }
    else
    {
        printf("���ɽ��ʧ�ܣ�\n");
    }
}

//ɾ���ؼ���
void DeleteList(LNode *L){
    int key,flag;
    LNode* p=L->next,*q=L;
    printf("����������Ҫɾ���Ĺؼ��֣�\n");
    scanf("%d",&key);
    while(p)
    {
        if(p->data==key){
            q=q->next->next;
            flag=1;
            printf("ɾ���ɹ���\n");
            break;
        }
        else{
            q=p;
            p=p->next;
        }
    }
    if(flag==0){
        printf("�ؼ��ֲ�����!\n");
    }
}
//���ҹؼ���
void SearchList(LNode *L){
    int key;
    LNode *p=L->next;
    int locate=1;
    printf("������Ҫ���ҵĹؼ��֣�\n");
    scanf("%d",&key);
    while(p)
    {
        if(p->data==key)
        {
            printf("���ҳɹ���\n");
            printf("���ҳɹ�λ��Ϊ��%d\n",locate);
            break;
        }
        else{
            p=p->next;    //ָ����ƣ�λ�ü�һ
            locate++;
        }
    }
}
//�޸Ĺؼ���
void ModifyList(LNode *L)
{
    LNode *p=L->next;
    int key1,key2;
    printf("������Ҫ�޸ĵĹؼ��֣�\n");
    scanf("%d",&key1);
    printf("�������޸ĺ�Ĺؼ��֣�\n");
    scanf("%d",&key2);
    while(p){
        if(p->data==key1)
        {
            p->data=key2;
            printf("�޸ĳɹ���\n");
        }
        else{
            p=p->next;
        }
}
}
//���Ա�ĳ���
int LengthList(LNode *L)
{
    LNode *p=L->next;
    int length=0;
    while(p){
        length++;
        p=p->next;
    }
    return length;
}


//���Ա��еĹؼ�������
void SortedList(LNode *L)
{
    LNode *p,*q;
    int t;
    int length=LengthList(L)-1;
    while(length)
    {
            p=L->next;
            q=p->next;
        while(q!=NULL)
        {
            if(p->data>q->data){
                t=p->data;
                p->data=q->data;   //����ָ����ָ���Ԫ��ֵ
                q->data=t;
                p=q;               //ָ�����
                q=q->next;
            }
            else{
                p=q;
                q=q->next;
            }
        }
        length--;
    }
    if(length==0){
        printf("����ɹ���\n");
    }
}
