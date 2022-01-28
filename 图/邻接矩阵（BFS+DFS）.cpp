#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
#define MaxInt 32765
#define MVNum 100
#define True 1
#define  False 0
/*
测试数据：
5 5       （总顶点数和边数）
A B C D E  (顶点)
A B 1
A C 2
B D 3
B E 4
D E 5
*/
typedef struct
{
   char vexs[MVNum];                //顶点表
   int arcs[MVNum][MVNum];          //邻接矩阵
   int points,edge;                   //点和边

}AMGraph;

//函数声明
void CreateUDN(AMGraph &G) ;//邻接矩阵的构建
int LocateVex(AMGraph &G,char V1);//返回字符位置下标
void DFS(AMGraph &G,int v,int visited[]);//深度优先遍历

void BFS_AM(AMGraph G,int v,int visited[]);//广度优先遍历
int main()
{
	AMGraph G;
	int visited1[30];
	int visited2[40];
	int v=2;
	CreateUDN(G);
	printf("\n");              //创建一个向网
	printf("深度优先遍历结果为：\n");
 	DFS(G,v,visited1);                //深度优先搜索遍历
 	printf("\n广度优先遍历结果为：\n");
 	BFS_AM(G,v,visited2);
 	return  0;
}

//返回顶点为V1字符的位置
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

//创建邻接矩阵
void CreateUDN(AMGraph &G)          //采用邻接矩阵表示法，创建无向网
{
    char v1,v2;
    int i,j,k,t;
    cout<<"请输入总顶点数和总边数：";
    cin>>G.points>>G.edge;            //输入总顶点数和总边数
    printf("请输入顶点:\n");
    for(int i=1;i<=G.points;++i)
    {
        cin>>G.vexs[i];
    }
    for(i=1;k<=G.points;++i)               //初始化邻接矩阵，边的权值均置为极大值MaxInt
       for(int j=1;k<=G.points;++k)
            G.arcs[i][j]=MaxInt;            //初始化邻接矩阵，将其中所有值均置为最大值
    printf("请输出两条边依附的顶点及权值：\n");
    for(int w,k=0;k<G.edge;++k)             //构造邻接矩阵
    {
        cin>>v1>>v2>>w;                    //输入一条边依附的顶点及权值
    	i=LocateVex(G,v1);                 //确定v1和v2在G中的位置，即定点数组的下标
    	j=LocateVex(G,v2);
    	G.arcs[i][j]=w;                    //边<v1,v2>的权值置为w
        G.arcs[j][i]=G.arcs[i][j];         //置<v1,v2>的对称边<v2,v1>的权值为w
    }
    printf("初始化成功！");
}
//DFS（深度优先搜索遍历）
void DFS(AMGraph &G,int v,int visited[])
{
    cout<<G.vexs[v]<<" ";
    visited[v]=1;                          //访问过的顶点置1
    for(int j=1;j<=G.points;j++)
    {
        if(G.arcs[v][j]!=0&&visited[j]==0)
            DFS(G,j,visited);
    }
}
//邻接矩阵广度搜索
void BFS_AM(AMGraph G,int v,int visited[])
{
	cout<<G.vexs[v]<<" ";
	visited[v]=1;           //访问第v个顶点
	queue<int> Q;          //辅助队列Q初始化
	Q.push(v);              //v进队
	while(!Q.empty())      //队列非空
	{
		int t=Q.front();
		Q.pop();            //队头元素出队并赋给t
		for(int w=1;w<=G.points;w++)
		{
			if(G.arcs[t][w]!=0&&visited[w]==0)
			{
				visited[w]=1;
				cout<<G.vexs[w]<<" ";
				Q.push(w);   //w进队
			}
		}
	}
}
