#include <bits/stdc++.h>
using namespace std;

vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load);
int main () {
	vector<int> nums1;
	vector<int> nums2;
	int buf1[] = {1,2,3,4,5};
	int buf2[] = {5,2,3,3,3};
	for (int i = 0; i < sizeof(buf1) / 4; i++)
		nums1.push_back(buf1[i]);
	for (int i = 0; i < sizeof(buf2) / 4; i++)
		nums2.push_back(buf2[i]);
	vector<int> ans = busiestServers(3,nums1,nums2);
	for (int i = 0; i < ans.size(); i++)
		cout<<ans[i]<<" ";	
	return 0;
} 
vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    int max1 = 0;
    vector<int> ans;
    set<int> se1;
    priority_queue< pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > prique;
    vector<int> buf(k, 0);
    for (int i = 0; i < k; i++)
        se1.insert(i);
    for (int i = 0; i < arrival.size(); i++) {
        while (!prique.empty() && prique.top().first <= arrival[i]) {
            se1.insert(prique.top().second);
            prique.pop();
        }
        if (se1.empty())
            continue;
        set<int>::iterator p = se1.lower_bound(i % k);
        if (p == se1.end())
            p = se1.begin();
        buf[*p] ++;
        se1.erase(p);
        prique.push(make_pair(arrival[i] + load[i], *p));
    }
    for (int i = 0; i < k; i++) {
        if (buf[i] > max1)
            max1 = buf[i];
    }
    for (int i = 0; i < k; i++) {
        if (buf[i] == max1)
            ans.push_back(max1);
    } 
    return ans;
}









