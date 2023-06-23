#ifndef __LIST_QUEUE_
#define __LIST_QUEUE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define StackSizeMix 200
typedef struct {
	int* data;
	int top;
	int StackSize;
}Tstacknode;
typedef struct {
	int capacity;
	char* data;
	int rear;
	int front;
//	int listsize;
}listnode;
typedef struct signode{
	struct signode* next;
	int data;
}node;
int Push(Tstacknode* ,int);
int pop(Tstacknode* p);
Tstacknode* creat(int size);
listnode* creatlist(int size);
int inlist(listnode* p,char x);
char outlist(listnode* p);
int infix(void);

#endif
