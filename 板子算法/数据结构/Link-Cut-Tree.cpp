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
 
const int N = 4e5+10,M = 4e5+10  ;
const LL mod = 1e9+7 , INF = 1e18+10;
const int inf =  1e8 ; 
const double eps = 1e-7 ;
const ULL  P=  131 ;
LL n , m  , k   ;

struct Node{
	int s[2], v, p ;
	int sum ,rev;
}tr[N];

struct Link_Cur_Tree{
	int stk[N] ; 
	void pushrev(int x) { 
		swap( tr[x].s[0] , tr[x].s[1]) ; 
		tr[x].rev ^=1 ;
	}	
	void pushup(int x ) {
		tr[x].sum = tr[ tr[x].s[0]].sum ^tr[x].v ^ tr[ tr[x].s[1]].sum ; 
	}
	
	void pushdown( int x ) {
		if( tr[x].rev) {
			pushrev( tr[x].s[0]) , pushrev( tr[x].s[1]) ; 
			tr[x].rev = 0;
		}
	}
	
	bool isroot(int x) {
		return tr[tr[x].p].s[0] != x && tr[ tr[x].p].s[1] != x ;
	}
	
	
	void rorate(int x) {
		int y = tr[x].p , z = tr[y].p ; 
		int k = tr[y].s[1] == x ;
		if( !isroot(y))  tr[z].s[ tr[z].s[1] == y] = x ;
		tr[x].p = z ;
		tr[y].s[k] = tr[x].s[k^1] , tr[ tr[x].s[k^1] ].p  = y ;
		tr[x].s[k^1] = y ; tr[y].p = x ;
		pushup( y) ; pushup( x) ;
	}
	
	void splay(int x) {
		int top = 0 ,r = x;
		stk[++top] = r;
		while( !isroot(r)) stk[++top] = r= tr[r].p ;
		while( top) pushdown( stk[top--]) ;
		while( !isroot( x)) {
			int y = tr[x].p , z = tr[y].p ;
			if (!isroot( y) ) {
				if( (tr[y].s[1] == x ) ^( tr[z].s[1]  == y ) ) rorate( x);
				else rorate( y ); 
			}
			rorate( x) ; 
		}
	}
	
	void access(int x ) {
		int z =x ;
		for(int y = 0 ; x ; y =x,  x= tr[x].p) {
			splay( x ) ;
			tr[x].s[1] = y ; pushup(x) ;
		}
		splay( z) ;
	}
	void makeroot(int x ) {
		access(x) ;
		pushrev(x);
	}
	
	int findroot( int x ) {
		access( x ) ; 
		while( tr[x].s[0]) pushdown(x) , x = tr[x].s[0] ;
		splay(x) ;
		return x ;
	}
	void split(int x ,int y ) {
		makeroot( x ) ;
		access( y ) ;
	}
	void link(int x , int y ) {
		makeroot(x) ;
		if( findroot( y) !=x ) tr[x].p = y ;
	}
	void cut(int x ,int y ) {
		makeroot(x)  ;
		if( findroot(y) ==x && tr[y].p ==x  && !tr[y].s[1] ) {
			tr[x].s[1] = tr[y].p = 0 ;
			pushup(x) ;
		}
	}
};


void solve( ) {
	cin >> n >> m ;
	Link_Cur_Tree  T ; 
	for(int i =1; i <=n ; ++ i ) cin >>  tr[i].v ;
	
	while( m  -- ) {
		int op , x, y ; 
		cin >> op >> x >> y ; 
		if( op == 0) {
			T.split( x, y ) ;
			cout << tr[y].sum  <<'\n';
		}
		else if( op == 1 ) T.link( x, y ) ;
		else if( op ==2 ) T.cut( x , y ) ;
		else {
			T.splay( x) ; 
			tr[x].v = y ; 
			T.pushup(x ) ;
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
