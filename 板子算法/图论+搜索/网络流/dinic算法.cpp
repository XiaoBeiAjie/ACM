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



LL n , m  , k  ,S,T  ;
int h[N ] ,e[M] ,ne[M]  ,  idx ; 
LL f[N] , cur[N] , d[N ] ; 

void add(int a, int b ,LL c  ) {
	e[idx] =b  ,ne[idx] = h[a] , f[idx] = c , h[a] = idx ++ ; 
	e[idx] =a ,ne[idx] = h[b] , f[idx] = 0 , h[b] = idx++ ; 
}

bool bfs( ) {
	for(int i = 0; i <=n+ m + 1  ; ++ i ) d[i] = -1 ;
	d[S] = 0 ; cur[S] = h[S] ; 
	queue<int> q; q.push( S) ; 
	while(q.size() ) {
		int  u = q.front()  ;q.pop() ;
		for(int i =h[u]; ~i; i = ne[i]){
			int j = e[i] ; 
			if(  d[j] == -1 && f[i]) {
				d[j] = d[u] + 1 ;
				cur[j] = h[j] ; 
				if( j == T) return true ;
				q.push( j ) ; 
			}
		}
	}
	return false ;
}

LL dfs(int u , LL limit) {
	if( u == T)  return  limit ;
	LL flow = 0 ;
	for(int i = cur[u] ;~i &&  flow < limit ; i = ne[i]) {
		cur[u] = i ; 
		int j = e[i] ; 
		if( d[j] == d[u] + 1 && f[i]) {
			LL  t = dfs( j ,  min(f[i] , limit - flow ))  ;
			if( !t ) d[j] = -1 ;
			f[i] -=t ; f[i^1] += t ; flow += t ;
		}
	}
	return flow ;
}


LL dinic( ) {
	LL res=  0 , flow = 0 ; 
	while( bfs( )) while( flow = dfs( S , INF )) res += flow ;
	return res ;
}

void solve( ) {
	cin >> n >>  m  >> k ; 
	for(int i = 0; i <=n  + m  + 1  ; ++ i )  h[i] = -1 ; idx = 0 ; 
	S =  0  , T = n + m  + 1 ; 
	for(int i =1; i <=n ; ++ i )add( S , i , 1 ) ;
	for(int i = n + 1 ; i <=n + m  ; ++ i ) add( i , T , 1 ) ;
	for(int i =1;  i  <= k  ; ++ i ) {
		int a,b ;  cin >> a >>b ;
		add(a,b + n ,1) ; 
	}
	cout <<dinic( ) <<'\n'; 
	for(int i = 0  ; i<=idx ; i +=2 ) {
		if( !f[i] && e[i] > n &&  e[i^1] <=n   ) 
			cout << e[i^1] <<" "  << e[i] - n  <<'\n';
	}
} 	
 
 
 
int main(){ 	
 
	ios::sync_with_stdio(true);
	cin.tie( 0 ) ;
	int T ; T= 1 ;
	while(T-- ){	
		solve() ;  
   	}        
 	return  0 ;
}
