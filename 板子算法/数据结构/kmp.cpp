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

const int N = 6e5+10,M = 6e5+10  ;
const LL mod = 998244353 , INF = 1e10+10;
const double eps = 1e-7 ;
const ULL  P=  131 ;

LL n , m   , k ;

int ne[N] ; 


void init(string &t) {
	ne[0] = ne[1] = 0  ;
	for(int j = 0 , i = 2; i <=m ; ++ i) {
		while(j && t[j+1]!= t[i]) j = ne[j] ; 
		if( t[j+1] == t[i]) ++ j ;	
		ne[i] = j ; 
	}
}
vector<int> ans ; 

void kmp(string s, string t) {
	for(int i= 1 , j = 0 ;  i <= n ;++ i) {
		while( j && t[j+1] != s[i]) j = ne[j] ; 
		if( t[j+1] == s[i]) ++ j ;
		if( j == m ) {
			cout <<   i - j + 1 <<'\n' ;  j =ne[j] ; 
		}
	}
}

void solve( ) {
	string s , t ; cin >>s >> t ;
	n = s.size() ; m = t.size() ; 
	s = " " + s;  t =  " " + t ;
	init(  t )  ; 
	kmp(  s, t ) ; 
	for(int i =1; i <=m; ++ i) cout <<ne[i] <<" " ; cout <<'\n' ; 
	
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
