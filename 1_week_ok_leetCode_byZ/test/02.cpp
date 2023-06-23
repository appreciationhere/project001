#include <bits/stdc++.h>
using namespace std;
string s;
int dp[9];
int atMostNGivenDigitSet(vector<string>& digits, int n) {
    for (int n1 = n; n1 > 0; n1 /= 10) {
        s.insert(s.begin(), n1 % 10);
    }
    vector<int> nums;
    for (int i = 0; i < digits.size(); ++i) {
        nums.push_back(digits[i][0] - '0');
    }
    memset(dp, 0, sizeof(dp));
    return dfs(nums, 0, 1);
}
int dfs (vector<int>& nums, int i, int limit) {
    if (i == s.size())
        return 1;
    if (!limit && dp[i])
        return dp[i];
    int res = 0;
    int up = limit ? getindex(nums, i) : nums.size() - 1;
    for (int j = 0; j <= up; ++j) {
        res += dfs(nums, i + 1, limit && (nums[j] == s[i] - '0'));
    }
    if (!limit)
        dp[i] = res;
    return res;
}
int getindex(vector<int>& nums, int j) {
    int i;
    int s1 = s[j] - '0';
    for (i = 0; i < nums.size(); ++i) {
        if (nums[i] > s1)
            return i - 1;
    }
    return i - 1;
}

int main () {
	string p1;
	vector<int> buf;
	cin>>p1;
	while (p1 != "-1") {
		buf.push_back(p1[0] - '0');
		cin>>p1;
	}
	for (int i = 0; i < buf.size(); i++) {
		string *p = new string[2188];
		maxConsecutiveAnswers(buf[i], p);
		for (int j = 1; j <= pow(3, buf[i] - 1); j ++)
			cout<<p[j]<<endl;
		cout<<"-"<<endl;
		delete []p;		
	}

	return 0;
}






