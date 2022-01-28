#include<iostream>
#include<stdio.h>
#define MVNum 100
using namespace std;
/*��������
5 5���������ͱ�����

A B C D E�����㣩

A B 1
A C 2
B D 3
B E 4
D E 5
*/
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
    int weight;                 //�����ص���Ϣ
}ArcNode;

typedef struct VNode{
    char data;
    ArcNode *firstarc;
}VNode ,AdList[MVNum];

typedef struct
{
    AdList vertices;
    int vexnum,arcnum;  //ͼ��ǰ�Ķ������ͱ���
}ALGraph;

//���ض���ΪV1�ַ���λ��
int LocateVex(ALGraph G,char V1)
{
	for(int i=0;i<G.vexnum;i++)
    {
		if(G.vertices[i].data==V1)
        {
			return i;
			break;
		}
	}
	return -1;
}

//�����������
void DFS(ALGraph G,int v,int visited[])
{
    ArcNode *p;
    int w;
    cout<<G.vertices[v].data<<" ";
    visited[v]=1;                          //���ʹ��Ķ�����1
    p=G.vertices[v].firstarc;
    while(p!=NULL)
   {
        w= p->adjvex;                     //ָ���������ڵ���һ����
        if(visited[w]==0) DFS(G,w,visited);
        p=p->nextarc;
   }
}

//�ڽӱ���
ALGraph Create()
{   ALGraph G;
    int m,n,weigh;
    char v1,v2;
    int i,j;
    ArcNode *p1,*p2;
    cout<<"�������ܶ��������ܱ���";
    cin>>G.vexnum>>G.arcnum;
    cout<<"�����������"<<endl;
    for( i= 0;i<G.vexnum;i++)
    {
        cin>>G.vertices[i].data;                //���붥������
        G.vertices[i].firstarc=NULL;            //����ָ�����ÿ�
    }
    cout<<"������������ӵ������㼰�ߵ�Ȩ��"<<endl;
    for(int k=0;k<G.arcnum;k++)
    {
        cin>>v1>>v2>>weigh;

        i=LocateVex(G,v1);                 //ȷ��v1,v2 ��λ���±�
        j=LocateVex(G,v2);

        p1=new ArcNode;
        p1->adjvex=j;
        p1->weight=weigh;
        p1->nextarc=G.vertices[i].firstarc;
        G.vertices[i].firstarc=p1;
        //���½��*p1���붥��v1�ı߱�ͷ��
        p2 = new ArcNode;
        p2->adjvex=i;
        p2->weight=weigh;
        p2->nextarc=G.vertices[j].firstarc;
        G.vertices[j].firstarc=p2;
        //���½��*p2���붥��v2�ı߱�ͷ��
    }
    return G;
}
int main()
{
    ALGraph GH;
    int v=0;
    int visited[20]={0};
    GH=Create();
    printf("������ȱ������Ϊ��\n");
    DFS(GH,v,visited);
    return 0;
}
