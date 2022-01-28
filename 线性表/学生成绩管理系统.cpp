/*用链式存储结构来实现简单的成绩管理系统*/

#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct //学生基本信息
{
    char ID[15];//学号
	char name[10];//姓名
    float math;//数学成绩
    float chinese;//语文成绩
	float english;//英语成绩
	float average;//平均成绩
}Student;//别名

//结点
typedef struct _LNode
{
	Student data;                    //数据域
	struct _LNode* next;             //指针域
}LNode;                              //别名
LNode* g_head =NULL;                 //头结点的初始化

//函数声明

int Judge(char user[]);              //判断用户名是否符合
void Welcome();                      //功能菜单
float Average(LNode* pnewstudent);   //求学生成绩的平均值
void Inputinformation();             //输入学生信息
void Outputinformation();            //输出学生信息
void Delete(LNode* L,int n);         //删除线性表某一学生信息
void Search(LNode*L);                //查找学生信息
int Linklist_Length(LNode*g_head);   //求线性表的长度
void  Change(LNode*g_head);          //修改学生信息
int UserPassword();                  //用户初始页面，设置登陆账号和密码

int main()
{ int i,n,choice;
i=UserPassword();
printf("\n");
while(i)
    {Welcome();
	while (1)
	{
	    printf("请输入执行功能序号：\n");
		scanf("%d",&choice);
		switch (choice)
		{
		case 1:   Inputinformation();                 break;
		case 2:   Outputinformation();                break;
		case 3:{  i=Linklist_Length(g_head);
		            printf("%d\n",i);
		                  }                            break;
		case 4:    Search(g_head);                    break;
		case 5:     Change(g_head) ;                  break;
		case 6:{  n=Linklist_Length(g_head);
		                Delete(g_head,n);
                          };                           break;
		case 0:printf("欢迎使用管理系统"); exit(0);   break;
		default:printf("你的输入信息有误，请从新输入");break;
		}
		printf("\n");
	}


}
	return 0;
}
int Judge(char user[])                             //判断用户名是否符合
{
if(strlen(user)!=4)
{
    printf("用户输入有误（用户字母不等于四）");
    return 1;
}
else
{
    printf("用户名设置成功！\n");
    return 0;
}
}
void Welcome()//功能菜单
{
	printf("\t***********************************************\n");
	printf("\t*          欢迎使用学生成绩管理系统           *\n");
	printf("\t***********************************************\n");
	printf("\t*             请选择功能列表                  *\n");
	printf("\t*               1.请输入学生相关信息          *\n");
	printf("\t*               2.打印学生信息                *\n");
	printf("\t*               3.统计所有学生人数            *\n");
	printf("\t*               4.查找学生信息                *\n");
	printf("\t*               5.修改学生信息                *\n");
	printf("\t*               6.删除学生信息                *\n");
	printf("\t*               0.退出系统                    *\n");
	printf("\t***********************************************\n");

}
float Average(LNode* pnewstudent)                       //求平均数
{
return((pnewstudent->data.math+pnewstudent->data.chinese+pnewstudent->data.english)/3.0);
}
void Inputinformation()                                   //输入 数据
{

	//结点的插入
	LNode* pnewstudent = (LNode*)malloc(sizeof(LNode));   //动态分配存储空间
	pnewstudent->next = NULL;
    //头插法：
	if (g_head== NULL)
		g_head = pnewstudent;
	else
	{
		pnewstudent->next = g_head;//g_head存储的为下一节点的位置，在该位置插入节点
		g_head= pnewstudent;//将新节点的地址存储在首元结点的指针域
	}
	printf("请输入学生学号：\n");
	scanf("%s",pnewstudent->data.ID);
	if(strlen(pnewstudent->data.ID)>15){
        printf("你输入的学生号位数不符：");
	}
	printf("请输入学生姓名：\n");
	scanf("%s",pnewstudent->data.name);
	printf("请输入数学成绩：\n");
	scanf("%f",&pnewstudent->data.math);
	printf("请输入语文成绩：\n");
	scanf("%f",&pnewstudent->data.chinese);
	printf("请输入英语成绩：\n");
	scanf("%f",&pnewstudent->data.english);
    pnewstudent->data.average=Average(pnewstudent);
	printf("录入学生信息成功：\n");
	system("pause");//暂停
	system("cls");//清屏
}
void Outputinformation()
{
    printf("**************************************************************************************************************************\n");
	printf("*                     欢迎使用学生成绩管理系统              *\n");
	printf("**************************************************************************************************************************\n");
	printf("*     学号\t姓名\t数学成绩\t语文成绩\t英语成绩\t平均成绩     *");
	printf("\n");
	LNode* p = g_head;
	while (p != NULL)
	{

		printf("%s\t%s\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", p->data.ID,
			p->data.name,
			p->data.math,
			p->data.chinese,
			p->data.english,
			p->data.average
			);
        p = p->next;//必须指向下一个结点，否则会陷入死循环

	}
        printf("**************************************************************************************************************************\n");
}

void Delete(LNode* L,int n)//删除线性表某一结点
{
    char s[10];
    LNode* q;
    LNode* m;
    int i,j;
    printf("请输入要删除的学生姓名");
    scanf("%s\n",s);
    q=L;
   j=n;
    for(i=0;i<j;i++)
        {
        if((strcmp(L->data.name,s))==0)
            {
                i=i+1;
                break;
            }
        else
            ;
        L=L->next;
        q=L;
    }

    if(i>=j)
    printf("不存在该学生信息\n");
    q=L;
    j=0;
    while((L->next)&&(j<i-1))//查找第（i-1）个节点，p指向该节点
   {
        L=L->next;
        ++j;
    }
    m=L->next;
    L->next=L->next;
    free(q);
}


void Search(LNode*L)//查找学生信息
{

printf("请输入将要查找学生姓名：");
char s[15];
scanf("%s",s);
LNode*p,*q;
p=L;
while(p!=NULL){
    if(strcmp(p->data.name,s)==0)
        {
    printf("**************************************************************************************************************************\n");
	printf("*     学号\t姓名\t数学成绩\t语文成绩\t英语成绩\t平均成绩     *");
    printf("%s\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f", p->data.ID,
			p->data.name,
			p->data.math,
			p->data.chinese,
			p->data.english,
			p->data.average
			);
	printf("**************************************************************************************************************************\n");

    break;

    }
    else{
        p=p->next;
    }
}
if(p==NULL)
{
    printf("系统中不存在该同学信息");

}

}
int Linklist_Length(LNode*g_head);
void  Change(LNode*g_head);
int UserPassword()
{
char user[5],user2[5];
int n;
char password[7],password1[7];
printf("请输入用户名（四个英文字母）：\n");
scanf("%s",user);
n=Judge(user);
while(n)
{
    scanf("%s\n",user);
    n=Judge(user);
}
 printf("请输入密码：（字母或数字六位）");
 scanf("%s",password);
if(strlen(password)==6){
    printf("密码初始化成功！");
}
 system("pause");                                   //暂停
 system("cls");                                     //清屏

 printf("登录\n\n");
 printf("请输入用户名");
 scanf("%s",user2);
while(1)
{
    if(!strcmp(user,user2))//字符串比较函数，逐个字符进行比较
    {
        printf("用户名输入正确");
        break;
    }
    else{
    printf("用户名错误，请重新输入");
    scanf("%s",user2);
    }
}
printf("请输入登录密码：\n");
for(int j=0;j<7;j++)
{
    password1[j]=getch();
    if(password1[j]=='\r')
    {
        password1[j]='\0';
    }
        printf("*");
}
while(1)
{
    if(!strcmp(password1,password))
    {
        break;
    }
    else
    {
        printf("密码错误，请重新输入密码");
        for(int j=0;j<7;j++)
        {
            password1[j]=getch();
           if(password1[j]=='\r')
           {
                password1[j]='\0';
           }
                printf("*");
        }
    }

}
    printf("输密码正确！");
    return 1;
 }

int Linklist_Length(LNode*L) //记录单链表长度
{
    LNode* p1;
    int m=1;
    p1=L->next;
while(p1!=NULL)
{
    m++;
    L=L->next;
    p1=L;

}
    return m;
}
void  Change(LNode*g_head)//改变学生信息
{
    printf("请输入要更改的学生姓名：\n");
    char name2[15];
    scanf("%s",name2);
    LNode* p2;
    p2=g_head;
while(p2!=NULL)
   {
      if(strcmp(p2->data.name,name2)==0){
        printf("学生信息存在该系统中：\n");
        printf("请输入更改后的信息：\n");
        printf("请输入学生姓名：\n");
        scanf("%s",p2->data.name);
        printf("请输入数学成绩：\n");
        scanf("%f",&p2->data.math);
        printf("请输入语文成绩：\n");
        scanf("%f",&p2->data.chinese);
        printf("请输入英语成绩：\n");
        scanf("%f",&p2->data.english);
        p2->data.average=Average(p2);
        printf("修改学生信息成功：\n");
         break;
     }
    else{
        p2=p2->next;
     }
    }
}
