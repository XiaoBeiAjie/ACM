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

const int N = 1e5+10,M = 6e5+10  ;
const LL mod = 1e9+7, INF = 1e14+10;
const double eps = 1e-7 ;
const ULL  P=  131 ;

int n , m   , k ;

template<typename T> 
class DSU{
	public :
		int size ;
		vector<T> fa ;
		vector<T> siz ;
	DSU( ) :size(0) {}
	DSU( int _size) : size(_size) , siz(_size+1 ,1) ,fa(_size+1)    {
		for(int i = 0 ; i <=size; ++ i) fa[i] = i  ;
	}
	DSU( const DSU &_t) {	size = _t.size ;  fa = _t.fa  ; siz = _t.siz  ;  }
	~DSU( ) { fa.clear() , siz.clear()  ; } 
	int find( int x ) {
		if( fa[x] == x ) return x ;
		return fa[x] = find( fa[x]); 
	}
	void merge( int a ,int b) {
		int pa = find( a) ,  pb=  find(b ) ; 
		if( pa ==pb) return  ;
		siz[pa] += siz[pb] ; 
		fa[pb] = pa ;
	}
	
	bool same(int a ,int b ){
		return find(a) == find(b ) ; 
	}
	
};

void solve() { 
	cin >> n >> m ; 
	DSU<int> dsu( n )  ;
	while( m --) {
		int a,b; cin >>a >>b ;
		dsu.merge( a,b) ;
	} 
	vector<int> ans ( n + 1 ) ; 
	int cnt = 0 ;
	for(int i = 1;  i <=n ; ++ i ) if( dsu.find(i) == i )  ans[i] = ++cnt ;
	cout <<cnt <<'\n' ; 
	for(int i =1; i  <=n ; ++ i ) cout << ans[dsu.find(i)] <<" " ; cout <<'\n';
	
}	

int main(){ 	
	ios::sync_with_stdio(false);
	cin.tie( 0 ) ;
	int T;T=1; 
	while(T-- ){	
		solve() ;  
   	}        
 	return  0 ;
}
