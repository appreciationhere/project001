#include <bits/stdc++.h>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int n,m,k;
  int ans = 0;
  cin>>m>>n>>k;
  vector<vector<unsigned int>> v1(m + 1, vector<unsigned int>(n + 1, 0));
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      int p;
      cin>>p;
      v1[i][j] = v1[i - 1][j] + v1[i][j - 1] - v1[i - 1][j - 1] + p;
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
    	int up = 1;
    	int left = 1;
    	for (int i1 = i; i1 >= up; --i1) {
    		for (int j1 = j; j1 >= left; --j1) {
    			int now = v1[i][j] + v1[i1 - 1][j1 - 1] - v1[i][j1 - 1] - v1[i1 - 1][j];
    			if (now <= k)
    				++ans;
    			else {
    				left = j1 + 1;
				}
			}
		}
    }
  }
  cout<<ans;
  return 0;
}