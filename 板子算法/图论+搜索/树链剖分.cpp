#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5+10 ;
typedef long long LL ; 
LL mod ; 
int n , m  , q; 
int h[N ] ,e[N*2] , ne[N*2] , idx ;
int  w[N] ,v[N]; 
int  dfn[N] , fa[N] , son[N] , siz[N] , depth[N], top[N]  ,  cnt; 

void add(int a, int b ) {
	e[idx] =b , ne[idx] = h[a] , h[a] = idx++ ;  
}

void dfs1( int u, int pa , int d ) {
	siz[u] = 1 ; fa[u] = pa;   depth[u] = d ;
	for(int i = h[u] ; ~i ; i =ne[i]) {
		int j=e[i] ; 
		if( j ==  pa) continue ;
		dfs1(  j ,  u  ,d + 1) ; 
		siz[u] += siz[j] ;
		if( siz[ son[u]] < siz[j]) son[u] = j  ;
	}
}

void dfs2(int u , int pa ) {
	dfn[u]= ++cnt ; top[u] = pa ; v[cnt] = w[u] ; 
	if( !son[u] ) return ;
	dfs2( son[u] , pa ) ;
	for(int i =h[u]; ~i ;  i = ne[i]) {
		int j = e[i] ;
		if( j == fa[u] || j == son[u]) continue ;
		dfs2( j ,  j ) ;  
	}
}

struct tree{
	int l , r; 
	LL sum , add ;
}tr[N*4] ;


void pushup(int x ) {
	tr[x].sum = tr[x << 1 ].sum + tr[x << 1 | 1 ].sum ; 
}

void pushdown(int x ) {
	auto &root = tr[x] , &left =tr[x << 1 ] , &right = tr[x<<1|1] ; 
	if( root.add) {
		left.add  += root.add ; left.sum += root.add *( left.r - left.l + 1 ) ;
		right.add  += root.add ; right.sum += root.add *( right.r - right.l  + 1) ; 	
		root.add = 0 ;
	}
}


void build( int x, int l , int r ) {
	tr[x] = { l  ,r , v[l]  , 0  }  ;
	if( l == r ) {
		 return  ;
	}
	int mid = l + r >> 1; 
	build( x<< 1, l , mid ) ; build( x<<1| 1 ,  mid +1,  r ) ; 
	pushup( x ) ; 
}


void update( int x , int l , int r, LL k ) {
	if(  l <= tr[x].l  && r >= tr[x].r ) {
		tr[x].add +=  k ;
		tr[x].sum += k*( tr[x].r - tr[x].l + 1 ) ; 
		return ; 
	}
	pushdown( x ) ;
	int mid =tr[x].l + tr[x].r >> 1; 
	if( l <=mid ) update( x << 1 , l , r , k )  ;
	if( r > mid  ) update( x << 1 | 1 , l , r , k )  ;
	pushup( x) ;  
}

LL query( int x, int l , int r ) {
	if( tr[x].l >=  l && tr[x].r <= r ) return tr[x].sum ; 
	pushdown(x) ;
	LL res = 0 ;
	int mid = tr[x].l + tr[x].r>> 1 ;
	if( l <=mid ) res += query( x << 1 , l , r ) ;
	if( r >mid )res += query( x << 1 | 1 , l   , r)  ;
	return res;
}


void update_path(int x , int y , int z ) {
	while( top[x] != top[y]) {
		if( depth[top[x]] < depth[top[y]]) swap( x, y ) ; 
		update( 1 , dfn[ top[x]] , dfn[x] ,z) ; 
		x = fa[ top[x]] ; 
	}
	if(  depth[x] < depth[y]) swap( x , y ) ; 
	update(  1,  dfn[y] , dfn[x] , z ) ;
}




LL query_path( int x, int y ) {
	LL res = 0 ;
	while( top[x] != top[y]) {
		if( depth[top[x] ]  < depth[top[y]]) swap( x ,  y ) ; 
		res += query(  1 , dfn[top[x]] , dfn[x]) ; 
		x = fa[ top[x]] ; 
	}
	if( depth[x] < depth[y]) swap( x , y )  ;
	res += query( 1, dfn[y] , dfn[x] ) ;
	return res;
}


void update_tree(int x , int z ) {
	update( 1 , dfn[x] , dfn[x] + siz[x] - 1 ,z   ) ;
}


LL query_tree(int x ) {
	return query( 1, dfn[x] , dfn[x] + siz[x]  - 1 ) ;
}


void solve( ) {
	int root =1   ,q =0 ; 
	cin >> n ; cin >> q ; mod = 1e9+7;
	for(int i =1; i <=n ; ++ i  )  cin >>w[i] , h[i] = - 1 ; 
	for(int i= 1;  i <n ; ++ i ) {
		int a, b ; cin >>a >>b; 
		add(a,b) ; add(b,a) ; 
	}
	dfs1( root , root , 1 ) ; 
	dfs2( root  , root   ) ; 
	build( 1, 1,  n  ) ; 
	while(q--){
		int op, x, y,z ;
		cin >> op ;
		if( op == 1 ) {
			cin >> x >> y >> z ;
			update_path( x, y ,z  ) ;
		}else if( op ==3) {
//			cin >> x >> y ; 
//			LL res = query_path( x, y ) ; 
//			cout << ( res + mod )%mod <<'\n' ;
			LL ans = 0 ;
			for(int i =1; i <=n ; ++ i ) {
				for(int j = i ; j <= n ; ++ j )
					ans += query_path( i, j ) ;
			}
			cout << ans <<'\n';
		}else if( op ==2 ) {
			cin >> x >> z ; 
			update_tree( x , z ) ; 
		}else {
			cin >> x; 
			LL res= query_tree( x ) ;
			cout << ( res + mod ) % mod <<'\n' ;
		}
	}
}


int main ( ) {
	int  T; T = 1;
	while(T--) solve( ) ; 
	return 0 ; 
}
