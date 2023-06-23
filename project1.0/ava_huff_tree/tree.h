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
AVLTree* Delete(int x,AVLTree* T);// ɾ��һ�� 
AVLTree* Singalroleft(AVLTree* T);
AVLTree* Singalroright(AVLTree* T);
AVLTree* Doublerotate(AVLTree* T);
int* PreoderA_Tree(AVLTree* T,int *a,int n);
int Max(int,int);


typedef struct Bitr_Tree{
	struct Bitr_Tree* left;
	struct Bitr_Tree* right;
	int data;
}Bitr_Tree;//��ͨ������ 
Bitr_Tree* Inorer_Creat(int* a);//���������˳��洢 
Bitr_Tree* Preordoer_Creat(Bitr_Tree* P,int* a);//����ʽ�洢��������,#����� 
int* PreoderB_Tree(Bitr_Tree* T,int *a,int);// �������������
int Compu_Depth(Bitr_Tree* T);//��������������  
int Node_Count(Bitr_Tree* T);//����ڵ����� 
int Leaf_Count(Bitr_Tree* T);//����Ҷ�ӽڵ������ 



typedef struct Clue_Btree{
	struct Clue_Btree* left;
	struct Clue_Btree* right;
	int ltag;
	int rtag;
	int data;
}Clue_Btree;// ���������� 

typedef struct Node{
	int p;
	struct Node* next;
}Node;// ��������ڵ�
 
typedef struct Par_Dri_Tree{
	int data[SIZEMAX];
	int n,r;
	struct Node* Firstchlid;
}Par_Dri_Tree; //����˫��+���ӱ�ʾ 


typedef struct HuffTree{
	int weight;
	int parent,left,right;
}HuffTree;
typedef  char* Hcode;
HuffTree* Creat_HuffTree(int* w,int n);
int Select_Huff(HuffTree* p,int end,int* s1,int* s2);
int* PreoderH_Tree(HuffTree* ,int *,int); //�������������Ҷ�� 
int W_Length(HuffTree* P);// ��Ȩ·������ 
Hcode* H_CODE(HuffTree* ,Hcode*,int n);
#endif
