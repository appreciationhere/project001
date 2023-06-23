#include "hash_map.h"
int main(void)
{
	/*
	int n;
	int b[100];
	ADnote* a;
	for(int i=0;i<100;i++)
		b[i]=0;
	Ajlist_Creat(&a,&n);
	DFS_List(a,b,0);
	*/ //接链表深度优先搜索遍历 
	/*
	int n,t;
	Edge edge[100];
	Edlist_Creat(edge,&n);
	for(int i=1;i<n+1;i++)
	{
		t=Head[i];
		if(t==-1)
		{
			printf("没有边");
			continue;
		}
		while(edge[t].next!=-1)
		{
			printf("%d ",edge[t].to);
			t=edge[t].next;
		}
		printf("%d\n",edge[t].to);
	}
	*/  //链式向前星测试 
	
	/*ADmatrix a;
	ADmatrix_Creat(&a);
	for(int i=0;i<a.vexnum;i++)
		printf("%d ",a.Vervex[i]);
	printf("\n");
	for(int i=0;i<a.vexnum;i++)
		printf("%d ",a.Arc_Type[1][i]);*/ //邻接矩阵构建测试 
	/*int* a;int b[]={15,2,3,7,9,11,34,23,12};
	a=Hash_Creat(b,sizeof(b)/sizeof(int));
	for(int i=0;i<11;i++)
		printf("%d ",a[i]);
	printf("%d ",Hash_Search(23,a));*/ //hash查找测试 
	return 0;
}
int* Hash_Creat(int* a,int n)
{
	int k=0,num,un;
	while(p<n)
	{
		k++;p=4*k+3;
	}
	int* m=(int*)calloc(p,sizeof(int));
	for(int i=0;i<n;i++)
	{
		int t=0;
		num=a[i]%p;un=num;
		while(m[(num+t*t)%p]&&m[un%p])
		{
			t++;
			if((num-t*t)<0)
				un=-(num-t*t);
			else
				un=num-t*t;
		}
		if(m[un%p])
			m[(num+t*t)%p]=a[i];
		else
			m[un%p]=a[i];
	}
	return m;
}
int Hash_Search(int a,int* m)
{
	int num,t=0,un;
	num=a%p;
	while(m[(num+t*t)%p]-a&&m[un%p]-a)
	{
		t++;
		if((num-t*t)<0)
			un=-(num-t*t);
		else
			un=num-t*t;
		if(t==100)
			return MAX_INT;
	}
	if(m[(num+t*t)%p]-a)
		return un%p;
	else
		return num+t*t;
}
int  ADmatrix_Creat(ADmatrix* a)
{
	int j,k,l;
	printf("请输入总顶点数和总边数,用空格隔开:");
	scanf("%d %d",&(*a).vexnum,&(*a).arcnum);
	printf("请依次输入顶点的值:");
	for(int i=0;i<(*a).vexnum;i++)
		scanf("%d",&(*a).Vervex[i]);
	for(int p=0;p<(*a).vexnum;p++)
		for(int y=0;y<(*a).vexnum;y++)
			(*a).Arc_Type[p][y]=MAX_INT;
	printf("请依次输入顶点编号和对应边的权值,用空格隔开:");
	for(int i=0;i<(*a).arcnum;i++)
	{
		scanf("%d %d %d",&j,&k,&l);
		(*a).Arc_Type[j-1][k-1]=l;
	}
	return 0;
}
int  Ajlist_Creat(ADlist* a,int* n)
{
	int k,l,j,m;
	Ajpoint* T;
	printf("请输入总顶点数和总边数,用空格隔开:");
	scanf("%d %d",n,&k);
	*a=(ADlist)malloc(sizeof(ADnote)*(*n));
	printf("请依次输入顶点的值:");
	for(int i=0;i<*n;i++)
	{
		scanf("%d",&(*a)[i].data);
		(*a)[i].firstarc=NULL;
	}
	printf("请依次输入顶点编号和对应边的权值,用空格隔开:");
	for(int i=0;i<k;i++)
	{
		scanf("%d %d %d",&j,&l,&m);
		Ajpoint* p=(*a)[j-1].firstarc;
		if(!p)
		{
			T=(Ajpoint*)malloc(sizeof(Ajpoint));
			T->adjvex=l-1;
			T->info=m;
			T->nextarc=NULL;
			(*a)[j-1].firstarc=T;
			continue;
		}	
		while(p->nextarc)
			p=p->nextarc;
		T=(Ajpoint*)malloc(sizeof(Ajpoint));
		T->adjvex=l-1;
		T->info=m;
		T->nextarc=NULL;
		p->nextarc=T;
	}
	return 0;
}
int Edlist_Creat(Edge* a,int* n)
{	
	int l,j,m,t;
	printf("请输入总顶点数和总边数,用空格隔开:");
	scanf("%d %d",n,&cnt);
	for(int i=0;i<cnt;i++)
	{	
		a[i].next=-1;
		a[i].to=-1;
		a[i].w=-1;
	}
	for(int i=0;i<*n+1;i++)
		Head[i]=-1;
	printf("请依次输入顶点编号和对应边的权值,用空格隔开:");
	for(int i=0;i<cnt;i++)
	{
		scanf("%d %d %d",&j,&l,&m);
		a[i].w=m;
		t=Head[j];
		if(Head[j]==-1)
			Head[j]=i;
		else
		{
			while(a[t].next!=-1)
				t=a[t].next;
			a[t].next=i;
		}
		a[i].to=l;		
	}
	return 0;
}
int DFS_List(ADnote* a,int visited[100],int p)
{
	Ajpoint* T;
	printf("%d ",a[p].data);
	visited[p]=1;
	T=a[p].firstarc;
	if(!T)
		return 0;
	while(T)
	{
		if(!visited[T->adjvex])
			DFS_List(a,visited,T->adjvex);
		T=T->nextarc;
	}
	return 0;
}
