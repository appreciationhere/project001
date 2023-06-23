#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct P {
	ll val;
	ll cnt;
};
struct P1 {
	ll l,r;
};
P nums[500002];
P1 nums1[500002];
struct P2 {
	ll id;
	ll val;
	bool operator>(const P2& a) const {
		return val == a.val ? id > a.id : val > a.val;
	}
};
priority_queue<P2, vector<P2>, greater<P2>> que1;
ll n,k;
int main() {
	cin>>n>>k;
	ll r1 = n + 1;
	for (ll i = 1; i <= n; ++i) {
		cin>>nums[i].val;
		P2 p2;
		p2.id = i;
		p2.val = nums[i].val;
		nums1[i].l = 1;
		nums1[i].r = 1;
		que1.push(p2);
	}
	for (ll i = 1; i <= k; ++i) {
		while (nums[que1.top().id].cnt != 0) {
			--nums[que1.top().id].cnt;
			que1.pop();
		}
		ll id = que1.top().id;
		ll val = nums[id].val;
		ll l1 = id - nums1[id].l, r1 = id + nums1[id].r;
		nums[id].cnt = -1;
		que1.pop();
		nums[l1].val += val, ++nums[l1].cnt;
		nums[r1].val += val, ++nums[r1].cnt;
		nums1[id + nums1[id].r].l = nums1[id].l + nums1[id].r;
		nums1[id - nums1[id].l].r = nums1[id].l + nums1[id].r;
		que1.push({l1, nums[l1].val});
		que1.push({r1, nums[r1].val});
	}
	for (ll i = 1; i <= n; ++i) {
		if (nums[i].cnt != - 1)
			cout<<nums[i].val<<" ";
	}
    return 0;
}



