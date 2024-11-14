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
const int inf =  1e9 ; 
const double eps = 1e-7 ;
const ULL  P=  131 ;
LL n , m    ;

LL a[N] ; 
LL k[N<<2] , d[ N << 2 ] ,sum[ N << 2 ];


void pushup(int x ) {
	sum[x] = sum[ x << 1 ] + sum[ x << 1 | 1 ];
}

void pushdown(int x ,LL K , LL D , LL len ) {
	sum[x] += ( K + ( K + (len -1 ) * D ) ) * len/2 ;
	// sum[x] += len * K + len *( len -1)/2 *D ;
	k[x] += K ; d[x] += D ;
}

void pushdown(int x ,int l , int r  ) {
	if( ! k[x]  && !d[x]  ) return ;
	int mid = l + r >> 1 ;
	pushdown( x << 1 ,  k[x] , d[x] , mid - l + 1   ) ;
	pushdown( x << 1 | 1 , k[x] + 1ll *( mid - l + 1 ) * d[x] , d[x] , r - mid   ) ;
	k[x] = d[x] = 0 ;
}

void build(int x ,int l ,int r ) {
	if( l == r ) {
		sum[x] = a[l] ; return ;
	}
	int mid = l + r >> 1 ;
	build( x << 1  , l , mid ) ;build( x << 1 | 1 , mid + 1 , r ) ;
	pushup( x );
}

void update( int x ,int l , int r ,int L ,int R ,int K , int D ) {
	if( L <=l && r <= R ) {
		pushdown( x , K ,D , r -l +1  ) ;
		return ;
	}
	pushdown( x , l , r ) ;
	int mid = l + r >> 1 ;
	if( R <= mid ) update( x << 1 , l , mid , L , R , K , D ) ;
	else if( L > mid ) update( x << 1 | 1 , mid + 1 , r , L , R , K , D );
	else {
		update( x << 1 , l , mid ,L  , mid ,  K , D ) ;
		update( x << 1 | 1 , mid + 1 ,r , mid + 1  , R , K + 1ll*( mid - L + 1 )*D , D  ) ;
	}
	pushup( x ) ;
}


LL query(int x,int l ,int r ,int L , int R ) {
	if( L <= l && r <= R )return sum[x] ;
	pushdown( x , l , r ) ;
	int mid = l + r >> 1 ;
	LL res= 0 ;
	if( L <=mid )res += query( x << 1 , l , mid , L , R );
	if( R > mid ) res += query( x << 1 | 1 , mid +1 , r ,L ,  R );
	return res;
}



void solve( ) {
	cin >> n >> m ;
	for(int i =1; i<=n ; ++ i ) cin >>a[i] ;
	build( 1 ,1 , n ) ;
	while( m -- ) {
		int op,a,b; cin >> op >> a >> b ;
		if( op == 1 ) update( 1 , 1 ,n , a ,b , 1 ,1 ) ;
		else cout << query( 1 ,1 , n , a, b) <<'\n';
	}
} 	
 
 
 
int main(){ 	
	ios::sync_with_stdio(false);
	cin.tie( 0 ) ;
	int T ; T =1; 
	while(T-- ){	
		solve() ;  
   	}        
 	return  0 ;
}
