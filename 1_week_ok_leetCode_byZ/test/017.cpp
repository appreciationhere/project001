#include <bits/stdc++.h>
using namespace std;

long long dp[11][2023];
int main()
{
  // 请在此输入您的代码
  	int n, m, ans = 0;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	dp[0][0] = 1;
	for (int i = 1; i <= m; ++i) {
        for (int k = n; k >= 1; --k) {
            for (int j = i; j <= m; ++j) {
//            	dp[k][i][j] += dp[k][i - 1][j];
//            	if (j - i > 0)
           	    	dp[k][j] += dp[k - 1][j - i];
			}
		}
    }
    cout<<dp[n][m];
	return 0;
}