#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
string reverse(string& s);
int main() {
	
				
   string s0 = "{G0001#000P1540T2000!#001P2206T2000!#002P0604T2000!#003P1405T2000!#004P1660T2000!#005P1535T2000!}";
   string s1 = "{G0002#000P1420T2000!#001P2206T2000!#002P0675T2000!#003P1303T2000!#004P1802T2000!#005P1543T2000!}";
   string s2 = "{G0003#000P0550T2000!#001P2240T2000!#002P0784T2000!#003P1154T2000!#004P1731T2000!#005P1563T2000!}";
   string s3 = "{G0004#000P0550T2000!#001P1456T2000!#002P1045T2000!#003P2000T2000!#004P0835T2000!#005P1452T2000!}";
   string s4 = "{G0005#000P1500T2000!#001P1456T2000!#002P1045T2000!#003P2000T2000!#004P0835T2000!#005P1452T2000!}";
   string s5 = "{G0006#000P1580T2000!#001P1456T2000!#002P1045T2000!#003P2000T2000!#004P0835T2000!#005P1452T2000!}";
   string s6 = "{G0007#000P1500T2000!#001P1500T2000!#002P1925T2000!#003P2304T2000!#004P1932T2000!#005P1484T2000!}";
	                                                                                                                                                                                                                                    
	string s11 = reverse(s6);
	printf("size = %d\n", s11.size());
	for (auto &c : s11)
	printf("%x_", c);
	return 0;
}
string reverse(string& s) {
	int n = s.size();
	string s0;
	for (int i = n - 1, j = 0; i >= 0; --i) {
		s0.push_back(s[i]);
	}
	return s0;
}