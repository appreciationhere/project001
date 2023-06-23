#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
/**
*solve1() : 桶排序 
*solve2() : 插入排序 
*/
void solve2(int* L, int n);
void solve1(int* L, int n);
int Buf[10] = {0};
int temp[100] = {0};
int main() {
	int L[] = {999,31,72,2,5,1,22,3,4,71,0,11,-123,-11,0};
	solve2(L, sizeof(L)/sizeof(int));
	for (int i = 0; i < sizeof(L)/sizeof(int); i++) {
		cout<<L[i]<<" ";
	}
}
void solve1(int* L, int n) {
	int loop = 1; //  最大的数的位数 
	// 给loop赋值 
	for (int i = 0; i < n; i++) {
		int j = 1;
		int t = L[i];
		while (t/=10) 
			j++;
		if (loop < j)
			loop = j;
	}
	for (int i = 0; i < loop; i++) {
		// 得到这一次循环的数出现的次数放入buf中 
		for (int j = 0; j < n; j++) {
			int t = L[j];
			for (int k = 0; k < i; k++)
				t/=10;
			for (int l = t % 10; l < 10; l++)
				Buf[l] += 1;
		}
		// 为了排序的稳定性应该逆序放入桶中 
		for (int m = n - 1; m >= 0; m--) {
			int t = L[m];
			for (int k = 0; k < i; k++)
				t/=10;
			temp[Buf[t%10] - 1] = L[m];
			Buf[t%10]--;
		}
		// 把新的排序结果赋值给L 进行下一轮排序 
		for (int k = 0; k < n; k++)
			L[k] = temp[k];
		memset(Buf,0,10*4);
	}
}
void solve2(int* L, int n) {
	for (int i = 1; i < n; i++) {
		int t = L[i];
		for (int j = i - 1; j >=0 && L[j] > t; j--) {
			L[j + 1] = L[j];
			L[j] = t;
		}
	}
}















