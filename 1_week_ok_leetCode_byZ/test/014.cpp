#include <bits/stdc++.h>
using namespace std;
class P{
public: 
	void display() const {
		cout<<"const"<<endl;
	};
	void display() {
		cout<<"unconst"<<endl;
	};
	P(float i, string s): i1(i), s1(s) {
		cout<<"unconst creat"<<endl;
	}
	void f(float pos) {
		//cout<<P::pos;
	}
	static void f1(int i);
	const static int pos = 10;
	float i1;
	string s1;
};
void P::f1(int i) {
		cout<<i;
}
int main() {
	cout<<string::npos;
	return 0;
}