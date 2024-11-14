#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue> 
using namespace std;
const int N = 1e3+10 ,  M =5e5+10 ;
const int inf = 1e8+10 ; 
int n , m ,r; 
int cnt ;
int inv[N] , vis[N] , id[N] ,pre[N];  
struct edge{
	int a, b,c; 
}e[M];

int work( ) {
	int res = 0 ;
	while(1) {
		cnt = 0 ;
		for(int i =1; i <=n ; ++ i ) inv[i] = inf , vis[i] = id[i] = 0 ;
		for(int i = 1;  i <=m  ; ++ i ) {
			if( e[i].a  != e[i].b && inv[ e[i].b] > e[i].c) 
				inv[e[i].b] =  e[i].c , pre[ e[i].b] = e[i].a ;
		}
		// 不连通则返回 -1  
		for(int i = 1; i <=n ; ++ i ) if( i != r && inv[i] == inf ) return -1 ;
		for(int i =1 ;i <=n ; ++ i ) {
			if( i == r ) continue ;
			res += inv[i] ; 
			int u = i ;
			while( vis[u] != i && !id[u] && u != r) vis[u] = i ,  u = pre[u] ; 
			if( !id[u] &&  u!= r ) {
				id[u] = ++cnt ;
				for(int j = pre[u] ; j != u ; j = pre[j]) id[j] = cnt ;
			} 
		}
		if(!cnt ) break ; 
		for(int i =1 ; i <=n ; ++ i) if(!id[i]) id[i] = ++cnt ;
		for(int i =1; i <=m ; ++ i ) {
			int u  = e[i].b  ;
			e[i].a = id[ e[i].a] , e[i].b = id[e[i].b] ; 
			if( e[i].a != e[i].b) e[i].c -= inv[u] ; 
		}
		n = cnt ,  r  =id[r] ; 
	}
	return  res ;
}


int main( ) {
	cin >> n  >> m >> r; 
	++ r; 
	for(int i = 1; i <=m ; ++ i ) {
		int a, b ,c; cin >>a >>b >>c ;
		++a , ++b ;
		e[i] = { a, b, c} ; 
	}
	cout << work( ) <<'\n';
	return  0 ; 
}
