#ifndef __TREE_
#define __TREE_
#include "stdio.h"
#include "stdlib.h"
#define SIZEMAX 100
typedef struct AVLTree{
	struct AVLTree* left;
	struct AVLTree* right;
	int data;
	int Height;
}AVLTree;
typedef AVLTree* Position;
int Height(Position P);
AVLTree* Insert(int x,AVLTree* T);
AVLTree* Delete(int x,AVLTree* T);// 删除一个 
AVLTree* Singalroleft(AVLTree* T);
AVLTree* Singalroright(AVLTree* T);
AVLTree* Doublerotate(AVLTree* T);
int* PreoderA_Tree(AVLTree* T,int *a,int n);
int Max(int,int);


typedef struct Bitr_Tree{
	struct Bitr_Tree* left;
	struct Bitr_Tree* right;
	int data;
}Bitr_Tree;//普通二叉树 
Bitr_Tree* Inorer_Creat(int* a);//二叉链表的顺序存储 
Bitr_Tree* Preordoer_Creat(Bitr_Tree* P,int* a);//先序方式存储数组数据,#代表空 
int* PreoderB_Tree(Bitr_Tree* T,int *a,int);// 先序遍历二叉树
int Compu_Depth(Bitr_Tree* T);//计算二叉树的深度  
int Node_Count(Bitr_Tree* T);//计算节点总数 
int Leaf_Count(Bitr_Tree* T);//计算叶子节点的总数 



typedef struct Clue_Btree{
	struct Clue_Btree* left;
	struct Clue_Btree* right;
	int ltag;
	int rtag;
	int data;
}Clue_Btree;// 线索二叉树 

typedef struct Node{
	int p;
	struct Node* next;
}Node;// 单链表常规节点
 
typedef struct Par_Dri_Tree{
	int data[SIZEMAX];
	int n,r;
	struct Node* Firstchlid;
}Par_Dri_Tree; //树的双亲+孩子表示 


typedef struct HuffTree{
	int weight;
	int parent,left,right;
}HuffTree;
typedef  char* Hcode;
HuffTree* Creat_HuffTree(int* w,int n);
int Select_Huff(HuffTree* p,int end,int* s1,int* s2);
int* PreoderH_Tree(HuffTree* ,int *,int); //先序遍历哈夫曼叶子 
int W_Length(HuffTree* P);// 带权路径长度 
Hcode* H_CODE(HuffTree* ,Hcode*,int n);
#endif
