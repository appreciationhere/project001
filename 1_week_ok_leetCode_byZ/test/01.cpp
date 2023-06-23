#include <bits/stdc++.h>
using namespace std;

int findTargetSumWays(vector<int>& nums, int target);
int sx,sy,ex,ey;
int main(){
	int buf[2] = {1,1};
	vector<int> nums;
	for (int i = 0; i < sizeof(buf) / 4; i++)
		nums.push_back(buf[i]);
	cout<<findTargetSumWays(nums, 0);
    return 0;
}
int findTargetSumWays(vector<int>& nums, int target) {
        map<int, int> dp;
        map<int, int> dp1;
        dp[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (map<int, int>:: iterator ite = dp.begin(); ite != dp.end(); ++ite) {
                int buf1 = (*ite).first;
                if(dp1.count(buf1 + nums[i])) 
                    dp1[buf1 + nums[i]]++;
                else {
                    if (dp.count(buf1 + nums[i]))
                        dp1[buf1 + nums[i]] = dp[buf1 + nums[i]];
                    else
                        dp1[buf1 + nums[i]] = 1;
                }
                if(dp1.count(buf1 - nums[i])) 
                    dp1[buf1 - nums[i]]++;
                else {
                    if (dp.count(buf1 - nums[i]))
                        dp1[buf1 - nums[i]] = dp[buf1 - nums[i]];
                    else
                        dp1[buf1 - nums[i]] = 1;
                }
            }
            dp = dp1;
            dp1.clear();
        }
        return dp.count(target) ? dp[target] : 0;
    }































