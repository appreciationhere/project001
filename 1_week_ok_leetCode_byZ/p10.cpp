#include <iostream>
#include <string>
using namespace std;
/**
*  solve1 : ��ӡ�ַ��������ַ���
*  solve2 : �ַ�����ȫ���� 
*/
void solve1(string, int); 
void solve2(string); 
int main() {
	solve1("abc", 0);
	return 0;
}
void solve1(string a, int i) {
	if (i == a.length()) {
		cout<<a<<endl;
		return;
	}
	solve1(a, i + 1);
	char tem = a[i];
	a[i] = 0;
	solve1(a, i + 1);
	a[i] = tem;
}
