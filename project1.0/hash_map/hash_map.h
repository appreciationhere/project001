#ifndef __HASH_MAP
#define __HASH_MAP
#include"stdio.h"
#include"stdlib.h"
#include"list_queue.h"
#define MAX_INT 2147483647
#define MAX_NUM 100 
int p=3;
int* Hash_Creat(int* a,int n);//哈希查找法的构建
int Hash_Search(int a,int* m);//哈希查找 


typedef struct{
	int	Vervex[MAX_NUM];
	int Arc_Type[MAX_NUM][MAX_NUM];
	int vexnum,arcnum;
}ADmatrix;//邻接矩阵
int  ADmatrix_Creat(ADmatrix* a);//邻接矩阵构建 



typedef struct Ajpoint{
	int adjvex;
	int info;
	struct Ajpoint* nextarc;
}Ajpoint;//邻接点域
typedef struct{
	int data;
	struct Ajpoint* firstarc;
}ADnote,*ADlist; 
int  Ajlist_Creat(ADlist* a,int* n);//邻接表构建 
int DFS_List(ADnote* a,int visited[100],int p);//邻接链表深度优先搜索遍历 



typedef struct{
	int w;
	int to;
	int next;
}Edge;
int cnt=0;
int Head[100];				//链式向前星 
int Edlist_Creat(Edge* a,int* n);//链式向前星表构建 
#endif 
