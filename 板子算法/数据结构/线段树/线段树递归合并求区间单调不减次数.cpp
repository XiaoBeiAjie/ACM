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

LL a[N] ; 
struct node{
	LL cost , mx , sum  ;
	int l ,r ;
	LL len ;
}tr[N << 2 ] ; 


LL dfs( int x , int l , int r, LL mx  ) {
	if( l == r ) return  max( 0ll , mx - tr[x].sum ) ;
	int mid = l + r >> 1 ;
	if(  tr[x << 1].mx >= mx  ) return tr[x].cost - tr[x<<1].cost + dfs( x << 1 , l , mid , mx ) ;
	return tr[x<<1].len * mx - tr[x << 1 ].sum + dfs( x << 1 | 1 , mid + 1 ,r , mx ) ;
}

node pushup(  int x , node& left ,node& right  ) {
	node fa ;
	fa.sum = left.sum + right.sum ;
	fa.mx = max( left.mx , right.mx ) ;
	fa.len = left.len + right.len ;
	fa.l = left.l , fa.r = right.r;
	fa.cost = left.cost + dfs(  x  ,right.l , right.r , left.mx ) ;
	return fa ;
}

void build(int x , int l , int r ){
	if( l == r ) {
		tr[x] =  { 0 , a[l] , a[l] , l ,r ,  1  } ; return ;
	}
	int mid = l + r >> 1 ;
	build( x << 1 , l , mid ) ;build( x << 1 | 1,  mid + 1 ,r ) ; 
	tr[x] = pushup(  x << 1 |1  , tr[x << 1 ] , tr[x << 1 | 1 ]    ) ;
	// cout << l <<" " << r <<" " << tr[x].cost <<'\n';
}

vector<int> d ;


void query(int x ,int l , int r, int L ,int R ) {
	if( L <= l && r <= R)  {
		d.push_back( x) ;
		return ;
	}
	int mid = l + r >> 1 ;
	if( L <= mid ) query( x << 1 , l  , mid , L ,  R  );
	if( R > mid )query( x << 1 |1 , mid + 1 ,r , L , R ) ;
	
}

void solve( ) {
	cin >> n >> m ;
	for(int i =1; i <=n ; ++ i ) cin >>a[i] ;
	build( 1, 1, n ); 
	while( m -- ) {
		int l , r ; cin >> l >> r ;
		d.clear( ) ;
		query(1 , 1 , n , l , r  ) ;
		reverse( d.begin() , d.end()) ;
		// for(auto x : d ) cout << x <<" " << tr[x].l <<" " << tr[x].r <<" " << tr[x].cost <<'\n';
		auto res = tr[d.back()] ; d.pop_back( ) ;
		while( d.size() ) {
			int u = d.back( ) ; d.pop_back()  ;
			// cout  << res.l <<" " << res.r <<" " << res.cost <<"-"  ;
			// cout << u <<" " << tr[u].l <<" " << tr[u].r <<" " << tr[u].cost<<'\n';
			res = pushup( u , res , tr[u] );  
		}
		// cout  << res.l <<" " << res.r <<" " << res.cost <<'\n';
		cout << res.cost <<'\n';
		
	}
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
