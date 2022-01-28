#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
#define MaxInt 32765
#define MVNum 100
#define True 1
#define  False 0
/*
�������ݣ�
5 5       ���ܶ������ͱ�����
A B C D E  (����)
A B 1
A C 2
B D 3
B E 4
D E 5
*/
typedef struct
{
   char vexs[MVNum];                //�����
   int arcs[MVNum][MVNum];          //�ڽӾ���
   int points,edge;                   //��ͱ�

}AMGraph;

//��������
void CreateUDN(AMGraph &G) ;//�ڽӾ���Ĺ���
int LocateVex(AMGraph &G,char V1);//�����ַ�λ���±�
void DFS(AMGraph &G,int v,int visited[]);//������ȱ���

void BFS_AM(AMGraph G,int v,int visited[]);//������ȱ���
int main()
{
	AMGraph G;
	int visited1[30];
	int visited2[40];
	int v=2;
	CreateUDN(G);
	printf("\n");              //����һ������
	printf("������ȱ������Ϊ��\n");
 	DFS(G,v,visited1);                //���������������
 	printf("\n������ȱ������Ϊ��\n");
 	BFS_AM(G,v,visited2);
 	return  0;
}

//���ض���ΪV1�ַ���λ��
int LocateVex(AMGraph &G,char V1)
{
	for(int i=1;i<=G.points;i++)
    {
		if(G.vexs[i]==V1)
        {
			return i;
		}
	}
}

//�����ڽӾ���
void CreateUDN(AMGraph &G)          //�����ڽӾ����ʾ��������������
{
    char v1,v2;
    int i,j,k,t;
    cout<<"�������ܶ��������ܱ�����";
    cin>>G.points>>G.edge;            //�����ܶ��������ܱ���
    printf("�����붥��:\n");
    for(int i=1;i<=G.points;++i)
    {
        cin>>G.vexs[i];
    }
    for(i=1;k<=G.points;++i)               //��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵMaxInt
       for(int j=1;k<=G.points;++k)
            G.arcs[i][j]=MaxInt;            //��ʼ���ڽӾ��󣬽���������ֵ����Ϊ���ֵ
    printf("����������������Ķ��㼰Ȩֵ��\n");
    for(int w,k=0;k<G.edge;++k)             //�����ڽӾ���
    {
        cin>>v1>>v2>>w;                    //����һ���������Ķ��㼰Ȩֵ
    	i=LocateVex(G,v1);                 //ȷ��v1��v2��G�е�λ�ã�������������±�
    	j=LocateVex(G,v2);
    	G.arcs[i][j]=w;                    //��<v1,v2>��Ȩֵ��Ϊw
        G.arcs[j][i]=G.arcs[i][j];         //��<v1,v2>�ĶԳƱ�<v2,v1>��ȨֵΪw
    }
    printf("��ʼ���ɹ���");
}
//DFS�������������������
void DFS(AMGraph &G,int v,int visited[])
{
    cout<<G.vexs[v]<<" ";
    visited[v]=1;                          //���ʹ��Ķ�����1
    for(int j=1;j<=G.points;j++)
    {
        if(G.arcs[v][j]!=0&&visited[j]==0)
            DFS(G,j,visited);
    }
}
//�ڽӾ���������
void BFS_AM(AMGraph G,int v,int visited[])
{
	cout<<G.vexs[v]<<" ";
	visited[v]=1;           //���ʵ�v������
	queue<int> Q;          //��������Q��ʼ��
	Q.push(v);              //v����
	while(!Q.empty())      //���зǿ�
	{
		int t=Q.front();
		Q.pop();            //��ͷԪ�س��Ӳ�����t
		for(int w=1;w<=G.points;w++)
		{
			if(G.arcs[t][w]!=0&&visited[w]==0)
			{
				visited[w]=1;
				cout<<G.vexs[w]<<" ";
				Q.push(w);   //w����
			}
		}
	}
}
