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

const int N = 5e5+10,M = 6e5+10  ;
const LL mod = 1e9+7, INF = 1e14+10;
const double eps = 1e-7 ;
const ULL  P=  131 ;

int n , m   , k ;


int ne[N] ; 


void get(string s) {
	ne[0] = ne[1 ] = 0 ;
	for(int i =2 , j = 0 ; i < s.size() ; ++ i) {
		while( j && s[j+1] != s[i] ) j = ne[j] ;
		if( s[i] == s[j + 1 ]) ++ j ;
		ne[i] = j ;
	}
}

void solve(){
	string s , t ;
	cin >>s >> t ;
	n = s.size() , m = t.size() ; 
	s = " " + s,  t = " " + t ;
	get( t ) ;
	for(int i =1 , j = 0 ; i <= n ; ++ i ) {
		while( j && s[i] != t[j+1]) j = ne[j] ; 
		if( s[i] == t[j+1]) ++ j ;
		if( j == m  ) cout << i - j  +1  <<'\n' , j =ne[j] ; 
	}
	for(int i =1; i < t.size() ; ++ i)  cout << ne[i] <<" " ; cout <<'\n';
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
