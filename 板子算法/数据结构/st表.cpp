#include <iostream>
using namespace std;
const int N = 2e5+10 ; 
typedef long long LL ; 
int n ; 
int a[N] ;
int f[N][20]  ;
int lg[N] ; 

void init()
{
	lg[1]=0;
	for(int r=2;r<=n;r++)
	{
		lg[r]=lg[r>>1]+1;//预处理log2(r)下取整的值
	}
    // 数组下标从1开始
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = a[i];
    }
    
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
        }
    }
}

int query(int l, int r)
{
    int k = lg[r-l+1] ;
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main()
{
	return  0  ;
}

