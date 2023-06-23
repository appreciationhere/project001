#include<iostream>
using namespace std;
/**
*solve1() : 利用归并求逆序对 
*solve2() : 荷兰国旗问题 
*/
int temp[100]; // 
int solve1(int* L, int left, int right); 
int merge(int* L, int left, int mid, int right);
void solve2(int* L, int start, int end, int num);
int main() {
	
	return 0;
}
int solve1(int* L, int left, int right) {
	if (left >= right)
		return 0;
	int mid = left + (right - left >> 1);
	return solve1(L, mid + 1, right) + solve1(L, left, mid) + merge(L, left, mid, right);
}
int merge(int* L, int start, int mid, int end) {
	int sum = 0;
	int t = mid;
	int num = start;
	int s = start;
	mid ++;
	while (start <= t && mid <= end) {
		if (L[start] > L[mid]) {
			temp[num++] = L[start++];
			sum += t - start + 1;
		}
		else
			temp[num++] = L[mid++];
	}
	if (start > t)
		while (mid <= end)
			temp[num++] = L[mid++];
	else
		while (start <= t)
			temp[num++] = L[start++];	
	while (s <= end)	
		L[s] = temp[s++];	
	return sum;
}
void solve2(int* L, int start, int end, int num) {
	int left = start; // 左边小于的下标 
	int right = end;  // 右边 大于的下标 
	while (start <= right) {
		if (L[start] < num) {
			int t = L[left];
			L[left++] = L[start];
			L[start++] = t;
		}
		else if (L[start] == num) {
			start++;
		}
		else {
			int t = L[right];
			L[right--] = L[start];
			L[start] = t;
		}
	}
}







