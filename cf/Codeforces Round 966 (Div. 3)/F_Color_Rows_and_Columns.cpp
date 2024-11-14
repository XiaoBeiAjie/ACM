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
#include <array>
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
 
const int N = 5e5+10,M = 4e5+10  ;
const LL mod = 1e9+7 , INF = 1e18+10;
const int inf =  1e8 ; 
const double eps = 1e-7 ;
const ULL  P=  131 ;
LL n , m  , k   ;

int cost[101][101][201] ;

void init( ) {
	for(int i = 0 ; i <= 100 ; ++ i )
		for(int j = 0 ; j <= 100 ; ++ j )
			for(int k = 0 ; k <= 200 ; ++ k )
				cost[i][j][k] = inf ;
	for(int R = 0 ; R <= 100 ; ++ R ){
		for(int C = 0 ; C <= 100 ; ++ C ) {
			for(int r = 0 ; r <= R ; ++ r ) {
				for(int c = 0 ; c <= C ; ++ c ) {
					int &res = cost[R][C][r+c] ;
					res = min(res , r * C + c * R - r * c ) ;
				}
			}
		}
	}
}

void solve( ) {
	cin >> n >> k ;
	vector<int> f( k + 1 , inf ) ; 
	f[0] = 0 ;
	for(int i = 1; i <= n ; ++ i )  {
		int r , c ; cin >> r >> c ;
		auto g = f ;
		for(int j = 0 ; j < k ; ++ j ) {
			for(int v = 1 ;  v <= r + c && j + v <= k ; ++ v ) {
				g[j+v] = min( g[j+v] , f[j] +  cost[r][c][v] ) ;
			}
		}
		swap( f ,g ) ;
	}
	if( f[k] == inf ) cout << -1 <<'\n';
	else cout << f[k] <<'\n';
} 	
 
 
 
int main(){ 	
	ios::sync_with_stdio(false);
	cin.tie( 0 ) ;
	init( ) ; 
	int T ; cin >> T ;
	while(T-- ){	
		solve() ;  
   	}        
 	return  0 ;
}