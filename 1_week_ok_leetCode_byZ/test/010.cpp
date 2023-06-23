/*
map<int, map<int, unordered_map<int, int>>> mp, 按<x, <y, <r, count>>> 存雷。 mp[x][y][r]：(x, y) 点爆炸半径为 r 有几颗雷。

res 存结果，可以引爆几颗
读入扫雷火箭 x, y, r。放入队列q中。
每次在队列取出第一个(x, y, r), 找可以被引爆的其他雷
找在(x-r, x+r), (y-r,y+r) 方形区域内的雷，剪枝操作。
xiter = mp.lower_bound(x - r), 二分查找 第一个不小于 x-r 的横坐标
xed = mp.upper_bound(x + r), 二分查找 第一个大于 x+r 的横坐标
横坐标范围: [xiter->first, xed->first)
横坐标确定后找满足条件的纵坐标
yiter = xiter->second.lower_bound(y - r)
yed = xiter->second.upper_bound(y + r)
xiter->second 也就是 mp[x]
纵坐标范围: [yiter->first, yed->first)
判断炸弹(xiter->first, yiter->first)是否在引爆范围，如果在：
yiter->second也就是mp[x][y], 得到key为半径r, value为炸弹个数的unordered_map<int, int>
遍历以该点为圆心的炸弹for(const auto& bm:yiter->second)
res += bm->second也就是当前雷的个数，
将雷(xiter->first, yiter->first, bm->first)放入队列
删除该点的雷：
先清空纵坐标, map[x].erase(y)，yiter = xiter->second.erase(yiter)。
如果mp[x]全处理完后也为空，mp.erase(x), xiter = mp.erase(xiter);
重复此过程，直到队列为空。 读入下一个扫雷火箭，直到所有火箭处理完。
*/
#include <bits/stdc++.h>
using namespace std;
typedef struct {
	unsigned long x;
	unsigned long y;
	int r;
}num;
typedef unsigned long u32;
typedef unsigned char u8;
map<u32, map<u32, unordered_map<u8, u8>>> se1;  // 存储地雷的x,y,r
const u32 mod = 1e6 + 7;
stack<num> sta1;   // 深度遍历炸雷
u32 ans = 0;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<num> nums2(m);
   for (int i = 0; i < n; ++i) {
   		u32 x,y,r;
		cin>>x;
		cin>>y;
		cin>>r;
		se1[x][y][r]++;  // 记录x,y,r地雷的个数
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
		// 二分法先找出当前炸雷的 x - r, x + r范围内的剩余炸雷, 找到后在此基础上再二分法找y -r , y + r的炸雷
		for (auto xiter = se1.lower_bound(p.x > p.r ? p.x - p.r : 0), xed = se1.upper_bound(p.x + p.r); xiter != xed;) {
			for (auto yiter = xiter->second.lower_bound(p.y > p.r ? p.y - p.r : 0), yed = xiter->second.upper_bound(p.y + p.r); yiter != yed;) {
				// 如果在半径范围内
				if (pow(abs((long long)(xiter->first - p.x)), 2) + pow(abs((long long)(yiter->first - p.y)), 2) <= p.r * p.r) {
					for (auto& buf : yiter->second) {
						ans += buf.second;
						sta1.push({xiter->first, yiter->first, buf.first});
					}
					yiter = xiter->second.erase(yiter);
				} else
					++yiter;
			}
			if (xiter->second.empty())
				xiter = se1.erase(xiter);
			else
				++xiter;
		}
  	}
 	cout<<ans;
  	return 0;
}





