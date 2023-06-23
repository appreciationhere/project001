#include <bits/stdc++.h>
using namespace std;

int match1(string &s); // 如果s是由'('和')'构成的, 问最少补多少个括号才能使得'(',')'两两配对;
int main() {

	return 0;
}
int match1(string &s) {
	int n = s.size();
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(')
			++cnt;
		else {
			if (cnt == 0)
				++ans;
			else
				--cnt;
		}
	}
	return ans + cnt;
}