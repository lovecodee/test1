/* 线性表之顺序存储的基本操作*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 20
/*测试数据：
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
//函数声明
void Menu();                                              //主菜单
int Array(int* S,int length);                            //初始化数组
void AddElement(int *S,int length);                      //添加元素
void DeleteElement(int *S,int length);                   //删除元素
void SearchElement(int *S,int length);                   //查找元素
void Modify(int *S,int length);                          //修改元素
void Sorted(int *S,int length);                          //顺序表排序
void Print(int *S,int length);                           //遍历顺序表


int main(){
static int length=0;
int S;
S = (int *)malloc(sizeof(int)*MAXSIZE);
int choice;
   Menu();
while(1){
    printf("请输入选择：\n");
    scanf("%d",&choice);
    switch(choice){
    case 1: length=Array(S,length);
           printf("长度：%d\n",length)       ;break;
    case 2:AddElement(S,length);break;
    case 3:DeleteElement(S,length);break;
    case 4:SearchElement(S,length);break;
    case 5:Modify(S,length);break;
    case 6:Sorted(S,length);break;
    case 7:Print(S,length);break;
    case 8:Menu();break;
    default:printf("输入错误！\n");break;
        }
}
    return 0;
}

//选择菜单
void Menu(){
printf("\t******************************************\n");
printf("\t**       线性表（顺序存储）基本操作     **\n");
printf("\t**           1.初始化                   **\n");
printf("\t**           2.添加元素                 **\n");
printf("\t**           3.删除元素                 **\n");
printf("\t**           4.查找元素                 **\n");
printf("\t**           5.修改元素                 **\n");
printf("\t**           6.元素排序                 **\n");
printf("\t**           7.打印顺序表               **\n");
printf("\t**           8.显示菜单                 **\n");
printf("\t******************************************\n");
}

//初始化数组
int Array(int* S,int length){
    int total;
    printf("请输入元素总个数：\n");
    scanf("%d",&total);
    length = total;
    printf("请输入元素：\n");
    for(int i=0;i<total;i++)
    {
        scanf_s("%d",S+i);
    }
    printf("初始化成功!\n");
        return length;
}
//添加元素
void AddElement(int *S,int length)
{
    int key;
    printf("请输入关键元素：\n");
    scanf("%d",&key);
    S[length]=key;
    printf("添加成功！");
}
//删除元素
void DeleteElement(int *S,int length){
    int key,j,k;
    printf("请输入删除的关键字：\n");
    scanf("%d",&key);
    j=length;
    for(int i=0;i<j;i++){
        if(S[i]==key){
            for(k=i;k<j;k++){
                S[k]=S[k+1];
            }
            length--;
            printf("删除成功！\n");
            break;
        }
    }


}
//查找元素
void SearchElement(int *S,int length){
    int key,k;
    printf("请输入要查找的关键字：\n");
    scanf("%d",&key);
    k=length;
    for(int i=0;i<k;i++){
        if(S[i]==key){
            printf("查找成功，位置为：%d\n",i+1);
            break;
        }
    }
}

//修改元素
void Modify(int *S,int length){
    int i,key2;
    int j=length;
    printf("请输入要修改元素的下标：\n");
    scanf("%d",&i);
    printf("请输入修改后的元素：\n");
    scanf("%d",&key2);
    if(i<j){
        S[i]=key2;
        printf("修改成功！\n");
    }
    else{
        printf("该下标对应单元存储无元素！\n");
    }
}

//数组元素排序
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
    printf("排序成功！\n");
}
}

//遍历顺序表
void Print(int *S,int length){
    printf("元素的总个数为：%d\n",length);
    for(int j=0;j<length;j++){
        printf("%d\t",S[j]);}
        printf("\n");
}










