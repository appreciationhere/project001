#ifndef __HASH_MAP
#define __HASH_MAP
#include"stdio.h"
#include"stdlib.h"
#include"list_queue.h"
#define MAX_INT 2147483647
#define MAX_NUM 100 
int p=3;
int* Hash_Creat(int* a,int n);//��ϣ���ҷ��Ĺ���
int Hash_Search(int a,int* m);//��ϣ���� 


typedef struct{
	int	Vervex[MAX_NUM];
	int Arc_Type[MAX_NUM][MAX_NUM];
	int vexnum,arcnum;
}ADmatrix;//�ڽӾ���
int  ADmatrix_Creat(ADmatrix* a);//�ڽӾ��󹹽� 



typedef struct Ajpoint{
	int adjvex;
	int info;
	struct Ajpoint* nextarc;
}Ajpoint;//�ڽӵ���
typedef struct{
	int data;
	struct Ajpoint* firstarc;
}ADnote,*ADlist; 
int  Ajlist_Creat(ADlist* a,int* n);//�ڽӱ��� 
int DFS_List(ADnote* a,int visited[100],int p);//�ڽ�������������������� 



typedef struct{
	int w;
	int to;
	int next;
}Edge;
int cnt=0;
int Head[100];				//��ʽ��ǰ�� 
int Edlist_Creat(Edge* a,int* n);//��ʽ��ǰ�Ǳ��� 
#endif 
