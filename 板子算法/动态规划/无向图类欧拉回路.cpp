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
LL f[1<<16] ; 	


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
		f[i] = INF ; 
	for(int i = 0 ; i < n ; ++ i ) dist[i][i] = 0  ;
	LL ans = 0 ; 
	int state = 0 ; 
	while( m--) {
		int a,b; LL c  ;cin >> a >>b >>c ;
		dist[b][a] = dist[a][b]  = min( dist[a][b]  ,c ) ; 
		ans += c; 
		state ^= 1<<a ; state ^= 1<<b ;
	}
	floyd( ) ; 
	vector<int> p ; 
	for(int i = 0 ; i <n  ;++ i )  if( state >> i & 1 ) p.push_back( i ) ;
	int size=  p.size() ; 
	f[0] = 0 ;
	for(int state = 0 ; state  < (1<<size) ; ++ state ) {
		
		for(int i = 0 ;  i < size; ++ i) {
			if( state >> i & 1 ) continue ;
			for(int j = 0 ; j < size ; ++ j ) {
				if( state >> j & 1 ) continue ;
				f[state ^ (1<< i) ^ (1<< j)] = min( f[state ^(1<< i)^ (1<< j)] , f[state] + dist[p[i]][p[j]] ) ; 
			}
		}
	}
	cout << ans + f[(1<<size) -1 ] <<endl ; 
	
	
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
