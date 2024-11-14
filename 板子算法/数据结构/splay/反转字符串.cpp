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

string s ;
struct Node{
	int s[2] , p , v; 
	int siz , rev ; 
	char ch ; 
	void init( int _v  ,int _p ) {
		v = _v , p = _p , siz = 1 ;rev=  0; 
		ch = s[v] ; 
	}
}tr[N];
int stk[N]  ;

int root ,idx ;

void pushup(int x ) {
	auto &fa=  tr[x] , &left = tr[ tr[x].s[0]]  ,&right = tr[ tr[x].s[1]] ;
	fa.siz = left.siz + right.siz  + 1 ;
}

void pushrev( int x ) {
	swap( tr[x].s[0]  ,tr[x].s[1]) ;
	tr[x].rev ^= 1 ;
}

void pushdown(int x ) {
	auto &fa=  tr[x] , &left = tr[ tr[x].s[0]]  ,&right = tr[ tr[x].s[1]] ;
	if( fa.rev) {
		pushrev( tr[x].s[0]) ; pushrev( tr[x].s[1] ) ;
		fa.rev =   0 ;
	}
}

void rotate(int x ) {
	int y = tr[x].p , z = tr[y].p ; 
	int k = tr[y].s[1] == x ;
	tr[z].s[  tr[z].s[1] == y] = x;  tr[x].p  =  z; 
	tr[y].s[k] =   tr[x].s[ k^1 ]  ; tr[ tr[x].s[k^1]].p = y ; 
	tr[x].s[k^1] = y ; tr[y].p =  x; 
	pushup( y ) ; pushup( x) ;
}

void splay(int x ,int k  ) {
	while( tr[x].p != k) {
		int y = tr[x].p , z=  tr[y].p ; 
		if( z != k  ) {
			if( ( tr[y].s[1] == x) ^( tr[z].s[1] == y)) rotate( x );
			else rotate( y ) ; 
		}
		rotate( x ) ; 
	}
	if(!k) root = x; 
}

int get_k(int x ){
	int u = root ,res= 0 ;
	while( u ){
		pushdown(u ) ;
		if( tr[ tr[u].s[0] ].siz  +res ==x ) {
			splay( u , 0 ); 
			return u ; 
		}else if( tr[ tr[u].s[0] ].siz  +res  > x ) u = tr[u].s[0] ;
		else res += tr[ tr[u].s[0]].siz + 1 , u = tr[u].s[1] ; 
		
	}
	return -1; 
}


void insert(int v ) {
	int u = root ,p = 0 ;
	while( u ) p =u , u = tr[u].s[ v > tr[u].v] ; 
	u = ++idx ;
	if( p ) tr[p].s[ v > tr[p].v] = u ;
	tr[u].init( v , p ) ; tr[u].ch = s[v] ;
	splay( u , 0 ) ;
}

string res ;
void dfs(int u ) {
	if(!u) return ; 
	
	pushdown(u) ; 
	dfs( tr[u].s[0]) ;
	if( tr[u].ch != '#') cout <<tr[u].ch ; 
	dfs( tr[u].s[1]) ; 
}



void solve( ) {
	cin >> n >> m ;
	cin >> s; s= "#" + s;  s += '#' ;
	for(int i = 0 ; i <=n + 1 ;++ i ) insert( i ) ; 
	while( m-- ) {
		int l ,r ;
		cin >> l >> r ;
		int pre = get_k( l-1 ) ,suf =get_k(r + 1 ) ; 
		splay( pre, 0 ) ;splay( suf, pre) ; 
		pushrev( tr[suf].s[0]) ; 
	}
	dfs( root ) ;
} 	
 

int main(){ 	
 
	ios::sync_with_stdio(false);
	cin.tie( 0 ) ;
	int T ; T = 1; 
	while(T-- ){	
		solve() ;  
   	}        
 	return  0 ;
}
