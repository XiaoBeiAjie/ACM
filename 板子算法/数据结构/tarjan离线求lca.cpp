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

const int N = 1e4+10,M = 6e5+10  ;
const LL mod = 998244353 , INF = 1e10+10;
const int inf = 1e8 ; 
const double eps = 1e-7 ;
const ULL  P=  131 ;

LL n , m   , k ;

int h[N] ,e[M] , ne[M] ,w[M] ,idx; 
bool st[N]  ; 
int cnt[N] ; 
int dist[N] ;  

template<typename T> 
class DSU{
	public :
		int size ;
		vector<T> fa ;
		vector<T> siz ;
	DSU( ) :size(0) {}
	DSU( int _size) : size(_size) , siz(_size+1 ,1) ,fa(_size+1)    {
		for(int i = 0 ; i <=size; ++ i) fa[i] = i  ;
	}
	DSU( const DSU &_t) {	size = _t.size ;  fa = _t.fa  ; siz = _t.siz  ; }
	~DSU( ) { fa.clear() , siz.clear()  ; } 
	int find( int x ) {
		if( fa[x] == x ) return x ;
		return fa[x] = find( fa[x]); 
	}
	void merge( int a ,int b ) {
		int pa = find( a) ,  pb=  find(b ) ; 
		if( pa ==pb) return  ;
		siz[pa] +=siz[pb] ,  fa[pb] = pa ;
	}
	
	bool same(int a ,int b ){
		return find(a) == find(b ) ; 
	}
	
};


class Tarjan{
	public :
		int size ; 
		vector< vector<int> > adj ; 
		vector<int> st ;
		vector< vector< pair<int,int> >  >  Query ; 
		vector<int> ans ; 
		int cmd ; 
		DSU<int>  fa ;
	Tarjan() : size(0) { } 
	Tarjan(int _size): size(_size) , st(_size+ 1,  0) ,adj( _size+1) ,Query(_size + 1) ,fa(_size) ,cmd(0) {	}
	void addedges(int a, int b ) {
		adj[a].push_back( b) ; 
	}
	void  getquery(int x) {
		ans.assign( x , 0 ) ;  cmd = 0 ;
	}
	void addquery(int a , int b  ) {
		if( a ==b) ans[cmd] = a; 
		Query[a].push_back(   { b, cmd }) ;
		Query[b].push_back(   { a, cmd }) ;
		cmd ++  ;
	}
	
	void run(int u ) {
		tarjan( u ) ; 
	}
	void tarjan(int u ) {
		st[u]=   1 ;
		for(auto v : adj[u]) {
			if(st[v]) continue ;
			tarjan(v) ; 
			fa.fa[v] = fa.find( u) ; 
		}
		for(auto  q: Query[u]) {
			int ver = q.first , id = q.second ;
			if( ver == u) continue ;
			if( st[ver] == 2) ans[id] = fa.find( ver)  ;
		}
		st[u] = 2 ;
	}
	
	void printans( ) {
		for(int i  = 0 ;  i < cmd ; ++ i) cout   <<ans[i] <<"\n" ;
	}
	
};


void add(int a,int b,int c ) {
	e[idx] =b ,ne[idx ] = h[a] , w[idx] = c,  h[a] = idx  ++ ;   
}


void solve( ) {
	int q , u ; 
	cin >> n >> q >> u ; 
	Tarjan   lc( n ) ; 
	for(int i =1; i < n ; ++ i){
		int a,b;cin >>a >>b ;
		lc.addedges( a ,b) ; lc.addedges( b,a) ; 
	}
	lc.getquery( q)  ;
	while(q--) {
		int a,b;cin >>a >>b ;
		lc.addquery(  a,b) ; 
	} 
	lc.run( u ) ; 
	lc.printans( ) ; 
}


int main(){ 	
	ios::sync_with_stdio(false);
	cin.tie( 0 ) ;
	int T; T =1 ; 
	while(T-- ){	
		solve() ;  
   	}        
 	return  0 ;
}
