#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
int a[100000][1000];
int main()
{
	int n,m;
    cin>>n>>m;
    a[0][0] = 1;
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (i>=j)
            {
                a[i][j]=a[i-j][j]+a[i-j][j-1];
            }
        }
    }
    printf("%llu",a[m][n]);
    return 0;
}