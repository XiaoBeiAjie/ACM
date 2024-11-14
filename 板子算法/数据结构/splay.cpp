#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int  N= 2e5+10 ;
typedef long long LL ; 


const int inf = 1e8  ;

int n , m ;

struct Node{
	int s[2] , p ,v ; 
	int size ,cnt ; 
	void init( int _v, int _p) {
		v = _v , p = _p ;
		size =1 ; cnt = 1 ;
	}
	
}tr[N];

int root , idx ;

void pushup( int x ) {
	auto &fa = tr[x] , &l =  tr[ fa.s[0]] , &r = tr[ fa.s[1]] ;
	fa.size = l.size + r.size+ fa.cnt ;
}

void pushdown( int x ) {

} 

void rotate(  int x ) {
	int y = tr[x].p , z =  tr[y].p ; 
	int k = tr[y].s[1] == x ;
	tr[z].s[  tr[z].s[1] == y ] = x;  tr[x].p = z; 
	tr[y].s[k] = tr[x].s[k^1] ;  tr[ tr[x].s[k^1]].p = y ; 
	tr[x].s[ k ^1] = y ;  tr[y].p = x; 
	pushup( y ) ; pushup(x) ;
}

void splay(  int x, int k ) {
	while( tr[x].p != k ) {
		int y = tr[x].p , z = tr[y].p ;
		if( z != k )
			if( ( tr[y].s[0] == x ) ^( tr[z].s[0] == y)) rotate( x ) ; 
			else rotate( y ) ; 
		rotate( x ); 
	}
	if( !k ) root = x ; 
}




void insert(  int v) {
	int u  = root , p = 0 ;
	while( u) {
		if( tr[u].v == v ) break; 
		p = u , u = tr[u].s[ v > tr[u].v] ;
	}
	if( !u ) {
		u = ++idx ;
		if( p  ) tr[p].s[ v > tr[p].v] =  u ;
		tr[u].init( v, p) ; 
	}else {
		tr[u].cnt++ ; tr[u].size ++ ; 
	}
	splay( u , 0 )  ;
}



int get_k( int x ){
	int u = root , res = 0 ;
	while( u) {
		if( tr[ tr[u].s[0]].size + res <=x  ){
			if( tr[ tr[u].s[0]].size + res + tr[u].cnt > x  ) {
				splay( u , 0 ); 
				return u ;
			}
			else res += tr[ tr[u].s[0]].size + tr[u].cnt,  u = tr[u].s[1] ;
		}else u = tr[u].s[0] ; 
	}
	return -1 ;
}


int pre( int x) {
	int u = root , ans = 0 ;
	while( u) {
		if(  tr[u].v < x) ans = u , u  = tr[u].s[1] ; 
		else u = tr[u].s[0] ;
	}
	splay(ans , 0) ;
	return ans ; 
}

int suf( int x ) {
	int u = root ,ans = 0;
	while( u ) {
		if( tr[u].v > x ) ans = u , u = tr[u].s[0] ;
		else u = tr[u].s[1] ;
	}
	splay(ans , 0) ;
	return ans ; 
}

int rk(int x ) {
	int res= 0 , u = root , p = root;
	while( u) {
		if( tr[u].v == x ) {
			splay( u , 0 ) ; 
			return  tr[ tr[u].s[0]].size ;
		}
		if( tr[u].v < x ){
			res += tr[u].cnt + tr[ tr[u].s[0]].size; 
			p = u ; 
			u = tr[u].s[1] ;
		}else u = tr[u].s[0] ;
	}
	if(!p ) splay( p , 0) ;
	return res ;
}



void del( int x ) {
	int lst = pre(x ) , nxt = suf( x ) ;
	splay( lst , 0 ) ; splay( nxt ,lst ) ;
	if(  tr[nxt].s[0] ) {
		if( tr[ tr[nxt].s[0]].cnt == 1 ) {
			tr[nxt].s[0] = 0 ;
		}else {
			tr[ tr[nxt].s[0]].cnt-- ;tr[ tr[nxt].s[0]].size -- ;
		}
	}
	pushup( nxt);
	pushup( lst) ;
}


void dfs(int u ) {
	pushdown( u ) ;
	if( tr[u].s[0]) dfs( tr[u].s[0]) ;
	if(  -inf < tr[u].v && tr[u].v  < inf ) {
		for(int i = 1 ;i <=tr[u].cnt ;++ i ) cout << tr[u].v <<" " ; 
	}
	if (tr[u].s[1]) dfs( tr[u].s[1]) ; 
}

void dfs1(int u ) {
	pushdown( u ) ;
	if(  -inf < tr[u].v && tr[u].v  < inf ) {
		for(int i = 1 ;i <=tr[u].cnt ;++ i ) cout << tr[u].v <<" " ; 
	}
	if( tr[u].s[0]) dfs1( tr[u].s[0]) ;

	if (tr[u].s[1]) dfs1( tr[u].s[1]) ; 
}


void solve() {
	root = idx= 0 ;
	cin >>   m ;
	insert( -inf ) ;  insert( inf ) ; 
		auto get = [&]() {
			int ans = 0 ;
	vector<int> dis( idx+ 1 ,0 );
	queue<int> q; 
	q.push( root) ; dis[root] = 1;  
	while(q.size()){
		int siz = q.size() ; 
		while(siz--) {
			int u = q.front() ; q.pop( ) ;
//			cout << u <<" "<< tr[u].s[0] <<" " << tr[u].s[1] <<'\n';
			ans = max(ans , dis[u]) ;
			if( tr[u].s[0] ) q.push( tr[u].s[0]) , dis[ tr[u].s[0]] =  dis[u]  + 1 ;
			if( tr[u].s[1] ) q.push( tr[u].s[1]) , dis[ tr[u].s[1]] =  dis[u]  + 1 ;
			
		}
//		cout <<'\n';

	}
		return ans ;
	}; 
	
	while( m--) {
		int op ,x ; cin >> op >> x ; 
//		if( op != 1 && op !=2 )cout<<"res = " ;
		if( op == 1 ) {
			insert( x) ;
		}else if( op == 2 ) {
			del( x) ;
		}else if( op ==3 ) {
//			rk(x) ;
			cout << rk( x ) <<'\n';
		}else if( op ==4 ) {
			cout << tr[get_k(x  )].v <<'\n';
		}else if( op ==5 ) {
			cout << tr[pre(x)].v <<'\n';
		}else {
			cout << tr[ suf( x )].v <<'\n'; 
		}
//		dfs( root ) ; cout <<'\n';
//		if( op !=1 )cout <<"H = " << get( ) <<'\n';
	}

	
}


int main( ) {
//	  freopen("#.in", "r", stdin);
//    freopen("#.out", "w", stdout);
	int  T ;  T = 1;
	while(T--) solve( ) ; 
	return  0 ; 
}
