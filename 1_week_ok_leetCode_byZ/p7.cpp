#include <iostream>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
/**
* solve1 判断是否是搜索二叉树 
* solve2 判断是否为完全二叉树 
* solve3 判断是否为平衡二叉树
* solve4 找出两个节点最近的父节点
* solve5 折纸问题 
*/
#define MIN -100
int temp = MIN;
typedef struct BiTree {
	int value;
	BiTree* left;
	BiTree* right;
}Bitree;
typedef pair<BiTree*, int> P;
queue<BiTree*> que5;
map<BiTree*,int> map1;
map<BiTree*,int> map2;
void solve1(BiTree*); 
void solve2(BiTree*);
void solve3(BiTree*);
BiTree* solve4(BiTree*, BiTree*, BiTree*);
void solve5(int, int, bool);
int main() {
	BiTree* head = new Bitree;
	BiTree* h1 = new Bitree;	
	BiTree* h2 = new Bitree;	
	BiTree* h3 = new Bitree;	
	BiTree* h4 = new Bitree;
	BiTree* h5 = new Bitree;	
	BiTree* h6 = new Bitree;
	BiTree* h7 = new Bitree;
	h1->value = 2;h2->value = 1;h3->value = 3;
	h4->value = 6;head->value = 4;h5->value = 5;
	h6->value = 7;h7->value = 0;
	head->left = h1;head->right = h4;h1->left = h2;
	h1->right = h3;h4->right = h6;h4->left = h5;
	h3->left = NULL; h3->right = NULL;
	h2->left = h7; h2->right = NULL;
	h5->left = NULL; h5->right = NULL;
	h6->left = NULL; h6->right = NULL;
	h7->left = NULL; h7->right = NULL;	
	cout<<solve4(head, h5, h4)->value<<endl;
	solve5(1, 3, true);
	return 0;
}
void solve1(BiTree* head) {
	if (head == NULL)
		return;
	solve1(head->left);
	int t = head->value;
	if (t > temp)
		temp = t;
	else {
		cout<<"NO~"<<endl;
		return ;
	}
	solve1(head->right);
}
void solve2(BiTree* head) {
	BiTree* p = head;
	int curlevel = 1;
	int curnode = 0;
	map1.insert(P(p, curlevel));
	que5.push(head);
	while (!que5.empty()) {
		BiTree* p = que5.front();
		que5.pop();
		if (map1.at(p) == curlevel) {
			curnode ++;
		} else {
			if ( curnode == 1 || curnode == pow(2,1/(curlevel - 1))) {
				curnode = 1;
				curlevel++;
			} else {
				cout<<"NO~"<<endl;
				return ;
			}
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
}
void solve3(BiTree* head) {
	if (head == NULL) {
		map2.insert(P(head, 0));
		return;
	}
	int level = 1;
	solve3(head->left);
	solve3(head->right);
	if (!(abs(map2.at(head->left) - map2.at(head->right)) <= 1)) {
		cout<<"NO~"<<endl;
		return;
	} else {
		map2.insert(P(head, max(map2.at(head->left), map2.at(head->right)) + 1));
	}
}
BiTree* solve4(BiTree* head, BiTree* p1, BiTree* p2) {
	if (head == NULL || head == p1 || head == p2)
		return head;
	BiTree* left = solve4(head->left, p1, p2);
	BiTree* right = solve4(head->right, p1, p2);
	if (left != NULL && right != NULL)
		return head;
	return left != NULL? left : right;
}
void solve5(int i, int n, bool jud) {
	if (i > n)
		return;
	solve5(i + 1, n, true);
	string a = jud? "凹" : "凸"; 
	cout<<a<<endl;
	solve5(i + 1, n, false);
}












