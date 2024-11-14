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

const int N = 1e6+10,M = 6e5+10  ;
const LL mod = 998244353, INF = 1e17+10;
const double eps = 1e-7 ;



const ULL  P=  131 ;


int num[N] ; 
int n ;
struct tree{
	int l ,r  ;
	int tag ; 
	int val ;
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
		fa.val = max( left.val , right.val)  ;
	}
	
	void pushdown(int x ) {
		auto &fa = tr[x] , &left= tr[x<<1 ] , &right = tr[x<<1|1] ; 
		if( fa.tag) {
			left.val = max( left.val , fa.tag) ; right.val = max( right.val , fa.tag)  ;
			left.tag=  max( left.tag , fa.tag) ; right.tag = max( right.tag ,fa.tag) ; 
			fa.tag = 0  ;
		}
	}
	
	void build( int x ,int l ,int r) {
		tr[x] = { l ,r  ,  0 , 0}  ;
		if( l == r ) {
			tr[x].val = num[l] ;
			return  ;
		}
		int mid = l + r  >> 1 ;
		build( x<<1 , l , mid ) ; build( x<<1 |1 , mid+ 1, r ) ; 
		pushup(x) ; 
	}
	
	void update(int x ,int l, int r, int mx) {
		if( tr[x].l >= l && tr[x].r  <=r ) {
			tr[x].val = max( tr[x].val , mx)  ; 
			tr[x].tag = max( tr[x].tag , mx) ;
			return ; 
		}
		pushdown(x) ; 
		int mid = tr[x].l + tr[x].r  >> 1 ;
		if( l <=mid ) update(x <<1 , l , r ,mx ) ;
		if( r > mid ) update( x<<1| 1, l , r,  mx ) ; 
		pushup(x) ; 
	}
	
	int query(int x ,int l ,int r ) {
		if( tr[x].l >= l && tr[x].r <=r ) {
			return tr[x].val ; 
		}
		pushdown(x)  ;
		int mid = tr[x].l  + tr[x].r >> 1 ;
		if( r <= mid) return query( x<<1 , l , r )  ;
		if( l > mid ) return query( x<<1 |1 , l , r  )  ;
		return max( query( x<<1 , l , r )  , query( x<<1 |1 , l , r  ) ) ;
		
	}
};


int main()
{
	n =5 ;
	for(int i =1; i<=n; ++ i) num[i] =  i ; 
	segTree<tree> sg( n);
	sg.build(1 , 1, n ) ;
	for(int i =1; i <=n ; ++ i ) cout << sg.query( 1 , i , i ) <<" " ; cout <<endl;
	for(int i =1 ; i <3; ++ i) sg.update(1 ,i , i, i +10) ; 
	for(int i =1; i +1< n ; ++ i ) cout <<sg.query( 1 , i , i  + 1) <<" " ; cout <<endl;
	return  0 ;
}

