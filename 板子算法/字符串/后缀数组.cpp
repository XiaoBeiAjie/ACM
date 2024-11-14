#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6 +10  ;

typedef long long LL  ; 
class SA{
	public :
		int size ,mx ; 
		vector<int> sa , rk , height ;
	void build( vector<int> &a  ) {
		int n = size  , m =  max( mx , n ) ; 
		sa.assign( n + 1 , 0 ) ,  rk.assign(  n + 1 , 0 ) , height.assign( n + 1 ,  0) ; 
		vector<int> tax( m+1 , 0) , tp(n + 1) ; 
		for(int i =1; i <=n ; ++ i ) rk[i] = a[i] , tp[i] = i  ;
		auto RSort = [&]() {
			for(int i = 0 ; i <=m ; ++ i ) tax[i] = 0 ;
			for(int i =1; i <=n  ;++ i ) ++tax[  rk[ tp[i] ] ] ;
			for(int i =1; i <= m ; ++ i ) tax[i] += tax[i-1] ; 
			for(int i= n ; i ;  -- i )  sa[  tax[ rk[ tp[i] ] ]-- ] = tp[i] ; 
		};
		RSort( ) ;
		for(int k = 1 , p = 0; p < n ; k <<= 1, m = p) {
			p = 0 ;
			for( int i = n- k  + 1 ; i <= n ; ++ i ) tp[ ++ p ]  = i  ;
			for( int i =1 ; i  <= n ; ++ i  ) if( sa[i] > k )  tp[++p] = sa[i] -  k ;
			RSort( ) ; swap( rk , tp ) ; 
			rk[  sa[1] ] = p = 1 ;
			for(int i = 2 ; i <=n ; ++ i ) { 
				rk[ sa[i] ] = ( tp[ sa[i]] == tp[ sa[i-1]] && tp[ sa[i] + k ] == tp[ sa[i-1] +k ] ) ? p : ++ p ;
			}
				
 		}
 		int k = 0 ;
 		for(int i =1; i <=n ; ++ i ) {
 			if( rk[i] == 1 ) continue ;
 			if( k ) -- k ;
 			int j = sa[ rk[i] -1  ] ; 
 			while( j + k <= n && i + k <= n && a[i + k ] == a[ j + k ] ) ++ k ;
 			height[ rk[i] ] = k ;
		 }
	} 
	
	void builds( string s) {
		size  = mx  = s.size() ;  
		vector<int> a( size  + 1 ) ; 
		for(int i =1; i <= size ; ++ i ) a[i] = s[i-1 ] ,mx = max(  mx ,a[i] ); 
		build( a) ; 
	}

};

string s ; 
int main( ) {
	cin >> s; 
	int n = s.size() ; 
	SA sa ;
	sa.builds( s ) ; 
	int pos = 0 ,len = 0 ;
	for(int i = 2 ; i <= n ; ++ i ) if( sa.height[i] > len  ) pos = sa.sa[i] , len = sa.height[i] ; 
	if( !len ) cout << -1 <<'\n';
	else {
		for(int i = pos-1 , j = 0 ; j <len ; ++ j , ++ i ) cout << s[i] ;cout<<'\n';
	}
//	LL ans = 1LL*n *( n + 1 )/2 ;
//	for(int i =1 ;i <=n ; ++ i ) ans -= sa.height[i] ; 
//	cout <<ans <<'\n';
	return 0 ; 
}
