// 李白打酒加强版
#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<vector<int>>> dp(101, vector<vector<int>>(101, vector<int>(101, 0)));
unsigned long dfs(int i, int j, int n);
unsigned long mod = 1e9 + 7;
int main() {
    cin>>n>>m;
    dp[0][0][2] = 1;
    cout<<dfs(n, m - 1, 1);
    return 0;
}
unsigned long dfs(int n1, int m1, int w) {
    unsigned int res = 0;
    if (w < 0 || w > m)
    	return 0;
    if (w % 2 == 0) {
    	if (m1 > 0) {
    		dp[n1][m1 - 1][w + 1] += dfs(n1, m1 - 1, w + 1);
    		res = (res + dp[n1][m1 - 1][w + 1]) % mod;
		}
    	if (n1 > 0) {
    		dp[n1 - 1][m1][w / 2] += dfs(n1 - 1, m1, w / 2);
    		res = (dp[n1 - 1][m1][w / 2] + res) % mod;
		}
    } else {
    	if (m1 > 0) {
	    	dp[n1][m1 - 1][w + 1] += dfs(n1, m1 - 1, w + 1);
	     	res = (res + dp[n1][m1 - 1][w - 1]) % mod;	
		}
    }
    if (n1 > 0 && m1 > 0)
    	dp[n1][m1][w] = res;
    return dp[n1][m1][w];
}










