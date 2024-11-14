#include <iostream>
#include<cstdio>
#include<cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
const int N = 2e6+10 ;
const double PI = acos( -1.0) ;
class Complex{
	public :
		double x, y ; 
	Complex( ) :x( 0) ,y( 0 ) { }
	Complex(double _x , double _y) : x(_x) , y(_y){ } 
	Complex(const Complex &c) : x( c.x ) , y(c.y) { } 
	Complex operator+=(const Complex &c){
		x  += c.x ; y  += c.y ;
		return *this ;
	}
	Complex operator-=(const Complex &c){
		x  -= c.x ; y  -= c.y ;
		return *this ;
	}
	Complex operator*=(const Complex &com){
		double a = x, b = y ,c = com.x , d = com.y  ; 
		x = a*c - b*d ; y = a*d + b*c ;
		return *this ;
	}
	Complex operator+( const Complex &c) const {
		Complex t(*this) ; 
		return  t += c ;
	}
	Complex operator-( const Complex &c) const {
		Complex t(*this) ; 
		return  t -= c ;
	}
	Complex operator*( const Complex &c) const {
		Complex t(*this) ; 
		return  t *= c ;
	}
};
class FFT{
	public :
		int size ,tot , bit ;
		vector<int> rev; 
	FFT() { } 
	FFT(int _size ) :size(_size)  {
		int t = size ;  bit = 0 ;
		while( (1<<bit) < size + 1 )  ++bit  ; 
		tot = 1<<bit ;
		rev.assign( tot , 0) ; 
		for(int i = 0 ; i < tot ; ++ i )
			rev[i] = ( rev[ i>>1] >> 1 ) | ( (i & 1 ) << ( bit -1 )) ; 
	}
	~FFT( ) { rev.clear() ; } 
	// type : 1 - FFT  , 2 - IFFT
	void fft( vector< Complex> &a  ,int type ) {
		for(int i = 0 ;  i <tot ; ++ i ) 
			if( i < rev[i]) swap( a[i] , a[rev[i]])  ;
		for(int len = 1 ;len <tot ; len <<=1 ) {
			//w1 - w( n , 1 ) 
			Complex w1( cos( PI/len)  , sin(PI/len) *type ) ; 
			for(int i = 0 ; i < tot ; i += len*2){
				Complex wk( 1, 0 ) ; 
				for(int j = 0 ;  j< len ; ++ j , wk *= w1) {
					Complex x =  a[i+j] , y = wk*a[i+j +len] ; 
					a[i+j]  = x + y  , a[i+j +len ] = x - y ;
				}
			}
		}
	}
	
	
	
};
	int res[N] ;
int main() {
	string s,t;
	cin >>s >>t ;
	int flag = 0 ;
	if(s[0] == '-') s.erase( s.begin()) ,flag ^=1  ;
	if(t[0] == '-') t.erase( t.begin()),flag ^=1 ;
	int n  =s.size( ) , m =t.size() ; 
	FFT ft( n + m)  ;
	int tot = ft.tot;
	vector <Complex> a( tot ) ,b(tot ) ;
	for(int i = 0 ; i  < n ; ++ i) a[i].x = s[i] -'0' ; 
	for(int i = 0 ; i  < m  ;++ i ) b[i].x = t[i] -'0' ;
	
	ft.fft( a, 1 ) ;ft.fft(b,1) ;
	for(int i = 0 ; i  <ft.tot ; ++ i ) a[i] *= b[i]  ;

	ft.fft( a, -1) ; 
	reverse(a.begin() , a.begin() +n + m -1 )  ;
	int p , k = 0 ;
	for( p = 0 ; p < n + m-1 || k  ;++ p ) {
		res[p] = ((int)(a[p].x/ft.tot+0.5+k))%10;
		k=(a[p].x/ft.tot+0.5+k)/10;
	}
	if(flag && res[p] ) cout <<"-" ;
	for(p--;p>=0;p--) cout <<res[p] ;
}


int main1( ) {
	int n , m  ;
	cin >> n >> m ; 
	int tot = ( n + m )*3 ; 
	vector< Complex> a( tot) ,b( tot)  ; 
	for(int i = 0 ; i <=n ; ++ i ) cin>>a[i].x , a[i].y = 0 ;
	for(int i = 0 ; i <=m ; ++ i) cin >>b[i].x , b[i].y = 0 ; 
	FFT  ft( n + m ); 
	ft.fft( a, 1) ; ft.fft( b, 1 ) ; 
	for(int i = 0 ; i  <  ft.tot ; ++ i )  a[i] *=b[i] ;
	ft.fft( a, -1 ) ; 
	for(int i = 0 ; i  <= n + m ; ++ i )
		cout <<fixed <<setprecision(2) <<  (int)( a[i].x/ft.tot + 0.5 )  << " " ;
	cout <<'\n'; 
	return 0;
}
