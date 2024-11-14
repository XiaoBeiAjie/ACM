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
int a[N] ;



void solve( ) {
	LL ans = 0 ;
	int k1, k2 ;
	cin >> n  >> k1 >> k2;
	vector< vector<int>> adj( n +1 ) ; 
	vector<int> MX( n + 1) ,siz( n + 1 ) , dis( n + 1 )  ;
	vector<bool> st( n + 1 ) ;
	for(int i =1; i <n ; ++ i ) {
		int u , v ;cin >> u >> v  ;
		adj[u].push_back( v ) ;
		adj[v].push_back( u ) ; 
	}
	MX[0] = inf ;
	auto get_root =[&](auto self , int u  , int fa, int tot ,int &wc )->void {
		MX[u] = 0 ;siz[u] = 1 ;
		for(auto v :adj[u]) {
			if( v ==  fa || st[v]  ) continue ;
			self( self, v , u , tot , wc ) ; 
			siz[u] += siz[v] ; 
			MX[u] = max( MX[u] , siz[v] ) ;
		}
		MX[u] = max( MX[u] , tot - siz[u] ) ;
		if( MX[u] < MX[wc] ) wc= u; 
	} ;
	
	auto get_dis =[&](auto self ,int u , int fa , vector<int> &d )->void {
		d.push_back(  dis[u] ) ;
		for(auto v :adj[u] ) {
			if( v ==fa || st[v]) continue ;
			dis[v]  = dis[u] + 1 ;
			self(self , v , u , d ) ;
		}
	};
	
	auto calc =[&](auto self, int u , int  len )->LL {
		vector<int> d ;
		dis[u] = len ; 
 		get_dis( get_dis ,  u , u  ,d  ) ;
 		sort( d.begin() , d.end()) ;
 		int l = 0 , r= (int)d.size() -1 ;
 		LL res = 0 ; 
 		while( l <= r ) {
 			if( d[l] + d[r] <= k )  res += r - l  ,  ++ l ;
 			else --r ;
 		}
 		d.clear() ;
 		return res;
	};
	
	
	auto dfs = [&]( auto self , int u  , int tot  ) ->void {
		int rt = 0 ;
		get_root(  get_root , u ,  0 , tot , rt  ) ;
		u = rt ;
		ans += calc( calc , u , 0 ) ; 
		st[u] = true ;
		for(auto v :adj[u]) {
			if( st[v] ) continue ;
			ans -= calc( calc , v , 1 ) ;
		}
		for(auto v : adj[u]) {
			if( st[v]) continue ;
			self( self , v , siz[v]) ; 
		}
	} ;
	k = k2 ;
	dfs( dfs , 1 , n ) ;
	LL res = ans ; ans = 0 ;
	if( k1 -1 ) st.assign( n + 1 ,false) ,  k = k1-1 , dfs(dfs ,1 ,n ) ;
	// cout << ans <<'\n';
	cout << res -ans <<'\n';

	
} 	
 
 
 
int main(){ 	
	ios::sync_with_stdio(false);
	cin.tie( 0 ) ;
	int T ; T =1 ;
	while(T-- ){	
		solve() ;  
   	}        
 	return  0 ;
}
