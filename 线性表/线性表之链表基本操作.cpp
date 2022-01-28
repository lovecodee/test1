/*线性表之链式存储结构基本操作  */

#include <stdio.h>
#include <stdlib.h>
typedef struct LNode{
    int data;                //数据域
    struct LNode *next;      //指针域
}LNode,*LinkList;
//函数声明
void Menu();                                   //操作菜单
int* SetArray(int *S,int total);               //初始化数组
LNode* InitList(LNode *L);                      //初始化单链表
void CreateList(LNode *L,int *S,int total);    //创建单链表
int LengthList(LNode *L);                      //线性表的长度
void DispList(LNode *L);                       //遍历单链表
void AddList(LNode *L,int key);                //添加关键字
void DeleteList(LNode *L);                     //删除关键字
void SearchList(LNode *L);                     //查找关键字
void ModifyList(LNode *L);                     //修改关键字
void SortedList(LNode *L);                     //关键字排序
int main()
{   int *S;
    int choice;
    int total;
    int key;
    printf("*******数据的初始化*******\n");
    printf("请输入元素总个数：\n");
    scanf("%d",&total);
    S = SetArray(S,total);
    LinkList L;
    Menu();
while(1){
	printf("请输入你的操作选择：\n");
	scanf("%d",&choice);
	switch(choice){
        case 1:{L=InitList(L);
	            CreateList(L,S,total);}break;
        case 2:{printf("请输入要添加的关键字：\n");
                scanf("%d",&key);
                AddList(L,key);}break;
        case 3:{DeleteList(L);}break;
        case 4:{SearchList(L);}break;
        case 5:{ModifyList(L);}break;
        case 6:{SortedList(L);}break;
        case 7:{printf("遍历结果为：\n");
                DispList(L); } break;
        case 8:{Menu();}       break;
        default:printf("欢迎使用！");break;
	}
 }
}

void Menu(){
printf("\t******************************************************\n");
printf("\t**             线性表之链式存储基本操作             **\n");
printf("\t**                    1.初始化                      **\n");
printf("\t**                    2.添加关键字                  **\n");
printf("\t**                    3.删除关键字                  **\n");
printf("\t**                    4.查找关键字                  **\n");
printf("\t**                    5.修改关键字                  **\n");
printf("\t**                    6.关键字排序                  **\n");
printf("\t**                    7.遍历关键字                  **\n");
printf("\t**                    8.显示主菜单                    **\n");
printf("\t******************************************************\n");
}

//初始化单链表
LNode* InitList(LNode *L)
{
	L = (LNode *)malloc(sizeof(LNode));
	L->next = NULL;
	printf("单链表已初始化!\n");
	return L;
}
void CreateList(LNode *L,int *S,int total)//创建单链表
{
	LNode* p=L;
    int i;
    LNode *s;//定义一个新结点
    //给结点赋值关键字及信息
    for(i=0;i<total;i++)
	{
        s = (LNode *)malloc(sizeof(LNode));//生成新结点
        s->data=S[i];
		//将新结点依次接入单链表
		s->next = NULL;
		p->next = s;
		p = p->next;
	}
	printf("单链表创建成功!\n");
}

//遍历单链表
void DispList(LNode *L)
{
	LNode * q = L->next;
	printf("关键字信息为：\n");
	while(q!=NULL)
	{
		printf("%d ", q->data);//关键字信息
        q=q->next;
	}
	printf("\n\n");
}
int* SetArray(int *S,int total)
{
    int i;
    S = (int*)malloc(sizeof(int)*total); //动态分配内存空间
    printf("请输入元素：\n");
    for( i=0;i<total;i++)
    {
        scanf("%d",(S+i));
    }
    if(i==total){
        printf("数据存储成功！\n");
    }
    return S;
}

//添加关键字
void AddList(LNode *L,int key)
{
    LNode *s = (LNode *)malloc(sizeof(LNode));//生成新结点
    if(s)
    {
        s->data=key;
        s->next=L->next;   //头插法
        L->next=s;
        printf("添加关键字成功！\n");
     }
    else
    {
        printf("生成结点失败！\n");
    }
}

//删除关键字
void DeleteList(LNode *L){
    int key,flag;
    LNode* p=L->next,*q=L;
    printf("请输入你想要删除的关键字：\n");
    scanf("%d",&key);
    while(p)
    {
        if(p->data==key){
            q=q->next->next;
            flag=1;
            printf("删除成功！\n");
            break;
        }
        else{
            q=p;
            p=p->next;
        }
    }
    if(flag==0){
        printf("关键字不存在!\n");
    }
}
//查找关键字
void SearchList(LNode *L){
    int key;
    LNode *p=L->next;
    int locate=1;
    printf("请输入要查找的关键字：\n");
    scanf("%d",&key);
    while(p)
    {
        if(p->data==key)
        {
            printf("查找成功！\n");
            printf("查找成功位置为：%d\n",locate);
            break;
        }
        else{
            p=p->next;    //指针后移，位置加一
            locate++;
        }
    }
}
//修改关键字
void ModifyList(LNode *L)
{
    LNode *p=L->next;
    int key1,key2;
    printf("请输入要修改的关键字：\n");
    scanf("%d",&key1);
    printf("请输入修改后的关键字：\n");
    scanf("%d",&key2);
    while(p){
        if(p->data==key1)
        {
            p->data=key2;
            printf("修改成功！\n");
        }
        else{
            p=p->next;
        }
}
}
//线性表的长度
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


//线性表中的关键字排序
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
                p->data=q->data;   //交换指针所指向的元素值
                q->data=t;
                p=q;               //指针后移
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
        printf("排序成功！\n");
    }
}
