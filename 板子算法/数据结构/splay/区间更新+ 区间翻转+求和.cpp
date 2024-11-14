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
 
const int N = 2e5+10,M = 4e5+10  ;
const LL mod = 1e9+7 , INF = 1e18+10;
const int inf =  1e8 ; 
const double eps = 1e-7 ;
const ULL  P=  131 ;
LL n , m  , k   ;
int a[N] ; 
int stk[N] ; 
struct Node {
	int s[2] , p , v; 
	int siz ,rev ;
	LL sum ,val ,tag; 
	void init(int _v , int _p) {
		v= _v , p = _p ; rev= 0 ;
		siz = 1 ; sum = val =  0 ;
	}
}tr[N];

int root , idx ;


void pushrev(int x ){
	swap( tr[x].s[0]  ,tr[x].s[1]) ;
	tr[x].rev ^=1 ;
}

void pushup(int x ) {
	auto &fa=  tr[x] , &left = tr[ tr[x].s[0]]  ,&right = tr[ tr[x].s[1]] ;
	fa.sum = left.sum + right.sum + fa.val ;
	fa.siz = left.siz + right.siz + 1 ;
}

void pushdown(int x ) {
	auto &fa=  tr[x] , &left = tr[ tr[x].s[0]]  ,&right = tr[ tr[x].s[1]] ;
	if( fa.tag) {
		left.sum += left.siz*fa.tag , right.sum += right.siz * fa.tag ;
		left.val += fa.tag ,right.val += fa.tag ;
		left.tag += fa.tag , right.tag += fa.tag; 
		fa.tag = 0 ;
	}
	if( fa.rev) {
		pushrev( tr[x].s[0] ) ; pushrev( tr[x].s[1]) ;
		fa.rev =0 ; 
	}
}

void rotate(int x ) {
	int y = tr[x].p ,z=tr[y].p ; 
	int k=  tr[y].s[1] == x ;
	tr[z].s[  tr[z].s[1] == y] = x ; tr[x].p = z; 
	tr[y].s[k] =   tr[x].s[k^1]  ; tr[  tr[x].s[k^1]].p = y ; 
	tr[x].s[k^1] = y ; tr[y].p =x ;
	pushup( y ) ; pushup(x ) ; 
}


void splay(int x ,int k  ) {
	int top =0 , u = x; 
	stk[++top] =  u ;
	while(  tr[u].p) stk[++top ] = u =  tr[u].p ;
	while( top) pushdown( stk[top--] ) ;
	while( tr[x].p !=k) {
		int y  =tr[x].p , z= tr[y].p ; 
		if( z != k ) {
			if( ( tr[y].s[1] == x) ^( tr[z].s[1] == y)) rotate(x) ;
			else rotate( y ) ; 
		}
		rotate( x) ;
	}
	if(!k  ) root = x ;
}

void insert(int v) {
	int u = root ,p = 0 ;
	while( u ) p = u , u = tr[u].s[ v > tr[u].v] ;
	u = ++idx;
	if( p ) tr[p].s[ v > tr[p].v ] = u ; 
	tr[u].init( v , p )  ;  tr[u].val = a[v] ;
	splay( u , 0 ) ;
}

int get_k(int x ) {
	int u = root ,res =0 ;
	while( u ) {
		pushdown( u) ;
		if( tr[ tr[u].s[0]].siz + res == x   ) {
			splay( u ,0) ;
			return u ; 
		}
		else  if( tr[ tr[u].s[0]].siz + res > x   ) u = tr[u].s[0] ;
		else res += tr[ tr[u].s[0]].siz + 1 , u = tr[u].s[1];
	}
	return -1 ;
}


void update(int l ,int r ,LL d ) {
	int pre= get_k( l-1 ) , suf = get_k( r +1 );
	splay( pre,0 ) ; splay( suf , pre) ;
	tr[tr[suf].s[0] ].tag += d ;
	tr[tr[suf].s[0]].val += d ;
	tr[tr[suf].s[0] ].sum += d*tr[tr[suf].s[0] ].siz ;
	pushup(suf) , pushup( pre) ;
}

void reverse(int l , int r ) {
	int pre= get_k( l-1 ) , suf = get_k( r +1 );
	splay( pre,0 ) ; splay( suf , pre) ;
	pushrev( tr[suf].s[0] ) ; 
}


LL query(int l , int r ) {
	int pre= get_k( l-1 ) , suf = get_k( r +1 );
	splay( pre,0 ) ; splay( suf , pre) ;
	return tr[tr[suf].s[0] ].sum ; 
}

void solve( ) {
	cin >> n  >> m ;
	for(int i =1; i <=n ; ++ i ) cin >>a[i]; 
	for(int i = 0 ; i <=n+ 1;  ++ i ) insert( i ) ; 
	int ans[N] ; 
	while(m--){
		int op ; cin >> op;
		if( op == 0 ) {
			int x, y , k ;
			cin >> x >> y >> k ;
			update( x , y , k ) ;
		}else if( op == 1){
			int x, y ; cin >> x >> y ;
			reverse( x , y );
		}else {
			int x, y ; cin >> x >> y ;
			cout << query( x , y ) <<'\n';
		}
		
	}
	
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
