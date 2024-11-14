#include <iostream>
#include <cstring>
using namespace std;
const int N = 100010;
int primes[N];
int phi[N];
bool st[N];
int n;
int cnt = 0;

int main()
{
	cin>>n;
	for(int i=  2; i<= n ; ++i){
		if( !st[i]) {
			primes[cnt++] = i;
			phi[i] = i-1;
		}
		for(int j = 0 ; primes[j]<= n/i && j<cnt ; ++j ){
			st[ primes[j]*i ] = true;
			if( i% primes[j] == 0){
				phi[ i* primes[j]] = phi[i]*primes[j];
				break;
			}else phi[ i* primes[j] ] = phi[i]*(primes[j]-1);
		}
	}
	for(int i = 2; i<=n ; ++i){
		cout<<phi[i]<<" ";
	}
	
	return 0 ; 
}



