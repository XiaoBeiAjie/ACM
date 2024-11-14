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
 
const int N = 5e5+10,M = 5e5+10  ;
const LL mod = 1e9+7 , INF = 1e18+10;
const int inf =  1e8 ; 
const double eps = 1e-7 ;
const ULL  P=  131 ;



LL n , m  , k  ,S,T  ;
int h[N ] ,e[M] ,ne[M]  ,  idx ; 
LL f[N] ,  pre[N] ,d[N] ; 
bool st[N] ; 
vector< vector<int> > ans ;
void add(int a, int b ,LL c  ) {
	e[idx] =b  ,ne[idx] = h[a] , f[idx] = c , h[a] = idx ++ ; 
	e[idx] =a ,ne[idx] = h[b] , f[idx] = 0 , h[b] = idx++ ; 
}

bool  bfs( ) {
	for(int i =1;  i<=n ; ++ i  )  st[i] =false ;
	st[S] = true ; d[S] = INF ;  
	queue<int> q; q.push( S  ) ; 
	while(q.size()) {
		int u =q.front( ) ;  q.pop()  ; 
		for(int i = h[u] ;~i ; i = ne[i]) {
			int j =e[i] ; 
			if (!st[j] && f[i]) {
				st[j] = true ;
				pre[j] = i  ;
				d[j] = min(d[u] , f[i]) ;
				if( j == T) return true ;
				q.push( j ) ;
			}
		}
	}  
	return false ;
}

LL EK( ) {
	LL  flow = 0 ; 
	while( bfs( )) {
		flow += d[T] ; 
		vector<int> res ;
		for(int i  = T ; i != S ; i = e[ pre[i] ^ 1 ]){
			res.push_back( i ) ; 
			f[ pre[i] ] -=  d[T] ;  f[ pre[i] ^1 ]  += d[T] ; 
		}
		res.push_back( S ) ; 
		reverse( res.begin() , res.end() ) ; 
		ans.push_back( res) ; 
 	}
	return flow ; 
}

void solve( ) {
	cin >> n >>  m  ;
	for(int i =1; i <=n ; ++ i )  h[i] = -1 ; idx = 0 ; 
	S = 1 , T = n  ;
	for(int i =1;  i  <=m ; ++ i ) {
		int a,b ;  cin >> a >>b ; 
		add(a,b,1) ; 
	}
	
	cout << EK( )   <<'\n'; 
	for(auto res : ans ) {
		cout <<res.size() <<'\n' ;
		for( auto u  : res ) cout << u <<" "; cout <<'\n';
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
