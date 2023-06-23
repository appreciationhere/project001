#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
/**
* solve1 : 拓扑排序 (主要是依次解锁的先后关系，要学模电，必须要电路分析基础等等)
* solve2 : 最小生成树 k算法 
* solve3 : 最小生成数 p算法 
* solve4 : dijk两点最小距离算法 
*/
struct edge;
typedef struct node {
	int value;
	int in;
	int out;
	vector<node*> nexts;
	vector<edge*> edges;
}node;
typedef struct edge {
	node* from;
	node* to;
	int weight;
	bool operator() (edge* a, edge* b) 
  	{
    	return a->weight > b->weight; //小顶堆
  	}
}edge;
typedef struct Graph {
	map<int, node*> nodes;
	set<edge*> edges;
}Graph;
struct tmp2 //重写仿函数
{
  bool operator() (edge* a, edge* b) 
  {
    return a->weight > b->weight; //小顶堆
  }
};
map<node*, int>* rest = new map<node*, int>;
typedef pair<node* , int> P;
map<node*, int> map1;      // 为了根据节点指针来得到它是几号边 
map<int, node*>* map2;     // 指向图的map的指针来 
queue<node*> que1;    
priority_queue<edge*, vector<edge*>, edge> prique;   //  优先队列排列边 
priority_queue<edge*, vector<edge*>, tmp2> prique1;  //  优先队列排列边
void solve1(Graph*);
void solve2(Graph*); 
void solve3(Graph*); 
map<node*, int>* solve4(Graph*, node*); 
node* find_minNode(Graph* head, set<node* > se1);
int main() {
	int num = 1;
	int n;	
	set<edge*>* edges1;
	vector<node*>* nexts;
	vector<edge*>* edges2;
	map<int, node*>* map3;
	Graph* head = new Graph;
	edges1 = &(head->edges);
	map3 = &(head->nodes);
	cout<<"请输入节点的个数：";
	cin>>n;
	for (int i = 1; i <= n; i++) {
		node* p = new node;
		p->in = 0;
		map3->insert(make_pair(i, p));
	}
	for (int i = 1; i <= n; i++) {
		node* p = map3->at(i);
		int buf,value;
		cout<<"请依次输入"<<i<<"号节点的value和有几条边：";
		cin>>value>>buf; 
		p->value = value;
		p->out = buf;
		for (int j = 1; j <= buf; j++) {
			int to,weight;
			cout<<"请输入"<<i<<"号节点"<<j<<"号边的weight,to :"; 
			cin>>weight>>to;
			edge* buf1 = new edge;
			buf1->weight = weight;
			buf1->from = p;
			buf1->to = map3->at(to);
			(p->edges).push_back(buf1);
			(p->nexts).push_back(map3->at(to));
			((map3->at(to))->in)++;
			edges1->insert(buf1);
		}
	}
	solve3(head);
//	map<node*, int>* p = solve4(head, head->nodes.at(1));
//	
//	for (map<node*, int>::iterator p1 = p->begin();p1 != p->end(); p1++) {
//		node* p2 = p1->first;
//		cout<<p2->value<<" "<<p1->second<<endl;
//	}
	return 0;
}
void solve1(Graph* head) {
	map2 = &(head->nodes);
	/*
	*  找出每一个入度为0的节点入队 ，从入度为0的节点进行开始的拓扑排序 
	*/ 
	for (int i = 1; i <= map2->size(); i++) {
		node* p = map2->at(i);
		if (p->in == 0)
			que1.push(p);
	}
	while (!que1.empty()) {
		node* p = que1.front();
		que1.pop();
		cout<<p->value<<" ";    // 输入该输入为 0 的节点
		/*
		*  把输出节点的每一个连接的节点的入度 - 1
		*  同时找出 -1 后入度为 0 的点 入队 
		*/ 
		for (int i = 0; i < p->nexts.size(); i++) {
			node * p1 = p->nexts.at(i);
			(p1->in)--;
			if (p1->in <= 0)
				que1.push(p1);
		}
	}
}
void solve2(Graph* head) {
	vector<node*>* vec2 = new vector<node*>[(head->nodes).size()];  //都分配一个和nodes数量一致的vector数组 
	vector<node*>** vec3 = new vector<node*>*[(head->nodes).size()];//给每一个节点分配一个指针，来指向刚刚分配的数组 
	/*
	*  初始化vec 和 vec3 
	*/ 
	for (int i = 1;i <= (head->nodes).size(); i++) {
		(vec2[i - 1]).push_back((head->nodes).at(i));
		vec3[i - 1] = &(vec2[i - 1]);
	}
	/*
	*  map1为了根据节点指针来得到它是几号边 , 初始化map1 
	*/ 
	for (int i = 1; i <= (head->nodes).size(); i++) {
		map1.insert(P((head->nodes).at(i),i - 1));
	}
	/*
	*  把所有边都加入到优先队列中 
	*/
	for (set<edge*>::iterator i = (head->edges).begin(); i != (head->edges).end(); i++)
		prique.push(*i);
	while (!(prique.empty())) {
		edge* p = prique.top();
		prique.pop();
		if (vec3[map1.at(p->from)] == vec3[map1.at(p->to)]) { //如果from和to都指向同一个vector则继续  
			continue;
		}
		vec3[map1.at(p->to)] = vec3[map1.at(p->from)];   
		while (vec2[map1.at(p->to)].size()) {
			vec2[map1.at(p->from)].push_back(vec2[map1.at(p->to)].back()); // 把to的最后一个元素加入from 
			vec2[map1.at(p->to)].pop_back();  //删除最后一个元素 
		}
		cout<<p->weight<<" "; 
	}
}
void solve3(Graph* head) {
	set<node*> set1;
	map<int, node*> ma1 = head->nodes;
	int n = ma1.size();
	for (int i = 1; i <= n; i++) {
		if (set1.find(ma1[i]) == set1.end()) {
			set1.insert(ma1[i]);
			for (int j = 0; j < ma1[i]->edges.size(); j++) {
				prique1.push(ma1[i]->edges[j]);
			} 
			while (!prique1.empty()) {
				edge* p = prique1.top();
				prique1.pop();
				if (set1.find(p->to) == set1.end()) {
					set1.insert(p->to);
					cout<<p->weight;
					for (int k = 0; k < p->to->edges.size(); k++) {
						prique1.push(p->to->edges[k]);
					} 					
				}
			}
		}
	}
}
map<node*, int>* solve4(Graph* head, node* sta) {
	node* minNode = NULL;
	set<node*> se1;
	rest->insert(P(sta, 0));
	minNode = find_minNode(head, se1);
	while (minNode != NULL) {
		for (int i = 0; i < minNode->edges.size(); i++) {
			edge* p = minNode->edges[i];
			node* to1 = minNode->edges[i]->to;
			if (rest->find(to1) == rest->end())
				rest->insert(P(to1, rest->at(minNode) + p->weight));
			else
				rest->at(p->to) = rest->at(p->to) <= (rest->at(p->from) + p->weight) ?  
								 rest->at(p->to) : (rest->at(p->from) + p->weight);			
		}
		se1.insert(minNode);
		minNode = find_minNode(head, se1);
	}
	return rest;
}
node* find_minNode(Graph* head, set<node* > se1) {
	node* res = NULL;
	int min = 65535;
	for (map<node*, int>::iterator p = rest->begin(); p != rest->end(); p++) {
		if (se1.find(p->first) == se1.end() && p->second < min) {
			res = p->first;
			min = p->second;
		}
	}
	return res;
}









