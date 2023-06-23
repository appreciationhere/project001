#include<bits/stdc++.h>
using namespace std;

bool is2power(int num); // 是否是2的幂
bool is4power(int num); // 是否是4的幂
bool isNeg(int a);      // 是否是负数
int add(int a, int b);  // + 根据^是不进相加, &是进位的相加
int negnum(int a);      // 正负颠倒
int minus1(int a, int b); // -
int multip(int a, int b); // * 根据乘法运算法则
int div1(int a, int b);  // /  根据乘法运算法则的逆运算
int main() {

	return 0;
}
bool is2power(int num) {
    return (num & (num - 1)) == 0;
}
bool is4power(int num) {
    return (num & (num - 1)) == 0 && (num & 0x55555555);
}
int add(int a, int b) {
	int sum = a;
	while (b != 0) {
		sum = a ^ b;
		b = (a & b) << 1;
		a = sum;
	}
	return sum;
}
int negnum(int a) {
	return add(~a, 1);
}
int minus1(int a, int b) {
	b = negnum(b);
	return add(a, b);
}
int multip(int a, int b) {
	unsigned int b1 = b;
	int res = 0;
	while (b1 != 0) {
		if (b1 & 1) {
			res = add(res, a);
		}
		a <<= 1;
		b1 >>= 1;
	}
	return res;
}
int div1(int a, int b) {
	int a1 = isNeg(a) ? negnum(a) : a;
	int b1 = isNeg(b) ? negnum(b) : b;
	int res = 0;
	for (int i = 31; i >= 0; --i) {
		if ((a1 >> i) >= b1) {
			res |= (1 << i);
			a1 = minus1(a1, b1 << i);
		}
	}
	return isNeg(a) ^ isNeg(b) ? negnum(res) : res;
}
bool isNeg(int a) {
	return a & 1 << 31;
}






