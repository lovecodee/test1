#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef  struct _Student//学生基本信息
{
    char ID[15];//学号
	char name[10];//姓名
    float math;//数学成绩
    float chinese;//语文成绩
	float english;//英语成绩
	float average;//平均成绩
}Student;//别名
typedef struct StackNode{
    Student data;
    struct StackNode*next;
}StackNode,*LinkStack;
StackNode*S=NULL;
void Inputinformation(LinkStack &S);//输入学生信息
float Average(StackNode* pnewstudent);//求学生成绩的平均数
void Judge(LinkStack &S);             //判断栈是否为空
void Clear(LinkStack &S);             //清空栈
void OutputInformation(LinkStack &S);//输出栈中全部元素
void Output(LinkStack &S);           //输出栈顶元素
void Number(LinkStack &S);//统计栈中元素总数
void Welcome()//操作提示信息
{
	printf("****************************************************************\n");
	printf("*********            栈的链式的基本操作             ************\n");
	printf("****************************************************************\n");
	printf("*                    请选择功能列表                            *\n");
	printf("*                      1.输入信息（入栈）                      *\n");
	printf("*                      2.判断栈是否为空                        *\n");
	printf("*                      3.栈的清空                              *\n");
	printf("*                      4.输出学生信息                          *\n");
	printf("*                      5.输出全部学生信息                      *\n");
	printf("*                      6.统计学生人数                          *\n");
	printf("*                      7.返回选择菜单                          *\n");
	printf("*                      0.退出系统                              *\n");
	printf("****************************************************************\n");
}
int main()
{
int choice;
Welcome();
while(1){
             printf("请输入操作序号：");
             scanf("%d",&choice);
             switch(choice)
            {
                case 1:  Inputinformation(S); break;
                case 2:  Judge(S);break;
                case 3:  Clear(S); break;
                case 4: Output(S);break;
                case 5:OutputInformation(S);break;
                case 6:Number(S);break;
                case 7:Welcome();break;
                case 0: exit(0);break;
                default: printf("输入有误,请重新输入:\n");break;
               }
        }
return 0;
}
float Average(StackNode* pnewstudent)//求平均数
{
return((pnewstudent->data.math+pnewstudent->data.chinese+pnewstudent->data.english)/3.0);
}

void Inputinformation(LinkStack &S)//输入元素
{

StackNode*p=new StackNode;
if (S == NULL)
    S = p;
else
{
    p->next = S;
    S= p;
}
	printf("请输入学生学号：\n");
	scanf("%s",p->data.ID);
	printf("请输入学生姓名：\n");
	scanf("%s",p->data.name);
	printf("请输入数学成绩：\n");
	scanf("%f",&p->data.math);
	printf("请输入语文成绩：\n");
	scanf("%f",&p->data.chinese);
	printf("请输入英语成绩：\n");
	scanf("%f",&p->data.english);
    p->data.average=Average(p);
	printf("录入学生信息成功：\n");
	system("pause");//暂停
	//system("cls");//清屏
}
void Judge(LinkStack &S){
if(S==NULL){
    printf("栈已空！\n");
}
else{
    printf("栈未空！\n");
}
}
void Clear(LinkStack &S)
{
while(S!=NULL)
{StackNode *p;
p=S;
S=S->next;
delete p;
}
if(S==NULL){
    printf("栈已经清空！\n");
}
}
void OutputInformation(LinkStack &S){
StackNode *p;
printf("*************************************************************\n");
	printf("*                     欢迎使用学生成绩管理系统              *\n");
	printf("*************************************************************\n");
	printf("*     学号\t姓名\t数学成绩\t语文成绩\t英语成绩\t 平均成绩     *");
	printf("\n");
while(S!=NULL){
   p=S;
   printf("%s\t%s\t  %.2f\t        %.2f\t        %.2f\t         %.2f\n", p->data.ID,
			p->data.name,
			p->data.math,
			p->data.chinese,
			p->data.english,
			p->data.average
			);
        printf("**********************************************\n");
   S=S->next;
}
}
void Output(LinkStack &S)

{
StackNode *p;
if(S!=NULL){
    printf("*************************************************************\n");
	printf("*                     欢迎使用学生成绩管理系统              *\n");
	printf("*************************************************************\n");
	printf("*     学号\t姓名\t数学成绩\t语文成绩\t英语成绩\t 平均成绩     *");
	printf("\n");
   p=S;
   printf("%s\t%s\t  %.2f\t        %.2f\t        %.2f\t         %.2f\n", p->data.ID,
			p->data.name,
			p->data.math,
			p->data.chinese,
			p->data.english,
			p->data.average
			);
        printf("**********************************************\n");
   S=S->next;

}
else{
    printf("栈已空，已经无元素！\n");
}
}
void Number(LinkStack &S){
int i=0;
while(S!=NULL){
    ++i;
    S=S->next;
}
printf("学生总人数为:");
printf("%d\n",i);
}




















