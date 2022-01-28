#include<iostream>
#include<stdio.h>
#define MVNum 100
using namespace std;
/*测试数据
5 5（顶点数和边数）

A B C D E（顶点）

A B 1
A C 2
B D 3
B E 4
D E 5
*/
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
    int weight;                 //与边相关的信息
}ArcNode;

typedef struct VNode{
    char data;
    ArcNode *firstarc;
}VNode ,AdList[MVNum];

typedef struct
{
    AdList vertices;
    int vexnum,arcnum;  //图当前的顶点数和边数
}ALGraph;

//返回顶点为V1字符的位置
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

//深度搜索遍历
void DFS(ALGraph G,int v,int visited[])
{
    ArcNode *p;
    int w;
    cout<<G.vertices[v].data<<" ";
    visited[v]=1;                          //访问过的顶点置1
    p=G.vertices[v].firstarc;
    while(p!=NULL)
   {
        w= p->adjvex;                     //指向与其相邻的下一顶点
        if(visited[w]==0) DFS(G,w,visited);
        p=p->nextarc;
   }
}

//邻接表创建
ALGraph Create()
{   ALGraph G;
    int m,n,weigh;
    char v1,v2;
    int i,j;
    ArcNode *p1,*p2;
    cout<<"请输入总顶点数和总边数";
    cin>>G.vexnum>>G.arcnum;
    cout<<"请输入各顶点"<<endl;
    for( i= 0;i<G.vexnum;i++)
    {
        cin>>G.vertices[i].data;                //输入顶点内容
        G.vertices[i].firstarc=NULL;            //顶点指针域置空
    }
    cout<<"请输入边所连接的两顶点及边的权重"<<endl;
    for(int k=0;k<G.arcnum;k++)
    {
        cin>>v1>>v2>>weigh;

        i=LocateVex(G,v1);                 //确定v1,v2 的位置下标
        j=LocateVex(G,v2);

        p1=new ArcNode;
        p1->adjvex=j;
        p1->weight=weigh;
        p1->nextarc=G.vertices[i].firstarc;
        G.vertices[i].firstarc=p1;
        //将新结点*p1插入顶点v1的边表头部
        p2 = new ArcNode;
        p2->adjvex=i;
        p2->weight=weigh;
        p2->nextarc=G.vertices[j].firstarc;
        G.vertices[j].firstarc=p2;
        //将新结点*p2插入顶点v2的边表头部
    }
    return G;
}
int main()
{
    ALGraph GH;
    int v=0;
    int visited[20]={0};
    GH=Create();
    printf("深度优先遍历结果为：\n");
    DFS(GH,v,visited);
    return 0;
}
