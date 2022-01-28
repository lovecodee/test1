#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define ENDFLAG  20
typedef struct BSTree{
int data;
struct BSTree *lchild,*rchild;
}BSTree;
//函数声明
void InsertBST(BSTree *T,int key);   //插入结点
void CreateBST(BSTree *T);           //二叉排序树的初始化
void  DeleteBST(BSTree *T,int key);  //删除结点key
BSTree SearchBST(BSTree *T,int key);   //搜索关键是否在排序二叉树中

int main(){
BSTree *T;
BSTree D;
printf("如果输入值为20，则结束输入工作! \n");
CreateBST(T);
int key;
printf("请输入关键字：\n");
scanf("%d",&key);
D=SearchBST(T,key);
if(!D.data){
    printf("查找成功！");
}
else{
    printf("查找失败！");
}
    return 0;
}
//二叉排序树的创建
void CreateBST(BSTree *T){
//依次读入一个关键字为key的结点，将此节点插入二叉排序树T中
  T=NULL;            //将二叉树T初始化为空树
  int data;
  cin>>data;
while(data!=ENDFLAG)//ENDFLAG为自定义常量，作为输入结束标志
{
    InsertBST(T,data);  //将此结点插入二叉树排序树T中
    cin>>data;
}
}


//删除结点
void  DeleteBST(BSTree *T,int key){
//从二叉排序树T中删除关键字为key的结点
BSTree *p;
   p=T;
BSTree *f;
f=NULL;//初始化
while(p){
    if(p->data==key)break;
    f=p;
    if(p->data>key){
        p=p->lchild;         //在*p的左子树中继续查找
    }
    else{
        p=p->rchild;        //在*p的右子树中继续查找
    }
}
/*---考虑三种情况实现p所指子树的内部的处理:*p左右子树均不空、无右子树、无左子树---*/
BSTree *q=p;
BSTree *s;
if((p->lchild)&&(p->rchild))    //被删结点*p左右子树均不空
{
    s=q->lchild;
    while(s->rchild)                //在*p的左子树中继续查找其前驱结点，即最右下结点
    {
        q=s;
        s=s->rchild;                   //向右到尽头
    }
    p->data=s->data;                 //s指向被删除结点的“前驱”
    if(q!=p)q->rchild=s->lchild;     //重接*p的右子树
    else q->lchild=s->lchild;        //重接*p的左子树
    delete s;
    return ;
}
else if(!p->rchild)                  //被删结点*p无右子树，只需重连接起左子树
{
    p=p->lchild;
}
else if(!p->lchild)                  //被删结点*p无左子树，只需重接起右子树
{
    p=p->rchild;
}

if(!f) T=p;                            //被删结点为根结点
else if(q==f->lchild) f->lchild=p;     //挂接到*f的左子树位置
else f->rchild=p;                      //挂接到*f的右子树位置
delete q;
printf("删除成功！");
}

//查找
BSTree SearchBST(BSTree *T,int key){
//在根指针T所指二叉排序树中递归地查找某关键字等key的数据元素
//如果查找成功，则返回指向该数据元素结点的指针，否则返回空指针
if((!T)||key==T->data)  return T;//查找结束
else if(key<T->data) return SearchBST(T->lchild,key);//在左子树中继续查找
else return SearchBST(T->lchild,key);
}

//二叉排序树的插入（递归）
void InsertBST(BSTree *T,int key)
{//当二叉排序树T中不存在关键字keyd的数据元素时，则插入该元素
if(!T){                           //找到插入位置，递归结束
   BSTree *S=new BSTree;          //生成新结点*S
   S.data = key;                   //把新结点*S的数据域置为key
   S->lchild=S->rchild=NULL;      //新结点*S作为叶子结点
   T=S;                           //把新结点*S链接到已找到的插入位置
}
else if(key<T.data){
    InsertBST(T->lchild,key);      //将*S插入左子树
}
else if(key>T.data){
    InsertBST(T->rchild,key);      //将*S插入右子树
}



}
