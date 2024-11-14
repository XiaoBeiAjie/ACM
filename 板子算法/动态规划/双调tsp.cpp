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
typedef pair<LL , LL> PLL ; 
typedef pair<LL ,int > PLI ;
typedef pair<int,char > PIC ; 
typedef unsigned long long ULL ;

const int N = 1e3+10,M = 6e5+10  ;
const LL mod = 998244353, INF = 1e12+10;
const double eps = 1e-7 ;



const ULL  P=  131 ;


int n , m  ;


double dist[N][N] ; 
double f[N][N] ; 
double x[N] ,y[N]; 


double dis( int a  ,int b  ) {
	double dx = x[a] -x[b] , dy = y[a] -y[b] ; 
	return sqrt( ( dx*dx) +  (dy*dy) )  ; 
}

void solve() {
	
	/*
	初始化： f[0][i] =  f[0][i-1] + dis( i-1, i ) ,   f[0][0] = 0  
	转移过程： 
		由于 i <= j 与 i >= j 情况对称 ，默认 i <= j 
		i == j ;   f[i][j] = f[i-1][j] + dis( i-1,  j ) 
		i == j-1 ; f[i][j] =  min (   f[k][j-1]  + dis( k , j  ) )  ,  1 <= k < i  ;
		i < j -1 ;  f[i][j]  = f[i][j-1] + dis( j -1 , j  ) 
	*/ 
	
	cin >> n ;
	for(int i =1; i <=n  ; ++ i ) {
		cin >>x[i] >>y[i] ; 
	}
	for(int i =1; i <=n ; ++ i ) {
		for(int j =1; j <=n ; ++ j )
			dist[i][j] = dis(  i , j )   ,f[i][j] = 1e8  ; 
	}
	for(int i = 1;  i<=n ; ++ i) f[0][i] = 0  ;
	f[1][1] = 0 ; 
	for(int i =2; i <=n ; ++ i ) f[1][i] = f[1][i-1]  + dist[i-1][i]  ; 
	for(int  i =2;  i <=n ; ++ i ) {
		for(int j =  i  ; j <=n ; ++ j ) {
			if( i == j ) f[i][j] = f[i-1][j] + dist[i-1][j];
			else if( i == j -1) {
				for(int k = 1; k < i ; ++ k ) {
					f[i][j] = min(f[i][j] ,f[k][i] + dist[k][j]  )  ; 
				}
			}else {
				f[i][j]  = f[i][j-1]  + dist[j-1][j] ; 
			}
		}
	}

	cout<< fixed<< setprecision( 8) << f[n][n] <<endl;
}	



int main(){ 	
	ios::sync_with_stdio(false);
	cin.tie( 0 ) ;
	int T;T  =1; 
	while(T-- ){	
		solve() ;  
   	}        
 	return  0 ;
}
