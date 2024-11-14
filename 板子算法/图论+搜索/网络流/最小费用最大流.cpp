
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
LL n , m  , k  , S  , T  ;
int h[N] , e[N] , ne[N] , idx ;
LL f[N] , w[N] , d[N] , incf[N] ; 
int pre[N] ;
bool st[N] ; 
void add(int a, int b , int c , int d ) {
	e[idx] =b, ne[idx] = h[a] ,f[idx] = c, w[idx] = d ,h[a] = idx ++ ; 
	e[idx] = a, ne[idx] = h[b] , f[idx] = 0 , w[idx] = -d , h[b] = idx++ ; 
}

bool spfa( ) {
	queue<int> q; 
	q.push( S) ; 
	for(int i =1; i <=n ; ++ i ) d[i] = INF  ,incf[i] = 0  ; 
	d[S] = 0 ;  incf[S] =INF ;
	st[S] =  true ;
	while(q.size( )) {
		int u = q.front( ) ;q.pop( ) ;
//		cout << u <<" " << incf[u] <<" " << d[u] <<'\n' ; 
		st[u] = false ;
		for(int i = h[u] ;~i ; i =ne[ i]) {
			int j =e[i ] ; 
			if( d[j] > d[u] + w[i] && f[i]) {
				d[j] = d[u] + w[i] ; 
				incf[j] = min(f[i] , incf[u])  ;
				pre[j] = i  ;
				if( !st[j]) {
					st[j] = true ;
					q.push( j  ) ;
				}
			}
		}
	}
	return incf[T] > 0 ; 
}


void EK( LL &flow ,LL &cost ) {
	flow = 0 , cost = 0 ;
	while( spfa( )) {
		LL t =  incf[T];
		flow += t , cost += t *d[T] ; 
//		cout <<t <<" " << d[T] <<'\n';
		for(int i = T ;  i!= S ; i = e[ pre[i] ^1 ]) {
			f[ pre[i] ] -= t ; f[ pre[i] ^ 1 ] +=t ;
		} 
	}
}
 
void solve( ) {
	cin >> n  >> m ; 
	for(int i = 1; i <=n ; ++ i ) 	h[i] = -1 ; idx= 0 ; 
	while( m--) {
		int a, b, c , d ; 
		cin >>a >>b >>c >> d ;
		add(a, b,  c, d  ) ; 
	}
	S = 1 , T = n  ;
	LL flow , cost ;
	EK( flow , cost) ; 
//	cout <<'\n';
	cout << flow <<" " << cost <<'\n' ;
} 	
 
 
 
int main(){ 	
 
	ios::sync_with_stdio(true);
	cin.tie( 0 ) ;
	int T ; T = 1; 
	while(T-- ){	
		solve() ;  
   	}        
 	return  0 ;
}
