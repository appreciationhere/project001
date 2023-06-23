#include <bits/stdc++.h>
using namespace std;
/*

小蓝面前有 N 件物品, 其中第 i件重量是 W[i] , 价值是 m。她还有一个背包, 最大承重是 M 。小蓝想知道在背包称重范围内, 她最多能装总价值多少的物品?

特别值得一提的是, 小蓝可以使用一个魔法 (总共使用一次), 将一件物品 的重量增加 
 
K, 同时价值双倍。(当然小蓝也可以不使用魔法)
*/
int w[2000];
int v[2000];
int dp[2][10001];
int main(){
	int n,m,k;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for (int i = 0; i < n; ++i)
		cin>>w[i]>>v[i];
	for (int i = 0; i < n; ++i) {
		for (int j = m; j >= 0; --j) {
			int buf = w[i] + k;
			if (j - w[i] >= 0){
				dp[1][j] = max(dp[1][j], dp[1][j - w[i]] + v[i]);
				if (j - buf >= 0)
					dp[1][j] = max(dp[0][j - buf] + 2 * v[i], dp[1][j]);
			} else                                     
				break;
			//cout<<dp[1][j]<<" ";
		}
		for (int j = m; j >= 0; --j) {
			if (j - w[i] >= 0) {
				dp[0][j] = max(dp[0][j], dp[0][j - w[i]] + v[i]);
			} else
				break;
			//cout<<dp[0][j]<<" ";
		}
		//cout<<endl;
	}
	cout<<max(dp[0][m], dp[1][m]);
    return 0;
}
