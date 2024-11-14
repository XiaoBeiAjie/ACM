// Problem: Easy Integration
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/65260/J
// Memory Limit: 524288 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
 
const int N = 2e6+10,M = 4e5+10  ;
const LL mod = 998244353 , INF = 1e18+10;
const int inf =  1e8 ; 
const double eps = 1e-7 ;
const ULL  P=  131 ;
LL n , m  , k   ;

LL fab[N] , inv[N] ;
LL pre[N] , suf[N] ; 
LL qmi( LL a ,LL b  ){
	LL res= 1; 
	while(b) {
		if (b & 1) res = (res *a) %mod ;
		b >>= 1; 
		a = (a *a) % mod ;
	}
	return res; 
}
void init( ) {
	fab[0] = inv[0 ] = 1 ;
	for(int i =1 ; i < N ; ++ i ){
		fab[i] = ( fab[i-1]  * i ) %mod ;
		inv[i] = inv[i-1] * qmi( i  , mod-2 ) %mod ;
	}
}

inline LL C( LL n , LL m ) {
	return fab[n] *inv[n-m] %mod * inv[m] % mod ;
}

void solve( ) {

	LL ans =0 ;  
	pre[0] =  n+ 1 ;
	for(int i =1 ;i  <=n ; ++ i )  pre[i] = pre[i-1] *( n + 1  + i ) %mod ;
	suf[n] = 2*n + 1 ;
	for(int i = n-1 ; i >=0 ; -- i ) suf[i] = suf[i+ 1] * ( n + i + 1 ) %mod ;  
	for(int i = 0 ; i <= n ; ++ i ) {
		LL p = ( i == 0)? 1  : pre[i-1] ;
		LL s = ( i == n ) ? 1 : suf[i+1] ; 
		ans = ( ans + C( n , i) *( ( i & 1 )? -1 : 1  )*p %mod *s %mod  ) %mod ;
	}
	ans = (ans * qmi( pre[n] , mod -2 )) %mod ;
//	cout << (ans + mod) %mod <<'\n';
	
} 	
 
 
 
int main(){ 	
 	init( ) ; 
	ios::sync_with_stdio(true);
	cin.tie( 0 ) ;
	n = 1e4 ; 
	while(  n <=1e5 ){	
		solve() ; 
   	}        
 	return  0 ;
}
