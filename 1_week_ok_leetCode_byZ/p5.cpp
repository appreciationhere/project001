#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
/**
*solve1 : 单链表回文数判断栈的做法o(N) 
*solve2 : 单链表回文数判断快慢指针做法o(1) 
*solve3 : 荷兰国旗单链表 o(1) 
*/
class A {
public:
	A(string name, string sex, int age, int high) {
		this->name = name;
		this->sex = sex;
		this->age = age;
		this->high = high;
	}
	A() {
	}
	string name;
	string sex;
	int age;
	int high;
};
typedef struct Node {
	int value;
	Node* next;
}Node;
bool compare1(A a, A b);
bool solve1(Node* head);
bool solve2(Node* head);
void solve3(Node* head, int num);
int main() {
	A a[10];
	Node* head = new Node;
	Node* p = head;
	head->next = NULL;
	string b = "杨";
	for (int i = 0; i < 10; i++) {
		a[i].name =  b;
		a[i].age = i;
		a[i].high = i+170;
		a[i].sex = "男";
	}
	sort(a, a+10, compare1);
	for (int i = 0; i < 10; i++) {
		cout<<a[i].name<<" ";
		cout<<a[i].sex<<" ";
		cout<<a[i].age<<" ";
		cout<<a[i].high<<" "<<endl;
	}
	p->next = new Node;
	p->next->value = 1;
	p = p->next;
	p->next = new Node;
	p->next->value = 2;
	p = p->next;
	p->next = new Node;
	p->next->value = 3;
	p = p->next;
	p->next = new Node;
	p->next->value = 2;
	p = p->next;
	p->next = new Node;
	p->next->value = 1;
	p->next->next = NULL;
	solve3(head, 2);	
	while (head->next != NULL) {
		cout<<head->next->value<<"  ";
		head = head->next;
	}
	return 0;
}
bool compare1(A a, A b) {
	if (a.age < b.age)
		return false;
	else if  (a.age == b.age) {
		return a.high < b.high ? false : true;
	}
	else
		return true;
}
bool solve1(Node* head) {
	stack<int> buf;
	Node* p = head;
	while (head->next != NULL) {
		buf.push(head->next->value);
		head = head->next;
	}
	while (p->next != NULL) {
		int value = buf.top();
		buf.pop();
		if (p->next->value != value) {
			return false;
		} 
		p = p->next;
	}
	return true;
}
bool solve2(Node* head) {
	Node* low = head;
	Node* fast = head;
	Node* mid = NULL;
	Node* next = NULL;
	Node* mid1 = NULL;
	bool parity = 1; // 链表长度的奇偶性 
	bool ret = false;
	if (head == NULL)
		return false;
	// 给parity 以及fast low 赋值 
	while (fast != NULL) {
		fast = fast->next;
		if (fast == NULL) {
			parity = 0;
			break;
		}
		low = low->next;
		fast = fast->next;
	}
	mid = low;  //  
	if (mid->next == NULL)
		return true;
	mid1 = parity ? mid : mid->next; // 记录中间位置的节点 
	next = mid1->next;
	mid->next = NULL;
	mid1->next = NULL;
	// 把链表以中间位置开始往后翻转 
	while (next != NULL) {
		Node* buf = mid1;
		mid1 = next;
		next = next->next;
		mid1->next = buf;
	}
	next = mid1;
	// 判断两个链表是否相等 
	while (head->next->next != NULL && mid1->next != NULL) {
		if (head->next->value != mid1->value)
			break;
		head = head->next;
		mid1 = mid1->next;
	}
	if (head->next->value == mid1->value)
		ret = true;
	mid1 = next->next;
	next->next = NULL;
	// 将两个链表恢复为一个链表 
	while (mid1 != NULL && mid1 != mid) {
		Node* buf = next;
		next = mid1;
		mid1 = mid1->next;
		next->next = buf;
	}
	mid->next = next;
	return ret;
}
void solve3(Node* head, int num) {
	/* 未解之谜*/
//	Node* p1 = head;
//	Node* p = head->next;
//	Node* left = head;
//	Node* mid = head;
//	Node* prehead = head;
//	while (p != NULL) {
//		if (p->value < num) {
//			Node* buf = left->next;
//			p = p->next;
//			if (prehead == left) {
//				mid = mid->next;
//			}
//			else{
//				left->next = prehead->next;
//				left->next->next = buf;				
//			}
//
//			left = left->next;
//			prehead->next = p;
//		}
//		else if (p->value == num) {
//			Node* buf = mid->next;
//			p = p->next;
//			if (prehead != left) {
//				mid->next = prehead->next;
//				mid->next->next = buf;
//			}
//			mid = mid->next;
//			prehead->next = p;
//		}
//		else {
//			p = p->next;
//			prehead = prehead->next;
//		}
//	}
	// 思路：将链表分为3部分最后把这3个部分串起来 
	Node* p = head; 
	Node* low1 = NULL,*low2;
	Node* mid1 = NULL,*mid2;
	Node* high1 = NULL,*high2;
	while (head->next != NULL) {
		if (head->next->value < num) {
			if (low1 == NULL) {
				low1 = head->next;
				low2 = head->next;
			}
			else {
				low2->next = head->next;
				low2 = low2->next;
			}
		}
		else if (head->next->value == num) {
			if (mid1 == NULL) {
				mid1 = head->next;
				mid2 = head->next;
			}
			else {
				mid2->next = head->next;
				mid2 = mid2->next;
			}
		}
		else {
			if (high1 == NULL) {
				high1 = head->next;
				high2 = head->next;
			}
			else {
				high2->next = head->next;
				high2 = high2->next;
			}
		}
		head = head->next;
	}
	high2->next = NULL;
	low2->next = NULL;
	mid2->next = NULL;
	if (mid1 != NULL)
		mid2->next = high1;	
	else 
		mid1 = high1;
	if (low1 != NULL)
		low2->next = mid1;
	else
		low1 = mid1;
	p->next = low1;
}













