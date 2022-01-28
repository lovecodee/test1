#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef  struct _Student//ѧ��������Ϣ
{
    char ID[15];//ѧ��
	char name[10];//����
    float math;//��ѧ�ɼ�
    float chinese;//���ĳɼ�
	float english;//Ӣ��ɼ�
	float average;//ƽ���ɼ�
}Student;//����
typedef struct StackNode{
    Student data;
    struct StackNode*next;
}StackNode,*LinkStack;
StackNode*S=NULL;
void Inputinformation(LinkStack &S);//����ѧ����Ϣ
float Average(StackNode* pnewstudent);//��ѧ���ɼ���ƽ����
void Judge(LinkStack &S);             //�ж�ջ�Ƿ�Ϊ��
void Clear(LinkStack &S);             //���ջ
void OutputInformation(LinkStack &S);//���ջ��ȫ��Ԫ��
void Output(LinkStack &S);           //���ջ��Ԫ��
void Number(LinkStack &S);//ͳ��ջ��Ԫ������
void Welcome()//������ʾ��Ϣ
{
	printf("****************************************************************\n");
	printf("*********            ջ����ʽ�Ļ�������             ************\n");
	printf("****************************************************************\n");
	printf("*                    ��ѡ�����б�                            *\n");
	printf("*                      1.������Ϣ����ջ��                      *\n");
	printf("*                      2.�ж�ջ�Ƿ�Ϊ��                        *\n");
	printf("*                      3.ջ�����                              *\n");
	printf("*                      4.���ѧ����Ϣ                          *\n");
	printf("*                      5.���ȫ��ѧ����Ϣ                      *\n");
	printf("*                      6.ͳ��ѧ������                          *\n");
	printf("*                      7.����ѡ��˵�                          *\n");
	printf("*                      0.�˳�ϵͳ                              *\n");
	printf("****************************************************************\n");
}
int main()
{
int choice;
Welcome();
while(1){
             printf("�����������ţ�");
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
                default: printf("��������,����������:\n");break;
               }
        }
return 0;
}
float Average(StackNode* pnewstudent)//��ƽ����
{
return((pnewstudent->data.math+pnewstudent->data.chinese+pnewstudent->data.english)/3.0);
}

void Inputinformation(LinkStack &S)//����Ԫ��
{

StackNode*p=new StackNode;
if (S == NULL)
    S = p;
else
{
    p->next = S;
    S= p;
}
	printf("������ѧ��ѧ�ţ�\n");
	scanf("%s",p->data.ID);
	printf("������ѧ��������\n");
	scanf("%s",p->data.name);
	printf("��������ѧ�ɼ���\n");
	scanf("%f",&p->data.math);
	printf("���������ĳɼ���\n");
	scanf("%f",&p->data.chinese);
	printf("������Ӣ��ɼ���\n");
	scanf("%f",&p->data.english);
    p->data.average=Average(p);
	printf("¼��ѧ����Ϣ�ɹ���\n");
	system("pause");//��ͣ
	//system("cls");//����
}
void Judge(LinkStack &S){
if(S==NULL){
    printf("ջ�ѿգ�\n");
}
else{
    printf("ջδ�գ�\n");
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
    printf("ջ�Ѿ���գ�\n");
}
}
void OutputInformation(LinkStack &S){
StackNode *p;
printf("*************************************************************\n");
	printf("*                     ��ӭʹ��ѧ���ɼ�����ϵͳ              *\n");
	printf("*************************************************************\n");
	printf("*     ѧ��\t����\t��ѧ�ɼ�\t���ĳɼ�\tӢ��ɼ�\t ƽ���ɼ�     *");
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
	printf("*                     ��ӭʹ��ѧ���ɼ�����ϵͳ              *\n");
	printf("*************************************************************\n");
	printf("*     ѧ��\t����\t��ѧ�ɼ�\t���ĳɼ�\tӢ��ɼ�\t ƽ���ɼ�     *");
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
    printf("ջ�ѿգ��Ѿ���Ԫ�أ�\n");
}
}
void Number(LinkStack &S){
int i=0;
while(S!=NULL){
    ++i;
    S=S->next;
}
printf("ѧ��������Ϊ:");
printf("%d\n",i);
}




















