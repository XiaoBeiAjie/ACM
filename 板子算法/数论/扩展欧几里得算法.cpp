#include <iostream>
using namespace std;

// ���������a,b  �� ax+by = gcd( a,b)    x,y��Ϊ������ 
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
	//��xΪ��ֵ��ʱ��Ҫ��xΪ��������xҪ���y��С��
	//ÿ�α仯�ķ�����СΪ. a * dx = p * dy = lcs(a,p)��a , p ����С������
	// �� dx = lcs( a, p ) / a , dy = lcs( a, p ) / p
	//��a,p����ʱ�� dx = p , dy = a 
	//�����ʱ  xÿ������Ҫ����p 
	while( x  < 0 ) x+= b; 
	
	cout<<x<<" "<<y<<endl;
	
	return 0;
}
