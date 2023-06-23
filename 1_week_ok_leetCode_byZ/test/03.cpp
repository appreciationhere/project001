#include <bits/stdc++.h>
using namespace std;

int getmaxIndex(vector<int>& nums, int l, int r);
int getminIndex(vector<int>& nums, int l, int r);
int partitionDisjoint(vector<int>& nums);

int main () {
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	int buf1[100] = {3,0,2,8,3,8,6};
	for (int i = 0; i < 6; i++) {
		v1.push_back(buf1[i]);
	}
	v1.erase(v1.begin(), v1.begin() + 2);
	for (int i = 0; i < v1.size(); ++i)
		cout<<v1[i];
	//cout<<partitionDisjoint(v1);
	return 0;
}

int partitionDisjoint(vector<int>& nums) {
        int ans = 0;
        int l = 0;
        int r = nums.size();
        int lmax = r, rmax = 0;
        while (l < r) {
            int mid = l + (r -l)/2;
            //if (lmax >= mid)
                lmax = getmaxIndex(nums, l, mid);
            //if (rmax < mid)
                rmax = getminIndex(nums, mid, r);
            if (nums[lmax] <= nums[rmax]) {
                ans = mid + 1;
                r = mid;
            } else 
                l = mid;
        }
        return ans;
    }
int getmaxIndex(vector<int>& nums, int l, int r) {
        int res = l;
        for (int i = l + 1; i < r; i++)
            res = nums[i] > nums[res] ? i : res;
        return res;
}
int getminIndex(vector<int>& nums, int l, int r) {
        int res = l;
        for (int i = l + 1; i < r; i++)
            res = nums[i] < nums[res] ? i : res;
        return res;
}
