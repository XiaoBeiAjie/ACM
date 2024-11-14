#include <iostream>
using namespace std;
typedef long long LL ;
int main()
{
	int n;
	 n= 1; 
	while(n--){
		LL x;
		cin>>x;
		LL res = x;
		for(int i = 2; i<=x/i ; ++i){
			if( x%i == 0){
				res= res*(i-1)/i;
				while( x%i ==0 ) x/=i;
			}
		}
		if( x>1 ) res = res*(x-1)/x;
		cout<<res<<endl;
	}
	
	return 0;
}
