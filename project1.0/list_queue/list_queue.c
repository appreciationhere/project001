#include "list_queue.h" 
int main()
{
	int c;
	int i;
	Tstacknode* P=creat(9);
	
	/*while(1)
	{
		
		
		Push(P,c);
	}*/
	infix();
	return 0;
}
Tstacknode* creat(int size)
{
	Tstacknode* p=(Tstacknode*)malloc(sizeof(Tstacknode));
	p->data=(int*)malloc(size*sizeof(int));
	p->StackSize=size;
	p->top=-1;
	return p;
}
int Push(Tstacknode* p,int num)
{
	if(p->top==p->StackSize-1)
		return 1;
	p->data[++p->top]=num;
	return 0;
}
int pop(Tstacknode* p)
{
	if(p->top==-1)
		return '0';
	return p->data[p->top--];
}
listnode* creatlist(int size)
{
	listnode* p=(listnode*)malloc(sizeof(listnode));
	p->data=(char*)malloc((size+1)*sizeof(char));
	p->capacity=size;
	p->front=0;
	p->rear=0;
	return p;
}
int inlist(listnode* p,char x)
{
	if((p->rear+1)%(p->capacity+1)==p->front)
		return 1;
	p->data[p->rear++]=x;
	
	return 0;
}
char outlist(listnode* p)
{
	if(p->front==p->rear)
		return 1;
	return p->data[(p->front++)%p->capacity];
}
int renowsize(listnode* p)
{
	if(p->rear>p->front)
		return p->rear-p->front;
	else
		return p->rear-p->front+p->capacity;
}
int infix(void)
{
	int sum;
	char c;
	int i=0;
	int n;
	Tstacknode* p=creat(100);
	int output[100];
	
	while(1)
	{
		c=getchar();
		if(c=='\n')
			break;
		else if(c>='0'&&c<='9')
		{
			output[i++]=c;
		}
		else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')'||c==' '||c=='%')
		{
			if(c=='+'||c=='-')
			{
				while(p->data[p->top]!='('&&p->top!=-1)
				{
					output[i++]=pop(p);
				}
				Push(p,c);
			}
			else if(c=='*'||c=='/'||c=='%')
			{
				while(p->data[p->top]!='('&&p->top!=-1&&p->data[p->top]!='+'&&p->data[p->top]!='-')
				{
					output[i++]=pop(p);
				}
				Push(p,c);
			}
			else if(c=='(')
				Push(p,c);
			else if(c==')')
			{
				while(p->data[p->top]!='(')
				{
					if(p->data[p->top]==-1)
						return -1;
					else
						output[i++]=pop(p);
				}
				pop(p);
			}
			else
			{
			}
		}
		else
			return -1;
	}
	while(p->top!=-1)
		output[i++]=pop(p);
	for(n=0;n<i;n++)	
		printf("%c",output[n]);
	printf("\n");
	for(n=0;n<i;n++)
	{
		if(output[n]<='9'&&output[n]>='0')
		{
			Push(p,output[n]);
		}
		else
		{
			if(output[n]=='*')
			{
				sum=(pop(p)-'0')*(pop(p)-'0')+'0';
				Push(p,sum);
			}
			if(output[n]=='+')
			{
				sum=(pop(p)-'0')+(pop(p)-'0')+'0';
				Push(p,sum);
			}
			if(output[n]=='-')
			{
				int a,b;
				b=pop(p)-'0';a=pop(p)-'0';
				sum=a-b+'0';
				Push(p,sum);
			}
			if(output[n]=='/')
			{
				int a,b;
				b=pop(p)-'0';a=pop(p)-'0';
				sum=a/b+'0';
				Push(p,sum);
			}
			if(output[n]=='%')
			{
				int a,b;
				b=pop(p)-'0';a=pop(p)-'0';
				sum=a%b+'0';
				Push(p,sum);
			}
		}
	}
	printf("%d",sum-'0');
	
	return sum-'0';
}




