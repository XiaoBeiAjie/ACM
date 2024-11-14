#include <iostream>
#include <vector>

using namespace std;
typedef long long LL ;
int lowbit(int x ){
	return x&(-x) ; 
}
template <typename T>
class BIT{
	public :
		int row , col ;
		vector< vector<T> > t ;
	BIT( int _row , int _col) :row(_row), col( _col) ,  t(_row + 1,  vector<T>( col + 1 ,  0 )){   }  
	BIT() : row(0), col( 0) {}
	~BIT( ) { t.clear() ;} 
	BIT( const BIT &_t) {	row = _t.row ; col = _t.col ;  t = _t.t  ;} 
	void add(int x, int y , T d){
		if( !x || !y ) return ; 
		for(int i =x ; i<= row ; i+= lowbit( i)) {
			for(int j = y ; j <=col; j += lowbit( j ))
				t[i][j] += d ;
		}
	}
	T sum( int x ,int y  ) {
		T res = 0 ; 
		for(int i = x; i ; i -=lowbit(i)){
			for(int j  = y ; j ; j -=lowbit( j) )
				res += t[i][j] ; 
		}
		return res;
	}
};


int main(){
	int T ;cin >>T ;
	while(T--){
		int  n , q ; 
		cin >> n >> q; 
		BIT<LL> t( n + 1 , n + 1  ) ; 
		while(q--) {
			char op ;  cin >>op ;
			if( op =='C'){
				int a ,b,c,d ;
				cin >>a >>b >> c >>d ;
				t.add( a , b, 1 ) ;
				t.add( a ,d + 1, -1) ; 
				t.add( c + 1, b , -1 ) ;
				t.add( c + 1, d + 1 , 1 ) ;
			}else {
				int x, y ; 
				cin >> x >> y ; 
				if( t.sum(x , y) & 1 ) cout <<1 <<'\n';
				else cout << 0 <<'\n' ; 
			}

		}
	}
	
	
	return 0 ;
}
