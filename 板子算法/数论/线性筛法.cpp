#include <iostream>
#include <vector>
using namespace std;
const int N = 100010;
bool st[N];
int primes[N];
int cnt = 0; 
int main()
{
	int n;
	cin>>n;
	for(int i = 2; i<= n ; ++i){
		if( !st[i]){
			primes[++cnt] = i;
		}
		for(int j = 1; j <=cnt && primes[j]<=n/i ; ++j ){
			st[primes[j] * i] = true;
			if( i%primes[j] == 0) break;
		}
	}
	//for(int i = 2; i<=n ; ++i) if(!st[i]) cout<<i<<" ";
	cout<<cnt<<endl;
	return 0;
}

