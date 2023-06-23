#include <bits/stdc++.h>
using namespace std;
struct Node {
	int val;
	Node *left;
	Node *right;
};
void morris(Node *head); //morris遍历
void morris1(Node *head); //morris遍历先序
void morris2(Node *head); //morris遍历中序
void morris3(Node *head); //morris遍历后序
Node* reverse1(Node *head); // 反转链表
int main () {
	
	return 0;
}
void morris(Node *head) {
	if (head == NULL)
		return;
	Node *cur = head;
	Node *mRight = NULL;
	while (cur != NULL) {
		mRight = cur->left;
		if (mRight != NULL) {
			while (mRight->right != NULL && mRight->right != cur)
				mRight = mRight->right;
			if (mRight->right == NULL) {
				mRight->right = cur;
				cur = cur->left;
				continue;
			} else {
				mRight->right  = NULL;
			}
		}
		cur = cur->right;
	}
}
void morris1(Node *head) {
	if (head == NULL)
		return;
	Node *cur = head;
	Node *mRight = NULL;
	while (cur != NULL) {
		mRight = cur->left;
		if (mRight != NULL) {
			while (mRight->right != NULL && mRight->right != cur)
				mRight = mRight->right;
			if (mRight->right == NULL) {
				cout<<cur->val;
				mRight->right = cur;
				cur = cur->left;
				continue;
			} else {
				mRight->right  = NULL;
			}
		} else {
			cout<<cur->val;
		}
		cur = cur->right;
	}
}
void morris2(Node *head) {
	if (head == NULL)
		return;
	Node *cur = head;
	Node *mRight = NULL;
	while (cur != NULL) {
		mRight = cur->left;
		if (mRight != NULL) {
			while (mRight->right != NULL && mRight->right != cur)
				mRight = mRight->right;
			if (mRight->right == NULL) {
				mRight->right = cur;
				cur = cur->left;
				continue;
			} else {
				cout<<cur->val;
				mRight->right  = NULL;
			}
		} else {
			cout<<cur->val;
		}
		cur = cur->right;
	}
}
void morris3(Node *head) {
	if (head == NULL)
		return;
	Node *cur = head;
	Node *mRight = NULL;
	while (cur != NULL) {
		mRight = cur->left;
		if (mRight != NULL) {
			while (mRight->right != NULL && mRight->right != cur)
				mRight = mRight->right;
			if (mRight->right == NULL) {
				mRight->right = cur;
				cur = cur->left;
				continue;
			} else {
				cout<<cur->val;
				mRight->right  = NULL;
			}
		}
		Node *p = reverse1(cur->left);
		while (p != NULL) {
			cout<<p->val;
			p = p->right;
		}
		reverse1(p);
		cur = cur->right;
	}
	Node *p = reverse1(head);
	while (p != NULL) {
		cout<<p->val;
		p = p->right;
	}
	reverse1(p);
}
Node* reverse1(Node *head) {
	if (head == NULL)
		return head;
	Node* pre = head->right;
	Node* cur = head;
	cur->right = NULL;
	while (pre != NULL) {
		Node *buf = pre;
		pre = pre->right;
		buf->right = cur;
		cur = buf;
	}
	return cur;
}



