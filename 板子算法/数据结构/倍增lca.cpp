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


class LCA{
	public :
		int size ; 
		int mx; 
		vector<int> depth ;
		vector< vector<int> > fa ;
		vector< vector<int> > adj;  
	LCA() : size(0) { } 
	LCA(int _size): size(_size) , mx( log2(_size+1)+1 ) ,adj( _size+1) {
		fa.assign( _size +1, vector<int>( mx , 0 )) ; 
		depth.assign(_size+1 , inf ) ;
	}
	LCA(const LCA &_t):size(_t.size) , depth( _t.depth) , mx(_t.mx ) , fa( _t.fa) ,adj(_t.adj) { } 
	void addedges(int a, int b ) {
		adj[a].push_back( b) ; 
	}
	void run( int u ) { bfs( u );}
	
	void bfs(int u  ) {
		depth[0] =   0 ; 
		depth[u] = 1;  queue<int> q; 
		q.push( u ) ;
		while(!q.empty()) {
			int t =q.front() ;  q.pop() ; 
			for(auto u  : adj[t]) {
				if( depth[u] > depth[t ] + 1 ) {
					depth[u] =  depth[t] + 1 ;
					fa[u][0] = t; 
					for(int i = 1 ; i < mx; ++ i) {
						fa[u][i] = fa[ fa[u][i-1]][i-1] ;
					}
					q.push( u ) ; 
				}
			}
		}
	}
	
	int lca( int a,int b ) {
		if( a ==b) return a; 
		if( depth[a] < depth[b]) swap(a,b ) ;
		for(int i =mx -1;i>=0; --i) if( depth[ fa[a][i]] >= depth[b] ) a = fa[a][i] ; 
		if( a ==b ) return a; 
		for(int i = mx -1; i>=0 ; --i) if( fa[a][i] != fa[b][i]) a=fa[a][i] , b = fa[b][i]  ;
		return fa[a][0] ; 
	}
	
};


void add(int a,int b,int c ) {
	e[idx] =b ,ne[idx ] = h[a] , w[idx] = c,  h[a] = idx  ++ ;   
}


void solve( ) {
	int q , u ; 
	cin >> n >> q >> u ; 
	LCA   lc( n ) ; 
	for(int i =1; i < n ; ++ i){
		int a,b;cin >>a >>b ;
		lc.addedges( a ,b) ; lc.addedges( b,a) ; 
	}
	lc.run( u ) ; 
	while(q--) {
		int a,b;cin >>a >>b ;
		cout << lc.lca( a ,b)  <<'\n';
	} 
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
