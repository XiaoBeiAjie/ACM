#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5+10 ;
typedef long long LL ; 

class HLD{
	public :
		int size ,ts ; 
		vector< vector<int>> adj ; 
		vector<int>  dfn , top , fa ,dep ,   siz, son ;
	HLD(int _size): size(_size + 1 ) , ts( 0) , adj( _size + 1) , dfn( _size  + 1 ) , siz(_size + 1 ) , son(_size + 1) ,top(_size + 1 ) ,fa( _size + 1 ) ,dep(_size + 1 ) {}
	void addedges(int a, int b ) {
		adj[a].push_back( b) ; 
	}
	void dfs(int u ,int pa) {
		siz[u] = 1 ; fa[u] = pa ; dep[u] = dep[pa] + 1 ;
		for(auto v :adj[u]) {
			if( v== pa || v == u ) continue ;
			dfs( v, u ) ;
			siz[u] += siz[v];
			if( siz[v] > siz[ son[u] ]) son[u] = v ;
		}
	} 
	void dfs1(int u ,int pa ) {
		dfn[u] = ++ts ; top[u] = pa ; 
		if( son[u]  ) dfs1(  son[u]  , pa ) ;
		for(auto v :adj[u]) {
			if( v == fa[u] || v == son[u]) continue ;
			dfs1(   v , v );
		}
	}
	
	void run( int x ) {
		dfs( x , 0  ) ; dfs1(x ,x ) ;
	}
	void update_path(int x , int y , int z ) {
		while( top[x] != top[y]) {
			if( dep[top[x]] < dep[top[y]]) swap( x, y ) ; 
			//update( 1 , dfn[ top[x]] , dfn[x] ,z) ; 
			x = fa[ top[x]] ; 
		}
		if(  dep[x] < dep[y]) swap( x , y ) ; 
		//update(  1,  dfn[y] , dfn[x] , z ) ;
	}
	
	void update_tree(int x , int z ) {
		//update( 1 , dfn[x] , dfn[x] + siz[x] - 1 ,z   ) ;
	}
	
	LL query_path( int x, int y ) {
		LL res = 0 ;
		while( top[x] != top[y]) {
			if( dep[top[x] ]  < dep[top[y]]) swap( x ,  y ) ; 
			//res += query(  1 , dfn[top[x]] , dfn[x]) ; 
			x = fa[ top[x]] ; 
		}
		if( dep[x] < dep[y]) swap( x , y )  ;
		//res += query( 1, dfn[y] , dfn[x] ) ;
		return res;
	}
//	LL query_tree(int x ) {
//		return query( 1, dfn[x] , dfn[x] + siz[x]  - 1 ) ;
//	}
	int lca(int a ,int b ) {
		while( top[a] != top[b]){
			if( dep[top[a]] < dep[top[b]]) swap( a,  b) ;
			a = fa[ top[a] ];
		}
		return dep[a] < dep[b] ? a : b  ;
	} 
	
};

void solve() {
	int n , m, s ;
	cin >> n >> m >> s ;
	HLD hld(n+1) ;
	for(int i = 1 , u , v ; i < n ; ++ i ) cin >> u >> v, hld.addedges( u ,v ) , hld.addedges(v,u);
	hld.run( s ) ;
	while( m -- ) {
		int u , v; cin >> u >> v ;
		cout << hld.lca( u , v ) <<'\n';
	}
	
}
 
int main( ) {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	solve( ) ;
	return 0 ;
	
}
