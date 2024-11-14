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
typedef pair<LL , LL> PLL ; 
typedef pair<LL ,int > PLI ;
typedef pair<int,char > PIC ; 
typedef unsigned long long ULL ;

const int N = 16,M = 6e5+10  ;
const LL mod = 998244353, INF = 1e12+10;
const double eps = 1e-7 ;



const ULL  P=  131 ;


int n , m  ;


LL dist[N][N] ; 
LL f[1<<16][N] ; 	


void floyd( ) {
	for(int k = 0 ;  k < n ; ++ k ) {
		for(int i = 0 ; i < n ; ++ i ) {
			for(int j = 0 ; j < n ; ++ j ) {
				dist[i][j] = min( dist[i][j] , dist[i][k] + dist[k][j])   ;
			}
		}
	}
}

void solve() {
	cin >> n  >> m ; 
	for(int i = 0 ; i  < n ; ++ i )
		for(int j = 0 ;  j < n ; ++ j )
			dist[i][j] =   INF ; 
	for(int i = 0 ; i < (1<< n) ;  ++ i )
		for(int j = 0 ; j  < n  ;++ j )
			f[i][j] =  INF ; 
	for(int i = 0 ; i < n ; ++ i ) dist[i][i] = 0  ;
	while( m--) {
		int a,b; LL c  ;cin >> a >>b >>c ;
		dist[a][b]  = min( dist[a][b]  ,c ) ; 
	}
	f[1][0] =  0 ; 
	for(int state = 1 ; state < ( 1 << n ) ; ++ state ) {
		for(int i = 0 ;  i < n ; ++ i ) {
			if( state >> i & 1 ) {
				for(int j = 0 ; j < n ;++ j ) {
					if( ( state - ( 1 << i)) >> j & 1  ) {
						f[state][i]= min( f[state][i] , f[state - ( 1 << i )][j] + dist[j][i]);
					}
				}
			}
		}
	}
	LL ans = INF ;
	for(int i = 1 ; i < n ; ++ i ) ans = min( ans , f[(1<<n) -1 ][i]  + dist[i][0])  ; 
	if( ans == INF ) cout << -1 <<endl;
	else cout << ans <<endl;
}	



int main(){ 	
	ios::sync_with_stdio(false);
	cin.tie( 0 ) ;
	int T;T  =1; 
	while(T-- ){	
		solve() ;  
   	}        
 	return  0 ;
}
