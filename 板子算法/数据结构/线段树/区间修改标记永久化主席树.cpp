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
 
const int N = 3e5+10,M = 1e8+10  ;
const LL mod = 1e9+7 , INF = 1e18+10;
const int inf =  1e8 ; 
const double eps = 1e-7 ;
const ULL  P=  131 ;
int n , m  , k   ;


struct tree{
	int ls ,rs  ;
	LL tag , sum  ;
}tr[N*75];

int root[N] ,tot ;


void build( int &u ,int l , int r ) {
	u = ++tot ; 
	tr[u] = { 0 , 0 , 0 , 0  } ;
	if( l == r ) return ;
	int mid = l + r >> 1  ;
	build( tr[u].ls , l , mid ) ; build( tr[u].rs , mid + 1 , r ) ; 
}

void update(int &u , int v ,int l ,int r , int L ,int R ,LL add ) {
	u = ++tot ;  tr[u] = tr[v] ;  tr[u].sum += add*( R- L  + 1 )  ; 
	if( l == L && r == R ) {
		tr[u].tag  += add ; return ;
	}
	int mid = l+r >>1 ;
	if( R <= mid ) update(tr[u].ls , tr[v].ls , l , mid , L , R , add ) ;
	else if( L > mid ) update( tr[u].rs , tr[v].rs, mid + 1, r , L , R , add ) ;
	else {
		if( L <= mid ) update( tr[u].ls , tr[v].ls , l , mid , L , mid , add ) ;
		if( R > mid ) update( tr[u].rs,  tr[v].rs , mid +1 , r , mid + 1 , R , add ) ; 
	}
}

LL query(int u , int v , int l ,int r ,int L , int R  ,LL addv , LL addu ) {
	if( L <= l && R >= r ) return  tr[u].sum + addu*( r - l +  1) -tr[v].sum - addv*( r - l + 1)  ;
	int mid =  l  + r >> 1; LL res= 0 ;
	if( L  <= mid ) res += query( tr[u].ls , tr[v].ls , l , mid , L , R , addv + tr[v].tag ,  addu + tr[u].tag  ) ; 
	if( R > mid )  res += query( tr[u].rs , tr[v].rs , mid + 1, r , L , R , addv + tr[v].tag ,addu + tr[u].tag ) ;
	return res ;
} 


int h[N] , e[N] , ne[N] , idx  ;
PII t[N] ; 
void add(int a,int b ) {
	e[idx] = b, ne[idx ] = h[a] , h[a] = idx++ ; 
} 

int dfn[N] , lst[N] , ts ;  
void dfs(int u ) {
	dfn[u] = ++ts ;
	update( root[ts] , root[ts-1] , 1 , n, t[u].x,  t[u].y , 1 ) ; 
	for(int i =h[u] ; ~i ; i =ne[i]) {
		int j =e[i] ;
		dfs( j  ) ;  
	}
	lst[u] =  ts ;
}

void solve( ) {
	scanf("%d %d",&n ,&m) ; 
	for(int i =1; i <=m +1; ++ i ) h[i] = -1 ; 
	build( root[0] ,1,  n );
	t[1] =  {  1 , n } ; 
	for(int i = 1 ; i <=m ; ++ i) {
		int u ,v , l , r ;scanf("%d %d %d %d", &u , &v, &l , &r ) ;
		add( u , v) ;  t[v] = { l , r } ; 
	}
	dfs( 1 )  ; 
	scanf("%d " , &k);
	for(int i =1; i <= k ; ++ i ) {
		int u , l , r ; scanf("%d %d %d", &u ,&l , &r ) ;
		LL res = query( root[ lst[u] ] , root[ dfn[u] - 1] , 1 ,  n , l ,r  , 0 , 0 ) ;
		printf("%lld\n", res) ;
	}	
} 	
 
 
 
int main(){ 	
	ios::sync_with_stdio(false);
	cin.tie( 0 ) ;
	int T ;  T = 1 ;
	while(T--){	
		solve() ;  
		
   	}        
 	return  0 ;
}
