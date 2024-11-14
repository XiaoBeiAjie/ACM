#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long  qmi( long long a, long long k, long long p)
{
	long long res = 1;
	while( k){
		if( k & 1) {
			res = res*a %p ;
		}
		 k>>=1;
		 a = a*a %p ;
	}
	return res;
}


LL qmi(  LL a, LL b) {
	LL res =1;
	while(b) {
		if( b & 1 )res= ( res *a) % mod ;
		b >>= 1; 
		a= ( a*a ) %mod ;
	}
	return res; 
}

int main()
{
	long long a,k,p;
	cin>>a>>k>>p;
	cout<<qmi(a,k,p)<<endl;
	return 0;
}
