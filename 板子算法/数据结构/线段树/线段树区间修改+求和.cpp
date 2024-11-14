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
typedef pair<LL , LL> PLL ; 
typedef pair<LL ,int > PLI ;
typedef pair<int,char > PIC ; 
typedef unsigned long long ULL ;

const int N = 1e5+10,M = 6e5+10  ;
const LL mod = 1e9+7, INF = 1e12+10;
const double eps = 1e-7 ;



const ULL  P=  131 ;


int n , m   , k ;

int num[N] ; 
struct tree{
	int l ,r  ;
	LL tag ; 
	LL val ;
};

template<typename T>
class segTree{
	public :
		int size ;
		vector<T> tr;
	segTree( int _size) :size(_size) , tr( (_size+1)*4   ) { }
	segTree( ) : size(0) { }  
	segTree(const segTree &t) {  size = t.size ; tr= t.tr  ; }  
	~segTree( ) { tr.clear() ; }  
	
	void pushup(int x ){
		auto &fa = tr[x] , &left= tr[x<<1 ] , &right = tr[x<<1|1] ; 
		fa.val =  left.val + right.val  ;
	}
	
	void pushdown(int x ) {
		auto &fa = tr[x] , &left= tr[x<<1 ] , &right = tr[x<<1|1] ; 
		if( fa.tag != -1100) {
			left.val = fa.tag*( left.r - left.l +1) ; right.val = fa.tag*(right.r - right.l + 1)  ;
			left.tag =  fa.tag ; right.tag = fa.tag; 
			fa.tag = -1100 ;
		}
	}
	
	void build( int x ,int l ,int r) {
		tr[x] = { l ,r  ,  -1100 , 0}  ;
		if( l == r ) {
			tr[x].val = num[l] ;
			return  ;
		}
		int mid = l + r  >> 1 ;
		build( x<<1 , l , mid ) ; build( x<<1 |1 , mid+ 1, r ) ; 
		pushup(x) ; 
	}
	
	void update(int x ,int l, int r, LL mx) {
		if( tr[x].l >= l && tr[x].r  <=r ) {
			tr[x].val = 1LL*mx*( tr[x].r - tr[x].l + 1) ;
			tr[x].tag = mx ;
			return ; 
		}
		pushdown(x) ; 
		int mid = tr[x].l + tr[x].r  >> 1 ;
		if( l <=mid ) update(x <<1 , l , r ,mx ) ;
		if( r > mid ) update( x<<1| 1, l , r,  mx ) ; 
		pushup(x) ; 
	}
	
	LL query(int x ,int l ,int r ) {
		if( tr[x].l >= l && tr[x].r <=r ) {
			return tr[x].val ; 
		}
		pushdown(x)  ;
		int mid = tr[x].l  + tr[x].r >> 1 ;
		if( r <= mid) return query( x<<1 , l , r )  ;
		if( l > mid ) return query( x<<1 |1 , l , r  )  ;
		return ( query( x<<1 , l , r )  + query( x<<1 |1 , l , r  )) ;
		
	}
};



void solve() { 
	int q;cin >> n >> q ;
	for(int i=1; i <=n ; ++ i)  num[i] = 0; 
	segTree<tree> sg( n + 1 ) ; 
	sg.build( 1, 1, n ) ;
	while(q--){
		int op; cin >> op;
		if( op) {
			int l ,r ;cin >> l  >> r ;
			++ l ; ++r ;
			cout << sg.query( 1 , l , r ) <<endl;
		}else {
			int l , r ;
			LL x; 
			cin >> l >> r >> x ;
			++l ; ++r ;
			sg.update( 1 , l , r,  x ) ; 
		}

	}
}	

int main(){ 	
	ios::sync_with_stdio(false);
	cin.tie( 0 ) ;
	int T;T  =1; 
	while(T-- ){	
		solve() ;  
   	}        
 	return  0 ;
}
