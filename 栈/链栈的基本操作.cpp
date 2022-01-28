#include<stdio.h>
#include<iostream>
using namespace std;
typedef struct StackNode{
    int data;                 //数据域
    struct StackNode *next;   //指针域
}StackNode,*LinkStack;
//函数声明
void InitStack(StackNode *S);     //链栈的初始化
void Push(StackNode *S,int key);  //链栈的入栈
int  Pop(StackNode *S,int key);   //链栈的出栈
void Gettop(StackNode *S);        //取栈顶元素

int main(){
int i,total,key,key1;
StackNode *S;
InitStack(S);
printf("请输入元素总个数：\n");
scanf("%d",&total);
printf("请输入元素：\n");
for( i=0;i<total;i++){
    scanf("%d",&key);
    Push(S,key);
}
if(i==total){
    printf("入栈成功！\n");
}
printf("%d",(S->data));
   key1 = Pop(S,key1);
printf("%d\n",key1);
return 0;
}

//链栈的初始化
void InitStack(StackNode *S){
//构造一个空栈
    S=NULL;
    printf("初始化成功！\n");
}
//链栈的入栈
void Push(StackNode *S,int key){
//在栈顶插入元素
    StackNode *p  = new StackNode; //动态分配结点空间
    if(!p){
        printf("新结点生成失败！");
    }
    else{
        p->data= key;
        p->next=S;
        S=p;
}
}
//链栈的出栈
int Pop(StackNode *S,int key){
//删除S中的栈顶元素，用key返回其值
    StackNode *p;
    if(S==NULL)
        printf("栈已空！\n");
    else{
        key=S->data;              //将栈顶元素赋值给key
        p=S;                      //用p临时保存栈顶空间，已备释放
        S=S->next;                //修改栈顶指针
        delete p;                 //释放原栈顶元素的空间
       return key;
    }
}

//取栈顶元素
void Gettop(StackNode *S){
//返回S的栈顶指针，不修改栈顶指针
    if(S!=NULL){
        printf("栈顶元素为：%d",S->data);
    }
}





