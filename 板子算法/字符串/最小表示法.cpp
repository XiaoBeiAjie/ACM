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

const int N = 1e6+10,M = 6e5+10  ;
const LL mod = 1e9+7, INF = 1e14+10;
const double eps = 1e-7 ;
const ULL  P=  131 ;

int n , m   , k ;



int get_min(  string s ) {
	int n = s.size() ; 
	s = s + s; 
	int i = 0 ,  j = 1, k = 0 ;
	while( i < n && j < n && k < n ) {
		if( s[i+k] == s[j+k] ) ++ k;
		else if( s[i+k] > s[j+k] ) i += k + 1 , k = 0 ;
		else j  += k + 1 , k = 0 ;
		if( i == j ) ++ j ;
	}
	return min( i , j ) ; 
}


void solve1() { 
	string s;
	
	cin >> s; 
	n = s.size() ; 
	int ans = get_min(s) ;
	s = s + s ;
	cout << s.substr(ans , n) <<'\n';
	
}	

int a[N] ; 

void solve(){
	cin >> n ;
	for(int i =1; i <=n ; ++ i ) cin >>a[i] , a[i + n ] = a[i]  ;
	int i = 1 , j = 2 , k = 0 ;
	while( i <= n && j <= n && k < n  ) {
		if( a[i+k] == a[j+k]) ++ k;
		else if( a[i+k] > a[j+k]) i += k + 1, k  = 0;
		else j += k + 1 , k = 0 ;
		if( i == j ) ++ j ; 
	}
	int ans = min( i , j ) ;
	for(int i = ans , j = 0 ; j < n  ; ++ j , ++ i) cout <<a[i] <<" " ;cout <<'\n';
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
