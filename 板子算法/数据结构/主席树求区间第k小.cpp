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

const int N = 1e6+10,M = 6e5+10  ;
const LL mod = 998244353 , INF = 1e10+10;
const double eps = 1e-7 ;
const ULL  P=  131 ;

LL n , m   , k ;

struct tree{
	int l ,r ;
	LL val ; 
};

LL num[N] ; 

template<typename T>
class chairTree{
	public :
		int size ; 
		vector<T> t ; 
		int cnt ; 
	chairTree( ) :size(0) { } 
	//由于离散化后的m可能很小，而实际产生的记录与n有感，可能会很大，故t的规模需要根据n来确定 
	chairTree(int _size) : size(_size) ,t( 31*N )  ,cnt( 0) { } 
	~chairTree( ) { t.clear() ;} 
	int build(int l ,int r) {
		int cur=  ++cnt ;
		if( l == r ) {
			t[cur].val = 0  ;return  cur; 
		}
		int mid = l + r >> 1 ;
		t[cur].l = build(  l ,mid ) ; 
		t[cur].r = build( mid + 1, r ) ;
		return cur ;
	}
	
	int update( int pre , int l  ,int r  , int val ) {
		int cur = ++cnt ; 
		t[cur] = t[pre] ;  //copy old version  
		t[cur].val  ++ ; 
		if( l == r ) return cur ; 
		int mid = l +r >> 1 ;
		if( val <= mid ) t[cur].l = update( t[cur].l , l , mid , val)  ;
		else t[cur].r = update( t[cur].r , mid+ 1, r ,val ) ;
		return cur ;
	}
	
	int query( int left, int right ,  int  l , int r  ,int k) {
		if( l ==r  ) return   l ; 
		int mid = l + r >> 1 ;
		int v= t[t[right].l].val- t[t[left].l].val ; 	
//		cout << left <<" " <<right <<" " << l <<" " <<r <<" " <<t[t[right].l].val<<" "<<t[t[left].l].val  <<" " << k <<endl;

		if(  k <=v ) return query( t[left].l , t[right].l , l , mid , k ) ;
		return query( t[left].r , t[right].r ,mid + 1, r , k  - v  ) ;
	}
	
};

int root[N] ; 
int a[N]  , b[N]  ;

void solve( ) {
	int q  ; 
	cin >> n  >> q ; 
	for(int i = 1; i <=n ; ++ i )  cin >>a[i] , b[i] = a[i] ; 
	sort( b + 1, b +1  + n ) ;  m = unique( b+ 1, b + 1  + n )  -b -1 ;
	for(int i =1; i <=n ; ++ i )  a[i] = lower_bound( b+ 1 ,b + 1 +  m , a[i] )  -b  ; 
	chairTree<tree> sg( m ) ;
	root[0] = sg.build( 1 , m ) ;
	for(int i =1; i <=n ; ++ i) {
		root[i] =  sg.update( root[i-1] , 1 , m , a[i]) ; 
	}
	while( q--) {
		int l,r, k ; 
		cin >> l >> r >> k ;
//		cout<< sg.query( root[l-1] , root[r] , 1 , m  , k ) <<" " << l <<" " << r <<" " << k <<'\n';
		cout  << b[ sg.query( root[l-1]  ,root[r] , 1, m  , k)]  <<'\n' ;  
	}
}


int main(){ 	
	ios::sync_with_stdio(false);
	cin.tie( 0 ) ;
	int T; T= 1; 
	while(T-- ){	
		solve() ;  
   	}        
 	return  0 ;
}
