#include <iostream>
using namespace std;

// 对于任意的a,b  有 ax+by = gcd( a,b)    x,y均为正整数 
// a mod  b  =  a - [a/b]*b
//  
int gcd( int x,int y ){
	if( !y) return x;
	return gcd( y,x%y);
}


int exgcd( int a,int b , int &x, int &y){
	if( b== 0 ){
		x= 1; y = 0;
		
		return a;
	}
	int d = exgcd( b, a%b,y,x);
	y-= a/b*x;
	return d;
}

int main()
{
	
	int  a,b;
	cin>>a>>b;
	int x,y;
	cout<<exgcd( a,b,x,y) <<endl;
	// a *x  = gcd( a ,b)  + py;
	//当x为负值的时候，要求x为整数，则x要变大，y减小。
	//每次变化的幅度最小为. a * dx = p * dy = lcs(a,p)即a , p 的最小公倍数
	// 则 dx = lcs( a, p ) / a , dy = lcs( a, p ) / p
	//当a,p互质时， dx = p , dy = a 
	//因此这时  x每次最少要增加p 
	while( x  < 0 ) x+= b; 
	
	cout<<x<<" "<<y<<endl;
	
	return 0;
}
