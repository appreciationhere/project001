#include <bits/stdc++.h>
using namespace std;
int main()
{
  // 请在此输入您的代码
  long long n;
  cin>>n;
  vector<unsigned long> dp(n + 1, 0);
  vector<unsigned long> dp1(n + 1, 0);  // 前缀和
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 5;
  dp[4] = 11;
  dp1[4] = dp[1] + dp[0];
  for (int i = 5; i <= n; ++i) {
    long  buf = 0;
    dp1[i] = (dp1[i - 1] + dp[i - 3]) % 1000000007;
    dp[i] = (dp[i - 1] + dp[i - 2] + 2 * dp1[i]) % 1000000007;
  }
  cout<<dp[n];
  return 0;
}