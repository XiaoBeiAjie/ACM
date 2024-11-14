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

const int N = 3e5+10,M = 6e5+10  ;
const LL mod = 998244353 , INF = 1e10+10;
const double eps = 1e-7 ;
const ULL  P=  131 ;

LL n , m   , k ;

int id  ,st[N] ,ans[N] , f[N]; 


//  不进行dAG优化则，fail时会多次跳节点，时间复杂度上界 O( mL) ,trie图版本 
// 优化后可做到线性 
// sum 函数无法获得重复子串 ，需要dfs 统计字数 
stack<int> stk ; 
class AC_automation{
	public:
		int size ,cnt  ; 
		vector<int> fail , num ; 
		vector<vector<int> > tr  ;
	AC_automation():size( 0 ) ,cnt( 0) { }
	AC_automation( int _size):size( _size) , cnt( 0) ,fail(_size +1 , 0 ) ,num(_size+1 , 0)  ,tr( _size+1 ,vector<int>(26, 0)) { }
	void add( const string &s) {
		int root = 0 ; 
		for(int i = 0 ; i < s.size() ; ++ i) {
			if( !tr[root][s[i] -'a']) tr[root][ s[i] -'a' ] = ++cnt ;
			root = tr[root][s[i] -'a'] ; 
		}
		num[root] ++ ; ans[id] = root ;
	}
	
	void build( ) {
		queue<int> q; 
		for(int i = 0 ; i < 26; ++ i)  if( tr[0][i] ) q.push( tr[0][i] ) ;
		while(!q.empty()) {
			int u = q.front() ;  q.pop() ; 
			stk.push( u ) ; //此处为统计重复串的工作 
			for(int i = 0 ; i <26 ; ++ i ) {
				int v= tr[u][i] ; 
				if( v ) {
					fail[v] = tr[fail[u]][i] ;  q.push( v)  ; 
					//此处为优化匹配作拓扑的准备 
//					inv[ fail[v]] ++ ;
				}else tr[u][i] = tr[fail[u]][i] ; 
			}
		}
	}
	// 计算模式串出现在s的个数  
	int AC_num( string &s) {
		int root = 0 , ans = 0 ;
		for(int i = 0 ; i < s.size() ; ++ i) {
			root = tr[root][s[i] -'a'] ;
			int   u  = root ;
			//此处可以优化， 节点会被重复跳 
			while( u && num[u] != -1) {
				ans += num[u] ; 
				num[u] = -1 ; //访问过的防止重复计数 
				u =  fail[u ] ; 
			}
		}
		return ans ;
	} 
	
	//统计各模式串出现的总数 
	void AC_sum( string &s) {
		int root = 0  ;
		for(int i = 0 ; i < s.size() ; ++ i ) {
			root = tr[root][s[i] -'a'] ; 
			int u =  root ;
			//此处可以优化， 节点会被重复跳 
			for( ; u ;  u = fail[u])  ans[ st[u] ] ++ ; 
		}
	}
	
//	//DAG优化后 
//	void AC_sum1( string &s ) {
//		int root = 0 ; 
//		for(int i = 0 ; i <s.size() ; ++ i  ) {
//			root= tr[root][s[i]  -'a']  ;
//			f[root] ++ ; 
//		}
//		queue<int> q ;
//		for(int i =1; i <=cnt ;++ i) if(!inv[i]) q.push( i ) ; 
//		while(!q.empty()) {
//			int u = q.front() ; q.pop() ;
//			int v =fail[u] ; 
//			ans[st[u]] = f[u] ;
//			if( -- inv[v] == 0 ) q.push( v)  ;
//			f[v] += f[u]  ;
//		}
//	}
	
	// DFS建图 ,计算重复情况 
	void AC_sum2( string &s ) {
		int root = 0 ; 
		for(int i = 0 ; i <s.size() ; ++ i  ) {
			root= tr[root][s[i]  -'a']  ;
			f[root] ++ ; 
		}
		while(!stk.empty()) {
			int t= stk.top()  ; stk.pop() ; 
			f[ fail[t]] +=f[t] ;
		}
		
		
	}
	
	
	
};

string s[N] ; 

void solve( ) {
	id  =  0 ; 
	AC_automation ac( N)  ;
	cin >> n ;
	for(int i =1; i <=n ; ++ i ) {
		id = i ; 
		cin >>s[i] ; 
		ac.add( s[i])  ; 
	}
	ac.build() ; 
	string t ;cin >> t ;
	ac.AC_sum2( t ) ; 
	for(int i = 1; i <=n ; ++ i) {
		cout<< f[ans[i]] <<'\n' ;
	}
	cout <<endl;
	for(int i = 0 ; i <= ac.cnt ;++ i) f[i] = ans[i] = 0  ; 
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
