#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
/**
*solve1 : 先序中序后序的非递归形式 
*solve2 : 宽度遍历二叉树 
*solve3 : 计算二叉树的最大宽度 
*/
typedef struct BiTree {
	int value;
	BiTree* left;
	BiTree* right;
}Bitree;
typedef pair<BiTree*, int> P;
map<BiTree*, int> map1;
queue<BiTree*> que5;
void solve1(BiTree* );
void solve2(BiTree* );
void solve3(BiTree* );
int main() {
	BiTree* head = new Bitree;
	BiTree* h1 = new Bitree;	
	BiTree* h2 = new Bitree;	
	BiTree* h3 = new Bitree;	
	BiTree* h4 = new Bitree;
	BiTree* h5 = new Bitree;	
	BiTree* h6 = new Bitree;
	h1->value = 1;h2->value = 5;h3->value = 7;
	h4->value = 6;head->value = 2;h5->value = 8;
	h6->value = 0;
	head->left = h1;head->right = h4;h1->left = h2;
	h1->right = h3;h4->right = h6;h4->left = h5;
	h3->left = NULL; h3->right = NULL;
	h2->left = NULL; h2->right = NULL;
	h5->left = NULL; h5->right = NULL;
	h6->left = NULL; h6->right = NULL;	

	solve3(head);
	return 0;
		
}
void solve1(BiTree* head) {
	stack<BiTree*> sta1;
	BiTree* l = head;
	sta1.push(head);
	while (!sta1.empty()) {
		BiTree* p1 = sta1.top();
		sta1.pop();
		cout<<p1->value<<" ";
		if (p1->right != NULL)
			sta1.push(p1->right);
		if (p1->left != NULL)
		sta1.push(p1->left);
	}
	cout<<endl;
	
	
	stack<BiTree*> sta2;
	while (!sta2.empty() || l != NULL) {
		if (l != NULL) {
			while (l != NULL) {
				sta2.push(l);
				l = l->left;
			}			
		}
		else {
			BiTree* p = sta2.top();
			sta2.pop();
			cout<<p->value<<" ";
			l = p->right;
		}
	}
	cout<<endl;
	
	
	stack<BiTree*> sta3;
	stack<BiTree*> sta4;
	sta3.push(head);
	while (!sta3.empty()) {
		BiTree* p1 = sta3.top();
		sta3.pop();
		sta4.push(p1); 
		if (p1->right != NULL)
			sta3.push(p1->right);
		if (p1->left != NULL)
		sta3.push(p1->left);
	}
	while (!sta4.empty()) {
		cout<<sta4.top()->value<<" ";
		sta4.pop(); 
	}
	cout<<endl;
}
void solve2(BiTree* head) {  // 宽度遍历二叉树
	queue<BiTree*> que1;
	que1.push(head);
	while (!que1.empty()) {
		BiTree* p = que1.front();
		que1.pop();
		cout<<p->value<<" ";
		if (p->left != NULL) {
			que1.push(p->left);
		}
		if (p->right != NULL) {
			que1.push(p->right);
		}
	}
	cout<<endl;
}
void solve3(BiTree* head) { // 计算二叉树的最大宽度 
	BiTree* p = head;
	int curlevel = 1;
	int curnode = 0;
	int max1 = 0;
	map1.insert(P(p, curlevel));
	que5.push(head);
	while (!que5.empty()) {
		BiTree* p = que5.front();
		que5.pop();
		if (map1.at(p) == curlevel) {
			curnode ++;
		} else {
			max1 = max(max1,curnode);
			curnode = 1;
			curlevel++;
		}
		if (p->left != NULL) {
			map1.insert(P(p->left, curlevel+1));
			que5.push(p->left);
		}
		if (p->right != NULL) {
			map1.insert(P(p->right, curlevel+1));
			que5.push(p->right);
		}
	}
	cout<<"max node = "<<max(max1,curnode)<<endl; 
}
















