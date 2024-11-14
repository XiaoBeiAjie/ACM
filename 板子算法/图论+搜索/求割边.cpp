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

const int N = 1e4+10,M = 6e5+10  ;
const LL mod = 998244353 , INF = 1e10+10;
const double eps = 1e-7 ;
const ULL  P=  131 ;

// tarjan算法求无向图点双连通分量 , 时间复杂度  ( N + E )   
//注意：使用模板时， 请保证不存在自环 

class Tarjan {
	public :
		int size ; 
		vector< vector<int> > adj ; 
		vector<int>  dfn , low  ;
		vector<bool> st ;  
		vector< pair<int,int> > ans ; 
		vector< int> id ; 
		vector<vector<int>> Ecc ;
		int timestop ,cnt ; 
		stack<int> stk ; 
	Tarjan( ):size( 0 ) { }
	Tarjan( int _size) : size(_size) , id( _size + 1 ,0) ,dfn(_size+1, 0 ) ,low(_size+1, 0 )  , adj(_size+1) ,st(_size+1 , false) ,timestop(0) ,cnt(0){}
	Tarjan( const Tarjan &_t) {
		size = _t.size ;dfn = _t.dfn ;low = _t.low;
		timestop = _t.timestop ; cnt = _t.cnt ; st = _t.st ;
	}
	~Tarjan( ) { dfn.clear( ) ; low.clear() ;  } 
	void addedges(int a, int b ) {
		adj[a].push_back( b) ; 
	} 
	void run( ) {
		for(int i=1; i <=size; ++ i) if(!dfn[i]) tarjan( i , i)  ;
	}
	
	void tarjan(int u  ,int fa ) {
		dfn[u] = low[u] = ++ timestop ; 
		stk.push( u ) ;
		for(auto son  : adj[u]) {
			if( son == fa) continue ;
			if(!dfn[son]) {
				if( son == fa) continue ;
				tarjan(  son , u  ) ; 
				low[u] = min( low[u] , low[son]) ;
				if( dfn[u] < low[son]) ans.push_back( { u , son }) ;
			}else low[u] = min( low[u] , dfn[son]) ; 
		}
		if( dfn[u] == low[u] ) {
			int now = Ecc.size() ;
			vector<int> ecc ; 
			while( stk.top() != u ) {
				id[ stk.top() ] =  now ;
				ecc.push_back( stk.top()) ; stk.pop( ) ; 
			}
			id[u] = now ;
			stk.pop() ;
			Ecc.push_back(  ecc ) ;
		}
	}
	
};


int n ,  m ;
int h[N] ,e[M] ,ne[M] , idx ;
void add(int a,int b ) {
	e[idx] =b, ne[idx] = h[a] , h[a] =idx++ ; 
}


void solve( ) {
	cin >> n >> m ;
	Tarjan  t( n ) ; 
	while( m--) {
		int a, b;cin >>a >>b ;
//		++a , ++b ; 
		t.addedges( a ,b) ; t.addedges( b ,a) ; 
	}
	t.run() ; 
	cout <<t.ans.size() <<'\n';
//	for(auto &res  : t.ans ) if( res.x > res.y )swap( res.x , res.y) ;
//	sort( t.ans.begin() , t.ans.end()) ;
	for(auto res : t.ans) cout << res.x  <<" " <<res.y   <<'\n' ;
}


int main(){ 	
	ios::sync_with_stdio(false);
	cin.tie( 0 ) ;
	int T; T =1 ; 
	while(T-- ){	
		solve() ;  
   	}        
 	return  0 ;
}
