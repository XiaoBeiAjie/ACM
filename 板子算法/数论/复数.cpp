#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e6+10  ; 

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

int main() {
	return 0  ; 
} 
