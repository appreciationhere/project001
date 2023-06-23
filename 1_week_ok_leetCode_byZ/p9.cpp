#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
using namespace std;
/**
*    class pretree: 前缀树的操作 
*    solve1 :       切金条问题
*    
*/
typedef struct Node{
	int p;
	int s;
	map<char, Node*> edge;
}Node;
int solve1(int*, int); 
class Pretree {	
public:
	Pretree(int a,int b) {
		node.p = a;
		node.s = b;
	}
	void insert(string a);
	void deletes(string a);
	int search(string a);
	Node node; 
};

int main() {
	Pretree head(0,0);
	int L[] = {1,4,4,7,9,10};
	cout<<solve1(L, sizeof(L)/sizeof(int))<<endl;
	return 0;
} 
void Pretree::insert(string a) {
	Node* head = &(this->node);
	head->p++;
	for (int i = 0; i < a.size(); i++) {
		map<char, Node*>::iterator p = (head->edge).find(a[i]);
		if (p == (head->edge).end()) {
			Node* buf = new Node;
			buf->p = 1;buf->s = 0;
			head->edge.insert(make_pair(a[i], buf));
			head = buf;
		} else {
			head = p->second;
			head->p++;
		}
	}
	head->s++;
}
int Pretree::search(string a) {
	Node* head = &(this->node);
	for (int i = 0; i < a.size(); i++) {
		map<char, Node*>::iterator p = (head->edge).find(a[i]);
		if (p == (head->edge).end())
			return 0;
		else 
			head = p->second;	
	}
	return head->p;
}
void Pretree::deletes(string a) {
	Node* head = &(this->node);
	head->p--;
	if (this->search(a) != 0)  {
		for (int i = 0; i < a.size(); i++) {
			map<char, Node*>::iterator p = (head->edge).find(a[i]);
			head = p->second;
			head->p--;
		}
		head->s--;		
	}
}
int solve1(int* L, int n) {
	int rest = 0;
	priority_queue<int, vector<int>, greater<int> > que1;
	for (int i = 0; i < n; i++) {
		que1.push(L[i]);
	}
	while (!que1.empty()) {
		int a = 0,b = 0;
		a = que1.top();
		que1.pop();
		if (!que1.empty()) {
			b = que1.top();
			rest += a + b;
			que1.pop();
			if (!que1.empty())
				que1.push(a + b);
		} else
			break;
	}
	return rest;
}














