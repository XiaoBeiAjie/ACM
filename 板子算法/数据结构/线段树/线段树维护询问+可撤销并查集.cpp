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
 
const int N = 1e5+10,M = 4e5+10  ;
const LL mod = 998244353 , INF = 1e18+10;
const int inf =  1e8 ; 
const double eps = 1e-7 ;
const ULL  P=  131 ;
LL n , m  , k   ;
 
vector<PII> e[N<<2] ; 
int dep[N] , fa[N] ; 
int ans[N] , cnt ;

int find(int x ) {
	if( x == fa[x]) return x;
	return find( fa[x]) ;
}

void add(int x ,int l ,int r ,int L ,int R , PII u) {
	if( L <= l && r <= R ) {
		e[x].push_back( u ) ; return ;
	}
	int mid = l + r >> 1 ;
	if( L <= mid ) add( x << 1 , l , mid , L , R , u) ;
	if( R > mid ) add( x << 1 | 1 , mid + 1,  r, L , R , u ) ;
}

bool same( int x ,int y ) {
	return find( x ) == find( y ) ;
}

void dfs(int x ,int l ,int r ) {
	stack<PII> d ,f ;
	for(auto tmp : e[x] ) {
		int u = tmp.x ,v = tmp.y ;
		u = find( u ) , v = find( v ) ;
		if( u == v  ) continue ;
		--cnt ;
		if( dep[u] < dep[v] ) swap( u ,v ) ;
		f.push( { v , fa[v]} )  ; d.push( { u , dep[u] }) ;
		fa[v] = u ; dep[u] = max( dep[u] , dep[v] + 1 ) ;
	}
	if( l == r ) ans[l] = cnt ;
	else {
		int mid = l + r >> 1 ;
		dfs( x << 1 , l , mid ) ;dfs( x << 1 | 1 , mid + 1, r ) ;
	}
	while( d.size()  ) {
		auto uu = d.top() , vv = f.top() ;  d.pop() ; f.pop( );
		++ cnt ;
		dep[uu.x] =  uu.y ; fa[vv.x] = vv.y ;
	}
	
	
}


void solve( ) {
	int q ;
	cin >> n >> m >> q ;
	for(int i = 0; i <= n  ; ++ i ) dep[i] = 1 ,fa[i] = i; 
	map< PII ,int> mp ;
	for(int i =1; i <= m ; ++ i ) {
		int u ,v ;cin >> u >> v ;
		if( u > v ) swap( u , v )  ;
		mp[{u,v}] = 0 ;
	}
	for(int i =1; i <= q ; ++ i ) {
		int op , u ,v ; cin >> op >>  u >> v ;
		if( u > v ) swap( u , v ) ;
		if( op == 1  ) {
			mp[{u,v}] = i ;
		}else {
			add( 1 , 0 , q   ,  mp[{u,v}] ,i - 1  , { u ,v}  ) ;
			mp.erase( { u,v} ) ;
		}
	}
	for(auto tmp : mp ) {
		add( 1 , 0 , q , tmp.y , q , tmp.x ) ;
	}
	cnt = n ;
	dfs( 1 , 0 ,q  ) ;
	for(int i = 0 ;  i <=q ; ++ i ) cout << ans[i] <<" \n"[ i ==q ] ;
	
	
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
