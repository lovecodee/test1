/* ���Ա�֮˳��洢�Ļ�������*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 20
/*�������ݣ�
10
23
3
45
56
67
78
89
90
5
*/
//��������
void Menu();                                              //���˵�
int Array(int* S,int length);                            //��ʼ������
void AddElement(int *S,int length);                      //���Ԫ��
void DeleteElement(int *S,int length);                   //ɾ��Ԫ��
void SearchElement(int *S,int length);                   //����Ԫ��
void Modify(int *S,int length);                          //�޸�Ԫ��
void Sorted(int *S,int length);                          //˳�������
void Print(int *S,int length);                           //����˳���


int main(){
static int length=0;
int S;
S = (int *)malloc(sizeof(int)*MAXSIZE);
int choice;
   Menu();
while(1){
    printf("������ѡ��\n");
    scanf("%d",&choice);
    switch(choice){
    case 1: length=Array(S,length);
           printf("���ȣ�%d\n",length)       ;break;
    case 2:AddElement(S,length);break;
    case 3:DeleteElement(S,length);break;
    case 4:SearchElement(S,length);break;
    case 5:Modify(S,length);break;
    case 6:Sorted(S,length);break;
    case 7:Print(S,length);break;
    case 8:Menu();break;
    default:printf("�������\n");break;
        }
}
    return 0;
}

//ѡ��˵�
void Menu(){
printf("\t******************************************\n");
printf("\t**       ���Ա�˳��洢����������     **\n");
printf("\t**           1.��ʼ��                   **\n");
printf("\t**           2.���Ԫ��                 **\n");
printf("\t**           3.ɾ��Ԫ��                 **\n");
printf("\t**           4.����Ԫ��                 **\n");
printf("\t**           5.�޸�Ԫ��                 **\n");
printf("\t**           6.Ԫ������                 **\n");
printf("\t**           7.��ӡ˳���               **\n");
printf("\t**           8.��ʾ�˵�                 **\n");
printf("\t******************************************\n");
}

//��ʼ������
int Array(int* S,int length){
    int total;
    printf("������Ԫ���ܸ�����\n");
    scanf("%d",&total);
    length = total;
    printf("������Ԫ�أ�\n");
    for(int i=0;i<total;i++)
    {
        scanf_s("%d",S+i);
    }
    printf("��ʼ���ɹ�!\n");
        return length;
}
//���Ԫ��
void AddElement(int *S,int length)
{
    int key;
    printf("������ؼ�Ԫ�أ�\n");
    scanf("%d",&key);
    S[length]=key;
    printf("��ӳɹ���");
}
//ɾ��Ԫ��
void DeleteElement(int *S,int length){
    int key,j,k;
    printf("������ɾ���Ĺؼ��֣�\n");
    scanf("%d",&key);
    j=length;
    for(int i=0;i<j;i++){
        if(S[i]==key){
            for(k=i;k<j;k++){
                S[k]=S[k+1];
            }
            length--;
            printf("ɾ���ɹ���\n");
            break;
        }
    }


}
//����Ԫ��
void SearchElement(int *S,int length){
    int key,k;
    printf("������Ҫ���ҵĹؼ��֣�\n");
    scanf("%d",&key);
    k=length;
    for(int i=0;i<k;i++){
        if(S[i]==key){
            printf("���ҳɹ���λ��Ϊ��%d\n",i+1);
            break;
        }
    }
}

//�޸�Ԫ��
void Modify(int *S,int length){
    int i,key2;
    int j=length;
    printf("������Ҫ�޸�Ԫ�ص��±꣺\n");
    scanf("%d",&i);
    printf("�������޸ĺ��Ԫ�أ�\n");
    scanf("%d",&key2);
    if(i<j){
        S[i]=key2;
        printf("�޸ĳɹ���\n");
    }
    else{
        printf("���±��Ӧ��Ԫ�洢��Ԫ�أ�\n");
    }
}

//����Ԫ������
void Sorted(int *S,int length){
int i,j,t;
for(i=0;i<length;i++)
    for(j=i;j<=(length-i);j++){
    if(S[j]>S[j+1]){
        t=S[j];
        S[j]=S[j+1];
        S[j+1]=t;
    }
    }
    if(i==length){
    printf("����ɹ���\n");
}
}

//����˳���
void Print(int *S,int length){
    printf("Ԫ�ص��ܸ���Ϊ��%d\n",length);
    for(int j=0;j<length;j++){
        printf("%d\t",S[j]);}
        printf("\n");
}










