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

const int N = 3e7+10,M = 6e5+10  ;
const LL mod = 1e9+7, INF = 1e14+10;
const double eps = 1e-7 ;
const ULL  P=  131 ;

int n , m   , k ;

int d[N] ; 

string manacher( string  t) {
	string s ;  s += '@' ; 
	for(auto ch : t )  s +='#' , s += ch ; 
	s += "#$" ; 
	int mid = 1 , r= 1  , len = 0  ,ans = 0  ;
	for(int i = 1  ; i < s.size() ; ++ i ) {
		if( i < r   )  d[i] = min( d[(mid<<1) - i]  , r - i  ) ;
		else d[i] = 1 ;
		while( s[ i - d[i]] == s[i + d[i]] ) ++d[i] ;
		if( i + d[i]  > r )  r = i + d[i]  , mid = i ; 
		if( d[i] > len ) ans = i , len = d[i] ; 
	}
	cout << len <<'\n';
	string res ;
	for(int i = ans - len + 1 ;  i <= ans + len -1 ; ++ i   ) {
		if( s[i] != '#') res += s[i] ; 
	}
	return res ;
} 


void solve(){
	string  s ; cin >> s ;
	string t = manacher( s ) ;
	cout << t <<'\n';
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
