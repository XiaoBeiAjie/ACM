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

const int N = 5e5+10,M = 6e5+10  ;
const LL mod = 1e9+7, INF = 1e14+10;
const double eps = 1e-7 ;
const ULL  P=  131 ;

int n , m   , k ;


struct tree{
	int l ,r  ,len  ;
	ULL sum , tag ;
};

template<typename T>
class segTree{
	public :
		int size ;
		vector<T> tr;
		vector<ULL> p ,s ; 
	segTree( int _size) :size(_size) , tr( (_size+1)*4   ) ,p(  _size + 1  ) ,s(  _size + 1  )   { 
		p[0] =  s[0] =  1 ;
		for(int i = 1 ;i <= size ; ++ i ) p[i] = p[i-1]* P ,s[i] = s[i-1] + p[i] ; 
	}
	segTree( ) : size(0) { }  
	segTree(const segTree &t) {  size = t.size ; tr= t.tr  ; }  
	~segTree( ) { tr.clear() ; }  
	
	void pushup(int x ){
		auto &fa = tr[x] , &left= tr[x<<1 ] , &right = tr[x<<1|1] ; 
		fa.sum = left.sum *p[right.len] + right.sum ;   
	}
	
	void pushdown(int x ) {
		auto &fa = tr[x] , &left= tr[x<<1 ] , &right = tr[x<<1|1] ; 
		if( fa.tag != 0 ) {
		 	left.sum = fa.tag *s[left.sum-1] , right.sum = fa.tag*s[right.sum -1 ] ;
			left.tag = right.tag = fa.tag ; 
			fa.tag = 0 ;
		}
	}
	
	void build( int x ,int l ,int r , string &s) {
		tr[x] = { l ,r  , r-l + 1  , 0 , 0 }  ;
		if( l == r ) {
			tr[x].sum = s[l] ; 
			return  ;
		}
		int mid = l + r  >> 1 ;
		build( x<<1 , l , mid ,s ) ; build( x<<1 |1 , mid+ 1, r  ,s ) ; 
		pushup(x) ; 
	}
	
	void update(int x ,int l, int r, ULL v) {
		if( tr[x].l >= l && tr[x].r  <=r ) {
			tr[x].sum = s[  tr[x].len -1  ]*v ; 
			tr[x].tag = v ;
			return ; 
		}
		pushdown(x) ; 
		int mid = tr[x].l + tr[x].r  >> 1 ;
		if( l <=mid ) update(x <<1 , l , r ,v ) ;
		if( r > mid ) update( x<<1| 1, l , r,  v ) ; 
		pushup(x) ; 
	}
	
	ULL query(int x ,int l ,int r ) {
		if( tr[x].l >= l && tr[x].r <=r ) {
			return tr[x].sum ; 
		}
		pushdown(x)  ;
		int mid = tr[x].l  + tr[x].r >> 1 ;
		ULL res= 0 ,left = 0 , right = 0 , len = 0; 
		if( l <=mid ) left = query( x << 1 , l , r ) ;
		if( r > mid ) right = query( x << 1 | 1 , l , r ) , len = min( r -mid ,  tr[x<<1|1].len ) ;
		return left*p[len] + right ;
		
	}
};

string s ;


void solve(){
	cin >> n >> k >> s ;
	segTree<tree> sg1( n ) ,sg2( n ) ;
	string t = s ;  reverse( t.begin() , t.end()) ;
	s = '0'+ s , t = '0' + t ;
	sg1.build( 1, 1 , n ,  s) ,sg2.build( 1, 1 , n , t )  ; 
	while( k --){
		int op ;cin >> op;
		if( op == 1 ){
			int pos ;char ch ; cin >> pos >> ch ;
			sg1.update( 1 ,pos ,pos , ch ) ;
			sg2.update( 1, n + 1 - pos , n + 1 -pos , ch ) ; 
		}else {
			int l ,r ;cin >> l >> r ;
			if( sg1.query( 1 , l , r ) == sg2.query( 1 , n + 1 - r , n + 1 - l )) cout <<"YES\n";
			else cout <<"NO\n";
		}
	}
	
	
}


int main(){ 	
	ios::sync_with_stdio(true);
	cin.tie( 0 ) ;
	int T;T=1; 
	while(T-- ){	
		solve() ;  
   	}        
 	return  0 ;
}
