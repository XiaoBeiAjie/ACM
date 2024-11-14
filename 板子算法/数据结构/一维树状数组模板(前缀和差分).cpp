#include <iostream>
#include <vector>

using namespace std;

int lowbit(int x ){
	return x&(-x) ; 
}
template <typename T>
class BIT{
	public :
		int size ;
		vector<T> t ;
	BIT( int _size) :size(_size), t(_size + 1, 0){   }  
	BIT() : size(0) {}
	~BIT( ) { t.clear() ;} 
	BIT( const BIT &_t) {	size = _t.size ;  t = _t.t  ;} 
	void add(int x,T d){
		for(int i =x ; i<=size ; i+= lowbit( i)) t[i] +=d ;
	}
	T sum( int x ) {
		T res = 0 ; 
		for(int i = x; i ; i -=lowbit(i)) res +=t[i] ;
		return res;
	}
};


int main(){
	int  n ;
	int q; cin >> n >> q; 
	BIT<int> t( n+1  ) ; 
	for(int i =1; i <= n ; ++ i){
		int x ;cin >>x ;
		t.add( i , x ) ; t.add( i+1 ,-x)  ;
	}
	for(int i =1; i <=q ; ++ i) {
		int  op ;  
		cin >> op ; 
		if( op == 1) {
			int x , y , k ; 
			cin >> x >> y >> k ;
			t.add( x , k ) ; t.add( y+1 , -k ) ; 
		}
		else {
			int x; cin >>x  ;
			cout <<t.sum ( x) <<'\n' ;
		}
	}
	
	return 0 ;
}
