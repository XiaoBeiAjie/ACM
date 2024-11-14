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
LL gcd( LL a, LL b ){
	if (!b) return a ;
	return gcd( b, a%b) ; 
}

class  fra{
    public:	LL a ,b ;
	
	fra( LL _a , LL _b):a(_a) ,b(_b) {
		if(!b) cout<<"分母不能为0" <<endl ;
		sim() ; 
	} 
	
	fra( const fra &f ) {
		if(!b) cout<<"分母不能为0" <<endl ;
		a = f.a ; b=  f.b; 
		sim() ;
	}
	
	void sim(){
		LL t = gcd( a , b)  ; 
		a/=t , b/=  t ; 
	}
//	
//	fra operator+(  const  fra   &f){
//		LL c = a*f.b + f.a*b  ,d =  b *f.b  ;
//		a =c ; b=  d ;
//		sim() ; 
//		return *this ; 
//	}
//	fra operator-(  const  fra   &f){
//		LL c = a*f.b - f.a*b  ,d =  b*f.b ;
//		a =c ; b=  d ;
//		sim() ; 
//		return *this ; 
//	}
//	fra operator*( const fra &f) {
//		a *=f.a ; b*=f.b ;
//		sim( ) ;
//		return *this  ;
//	}
//	fra operator/(const fra &f){
//		fra t =f ; t.rev( ) ; 
//		return *this * t ; 
//	} 
	void rev( ){
		swap(a, b) ; 
	}
	
	friend ostream &operator<<(ostream &o , const  fra &f ) ; 
	friend fra operator+(const fra &x , const fra &y) ; 
	friend fra operator-(const fra &x , const fra &y) ; 
	friend fra operator*(const fra &x , const fra &y) ; 
	friend fra operator/(const fra &x , const fra &y) ; 
};

ostream &operator<<(ostream &o , const fra &f ) {
	o<< f.a <<"/" <<f.b ; 
	return o;
}

fra operator+(const fra &x , const fra &y){
	return fra( x.a *y.b + x.b*y.a ,  x.b*y.b) ; 
} 

fra operator-(const fra &x , const fra &y){
	return fra( x.a *y.b - x.b*y.a ,  x.b*y.b) ; 
}

fra operator*(const fra &x , const fra &y){
	return fra( x.a*y.a ,  x.b*y.b) ; 
}

fra operator/(const fra &x , const fra &y) {
	fra t = y  ; t.rev() ;
	return x*t ; 
}

int main(){
	fra a(1,3)  ,b(1,7)  ;
	cout <<a +b <<endl ;
	cout <<a -b <<endl ;
	cout <<a /b <<endl ;
	cout <<a *b <<endl ;
	return 0 ;
}
