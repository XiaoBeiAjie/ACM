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
const LL  INF = 1e14+10;
const double eps = 1e-7 ;
const ULL  P=  131 ;

int n , m   , k ;
LL mod ;
int h[N]  ,e[N] ,ne[N] ,idx ;
LL f[N] ,p[N] ;
void add(int a, int b ){
	e[idx] =b , ne[idx] =h[a ]  ,h[a] = idx++ ; 
}

void dfs(int u, int fa) {
	f[u] = p[u] = 1 ; 
	for(int i = h[u] ;~i ; i =ne[i]) {
		int j =e[i] ;
		if( j == fa) continue ;
		dfs( j , u ) ;
		f[u] = (f[u]*( f[j] +1) ) %mod ;
	}
}

void  dfs1(int u ,int fa) {
	vector<LL >  pre , suf  ;
	pre.push_back( 1)  ,suf.push_back( 1) ; 
	for(int i =h[u] ; ~i ; i =ne[i]) {
		int j = e[i] ; 
		if(  j== fa) continue ; 
		pre.push_back( f[j] + 1) ; suf.push_back( f[j] + 1 ) ; 
	}
	suf.push_back( 1 ) ; 
	for( int i = 1 ; i <pre.size() ; ++ i) pre[i] = ( pre[i] *pre[i-1]) % mod ;
	for(int i = suf.size() -2 ; i >=0 ; -- i) suf[i] = ( suf[i] *suf[i+1]) %mod ;
	for(int i = h[u] ,t= 1 ;~i ; i =ne[i]) {
		int j =e[i] ; 
		if( j == fa ) continue ;
		p[j] = ( pre[t-1]*suf[t+1]%mod*p[u] %mod + 1) %mod ;
		++ t ;
		dfs1( j , u ) ; 
	}
}


void solve() { 
	cin >> n >> mod; 
	memset( h , -1, sizeof h) ; 
	for(int i =1; i < n ; ++ i ) {
		int a,b;cin >> a >>b ;
		add(a,b) ; add(b,a) ; 
	}
	dfs( 1 , -1) ;
	dfs1( 1, -1) ; 
	
	for(int i =1;  i<=n ; ++ i )  cout << f[i]*p[i] %mod <<endl;
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
