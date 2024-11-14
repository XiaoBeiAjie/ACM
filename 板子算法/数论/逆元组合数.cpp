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

LL fab[N] , inv[N] ; 

LL qmi(LL a , LL b) {
	LL res = 1 ;
	while(b  ) {
		if( b & 1)   res= (res *a) %mod ;
		a = ( a*a) %mod ;
		b >>= 1 ;
	}
	return res ;
}
LL C(int a ,int b ) {
	return fab[a]*inv[b]%mod *inv[a-b] %mod ;
}
void init() {
	inv[0] =fab[0] = 1 ;
	for(int i =1; i <N ; ++ i ) {
		fab[i] = fab[i-1]*i %mod ;
		inv[i] = inv[i-1] *qmi( i ,mod-2) %mod ;
	}
}


int main(){ 	
	ios::sync_with_stdio(false);
	cin.tie( 0 ) ;
	int T;T=1; 
	while(T-- ){	
	
   	}        
 	return  0 ;
}
