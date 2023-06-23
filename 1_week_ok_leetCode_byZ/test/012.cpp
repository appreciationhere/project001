#include <bits/stdc++.h>
using namespace std;
typedef struct {
    unsigned long x;
    unsigned long y;
    int r;
}num;
void dfs(num p, unsigned long x, unsigned long y, vector<vector<int>>& dp, vector<num>& nums1);
unordered_map<unsigned long, unordered_map<unsigned long, int>> se1;
stack<num> sta1;
unsigned int ans = 0;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<num> nums2(m);
    vector<num> nums1(n);
   for (int i = 0; i < n; ++i) {
        cin>>nums1[i].x;
        cin>>nums1[i].y;
        cin>>nums1[i].r;
        se1[nums1[i].x][nums1[i].y] = i + 1;
    }
   for (int i = 0; i < m; ++i) {
        cin>>nums2[i].x;
        cin>>nums2[i].y;
        cin>>nums2[i].r;
        sta1.push(nums2[i]);
    }
      while (!sta1.empty()) {
        num p = sta1.top();
        sta1.pop();
        vector<vector<int>> dp(21, vector<int>(21, 0));
        
      }
     cout<<ans;
      return 0;
}
void dfs(num p, unsigned long x, unsigned long y, vector<vector<int>>& dp, vector<num>& nums1) {
    if (abs((long long)(x - p.x)) > p.r  || abs((long long)(y - p.y)) > p.r || dp[p.x + 10 - x][p.y + 10 -y])
        return;
    dp[p.x + 10 - x][p.y + 10 -y] = 1;
    if (pow(abs((long long)(x - p.x)), 2) + pow(abs((long long)(y - p.y)), 2) <= p.r * p.r && se1[x][y]) {
        sta1.push(nums1[se1[x][y] - 1]);
        se1[x].erase(y);
        ++ans;
    }
    dfs(p, x + 1, y, dp, nums1);
    dfs(p, x, y + 1, dp, nums1);
    dfs(p, x - 1, y, dp, nums1);
    dfs(p, x, y - 1, dp, nums1);
}