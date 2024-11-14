
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
typedef long long LL ;

int n , m  , k , q ;
const int inf = 1e8  ;
LL sum[N<<2] , tag[N<<2] , mx[N<<2] , mn[N<<2] ; 
LL a[N] ; 
void pushup(int x ) {
    sum[x] = sum[x<<1]  + sum[ x << 1 | 1 ] ;
    mx[x] =  max( mx[x<<1] , mx[x<<1 | 1 ]) ;
    mn[x] =  min( mn[x<<1] , mn[x << 1 | 1 ]) ; 
}

void pushdown( int x ,int l ,int r  ) {
    if( tag[x]) {
        int mid = l + r >> 1 ;
        sum[x<<1] += 1ll *( mid - l + 1 )* tag[x] ;
        sum[x<<1|1] += 1ll *( r - mid ) * tag[x] ;
        mx[x<<1] += tag[x] ; mx[x<<1|1] += tag[x] ;
        mn[x<<1] += tag[x] ; mn[x<<1|1] += tag[x] ; 
        tag[x<<1] += tag[x] ; tag[x<<1|1] += tag[x] ; 
        tag[x] = 0 ; 
    }
}


void add(int x, int l ,int r ,int L , int R , int d ) {
    if( L <= l && r <= R ) {
    	sum[x] += 1ll * ( r - l + 1 ) * d ; 
        mx[x] += d ; mn[x] += d ;tag[x] += d ;
        return ;
    }
    pushdown( x , l , r ) ;
    int mid = l + r >> 1 ;
    if( L <= mid ) add( x << 1 , l , mid , L , R , d ) ;
    if( R > mid ) add( x << 1 | 1 , mid + 1 ,r  , L , R , d ) ;
    pushup( x ) ;
}

LL query( int x, int l ,int r, int L , int R ) {
    if( L <= l && r <= R ) {
        return sum[x];
    }
    pushdown( x , l , r  ) ;
    int mid = l + r >> 1 ;
    LL res = 0;
    if( L <= mid ) res += query( x << 1 , l , mid , L , R  ) ;
    if( R > mid )  res += query( x << 1 | 1 , mid + 1 ,r  , L , R  ) ;
    return res ;
}
int querymx(int x, int l ,int r , int L ,int R , LL s) {
    if( l == r ) return mx[x] >= s ? l : inf ;
    int mid = l + r >> 1 ;
    pushdown( x , l , r ) ;
    if(  L <= l && r <= R ) {
        if( mx[x] < s ) return inf ;
        if( mx[x << 1 ] >= s  ) return querymx( x << 1 , l , mid , L , R , s ) ; 
        return querymx( x << 1 | 1 , mid + 1 , r,  L , R , s ) ;
    }
	int res = inf ;
	if( L <= mid ) res = min( res ,querymx( x << 1 , l , mid , L , R , s )) ;
	if( R > mid ) res = min(res ,querymx( x << 1 | 1 , mid + 1 , r,  L , R , s )) ;
	return res ; 
}

int querymn(int x, int l ,int r , int L ,int R , LL s) {
    if( l == r ) return mn[x] <= s ? l : inf ;
    int mid = l + r >> 1 ;
    pushdown( x , l , r ) ;
    if(  L <= l && r <= R ) {
        if( mn[x] > s ) return inf ; 
        if( mn[x << 1 ] <= s  ) return querymn( x << 1 , l , mid , L , R , s ) ;
        return querymn( x << 1 | 1 , mid + 1 , r , L , R  , s ) ;  
    }
	int res = inf ;
	if( L <= mid ) res = min(querymn( x << 1 , l , mid , L , R , s ) , res ) ;
	if( R > mid ) res = min(querymn( x << 1 | 1 , mid + 1 , r,  L , R , s ) ,res ) ;
	return res ; 
}


void build( int x, int l , int r ) {
    if( l == r ) {
        sum[x] = mx[x] = mn[x] = a[l] ; return ;
    }
    int mid = l + r >> 1 ;
    build( x << 1 , l , mid ) ; build( x << 1 | 1 , mid + 1 , r ) ;
    pushup( x ) ;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    // cin >> n >> m >> k >> q ;
    vector<char> op( k + 1  ) ;
    // vector<int> a( k + 1 ) ;
//    n = 5000  ;
//    for(int i = 1; i <= n ; ++ i ) a[i] = rng( ) % n  ;
	cin >> n >> m ;
	for(int i = 1; i <= n ; ++ i ) cin >> a[i] ; 
	build( 1 , 1 , n ) ;
    for(int i = 1 ; i <= m ; ++ i ) {
//       int op = rng( ) % 4 , l ,r  ; 
		int op ; cin >> op ;
        if( op == 1 ) {
        	int l , r , d  ;
        	cin >> l >> r >> d ;
        	add( 1 , 1 , n  , l , r , d ) ;
        }else if( op == 2 ) {
        	int l , r  ;
        	cin >> l >> r ;
        	cout << query( 1 , 1,  n ,l , r )  <<'\n' ;
        }else if( op == 3 ) {
        	int l , r , p ;
        	cin >> l >> r >> p ;
        	cout << querymx( 1 , 1 , n , l , r , p )  << '\n' ;
        }else if( op == 4 ) {
        	int l , r , p ;
        	cin >> l >> r >> p ;
        	cout << querymn( 1 , 1 , n , l , r , p )  << '\n' ;
        }
//        for(int j = 1 ; j<= n ; ++ j ) cout << query(1 ,1, n , j , j ) <<" " ;cout <<'\n';
    }
    // for(int i = 1 ; i <= n ; ++ i )  cin >> op[i] >> a[i]  ;
    // for(int i = 1 ; i <= n ; ++ i ) a[i]

}   
int main()
{
	ios::sync_with_stdio(false);
	cin.tie( 0 ) ;
    int t; t = 1 ;
    while(t--)
    solve();
}
