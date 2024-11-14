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
	chairTree(int _size) : size(_size) ,t( (_size+1)*24 )  ,cnt( 0) { } 
	~chairTree() {  t.clear() ;}
	int build(int l ,int r) {
		int cur=  ++cnt ;
		if( l == r ) {
			t[cur].val =   num[l ]  ;return  cur; 
		}
		int mid = l + r >> 1 ;
		t[cur].l = build(  l ,mid ) ; 
		t[cur].r = build( mid + 1, r ) ;
		return cur ;
	}
	
	int update( int pre , int l  ,int r ,int pos , LL val ) {
		
		int cur = ++cnt ; 
		t[cur] = t[pre] ;  //copy old version  
		if(  l == r ) {
			t[cur].val = val ; 
		}else {
			int mid = l +r >> 1 ;
			if( pos  <= mid )  t[cur].l  =  update( t[cur].l  , l , mid , pos , val)  ;
			else  t[cur].r = update( t[cur].r  , mid+ 1, r , pos ,val ) ; 
		}
		return cur ;
	}
	
	int query( int cur, int  l , int r  ,int x) {
		if( l ==r  ) return  t[cur].val ; 
		int mid = l + r >> 1 ;
		if( x <=mid ) return query( t[cur].l , l  ,mid, x ) ;
		return query( t[cur].r , mid + 1, r , x ) ;
	}
	
};

int root[N] ;

void solve( ) {
	cin >> n >> m ;
	for(int i = 1 ; i <=n ; ++ i) cin >>num[i] ; 
	chairTree<tree> sg( n ) ;
	root[0] = sg.build(  1 , n )  ;
	for(int i =1; i <= m ;++ i) {
		int version  , op , pos ;
		cin >> version >> op ; 
		if(  op == 1) {
			LL val ;
			cin >> pos >> val ;
			root[i] = sg.update(  root[version] , 1  ,  n  , pos ,val) ; 
		}else {
			cin >> pos ;
			root[i] = root[version] ; 
			cout << sg.query( root[version] ,  1, n, pos )  <<'\n' ; 
		}
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
