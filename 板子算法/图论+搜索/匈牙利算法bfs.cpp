#include <iostream>
#include <algorithm>
#include <queue> 
using namespace std ; 
const int N = 2e5+10 ,  M = 5e5 +10 ;

int h[N ] ,e[M] , ne[M] , idx ;
int match[N] , flag[N] , pre[N] ; 
int n , m , k ; 
void add(int a, int b  ) {
	e[idx] = b, ne[idx] = h[a]  , h[a] = idx++ ;  
} 

int find( ) {
	int ans = 0 ;
	for(int i =1 ;i <=n ; ++ i  ){
		queue<int> q; 
		q.push( i ) ; 
		pre[ i ]  = 0; 
		bool ok = false ;
		while(q.size()) {
			int  u = q.front() ; q.pop( ) ; 
			for(int t =h[u] ; ~t ; t = ne[t]) {
				int j =e[t] ;
				if( flag[j] == i) continue ;
				flag[j] = i ; 
				if( match[j]) {
					pre[ match[j]] = u ; 
					q.push( match[j])  ;
				}else {
					int a = u , b = j  , k ; 
					while(a) {
						k = match[a] ; 
						match[a] = b; 
						match[b] = a; 
						a = pre[a] ;
						b = k ;
					}
					ok  = true ; break  ;
				}
			}
			if( ok ) break ; 
		}
		if( match[i]) ++ans ;
	}
	return ans ; 
}


void solve ( ) {
	cin >> n >> m >> k  ; 
	for(int i =1 ; i<=n ; ++ i ) h[i] = -1 ; idx = 0 ;
	while(  k--) {
		int a, b;cin >>a >>b; 
		++a , ++b ;
		b +=n ;
		add(a,b) ;add(b,a) ; 
	}
	cout << find( ) <<'\n' ; 
}

int main( ) {
	
	int T ; T = 1; 
	while( T--  ) solve( ) ; 
	
	return  0 ;
}
