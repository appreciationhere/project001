#include <bits/stdc++.h>
using namespace std;
typedef unsigned long u32;
typedef unsigned char u8;
int main() {
	map<pair<u32, u32>, u8> mp;
	mp[{1,1}] = 1;
	mp[{2,1}] = 2;
	mp[{2,9}] = 3;
	mp[{2,10}] = 4;
	mp[{2,11}] = 5;
	mp[{5,11}] = 6;
	mp[{6,9}] = 8;
	mp[{6,10}] = 9;
	mp[{6,11}] = 7;
	for (auto xiter = mp.lower_bound(make_pair(1,2)), xed = mp.upper_bound(make_pair(6, 10)); xiter != xed;xiter++) {
		u8 j = xiter->second;
		printf("%d ",j);
	}
	cout<<1;
	return 0;
}