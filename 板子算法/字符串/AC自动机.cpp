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

const int N = 2e5+10,M = 6e5+10  ;
const LL mod = 1e9+7, INF = 1e14+10;
const double eps = 1e-7 ;
const ULL  P=  131 ;

int n , m   , k ;

struct ACam{
	struct node{
		int fail ; 
		int ch[26] = { 0 } ; 
	}tr[N]; 
	int cnt = 0 ;
	map<int,int> ref ;
	vector<int> adj[N] ; 
	int ans[M] ; 
	void insert( string &s ,int id ) {
		int u = 0 ;
		for( auto ch : s ) {
			int v = ch - 'a' ;
			if( !tr[u].ch[v] )  tr[u].ch[v] = ++cnt ; 
			u = tr[u].ch[v] ; 
		}
		ref[id] = u ; 
	}
	
	void build( )  {
		queue<int> q ;
		for(int i = 0 ; i <26 ;  ++ i ) {
			if( tr[0].ch[i]) {
				q.push(  tr[0].ch[i] ) ;
				tr[  tr[0].ch[i] ].fail =  0;
			}
		}
		while(q.size()) {
			int u = q.front() ; q.pop() ; 
			for(int i = 0 ; i <26 ; ++ i ) {
				if( tr[u].ch[i]) {
					tr[ tr[u].ch[i]].fail = tr[ tr[u].fail ].ch[i] ; 
					q.push(  tr[u].ch[i]  ) ;
				}else tr[u].ch[ i ] = tr[ tr[u].fail].ch[i ] ;
			}
		}
		for(int i =1; i <=cnt ; ++ i ) {
			adj[ tr[i].fail ].push_back( i  ); 
		}
	}
	
	void query( string &s) {
		int u = 0 ;
		for( char ch : s){
			u = tr[u].ch[ ch- 'a'] ; 
			ans[u] ++ ; 
		}
	}
	
	void get_ans() {
		dfs(  0 ) ;
	}
	
	void dfs(int u ) {
		for(auto v :adj[u]) {
			dfs(v) ;
			ans[u] += ans[v] ; 
		}
	}
	
	
}ac;


void solve(){
	
	string  s; cin >> s; 
	cin >> n ;
	for(int i =1; i <= n ; ++ i ) {
		string t ;cin >> t;
		ac.insert( t , i ) ; 
	}
	ac.build() ; 
	ac.query( s)  ;
	ac.get_ans( ) ; 
	for(int i =1; i <=n ; ++ i ) 
		cout << ac.ans[ ac.ref[i] ] <<'\n';
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
