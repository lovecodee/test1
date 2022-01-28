#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define ENDFLAG  20
typedef struct BSTree{
int data;
struct BSTree *lchild,*rchild;
}BSTree;
//��������
void InsertBST(BSTree *T,int key);   //������
void CreateBST(BSTree *T);           //�����������ĳ�ʼ��
void  DeleteBST(BSTree *T,int key);  //ɾ�����key
BSTree SearchBST(BSTree *T,int key);   //�����ؼ��Ƿ��������������

int main(){
BSTree *T;
BSTree D;
printf("�������ֵΪ20����������빤��! \n");
CreateBST(T);
int key;
printf("������ؼ��֣�\n");
scanf("%d",&key);
D=SearchBST(T,key);
if(!D.data){
    printf("���ҳɹ���");
}
else{
    printf("����ʧ�ܣ�");
}
    return 0;
}
//�����������Ĵ���
void CreateBST(BSTree *T){
//���ζ���һ���ؼ���Ϊkey�Ľ�㣬���˽ڵ�������������T��
  T=NULL;            //��������T��ʼ��Ϊ����
  int data;
  cin>>data;
while(data!=ENDFLAG)//ENDFLAGΪ�Զ��峣������Ϊ���������־
{
    InsertBST(T,data);  //���˽����������������T��
    cin>>data;
}
}


//ɾ�����
void  DeleteBST(BSTree *T,int key){
//�Ӷ���������T��ɾ���ؼ���Ϊkey�Ľ��
BSTree *p;
   p=T;
BSTree *f;
f=NULL;//��ʼ��
while(p){
    if(p->data==key)break;
    f=p;
    if(p->data>key){
        p=p->lchild;         //��*p���������м�������
    }
    else{
        p=p->rchild;        //��*p���������м�������
    }
}
/*---�����������ʵ��p��ָ�������ڲ��Ĵ���:*p�������������ա�������������������---*/
BSTree *q=p;
BSTree *s;
if((p->lchild)&&(p->rchild))    //��ɾ���*p��������������
{
    s=q->lchild;
    while(s->rchild)                //��*p���������м���������ǰ����㣬�������½��
    {
        q=s;
        s=s->rchild;                   //���ҵ���ͷ
    }
    p->data=s->data;                 //sָ��ɾ�����ġ�ǰ����
    if(q!=p)q->rchild=s->lchild;     //�ؽ�*p��������
    else q->lchild=s->lchild;        //�ؽ�*p��������
    delete s;
    return ;
}
else if(!p->rchild)                  //��ɾ���*p����������ֻ����������������
{
    p=p->lchild;
}
else if(!p->lchild)                  //��ɾ���*p����������ֻ���ؽ���������
{
    p=p->rchild;
}

if(!f) T=p;                            //��ɾ���Ϊ�����
else if(q==f->lchild) f->lchild=p;     //�ҽӵ�*f��������λ��
else f->rchild=p;                      //�ҽӵ�*f��������λ��
delete q;
printf("ɾ���ɹ���");
}

//����
BSTree SearchBST(BSTree *T,int key){
//�ڸ�ָ��T��ָ�����������еݹ�ز���ĳ�ؼ��ֵ�key������Ԫ��
//������ҳɹ����򷵻�ָ�������Ԫ�ؽ���ָ�룬���򷵻ؿ�ָ��
if((!T)||key==T->data)  return T;//���ҽ���
else if(key<T->data) return SearchBST(T->lchild,key);//���������м�������
else return SearchBST(T->lchild,key);
}

//�����������Ĳ��루�ݹ飩
void InsertBST(BSTree *T,int key)
{//������������T�в����ڹؼ���keyd������Ԫ��ʱ��������Ԫ��
if(!T){                           //�ҵ�����λ�ã��ݹ����
   BSTree *S=new BSTree;          //�����½��*S
   S.data = key;                   //���½��*S����������Ϊkey
   S->lchild=S->rchild=NULL;      //�½��*S��ΪҶ�ӽ��
   T=S;                           //���½��*S���ӵ����ҵ��Ĳ���λ��
}
else if(key<T.data){
    InsertBST(T->lchild,key);      //��*S����������
}
else if(key>T.data){
    InsertBST(T->rchild,key);      //��*S����������
}



}
