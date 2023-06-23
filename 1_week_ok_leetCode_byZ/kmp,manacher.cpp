#include <bits/stdc++.h>
using namespace std;
int getIndexOf(string &s1, string &s2); // kmp
int manacher(string &s);                // manacher
vector<int> getNextArray(string &s2);
int main(){
	string a = "babad";
	cout<<manacher(a);
    return 0;
}
vector<int> getNextArray(string &s2) {
	int n = s2.size(), i = 2, j = 0;
	if (n == 0)
		return {};
	vector<int> next(n);
	next[0] = -1, next[1] = 0;
	while (i < n) {
		if (s2[i - 1] == s2[j])
			next[i++] = ++j;
		else if (j > 0)
			j = next[j];
		else
			next[i++] = 0;
	}
	return next;
}
int getIndexOf(string &s1, string &s2) {
	int i1 = 0, i2 = 0, n1 = s1.size(), n2 = s2.size();
	if (n2 > n1 || n2 == 0)
		return n1;
	vector<int> next = getNextArray(s2);
	while (i1 < n1 && i2 < n2) {
		if (s1[i1] == s2[i2])
			++i1, ++i2;
		else if (i2 == 0) {
			++i1;
		} else
			i2 = next[i2];
	}
	return i2 == n2 ? i1 - i2 : n1;
}
int manacher(string &s1) {
	if (s1.empty())
		return 0;
	string s("#");
	for (auto c : s1) {
		s.push_back(c);
		s.push_back('#');
	}
	int R = -1, C = -1, ans = INT_MIN;
	int n = s.size();
	vector<int> pArr(n);
	for (int i = 0; i < n; ++i) {
		pArr[i] = R > i ? min(R - i, pArr[2 * C - i]) : 1;
		while (i - pArr[i] >= 0 && i + pArr[i] < n && s[i - pArr[i]] == s[i + pArr[i]])
			++pArr[i];
		if (i + pArr[i] > R) {
			R = i + pArr[i];
			C = i;
		}
		ans = max(ans, pArr[i]);
	}
	return ans - 1;
}






















