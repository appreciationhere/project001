#include "tree.h"
#include "list_queue.h"
int main(void)
{
	/*
	int x;
	int c[]={10,8,20,15,32,15};
	int y[100];
	int n=sizeof(c)/sizeof(int);
	Hcode* L;
	HuffTree* HT=NULL;
	HT=Creat_HuffTree(c,n);
	for(int i=0;i<2*n-1;i++)
		printf("%d ",HT[i].weight);
	printf("\n");
	PreoderH_Tree(HT,y,2*n-2);
	for(int i=0;i<n;i++)
		printf("%d ",y[i]);
	printf("\n");
	L=H_CODE(HT,L,n);
	for(int i=0;i<n;i++)
		printf("%s\n",L[i]);
	for(int i=n;i<2*n-1;i++)
		printf("%d ",HT[i].left);
	printf("\n");
	for(int i=n;i<2*n-1;i++)
		printf("%d ",HT[i].right);*/ //¹þ·òÂüÊ÷²âÊÔ 
	
	/*AVLTree* T=NULL;
	int a[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
	int num=sizeof(a)/sizeof(int);
	int b[100];
	for(i=0;i<num;i++)
	T=Insert(a[i],T);
	
	PreoderA_Tree(T,b,num);
	for(i=0;i<num;i++)
		printf("%d ",b[i]);
	printf("\n");
	T=Delete(11,T);
	PreoderA_Tree(T,b,num-1);
	for(i=0;i<num-1;i++)
		printf("%d ",b[i]);*/ //AVLÊ÷²âÊÔ  
	return 0; 
}

HuffTree* Creat_HuffTree(int* w,int n)
{
	int m=2*n-1;
	//int i;
	HuffTree* p=(HuffTree*)malloc(m*sizeof(HuffTree));
	for(int i=0;i<m;i++)
	{
		p[i].left=0;
		p[i].parent=0;
		p[i].right=0;
		if(i<n)
			p[i].weight=w[i];
		else
			p[i].weight=0;
	}
	for(int i=n;i<m;i++)
	{
		int s1=0,s2=0;
		Select_Huff(p,i,&s1,&s2);
		p[s1].parent=p[s2].parent=i+1;
		p[i].weight=p[s1].weight+p[s2].weight;
		p[i].left=s1+1;p[i].right=s2+1;
	}
	return p;
}
int Select_Huff(HuffTree* p,int end,int* s1,int* s2)
{
	int min1,min2,i=0;
	while(p[i].parent!=0&&i<end)
		i++;
	min1=p[i].weight;
	*s1=i++;
	while(p[i].parent!=0&&i<end)
		i++;
	if(min1>p[i].weight)
	{
		min2=min1;
		*s2=*s1;
		min1=p[i].weight;
		*s1=i;
	}
	else
	{
		min2=p[i].weight;
		*s2=i;
	}
	for(++i;i<end;i++)
	{
		if(p[i].parent!=0)
			continue;
		if(min1>p[i].weight)
		{
			min2=min1;
			*s2=*s1;
			min1=p[i].weight;
			*s1=i;
		}
		else  if(p[i].weight>=min1&&p[i].weight<min2)
		{
			min2=p[i].weight;
			*s2=i;
		}
	}
	return 0;
}
int Height(Position P)
{
	if(P==NULL)
		return -1;
	else
		return P->Height;
}
AVLTree* Insert(int x,AVLTree* T)
{
	if(T==NULL)
	{
		T=malloc(sizeof( struct AVLTree));
		T->data=x;T->Height=0;
		T->left=NULL;T->right=NULL;
	}
	else
	{
		if(x<=T->data)
		{
			T->left=Insert(x,T->left);
			if(Height(T->left)-Height(T->right)==2)
				if(x<=T->left->data)
					T=Singalroleft(T);
				else
					T=Doublerotate(T);
					
		}
		else
		if(x>T->data)
		{
			T->right=Insert(x,T->right);
			if(Height(T->right)-Height(T->left)==2)
				if(x>=T->right->data)
					T=Singalroright(T);
				else
					T=Doublerotate(T);
		}
	}
	T->Height=Max(Height(T->left),Height(T->right))+1;
	return T;
}
AVLTree* Singalroleft(AVLTree* T)
{
		AVLTree* P;
		P=T->left;
		T->left=P->right;
		P->right=T;
		P->Height=Max(Height(P->left),Height(P->right))+1;
		T->Height=Max(Height(T->left),Height(T->right))+1;
		return P;
	
}
AVLTree* Singalroright(AVLTree* T)
{
		AVLTree* P;
		P=T->right;
		T->right=P->left;
		P->left=T;
		P->Height=Max(Height(P->left),Height(P->right))+1;
		T->Height=Max(Height(T->left),Height(T->right))+1;
		return P;
}
int Max(int a,int b)
{
	if(a<b)
		return b;
	else
		return a;
}
AVLTree* Doublerotate(AVLTree* T)
{
	if(Height(T->left)>Height(T->right))
	{
		T->left=Singalroright(T->left);
		return 	Singalroleft(T);
	}
	else
	{
		T->right=Singalroleft(T->right);
		return 	Singalroright(T);
	}
}
int* PreoderA_Tree(AVLTree* T,int *a,int n)
{
	static int t=0;
	if(t==n) t=0;
	if(T!=NULL)
	{
		a[t++]=T->data;
		PreoderA_Tree(T->left,a,n);
		PreoderA_Tree(T->right,a,n);
	}
	return a;
}
Bitr_Tree* Inorer_Creat(int* a)
{
	static int n=sizeof(a)/sizeof(int);
	Bitr_Tree* P=(Bitr_Tree*)malloc(sizeof(Bitr_Tree));
	
	return P;
}
Bitr_Tree* Preordoer_Creat(Bitr_Tree* P,int* a)
{
	static int i=0;
	if(a[i]!='#')
	{
		P=(Bitr_Tree*)malloc(sizeof(Bitr_Tree));
		P->data=a[i++];
	}
	else
	{
		P=NULL;i++;
	}
	if(P==NULL)return P;
	P->left=Preordoer_Creat(P->left,a);
	P->right=Preordoer_Creat(P->right,a);
	return P;
}
int* PreoderB_Tree(Bitr_Tree* T,int *a,int n)
{
	static int i=0;
	if(i==n) i=0;
	if(T!=NULL)
	{
	a[i++]=T->data;
	PreoderB_Tree(T->left,a,n);
	PreoderB_Tree(T->right,a,n);
	return a;
	}
}
int Compu_Depth(Bitr_Tree* T)
{
	int m=0,n=0;
	if(T==0) return 0;
	else
	{
		m=Compu_Depth(T->left);
		n=Compu_Depth(T->right);
		if(m>n)
			return m+1;
		else
			return n+1;
	}
}
int Node_Count(Bitr_Tree* T)
{
	if(T==NULL)
		return 0;
	else
		return (Node_Count(T->left)+Node_Count(T->right)+1);
}
int Leaf_Count(Bitr_Tree* T)
{
	if(T==NULL) return 0;
	else if(T->left==NULL&&T->right==NULL)
		return 1;
	else
		return (Leaf_Count(T->left)+Leaf_Count(T->right));
}
AVLTree* Delete(int x,AVLTree* T)
{
	if(T==NULL)
		return T;
	AVLTree* P=T;
	AVLTree* tem=NULL;
    if(T->data==x)
	{
		if(T->left!=NULL&&T->right!=NULL)
		{
			P=P->right;
			if(!P->left)
			{
				P->left=T->left;
				P->Height=Max(Height(P),Height(T->left))+1;
			}
			else
			{
				while(P->left->left)
				{
					P=P->left;
					if(Height(P->left)>Height(P->right))
						P->Height=Height(P->left)-1;
				}
				P->left->left=T->left;
				P->left->right=T->right;
				tem=P->left;P->left=NULL;
				P=tem;P->Height=Max(Height(T->left),Height(T->right));
			}
			free(T);
		}
		else if(T->left==NULL&&T->right==NULL)
			free(T);
		else
		{
			if(!T->left)
			{
				P=T->left;
				free(T);
			}
			else
			{
				P=T->left;
				free(T);
			}		
		}
	}
	else if(T->data>x)
		T->left=Delete(x,T->left);
	else
		T->right=Delete(x,T->right);

	if(Height(P->left)-Height(P->right)==2)
	{
		if(Height(P->left->left)-Height(P->left->right))
			P=Singalroleft(P);
		else
			P=Doublerotate(P);
	}
	else if(Height(P->right)-Height(P->left)==2)
	{
		if(Height(P->right->right)-Height(P->right->left))
			P=Singalroright(P);
		else
			P=Doublerotate(P);
	}
	return P;
}
int* PreoderH_Tree(HuffTree* P,int * a,int n)
{
 	static int i=0;//HuffTree* T=P
 	if(n!=-1) 
 	{
 		if(P[n].left==0&&P[n].right==0)
		 	a[i++]=P[n].weight;
		 	
		PreoderH_Tree(P,a,P[n].left-1);
		PreoderH_Tree(P,a,P[n].right-1);
	}
 	return a;	
}
int W_Length(HuffTree* P)
{
	
}
int W_Length(HuffTree* P);// ´øÈ¨Â·¾¶³¤¶È 
Hcode* H_CODE(HuffTree* P,Hcode* HC,int n)
{
	HC=(char**)malloc(n*sizeof(char*[n+1]));	
	int m=2*n-1,t;
	for(int i=0;i<n;i++)
	{
		int num=i,len=n;
		HC[i]=(char*)malloc((n+1)*sizeof(char));
		for(int l=0;l<n+1;l++)
			HC[i][l]=' ';
		while(P[num].parent)
		{		
			t=P[num].parent-1;
			if(P[t].left-1==num)
			{
				HC[i][len--]='0';
				num=t;
			}
			else
			{
				HC[i][len--]='1';
				num=t;
			}
		}
	}
	return HC;
}

