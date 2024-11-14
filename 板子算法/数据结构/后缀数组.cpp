#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6 +10  ;

typedef long long LL  ; 
class SA{
	public :
		int size , mx ;
		vector<int> sa , rk , height ,a ;
	SA( ) : size( 0 ){ } 
	~SA( ) { sa.clear( ) ; rk.clear() ; height.clear() ;  a.clear() ;  } 
	SA(int _size  , int _mx) :  size( _size ),  mx(_mx) ,sa( _size + 2  ) ,rk( _size+ 1 ) ,height( _size+ 1 ) ,a(_size+1) {} 
	void buildSa( string s ) {
		int n =  size ,m  = mx; 
		vector<int> x( n + 1, 0 ) , y( n + 1,  0 ) ; 
		for(int i =1; i <=n ; ++ i  )  a[i]  = s[i-1]  ; 
		vector<int >  c( m + 1, 0  ) ; 
		for(int i =1; i <=n ; ++ i )  ++ c[  x[i] = a[i]] ; 
		for(int i =1 ; i <=m  ; ++ i  ) c[i]  += c[i-1 ] ; 
		for(int i = n  ; i ;   -- i ) sa[ c[x[i]] -- ] =  i ;
		for(int  k = 1 ;  k <=n ; k <<= 1 ) {
			//  第二关键字的排序 
			int num = 0 ;
			for(int i = n- k + 1;  i <=n ; ++ i )  y[++num] = i ;
			for(int i =1; i <=n ; ++ i )  if( sa[i] >  k ) y[++num] = sa[i] - k ; 
			
			//第一关键字基数排序 
			for(int i = 0; i <=m ; ++ i ) c[i] = 0 ; 
			for(int i =1; i <=n ; ++ i )   ++ c[ x[y[i]]] ; 
			for(int i =1 ; i <=m ; ++ i  ) c[i] += c[i-1] ; 
			for(int i = n  ;  i ; -- i) sa[  c[x[y[i]]] --  ] = y[i] , y[i] = 0 ; 
			swap(x , y ) ; 
			x[ sa[1]] = num =  1; 
			for(int i =2; i  <=n ; ++ i ) {
				x[ sa[i] ] = ( y[sa[i]] == y[sa[i-1]] && y[ sa[i] + k  ] == y[sa[i-1] + k ] ) ? num : ++num  ;
			}
			if( num >= n ) break ;
			m = num ; 
		} 

	} 
	void buildHeight(){
		int k = 0   , n  = size; 
		for(int i =1; i  <=n ; ++ i )  rk[ sa[i]] = i  ;
		for(int i =1; i <=n ; ++ i ) {
			if( rk[i] == 1 ) continue ;
			if( k ) -- k ; 
			int j = sa[ rk[i] -1 ] ; 
			while( j + k  <= n && i+k<=n && a[i+k] ==a[j+k] ) ++ k ;
			height[ rk[i]] = k  ; 
		}
	}
};

string s ; 
int main( ) {
	cin >> s ;
	int n  = s.size( ) ;  
	SA sa( s.size( ) , N) ; 
	sa.buildSa( s ) ; 
	sa.buildHeight()  ;
	LL ans = 1LL* n *( n  + 1) /2  ; 
	for(int i =1;  i <=n ; ++ i )  ans -= sa.height[i] ;
	cout << ans <<'\n'  ;
	return 0 ; 
}
