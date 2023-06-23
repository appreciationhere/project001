#include <bits/stdc++.h>
using namespace std;
typedef struct {
    unsigned long x;
    unsigned long y;
    int r;
}num;
typedef long long u32;
typedef unsigned char u8;
const u32 mod = 1e6 + 7;
void dfs(num p, unsigned long x, unsigned long y, vector<vector<int>>& dp, vector<num>& nums1);
stack<num> sta1;
map<pair<u32,u32>, u32> se1;
unsigned int ans = 0;
//num nums1[mod];
u32 hs[mod] = {0};
int id[mod]={0};
bool vis[mod]={0};
u32 hash_val(int x,int y)    //将二维坐标转换为一个hash值
{
    return u32((1e9 + 1ll)*x+y);
}
int hash_key(int x,int y)
{
    u32 val=hash_val(x,y);
    int key=(val%mod+mod)%mod;
    while(hs[key]!=-1&&hs[key]!=val)    //此处需要hs[key]!=key,因为后面需要查找用到二维坐标，
    {                                   //返回一个key值
       key++;
        if(key == mod) key = 0;  //防止出现负值
    }
    return key;
}
int main()
{
    int n,m;
    memset(hs,-1,sizeof(hs));
    cin>>n>>m;
    vector<num> nums1(n + 1);
    vector<num> nums2(m);
   for (int i = 1; i <= n; ++i) {
        cin>>nums1[i].x;
        cin>>nums1[i].y;
        cin>>nums1[i].r;
        auto key=hash_key(nums1[i].x, nums1[i].y);
        if(hs[key]==-1) //这一个if语句需不需要都行
            hs[key]=hash_val(nums1[i].x,nums1[i].y);
        if(!id[key] || nums1[i].r > nums1[id[key]].r)//如果id[key]第一次被使用，或者此点的半径比之前的大，
            id[key]=i; 
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
        for (int i = -p.r; i <= p.r; ++i) {
        	for (int j = -p.r; j <= p.r; ++j) {
        		if (i + p.x >= 0 && j + p.y >= 0 && i * i + j * j <= p.r * p.r ) {
                    u32 key = hash_key(i + p.x ,j + p.y);
                    if (id[key] && !vis[id[key]]) {
                        int pos = id[key];//如果这个点处的炸弹没被拆除掉
                        sta1.push(nums1[pos]);
                        vis[pos]=1;
                    	++ans;
                    }
				}
			}
		}
      }
     cout<<ans;
      return 0;
}