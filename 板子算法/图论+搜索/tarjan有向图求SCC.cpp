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

// tarjan算法求有向图强连通分量 , 时间复杂度  ( N + E )   

class Scc {
	public :
		int size ; 
		vector< vector<int> > adj ; 
		stack<int> stk ; 
		vector<int>  dfn , low ,id  ;
		vector<bool >  st ;
		vector< vector<int> > scc ;
		int timestop ,cnt ; 
	Scc( ):size( 0 ) { }
	Scc( int _size) : size(_size) , dfn(_size+1, 0 ) ,low(_size+1, 0 ) , id(_size+1 , 0) ,st( _size + 1, false) , adj(_size+1) ,scc(_size+1) ,timestop(0) ,cnt(0){}
	Scc( const Scc &_t) {
		size = _t.size ; stk = _t.stk ; dfn = _t.dfn ;low = _t.low;id = _t.id; 
		st = _t.st ; timestop = _t.timestop ; cnt = _t.cnt ; scc =_t.scc ;
	}
	~Scc( ) { dfn.clear( ) ; low.clear() ; id.clear() ; st.clear() ; scc.clear() ;while(!stk.empty()) stk.pop( ); } 
	void addedges(int a, int b ) {
		adj[a].push_back( b) ; 
	} 
	void run( ) {
		for(int i=1; i <=size; ++ i) if(!dfn[i]) tarjan( i)  ;
	}
	
	void tarjan(int u  ) {
		stk.push( u ) ; st[u] = true ;
		dfn[u] = low[u] = ++ timestop ; 
		for(auto son  : adj[u]) {
			if( !dfn[son]) {
				tarjan( son) ; 
				low[u] = min( low[u] ,low[son]) ;
			}else if( st[son]) low[u] =min( low[u] ,dfn[son]) ;
		}
		if( low[u] == dfn[u] ) {
			int v ;  
			++cnt ; 
			do{
				v = stk.top() ;  stk.pop() ; 
				id[v] = cnt ;
				scc[cnt].push_back( v) ;
				st[v] = false ;
			}while( v !=u )  ;
		}
	}
	
	bool same( int a, int b ) {
		return id[a] == id[b] ; 
	}
	
	int getsize(int x ) { return scc[x].size()  ;}
	
};


int n ,  m ;
int h[N] ,e[M] ,ne[M] , idx ;
void add(int a,int b ) {
	e[idx] =b, ne[idx] = h[a] , h[a] =idx++ ; 
}


void solve( ) {
	cin >> n >> m ;
	Scc sc(n) ;
//	memset(h , -1, sizeof  h )  ; idx= 0 ;
	while( m--) {
		int a,b;cin >>a >> b ;
//		add(a,b) ; 
		if( a ==b) continue ;
		sc.addedges( a ,b) ; 
	}
	sc.run() ; 
	if( sc.cnt == 1 ) cout<<"YES\n";
	else {
		cout<<"NO\n";
		for(int i =1; i <=n ; ++ i )	
			if( sc.id[i] == 1 )  {
				cout << i <<" "; break; 
			}
		for(int i =1; i <=n  ;++ i ) {
			if( sc.id[i] == 2 ){
				cout << i <<" " ;break ;
			}
		}
	}
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
