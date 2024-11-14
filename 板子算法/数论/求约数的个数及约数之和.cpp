#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	int n;
	cin>>n;
	unordered_map<int, int > primes;
	int Number_yueshu = 1;
	while(n--){
		int x; 
		cin>>x;
		for(int i = 2; i<=x; ++i){
			while(x%i == 0){
				primes[i]++;
				x/=i;
			}	
		}
		if( x>1) primes[x]++;
		//接下来输出约数个数 
		for( auto x : primes){
			Number_yueshu*=(x.second+1);
			//out<<x.first<<" "<<x.second<<endl;
		}
		 
		cout<<"约数个数总共有："<<Number_yueshu<<"个"<<endl;
		//接下来输出约数之和
		long long  sum = 1;
		for( auto x: primes){
			int p = x.first, a= x.second;
			int t= 1;
			while( a--){
				t= t*p+1;
			}
			sum*=t;
		} 
		cout<<"约数之和是："<<sum<<endl;
		Number_yueshu = 1;
		primes.clear();
	}
	return 0;
}
