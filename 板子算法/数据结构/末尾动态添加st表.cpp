// Problem: E2. Doremy's Drying Plan (Hard Version)
// Contest: Codeforces - Codeforces Round 906 (Div. 2)
// URL: https://codeforces.com/contest/1890/problem/E2
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <cstdio>
#include <unordered_map>
#include <deque>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <bitset>
#include <limits.h>
#define x first
#define y second
 
using namespace std;
typedef  long long LL;
typedef long long ll  ; 
typedef pair<int,int> PII;
typedef pair<int,LL> PIL;
typedef pair<int ,PII> PIII ;
typedef pair<int, pair<PII ,int > > PIIII;
typedef pair<LL , LL> PLL ; 
typedef pair<LL ,int > PLI ;
typedef pair<int,char > PIC ; 
typedef unsigned long long ULL ;
 
const int N = 5e5+10,M = 4e5+10  ;
const LL mod = 1e9+7 , INF = 1e18+10;
const int inf =  1e8 ; 
const double eps = 1e-7 ;
const ULL  P=  131 ;
LL n , m  , k   ;
LL lg[N] ; 
int f[N][11] ;
void init( ) {
	lg[1] = 0 ;
	for(int i =2;  i< N ; ++ i )
		lg[i] = lg[i>>1] + 1 ;
}


struct ST{
	int fa[N][20] ; 
	void insert( int i, int val ) {
		fa[i][0] =  val ; 
		for(int j =1 ; i - ( 1<< ( j-1) )  >=0 ; ++ j )
			fa[i][j] = max( fa[i][j-1] , fa[i -(1<<(j-1)) ][j-1]) ;
	}
	
	int query(int l,int r ) {
		if( l > r )return -inf ;
		int len = lg[ r- l + 1]  ;
		return max(  fa[r][len] , fa[ l + (1<<len) -1][len]  );
	}
	
}st ;


void solve( ) {
	init() ;
} 	
 
 
 
int main(){ 	
 	 
	ios::sync_with_stdio(false);
	cin.tie( 0 ) ;
	int T ; cin >> T ;
	while(T-- ){	
		solve() ;  
   	}        
 	return  0 ;
}
