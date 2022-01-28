/*����ʽ�洢�ṹ��ʵ�ּ򵥵ĳɼ�����ϵͳ*/

#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct //ѧ��������Ϣ
{
    char ID[15];//ѧ��
	char name[10];//����
    float math;//��ѧ�ɼ�
    float chinese;//���ĳɼ�
	float english;//Ӣ��ɼ�
	float average;//ƽ���ɼ�
}Student;//����

//���
typedef struct _LNode
{
	Student data;                    //������
	struct _LNode* next;             //ָ����
}LNode;                              //����
LNode* g_head =NULL;                 //ͷ���ĳ�ʼ��

//��������

int Judge(char user[]);              //�ж��û����Ƿ����
void Welcome();                      //���ܲ˵�
float Average(LNode* pnewstudent);   //��ѧ���ɼ���ƽ��ֵ
void Inputinformation();             //����ѧ����Ϣ
void Outputinformation();            //���ѧ����Ϣ
void Delete(LNode* L,int n);         //ɾ�����Ա�ĳһѧ����Ϣ
void Search(LNode*L);                //����ѧ����Ϣ
int Linklist_Length(LNode*g_head);   //�����Ա�ĳ���
void  Change(LNode*g_head);          //�޸�ѧ����Ϣ
int UserPassword();                  //�û���ʼҳ�棬���õ�½�˺ź�����

int main()
{ int i,n,choice;
i=UserPassword();
printf("\n");
while(i)
    {Welcome();
	while (1)
	{
	    printf("������ִ�й�����ţ�\n");
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
		case 0:printf("��ӭʹ�ù���ϵͳ"); exit(0);   break;
		default:printf("���������Ϣ�������������");break;
		}
		printf("\n");
	}


}
	return 0;
}
int Judge(char user[])                             //�ж��û����Ƿ����
{
if(strlen(user)!=4)
{
    printf("�û����������û���ĸ�������ģ�");
    return 1;
}
else
{
    printf("�û������óɹ���\n");
    return 0;
}
}
void Welcome()//���ܲ˵�
{
	printf("\t***********************************************\n");
	printf("\t*          ��ӭʹ��ѧ���ɼ�����ϵͳ           *\n");
	printf("\t***********************************************\n");
	printf("\t*             ��ѡ�����б�                  *\n");
	printf("\t*               1.������ѧ�������Ϣ          *\n");
	printf("\t*               2.��ӡѧ����Ϣ                *\n");
	printf("\t*               3.ͳ������ѧ������            *\n");
	printf("\t*               4.����ѧ����Ϣ                *\n");
	printf("\t*               5.�޸�ѧ����Ϣ                *\n");
	printf("\t*               6.ɾ��ѧ����Ϣ                *\n");
	printf("\t*               0.�˳�ϵͳ                    *\n");
	printf("\t***********************************************\n");

}
float Average(LNode* pnewstudent)                       //��ƽ����
{
return((pnewstudent->data.math+pnewstudent->data.chinese+pnewstudent->data.english)/3.0);
}
void Inputinformation()                                   //���� ����
{

	//���Ĳ���
	LNode* pnewstudent = (LNode*)malloc(sizeof(LNode));   //��̬����洢�ռ�
	pnewstudent->next = NULL;
    //ͷ�巨��
	if (g_head== NULL)
		g_head = pnewstudent;
	else
	{
		pnewstudent->next = g_head;//g_head�洢��Ϊ��һ�ڵ��λ�ã��ڸ�λ�ò���ڵ�
		g_head= pnewstudent;//���½ڵ�ĵ�ַ�洢����Ԫ����ָ����
	}
	printf("������ѧ��ѧ�ţ�\n");
	scanf("%s",pnewstudent->data.ID);
	if(strlen(pnewstudent->data.ID)>15){
        printf("�������ѧ����λ��������");
	}
	printf("������ѧ��������\n");
	scanf("%s",pnewstudent->data.name);
	printf("��������ѧ�ɼ���\n");
	scanf("%f",&pnewstudent->data.math);
	printf("���������ĳɼ���\n");
	scanf("%f",&pnewstudent->data.chinese);
	printf("������Ӣ��ɼ���\n");
	scanf("%f",&pnewstudent->data.english);
    pnewstudent->data.average=Average(pnewstudent);
	printf("¼��ѧ����Ϣ�ɹ���\n");
	system("pause");//��ͣ
	system("cls");//����
}
void Outputinformation()
{
    printf("**************************************************************************************************************************\n");
	printf("*                     ��ӭʹ��ѧ���ɼ�����ϵͳ              *\n");
	printf("**************************************************************************************************************************\n");
	printf("*     ѧ��\t����\t��ѧ�ɼ�\t���ĳɼ�\tӢ��ɼ�\tƽ���ɼ�     *");
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
        p = p->next;//����ָ����һ����㣬�����������ѭ��

	}
        printf("**************************************************************************************************************************\n");
}

void Delete(LNode* L,int n)//ɾ�����Ա�ĳһ���
{
    char s[10];
    LNode* q;
    LNode* m;
    int i,j;
    printf("������Ҫɾ����ѧ������");
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
    printf("�����ڸ�ѧ����Ϣ\n");
    q=L;
    j=0;
    while((L->next)&&(j<i-1))//���ҵڣ�i-1�����ڵ㣬pָ��ýڵ�
   {
        L=L->next;
        ++j;
    }
    m=L->next;
    L->next=L->next;
    free(q);
}


void Search(LNode*L)//����ѧ����Ϣ
{

printf("�����뽫Ҫ����ѧ��������");
char s[15];
scanf("%s",s);
LNode*p,*q;
p=L;
while(p!=NULL){
    if(strcmp(p->data.name,s)==0)
        {
    printf("**************************************************************************************************************************\n");
	printf("*     ѧ��\t����\t��ѧ�ɼ�\t���ĳɼ�\tӢ��ɼ�\tƽ���ɼ�     *");
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
    printf("ϵͳ�в����ڸ�ͬѧ��Ϣ");

}

}
int Linklist_Length(LNode*g_head);
void  Change(LNode*g_head);
int UserPassword()
{
char user[5],user2[5];
int n;
char password[7],password1[7];
printf("�������û������ĸ�Ӣ����ĸ����\n");
scanf("%s",user);
n=Judge(user);
while(n)
{
    scanf("%s\n",user);
    n=Judge(user);
}
 printf("���������룺����ĸ��������λ��");
 scanf("%s",password);
if(strlen(password)==6){
    printf("�����ʼ���ɹ���");
}
 system("pause");                                   //��ͣ
 system("cls");                                     //����

 printf("��¼\n\n");
 printf("�������û���");
 scanf("%s",user2);
while(1)
{
    if(!strcmp(user,user2))//�ַ����ȽϺ���������ַ����бȽ�
    {
        printf("�û���������ȷ");
        break;
    }
    else{
    printf("�û�����������������");
    scanf("%s",user2);
    }
}
printf("�������¼���룺\n");
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
        printf("���������������������");
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
    printf("��������ȷ��");
    return 1;
 }

int Linklist_Length(LNode*L) //��¼��������
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
void  Change(LNode*g_head)//�ı�ѧ����Ϣ
{
    printf("������Ҫ���ĵ�ѧ��������\n");
    char name2[15];
    scanf("%s",name2);
    LNode* p2;
    p2=g_head;
while(p2!=NULL)
   {
      if(strcmp(p2->data.name,name2)==0){
        printf("ѧ����Ϣ���ڸ�ϵͳ�У�\n");
        printf("��������ĺ����Ϣ��\n");
        printf("������ѧ��������\n");
        scanf("%s",p2->data.name);
        printf("��������ѧ�ɼ���\n");
        scanf("%f",&p2->data.math);
        printf("���������ĳɼ���\n");
        scanf("%f",&p2->data.chinese);
        printf("������Ӣ��ɼ���\n");
        scanf("%f",&p2->data.english);
        p2->data.average=Average(p2);
        printf("�޸�ѧ����Ϣ�ɹ���\n");
         break;
     }
    else{
        p2=p2->next;
     }
    }
}
