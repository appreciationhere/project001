#include <stdio.h>

int temp[100]; 
void quicksort(int*,int,int); //快排
int partition(int*,int,int); // 快排的中心值选择 

void adjust(int*,int,int);//堆排序的局部排序 
void heap_sort(int*,int); // 推排序

void merge_sort(int*,int,int);//归并排序
void msort(int* L, int start, int mid, int end); 
int main() {
	int a[10] = {0,8,3,2,4,6,1,5,7,9,10};
	heap_sort(a, 10);
	for (int i = 0; i < 10; i++)
		printf("%d ",a[i]);
	return 0;
}
void quicksort(int* L,int low,int high) {
	int t;
	if (low < high) {
		t = partition(L, low, high);
		quicksort(L, low, t - 1);
		quicksort(L, t + 1, high);
	}
}
int partition(int* L,int low,int high) {
	L[0] = L[low];
	while (low < high) {
		while (low < high && L[high] > L[0])
			high--;
		L[low] = L[high];
		while (low < high && L[low] < L[0])
			low++;
		L[high] = L[low];	
	}
	L[low] = L[0];
	return low;
}
void adjust(int* L,int s,int lenth) {
	int re = L[s];
	for (int i = 2 * s; i <= lenth; i *= 2) {
		if ( i < lenth && L[i + 1] < L[i]) 
			i++;
		if (re < L[i])
			break;
		L[s] = L[i];
		s = i;
	}
	L[s] = re;
}
void heap_sort(int* L,int n) {
	for (int i = n / 2; i >= 1; i--) {
		adjust(L, i, n);
	}
	for (int i = n - 1; i > 0; i--) {
		int t;
		t = L[i];
		L[i] = L[1];
		L[1] = t;
		adjust(L, 1, i - 1);
	}
}
void merge_sort(int* L,int start,int end) {
	if (start >= end)
		return;
	int mid = (start + end) / 2;
	merge_sort(L, start, mid);
	merge_sort(L, mid + 1, end);
	/*归并排序 */ 
	msort(L, start, mid, end);
}
void msort(int* L, int start, int mid, int end) {
	int t = mid;
	int num = start;
	int s = start;
	mid ++;
	while (start <= t && mid <= end) {
		if (L[start] < L[mid])
			temp[num++] = L[start++];
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
}






