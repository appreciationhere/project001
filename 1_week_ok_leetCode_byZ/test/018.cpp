#include <bits/stdc++.h>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int n, m, x, l, r, pre = 0;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m>>x;
  unordered_map<long long, int> ma1;
  vector<int> nums(n);
  vector<int> dp(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
  	cin>>nums[i];
    int t = x ^ nums[i];
    if (ma1.count(t)) {
      int buf = ma1[t];
      for (int j = buf; j >= pre; --j) {
      	    dp[j] = i;
      	    ma1.erase(nums[j]);
	  }
      pre = buf + 1;
    }
    ma1[nums[i]] = i;
  }
  for (int i = 0; i < m; ++i) {
    cin>>l>>r;
    if (dp[l] > l && dp[l] <= r)
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;
  }
  return 0;
}